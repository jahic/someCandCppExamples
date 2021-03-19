#ifndef __MULTIPLY_PARALLEL_HPP__
#define __MULTIPLY_PARALLEL_HPP__

#include<pthread.h>
#include<vector>
#include<math.h>
#include<sched.h>
#include<chrono>
#include<time.h>
#include<stdlib.h>
#include<sstream>
#include<fstream>

constexpr unsigned long long operator"" _THREADS(unsigned long long _threads)
{ 
    return  _threads; 
}

constexpr unsigned long long operator"" _PRIORITY(unsigned long long _priority)
{
    return _priority;
}


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

namespace TIME_FORMAT
{
    typedef std::milli MILLI;
    typedef std::micro MICRO;
    typedef std::nano  NANO;
}


struct settings
{
    public:
        settings() 
        {
            this->THREAD_NUMBER            =     2_THREADS;
            this->SCHED_STRATEGY           =     SCHEDULING_STRATEGY::SCHEDULING_TS;
            this->PRIORITY                 =     19_PRIORITY;
            this->AFFINITY                 =     AFFINITY::FALSE;
            this->PARALLELIZATION_STRATEGY =     PARALLELIZATION_STRATEGY::PTHREADS;
        }

        settings(int thread_number_, int parallelization_strategy_) :
            THREAD_NUMBER(thread_number_),
            SCHED_STRATEGY(SCHEDULING_STRATEGY::SCHEDULING_TS),
            PRIORITY(19_PRIORITY),
            AFFINITY(AFFINITY::FALSE),
            PARALLELIZATION_STRATEGY(parallelization_strategy_)
        {

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

    private:

        const char * get_scheduling_strategy(int scheduling_strategy) const
        {
            if(scheduling_strategy == SCHEDULING_STRATEGY::SCHEDULING_RR)
                return "\"RR\"";
            else if(scheduling_strategy == SCHEDULING_STRATEGY::SCHEDULING_FIFO)
                return "\"FIFO\"";
            
            return "\"TS\"";
        }

        const char * get_affinity(bool affinity_) const
        {
            if(affinity_)
                return "\"true\"";
            
            return "\"false\"";
        }

        const char * get_parallelization_strategy(int parallelization_strategy) const
        {
            if(parallelization_strategy == PARALLELIZATION_STRATEGY::OPENMP)
                return "\"OPENMP\"";

            return "\"PTHREADS\"";
        }

        friend std::ostream& operator<<(std::ostream& os, const settings& settings_);
};

std::ostream& operator<<(std::ostream& os, const settings& settings_)
{
    os << "[" << settings_.THREAD_NUMBER                                                    << ", "
              << settings_.get_scheduling_strategy(settings_.SCHED_STRATEGY)                << ", "
              << settings_.PRIORITY                                                         << ", "
              << settings_.get_affinity(settings_.AFFINITY)                                 << ", " 
              << settings_.get_parallelization_strategy(settings_.PARALLELIZATION_STRATEGY) << "]";

    return os;
}

template<typename T>
struct iterators
{

