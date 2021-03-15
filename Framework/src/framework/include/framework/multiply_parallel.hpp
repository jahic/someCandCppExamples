#ifndef __MULTIPLY_PARALLEL_HPP__
#define __MULTIPLY_PARALLEL_HPP__

#include<pthread.h>
#include<vector>
#include<math.h>
#include<sched.h>



constexpr unsigned long long 
    operator"" THREADS(unsigned long long _hours)
    { return  _hours; }


namespace PARALLELIZATION_STRATEGY
{
    int PTHREADS = 0;
    int OPENMP   = 1;
}

namespace AFFINITY
{
    bool TRUE  = true;
    bool FALSE = false;
}

namespace SCHEDULING_STRATEGY
{
    int SCHEDULING_TS   = 0;
    int SCHEDULING_FIFO = 1;
    int SCHEDULING_RR   = 2;
}

struct settings
{

    settings() 
    {
        this->THREAD_NUMBER            =     2;
        this->SCHED_STRATEGY           =     1;
        this->PRIORITY                 =    19;
        this->AFFINITY                 = false;
        this->PARALLELIZATION_STRATEGY =     1;
    }

    settings(int thread_number_, int sched_strategy_, int priority_, bool affinity_, int parallelization_strategy_) :
        THREAD_NUMBER(thread_number_),
        SCHED_STRATEGY(sched_strategy_),
        PRIORITY(priority_),
        AFFINITY(affinity_),
        PARALLELIZATION_STRATEGY(parallelization_strategy_)
    {

    }

    int  THREAD_NUMBER;
    int  SCHED_STRATEGY;
    int  PRIORITY;
    bool AFFINITY;
    int  PARALLELIZATION_STRATEGY;
};

struct iterators
{

    iterators(
        const std::vector<int>& matrix_a_, 
        const std::vector<int>& matrix_b_,
        std::vector<int>& matrix_c_, 
        int begin_,
        int end_,
        int size_, 
        int width_) : 
        matrix_a(matrix_a_),
        matrix_b(matrix_b_),
        matrix_c(matrix_c_),
        begin(begin_),
        end(end_),
        size(size_),
        width(width_)
    {

    }

    const std::vector<int>& matrix_a;
    const std::vector<int>& matrix_b;
    std::vector<int>& matrix_c;
    int begin;
    int end;
    int size;
    int width;
    //int width;
};


void * multiply_parallel_pthread(void * iterators__)
{
    iterators* iterators_ = (iterators*)iterators__;

    for(int i = iterators_->begin; i < iterators_->end; i++)
    {
        for(int j = 0; j < iterators_->width; j++)
        {
            for(int k = 0; k < iterators_->width; k++)
            {
                iterators_->matrix_c[i * iterators_->width + j] += 
                    iterators_->matrix_a[i * iterators_->width + k] * 
                    iterators_->matrix_b[k * iterators_->width + j]; 
            }
        }
    }
    return NULL;   
}

class multiply_parallel
{
    public:
        multiply_parallel(const std::vector<int>& matrix_a_, const std::vector<int>& matrix_b_, std::vector<int>& matrix_c_, const settings & settings_)
        {
            matrix_c_.reserve(matrix_a_.size());
            this->execute(matrix_a_, matrix_b_, matrix_c_, settings_);
        }

        multiply_parallel(const std::vector<int>& matrix_a_, std::vector<int>& matrix_c_, const settings & settings_)
        {
            matrix_c_.reserve(matrix_a_.size() / 2);

            const std::vector<int> matrix_one{matrix_a_.begin(), (matrix_a_.size() / 2) + matrix_a_.begin()};
            const std::vector<int> matrix_two{(matrix_a_.size() / 2) + matrix_a_.begin(), matrix_a_.end()};
            this->execute(matrix_one, matrix_two, matrix_c_, settings_);
        }

    private:

        void execute(const std::vector<int>& matrix_a_, const std::vector<int>& matrix_b_, std::vector<int>& matrix_c_, const settings & settings_)
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
                execute_openmp(matrix_a_,matrix_b_, matrix_c_, settings_);
            }
            
        }

        void execute_pthread(const std::vector<int>& matrix_a_, const std::vector<int>& matrix_b_, std::vector<int>& matrix_c_, const settings & settings_)
        {
            pthread_t* threads = new pthread_t[settings_.THREAD_NUMBER];
            iterators** iterators_ = new iterators*[settings_.THREAD_NUMBER];

            for(int i = 0; i < settings_.THREAD_NUMBER; i++)
            {
                if(i != settings_.THREAD_NUMBER - 1)
                {
                    int delimeter = (int)((matrix_a_.size() / sqrt(matrix_a_.size())) / settings_.THREAD_NUMBER);
                    iterators_[i] = new iterators(
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
                    iterators_[i] = new iterators(
                        matrix_a_, matrix_b_, matrix_c_,
                        i * delimeter,
                        matrix_a_.size() / sqrt(matrix_a_.size()),
                        matrix_a_.size(),
                        (int)(sqrt(matrix_a_.size()))
                    );
                }
                pthread_create(threads + i, NULL, multiply_parallel_pthread, (void*)iterators_[i]);                  
            }

            for(int i = 0; i < settings_.THREAD_NUMBER; i++)
            {
                pthread_join(*(threads + i), NULL);
            }
        }

        void execute_pthread_affine(const std::vector<int>& matrix_a_, const std::vector<int>& matrix_b_, std::vector<int>& matrix_c_, const settings & settings_)
        {
            pthread_t* threads = new pthread_t[settings_.THREAD_NUMBER];
            iterators** iterators_ = new iterators*[settings_.THREAD_NUMBER];

            cpu_set_t cpuset;
            int cpu_counter = 0;

            for(int i = 0; i < settings_.THREAD_NUMBER; i++)
            {   
                CPU_ZERO(&cpuset);
                if(i != settings_.THREAD_NUMBER - 1)
                {
                    int delimeter = (int)((matrix_a_.size() / sqrt(matrix_a_.size())) / settings_.THREAD_NUMBER);
                    iterators_[i] = new iterators(
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
                    iterators_[i] = new iterators(
                        matrix_a_, matrix_b_, matrix_c_,
                        i * delimeter,
                        matrix_a_.size() / sqrt(matrix_a_.size()),
                        matrix_a_.size(),
                        (int)(sqrt(matrix_a_.size()))
                    );
                }
                pthread_create(threads + i, NULL, multiply_parallel_pthread, (void*)iterators_[i]);   
                CPU_SET(cpu_counter, &cpuset);
                pthread_setaffinity_np(*(threads + i), sizeof(cpuset), &cpuset);
                
                cpu_counter += 2;    
                CPU_CLR(cpu_counter, &cpuset);        
            }

            for(int i = 0; i < settings_.THREAD_NUMBER; i++)
            {
                pthread_join(*(threads + i), NULL);
            }
        }

        void execute_pthread_sched(const std::vector<int>& matrix_a_, const std::vector<int>& matrix_b_, std::vector<int>& matrix_c_, const settings & settings_)
        {
            pthread_t* threads = new pthread_t[settings_.THREAD_NUMBER];
            iterators** iterators_ = new iterators*[settings_.THREAD_NUMBER];

            struct sched_param  sched_param_;
            sched_param_.sched_priority = settings_.PRIORITY;

            for(int i = 0; i < settings_.THREAD_NUMBER; i++)
            {
                if(i != settings_.THREAD_NUMBER - 1)
                {
                    int delimeter = (int)((matrix_a_.size() / sqrt(matrix_a_.size())) / settings_.THREAD_NUMBER);
                    iterators_[i] = new iterators(
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
                    iterators_[i] = new iterators(
                        matrix_a_, matrix_b_, matrix_c_,
                        i * delimeter,
                        matrix_a_.size() / sqrt(matrix_a_.size()),
                        matrix_a_.size(),
                        (int)(sqrt(matrix_a_.size()))
                    );
                }
                pthread_create(threads + i, NULL, multiply_parallel_pthread, (void*)iterators_[i]);  
                pthread_setschedparam(*(threads + i), settings_.SCHED_STRATEGY, &sched_param_);                
            }

            for(int i = 0; i < settings_.THREAD_NUMBER; i++)
            {
                pthread_join(*(threads + i), NULL);
            }
        }

        void execute_pthread_affine_sched(const std::vector<int>& matrix_a_, const std::vector<int>& matrix_b_, std::vector<int>& matrix_c_, const settings & settings_)
        {
            pthread_t* threads = new pthread_t[settings_.THREAD_NUMBER];
            iterators** iterators_ = new iterators*[settings_.THREAD_NUMBER];
            
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
                    iterators_[i] = new iterators(
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
                    iterators_[i] = new iterators(
                        matrix_a_, matrix_b_, matrix_c_,
                        i * delimeter,
                        matrix_a_.size() / sqrt(matrix_a_.size()),
                        matrix_a_.size(),
                        (int)(sqrt(matrix_a_.size()))
                    );
                }
                pthread_create(threads + i, NULL, multiply_parallel_pthread, (void*)iterators_[i]); 

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

        void execute_openmp(const std::vector<int>& matrix_a_, const std::vector<int>& matrix_b_, std::vector<int>& matrix_c_, const settings & settings_ )
        {
            #pragma omp parallel num_threads(settings_.THREAD_NUMBER)
            for(int i = 0; i < matrix_a_.size() / sqrt(matrix_a_.size()) ; i++)
            {
                for(int j = 0; j < matrix_a_.size() / sqrt(matrix_a_.size()); j++)
                {
                    for(int k = 0; k < matrix_a_.size() / sqrt(matrix_a_.size()); k++)
                    {
                        matrix_c_[i * sqrt(matrix_a_.size()) + j] += 
                            matrix_a_[i * sqrt(matrix_a_.size()) + k] * 
                            matrix_b_[k * sqrt(matrix_a_.size()) + j]; 
                    }
                }
            }
        }
};

#endif