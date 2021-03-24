#ifndef __ADJOINT_PARALLEL_HPP__
#define __ADJOINT_PARALLEL_HPP__

#include <vector>
#include <math.h>
#include <sched.h>
#include <pthread.h>
#include <type_traits>
#include <functional>

#include <framework/iterators/iterators.hpp>
#include <framework/settings/settings.hpp>
#include <framework/interfaces/base_parallel.hpp>


namespace framework
{

namespace base
{


template<typename T>
void getCofactor(std::vector<T> & A, std::vector<T> & temp, int p, int q, int n, int width)
{
    int i = 0, j = 0;
  
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i * width + j++] = A[row * width + col];
  
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

template<typename T>
T determinant(std::vector<T> & A, int n, int size, int width)
{
    T D = 0; 
  
    if (n == 1)
        return A[0];
  
    std::vector<int> temp; temp.reserve(size); 
  
    int sign = 1;  
 
    for (int f = 0; f < n; f++)
    {   
        getCofactor<T>(A, temp, 0, f, n, width);
        D += sign * A[0 * width + f] * determinant<T>(temp, n - 1, size, width);   
        sign = -sign;
    }
  
    return D;
}

template<typename T>
void * adjoint_parallel_pthread(void * iterators__)
{
    iterators<T>* iterators_ = (iterators<T>*)iterators__;
  
    int sign = 1;

    auto matrix_a = static_cast<std::vector<T>>(iterators_->matrix_a);
    auto matrix_b = static_cast<std::vector<T>>(iterators_->matrix_b);
    
    for (int i = iterators_->begin; i < iterators_->end; i++)
    {
        for (int j = 0; j < iterators_->width; j++)
        {
            getCofactor<T>(matrix_a, matrix_b , i, j, iterators_->width, iterators_->width);
            sign = ((i+j)%2==0)? 1: -1;
            iterators_->matrix_c[j * iterators_->width + i] = (sign)*(determinant<T>(matrix_b, iterators_->width - 1, iterators_->size, iterators_->width));
        }
    }
    return NULL; 
}
 

template<typename T>
void adjoint_parallel_openmp(const std::vector<T>& matrix_a_, const std::vector<T>& matrix_b_, std::vector<T>& matrix_c_, const settings & settings_)
{
    int matrix_delimeter = sqrt(matrix_a_.size());
    int boundary = matrix_a_.size() / sqrt(matrix_a_.size());

    int sign = 1;

    auto matrix_a = static_cast<std::vector<T>>(matrix_a_);
    auto matrix_b = static_cast<std::vector<T>>(matrix_b_);

    #pragma omp parallel for num_threads(settings_.THREAD_NUMBER)
    for (int i = 0; i < boundary; i++)
    {
        for (int j = 0; j < boundary; j++)
        {
            getCofactor<T>(matrix_a, matrix_b, i, j, matrix_delimeter, matrix_delimeter);
            sign = ((i+j)%2==0)? 1: -1;
            matrix_c_[j * matrix_delimeter + i] = (sign)*(determinant<T>(matrix_b, matrix_delimeter - 1, matrix_a_.size(), matrix_delimeter));
        }
    }

}

template<typename T>
void adjoint_serial(const std::vector<T>& matrix_a_, const std::vector<T>& matrix_b_, std::vector<T>& matrix_c_, const settings & settings_ )
{
    int matrix_delimeter = sqrt(matrix_a_.size());
    int boundary = matrix_a_.size() / sqrt(matrix_a_.size());

    int sign = 1;

    auto matrix_a = static_cast<std::vector<T>>(matrix_a_);
    auto matrix_b = static_cast<std::vector<T>>(matrix_b_);

    for (int i = 0; i < boundary; i++)
    {
        for (int j = 0; j < boundary; j++)
        {
            getCofactor<T>(matrix_a, matrix_b, i, j, matrix_delimeter, matrix_delimeter);
            sign = ((i+j)%2==0)? 1: -1;
            matrix_c_[j * matrix_delimeter + i] = (sign)*(determinant<T>(matrix_b, matrix_delimeter - 1, matrix_a_.size(), matrix_delimeter));
        }
    }

}

template<typename T>
class adjoint_parallel : public base_parallel<T>
{
    public:

        adjoint_parallel() : name("adjoint_parallel")
        {
            
        }

        adjoint_parallel(const std::vector<T>& matrix_a_, const std::vector<T>& matrix_b_, std::vector<T>& matrix_c_, const settings & settings_) : name("adjoint_parallel")
        {
            matrix_c_.reserve(matrix_a_.size());
            this->execute(matrix_a_, matrix_b_, matrix_c_, settings_);
        }

        adjoint_parallel(const std::vector<T>& matrix_a_, std::vector<T>& matrix_c_, const settings & settings_) : name("adjoint_parallel")
        {
            matrix_c_.reserve(matrix_a_.size() / 2);

            const std::vector<T> matrix_one{matrix_a_.begin(), (matrix_a_.size() / 2) + matrix_a_.begin()};
            const std::vector<T> matrix_two{(matrix_a_.size() / 2) + matrix_a_.begin(), matrix_a_.end()};
            this->execute(matrix_one, matrix_two, matrix_c_, settings_);
        }