    iterators(
        const std::vector<T>& matrix_a_, 
        const std::vector<T>& matrix_b_,
        std::vector<T>& matrix_c_, 
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

    const std::vector<T>& matrix_a;
    const std::vector<T>& matrix_b;
    std::vector<T>& matrix_c;
    int begin;
    int end;
    int size;
    int width;
};

template<typename T>
void * multiply_parallel_pthread(void * iterators__)
{
    iterators<T>* iterators_ = (iterators<T>*)iterators__;

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

template<typename T>
class benchmark;

template<typename T>
class base_parallel
{
    protected:
        virtual void ctor(const std::vector<T>& matrix_a_, const std::vector<T>& matrix_b_, std::vector<T>& matrix_c_, const settings & settings_) = 0;
    private:

        virtual std::string get_name() const = 0;

        virtual void execute(const std::vector<T>& matrix_a_, const std::vector<T>& matrix_b_, std::vector<T>& matrix_c_, const settings & settings_) = 0;
        virtual void execute_pthread(const std::vector<T>& matrix_a_, const std::vector<T>& matrix_b_, std::vector<T>& matrix_c_, const settings & settings_) = 0;
        virtual void execute_pthread_affine(const std::vector<T>& matrix_a_, const std::vector<T>& matrix_b_, std::vector<T>& matrix_c_, const settings & settings_) = 0;
        virtual void execute_pthread_sched(const std::vector<T>& matrix_a_, const std::vector<T>& matrix_b_, std::vector<T>& matrix_c_, const settings & settings_) = 0;
        virtual void execute_pthread_affine_sched(const std::vector<T>& matrix_a_, const std::vector<T>& matrix_b_, std::vector<T>& matrix_c_, const settings & settings_) = 0;
        virtual void execute_openmp(const std::vector<T>& matrix_a_, const std::vector<T>& matrix_b_, std::vector<T>& matrix_c_, const settings & settings_ ) = 0;

        friend class benchmark<T>;
};

template<typename T>
class multiply_parallel : public base_parallel<T>
{
    public:

        multiply_parallel() : name("multiply_parallel")
        {
            
        }

        multiply_parallel(const std::vector<T>& matrix_a_, const std::vector<T>& matrix_b_, std::vector<T>& matrix_c_, const settings & settings_) : name("multiply_parallel")
        {
            matrix_c_.reserve(matrix_a_.size());
            this->execute(matrix_a_, matrix_b_, matrix_c_, settings_);
        }

        multiply_parallel(const std::vector<T>& matrix_a_, std::vector<T>& matrix_c_, const settings & settings_) : name("multiply_parallel")
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
                execute_openmp(matrix_a_,matrix_b_, matrix_c_, settings_);
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
                pthread_create(threads + i, NULL, multiply_parallel_pthread<T>, (void*)iterators_[i]);                  
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
                pthread_create(threads + i, NULL, multiply_parallel_pthread<T>, (void*)iterators_[i]);   
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
                pthread_create(threads + i, NULL, multiply_parallel_pthread<T>, (void*)iterators_[i]);  
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
                pthread_create(threads + i, NULL, multiply_parallel_pthread<T>, (void*)iterators_[i]); 

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

        void execute_openmp(const std::vector<T>& matrix_a_, const std::vector<T>& matrix_b_, std::vector<T>& matrix_c_, const settings & settings_ )
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



class single_generator
{
    public:
        template<typename T = int>
        static std::vector<T> generate_input(int size)
        {
            std::vector<T> temp(size * size);

            srand(time(NULL));

            for(int i = 0; i < temp.capacity(); i++)
            {
                temp[i] = (T)(((rand() % RAND_MAX) + 1)+(rand() / RAND_MAX));
            }

            return temp;
        }
};


class generator
{
    public:
        template<typename T = int>
        static std::vector<std::vector<T> > generate_inputs(std::initializer_list<int> sizes)
        {
            srand(time(NULL));
            std::vector<std::vector<T> > content;

            for(auto size : sizes)
            {
                std::vector<T> temp(size * size);

                for(int i = 0; i < temp.capacity(); i++)
                {
                    temp[i] = (T)(((rand() % RAND_MAX) + 1)+(rand() / RAND_MAX));
                }

                content.push_back(temp);
            }

            return content;
            
        }

        static std::vector<settings> generate_settings(std::initializer_list<settings> settings_)
        {
            std::vector<settings> content;

            for(auto setting : settings_)
            {
                content.push_back(setting);
            }

            return content;
        }
};

class json_generator
{
    public:

        json_generator() = default;

        json_generator& add(const settings& settings_)
        {
            output_stream << settings_;

            return *this;
        }

        json_generator& add(const int&& iteration_)
        {
            output_stream << iteration_;

            return *this;
        }

        json_generator& add(std::string text_stream)
        {
            output_stream << text_stream.c_str();

            return *this;
        }

        template<typename T = TIME_FORMAT::NANO>
        json_generator& add(const std::chrono::duration<int64_t, T>& duration)
        {
            if(T::den / 1000000000 == 1)
                output_stream << "nano";
            else if(T::den / 1000000 == 1)
                output_stream << "micro";
            else
                output_stream << "milli";
            return *this;
        }

        void save_to_json_file(const std::string& file_name)
        {
            std::ofstream ofs(file_name + ".json", std::ios::out);

            ofs << output_stream.str();

            ofs.close();
        }

        void print()
        {
            std::cout << output_stream.str() << std::endl;
        }

    private:
        std::stringstream output_stream;
};



template<typename T>
class benchmark
{
    public:


        benchmark(base_parallel<T>* base_parallel_, std::vector<T> input_a_, std::vector<T> input_b_, settings settings_) : 
            base_parallel_(base_parallel_),
            input_a_(input_a_),
            input_b_(input_b_),
            settings_(settings_)
        {
            result_.reserve(input_a_.capacity());
        }

        benchmark(base_parallel<T>* base_parallel_, std::vector<std::vector<T> > inputs_a_, std::vector<std::vector<T> > inputs_b_, std::vector<settings> settingss_) :
            base_parallel_(base_parallel_),
            inputs_a_(inputs_a_),
            inputs_b_(inputs_b_),
            settingss_(settingss_)
        {
            
        }

        template<typename K = TIME_FORMAT::NANO> 
        unsigned long long
        execute()
        {
            before = std::chrono::high_resolution_clock::now();
            base_parallel_->ctor(input_a_, input_b_, result_, settings_);
            after  = std::chrono::high_resolution_clock::now();

            return std::chrono::duration_cast<std::chrono::duration<int64_t, K> >(after - before).count();
        }

        template<typename K = TIME_FORMAT::NANO>
        void
        execute_all()
        {

            std::string name = base_parallel_->get_name();
            
            json_generator_.add("{\n\t\"name\" : \"")
                           .add(name)
                           .add("\",\n\t\"time_unit\" : \"")
                           .add<K>(std::chrono::duration<int64_t, K>())
                           .add("\",")
                           .add("\n\t\"tests\" : {");

            for(int i = 0; i < settingss_.size(); i++)
            {
                json_generator_.add("\n\t\t\"test_")
                               .add(i + 1)
                               .add("\" : {")
                               .add("\n\t\t\t\"settings\" : ")
                               .add(settingss_[i])
                               .add(",\n\t\t\t\"measurements\" : {");

                for(int j = 0; j < inputs_a_.size(); j++)
                {
                    result_.reserve(inputs_a_[j].capacity());
                    before = std::chrono::high_resolution_clock::now();
                    base_parallel_->ctor(inputs_a_[j], inputs_b_[j], result_, settingss_[i]);
                    after  = std::chrono::high_resolution_clock::now();

                    json_generator_.add("\n\t\t\t\t\"")
                                   .add((int&&)sqrt(inputs_a_[j].size()))
                                   .add("x")
                                   .add((int&&)sqrt(inputs_a_[j].size()))
                                   .add("\" : ")
                                   .add((int&&)std::chrono::duration_cast<std::chrono::duration<int64_t, K> >(after - before).count());

                    if(j != inputs_a_.size() - 1)
                        json_generator_.add(",");
                   
                    result_.clear();
                }

                json_generator_.add("\n\t\t\t}");

                if(i == settingss_.size() - 1)
                    json_generator_.add("\n\t\t}");
                else
                    json_generator_.add("\n\t\t},");

            }

            json_generator_.add("\n\t}\n}");

            json_generator_.save_to_json_file(base_parallel_->get_name());
        }

       
    private:
    
        std::chrono::high_resolution_clock::time_point before;
        std::chrono::high_resolution_clock::time_point after;

        base_parallel<T>* base_parallel_;

        std::vector<T> input_a_;
        std::vector<T> input_b_;
        std::vector<T> result_;
        settings settings_;

        std::vector<std::vector<T> > inputs_a_;
        std::vector<std::vector<T> > inputs_b_;
        
        std::vector<std::vector<T>> results_;
        std::vector<settings>       settingss_;

        json_generator json_generator_;
        
};




#endif