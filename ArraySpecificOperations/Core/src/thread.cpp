#include<iostream>
#include<vector>
#include<thread>
#include<pthread.h>
#include<sched.h>
#include<math.h>
#include<chrono>

#define THREAD_NUM 4
#define ARR_LENGTH 36000

unsigned short * arr_;

void * heavy_computation(unsigned short * arr_, unsigned short iterator)
{
    unsigned short result = 0;
    

    for(unsigned short i = (iterator * 9000); i < (iterator + 1) * 9000; i++)
    {
        result += arr_[i];
        
    }
    
    /*std::cout   << "This is calculated on iterator:" << iterator 
                << " and logical cpu core:"          << sched_getcpu()
                << std::endl;
    */
    //std::this_thread::sleep_for(::std::chrono_literals::operator""ms(1000));
    return NULL;
}

int main(int argc, const char ** argv)
{
    


    arr_ = new unsigned short[ARR_LENGTH];

    for(int i = 0; i < ARR_LENGTH;i++)
        arr_[i] = i;
    
    cpu_set_t cpuset;

 
    std::this_thread::sleep_for(std::chrono_literals::operator""s(1));

    while(true)
    {
        unsigned short i = 0;
        unsigned short j = 0;
        
        std::vector<std::thread> threads(THREAD_NUM);

        for(std::vector<std::thread>::iterator it = threads.begin(); it < threads.end(); it++)
        {   
            CPU_ZERO(&cpuset);
            *it = std::thread(heavy_computation, arr_, j);
            CPU_SET(i, &cpuset);
            pthread_setaffinity_np(it->native_handle(), sizeof(cpuset), &cpuset);
            
            int policy;
            struct sched_param param;
            pthread_getschedparam(it->native_handle(), &policy, &param);
            param.sched_priority = 130;
            pthread_setschedparam(it->native_handle(), SCHED_RR, &param);
            CPU_CLR(i, &cpuset);
            i = i + 3;
            j++;
        }
        auto before = std::chrono::high_resolution_clock::now();
        for(std::vector<std::thread>::iterator it = threads.begin(); it < threads.end(); it++)
        { 
            it->join();
        }
        auto after = std::chrono::high_resolution_clock::now();

        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(after-before).count() << std::endl;

        std::this_thread::sleep_for(std::chrono_literals::operator""ms(1000));
    }

    return 0;
}