    protected:
        void ctor(const std::vector<T>& matrix_a_, const std::vector<T>& matrix_b_, std::vector<T>& matrix_c_, const settings & settings_) 
        {
            matrix_c_.reserve(matrix_a_.size());
            this->execute(matrix_a_, matrix_b_, matrix_c_, settings_);
        }        

    private:

        std::string name;

        std::string get_name() const
        {
            return this->name;
        }

        void execute(const std::vector<T>& matrix_a_, const std::vector<T>& matrix_b_, std::vector<T>& matrix_c_, const settings & settings_)
        {
            if(settings_.PARALLELIZATION_STRATEGY == PARALLELIZATION_STRATEGY::PTHREADS)
            {
                if(settings_.AFFINITY == AFFINITY::TRUE)
                {
                    if(settings_.SCHED_STRATEGY != SCHEDULING_STRATEGY::SCHEDULING_TS)
                        execute_pthread_affine_sched(matrix_a_,matrix_b_, matrix_c_, settings_);
                    else
                        execute_pthread_affine(matrix_a_,matrix_b_, matrix_c_, settings_);
                }
                else
                {
                    if(settings_.SCHED_STRATEGY != SCHEDULING_STRATEGY::SCHEDULING_TS)
                        execute_pthread_sched(matrix_a_,matrix_b_, matrix_c_, settings_);
                    else
                        execute_pthread(matrix_a_,matrix_b_, matrix_c_, settings_);
                }

            }
            else if(settings_.PARALLELIZATION_STRATEGY == PARALLELIZATION_STRATEGY::OPENMP)
            {
                adjoint_parallel_openmp<T>(matrix_a_,matrix_b_, matrix_c_, settings_);
            }
            else 
            {
                adjoint_serial<T>(matrix_a_,matrix_b_, matrix_c_, settings_);
            }
            
        }

        void execute_pthread(const std::vector<T>& matrix_a_, const std::vector<T>& matrix_b_, std::vector<T>& matrix_c_, const settings & settings_)
        {
            pthread_t* threads = new pthread_t[settings_.THREAD_NUMBER];
            iterators<T>** iterators_ = new iterators<T>*[settings_.THREAD_NUMBER];

            for(int i = 0; i < settings_.THREAD_NUMBER; i++)
            {
                if(i != settings_.THREAD_NUMBER - 1)
                {
                    int delimeter = (int)((matrix_a_.size() / sqrt(matrix_a_.size())) / settings_.THREAD_NUMBER);
                    iterators_[i] = new iterators<T>(
                        matrix_a_, matrix_b_, matrix_c_,
                        i * delimeter,
                        (i + 1) * delimeter,
                        matrix_a_.size(),
                        (int)(sqrt(matrix_a_.size()))
                    );
                }
                else
                {
                    int delimeter = (int)((matrix_a_.size() / sqrt(matrix_a_.size())) / settings_.THREAD_NUMBER);
                    iterators_[i] = new iterators<T>(
                        matrix_a_, matrix_b_, matrix_c_,
                        i * delimeter,
                        matrix_a_.size() / sqrt(matrix_a_.size()),
                        matrix_a_.size(),
                        (int)(sqrt(matrix_a_.size()))
                    );
                }
                pthread_create(threads + i, NULL, adjoint_parallel_pthread<T>, (void*)iterators_[i]);                  
            }

            for(int i = 0; i < settings_.THREAD_NUMBER; i++)
            {
                pthread_join(*(threads + i), NULL);
            }
        }

        void execute_pthread_affine(const std::vector<T>& matrix_a_, const std::vector<T>& matrix_b_, std::vector<T>& matrix_c_, const settings & settings_)
        {
            pthread_t* threads = new pthread_t[settings_.THREAD_NUMBER];
            iterators<T>** iterators_ = new iterators<T>*[settings_.THREAD_NUMBER];

            cpu_set_t cpuset;
            int cpu_counter = 0;
           

            for(int i = 0; i < settings_.THREAD_NUMBER; i++)
            {   
                CPU_ZERO(&cpuset);
                if(i != settings_.THREAD_NUMBER - 1)
                {
                    int delimeter = (int)((matrix_a_.size() / sqrt(matrix_a_.size())) / settings_.THREAD_NUMBER);
                    iterators_[i] = new iterators<T>(
                        matrix_a_, matrix_b_, matrix_c_,
                        i * delimeter,
                        (i + 1) * delimeter,
                        matrix_a_.size(),
                        (int)(sqrt(matrix_a_.size()))
                    );
                }
                else
                {
                    int delimeter = (int)((matrix_a_.size() / sqrt(matrix_a_.size())) / settings_.THREAD_NUMBER);
                    iterators_[i] = new iterators<T>(
                        matrix_a_, matrix_b_, matrix_c_,
                        i * delimeter,
                        matrix_a_.size() / sqrt(matrix_a_.size()),
                        matrix_a_.size(),
                        (int)(sqrt(matrix_a_.size()))
                    );
                }
                pthread_create(threads + i, NULL, adjoint_parallel_pthread<T>, (void*)iterators_[i]); 
                CPU_SET(cpu_counter, &cpuset);
                pthread_setaffinity_np(*(threads + i), sizeof(cpuset), &cpuset);
                
                if(settings_.LOGICAL_CPUS.size() > 0) 
                {
                    CPU_CLR(settings_.LOGICAL_CPUS[cpu_counter], &cpuset);
                    cpu_counter = (cpu_counter + 1) % settings_.LOGICAL_CPUS.size();     
                }
                else
                {
                    CPU_CLR(cpu_counter, &cpuset);
                    cpu_counter += 2;    
                }
                        
            }

            for(int i = 0; i < settings_.THREAD_NUMBER; i++)
            {
                pthread_join(*(threads + i), NULL);
            }
        }

        void execute_pthread_sched(const std::vector<T>& matrix_a_, const std::vector<T>& matrix_b_, std::vector<T>& matrix_c_, const settings & settings_)
        {
            pthread_t* threads = new pthread_t[settings_.THREAD_NUMBER];
            iterators<T>** iterators_ = new iterators<T>*[settings_.THREAD_NUMBER];

            struct sched_param  sched_param_;
            sched_param_.sched_priority = settings_.PRIORITY;

            for(int i = 0; i < settings_.THREAD_NUMBER; i++)
            {
                if(i != settings_.THREAD_NUMBER - 1)
                {
                    int delimeter = (int)((matrix_a_.size() / sqrt(matrix_a_.size())) / settings_.THREAD_NUMBER);
                    iterators_[i] = new iterators<T>(
                        matrix_a_, matrix_b_, matrix_c_,
                        i * delimeter,
                        (i + 1) * delimeter,
                        matrix_a_.size(),
                        (int)(sqrt(matrix_a_.size()))
                    );
                }
                else
                {
                    int delimeter = (int)((matrix_a_.size() / sqrt(matrix_a_.size())) / settings_.THREAD_NUMBER);
                    iterators_[i] = new iterators<T>(
                        matrix_a_, matrix_b_, matrix_c_,
                        i * delimeter,
                        matrix_a_.size() / sqrt(matrix_a_.size()),
                        matrix_a_.size(),
                        (int)(sqrt(matrix_a_.size()))
                    );
                }
                pthread_create(threads + i, NULL, adjoint_parallel_pthread<T>, (void*)iterators_[i]);  
                pthread_setschedparam(*(threads + i), settings_.SCHED_STRATEGY, &sched_param_);                
            }

            for(int i = 0; i < settings_.THREAD_NUMBER; i++)
            {
                pthread_join(*(threads + i), NULL);
            }
        }

        void execute_pthread_affine_sched(const std::vector<T>& matrix_a_, const std::vector<T>& matrix_b_, std::vector<T>& matrix_c_, const settings & settings_)
        {
            pthread_t* threads = new pthread_t[settings_.THREAD_NUMBER];
            iterators<T>** iterators_ = new iterators<T>*[settings_.THREAD_NUMBER];
            
            cpu_set_t cpuset;
            int cpu_counter = 0;

            struct sched_param  sched_param_;
            sched_param_.sched_priority = settings_.PRIORITY;

            for(int i = 0; i < settings_.THREAD_NUMBER; i++)
            {
                CPU_ZERO(&cpuset);
                if(i != settings_.THREAD_NUMBER - 1)
                {
                    int delimeter = (int)((matrix_a_.size() / sqrt(matrix_a_.size())) / settings_.THREAD_NUMBER);
                    iterators_[i] = new iterators<T>(
                        matrix_a_, matrix_b_, matrix_c_,
                        i * delimeter,
                        (i + 1) * delimeter,
                        matrix_a_.size(),
                        (int)(sqrt(matrix_a_.size()))
                    );
                }
                else
                {
                    int delimeter = (int)((matrix_a_.size() / sqrt(matrix_a_.size())) / settings_.THREAD_NUMBER);
                    iterators_[i] = new iterators<T>(
                        matrix_a_, matrix_b_, matrix_c_,
                        i * delimeter,
                        matrix_a_.size() / sqrt(matrix_a_.size()),
                        matrix_a_.size(),
                        (int)(sqrt(matrix_a_.size()))
                    );
                }
                pthread_create(threads + i, NULL, adjoint_parallel_pthread<T>, (void*)iterators_[i]); 

                CPU_SET(cpu_counter, &cpuset);
                pthread_setaffinity_np(*(threads + i), sizeof(cpuset), &cpuset); 
                
                pthread_setschedparam(*(threads + i), settings_.SCHED_STRATEGY, &sched_param_);  
                
                cpu_counter += 2;    
                CPU_CLR(cpu_counter, &cpuset);                      
            }

            for(int i = 0; i < settings_.THREAD_NUMBER; i++)
            {
                pthread_join(*(threads + i), NULL);
            }
        }

};

}

}

#endif