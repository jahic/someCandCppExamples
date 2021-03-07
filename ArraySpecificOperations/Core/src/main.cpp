#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <thread>
#include <iostream>
#include <chrono>
#include <pthread.h>
#include <unistd.h>
#include <math.h>
#include <vector>

using namespace std::chrono_literals;

#define MAX_ARRAY_SIZE 50000000

int * arr_;

void another_function(int i)
{
        std::this_thread::sleep_for(1500ms);
        std::cout << "this thread:" << i <<  " is running on this CPU:" << sched_getcpu() << std::endl;
}

void * my_stupid_function(void* arr_)
{
    std::chrono::high_resolution_clock::time_point before = std::chrono::high_resolution_clock::now();
    int* arr = (int*)arr_;
    for(int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        arr[i] = arr[i] + arr[i] * arr[i] * arr[i] * (int)pow(2.0f, 2.0f);
    }

    std::chrono::high_resolution_clock::time_point after = std::chrono::high_resolution_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count() 
              << " on CPU:"
              << sched_getcpu()
              << std::endl; 
    
    return NULL;
}


void * my_stupid_function_2(void* arr_)
{
    std::chrono::high_resolution_clock::time_point before = std::chrono::high_resolution_clock::now();
    int* arr = (int*)arr_;
    for(int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        arr[i] = arr[i] + arr[i] * arr[i] * arr[i] * (int)pow(2.0f, 2.0f);
    }

    std::chrono::high_resolution_clock::time_point after = std::chrono::high_resolution_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count() 
              << " on CPU:"
              << sched_getcpu()
              << std::endl; 
    
    return NULL;
}


int main(int argc, char ** argv) 
{

    arr_ = new int[MAX_ARRAY_SIZE];

    for(int i = 0; i < MAX_ARRAY_SIZE; i++)
        arr_[i] = i;


   

    /*
    // We want to camp on the 2nd CPU. The ID of that core is #1.
    const int core_id = 2;
    const pid_t pid = getpid();

    // cpu_set_t: This data set is a bitset where each bit represents a CPU.
    cpu_set_t cpuset;
    // CPU_ZERO: This macro initializes the CPU set set to be the empty set.
    CPU_ZERO(&cpuset);
    // CPU_SET: This macro adds cpu to the CPU set set.
    CPU_SET(core_id, &cpuset);
 
    // sched_setaffinity: This function installs the cpusetsize bytes long affinity mask pointed to by cpuset for the process or thread with the ID pid. If successful the function returns zero and the scheduler will in future take the affinity information into account.
    const int set_result = sched_setaffinity(pid, sizeof(cpu_set_t), &cpuset);
    */
    pthread_t thread;

    int i = 0;

     

        
    cpu_set_t cpuset;
    

    pthread_create(&thread, NULL, my_stupid_function, (void*)arr_);
    CPU_ZERO(&cpuset);
    CPU_SET(5, &cpuset);
    pthread_setaffinity_np(thread, sizeof(cpuset), &cpuset);
    pthread_join(thread, NULL);
    
    CPU_CLR(5, &cpuset);
        
        
       while(true)
       {
            pthread_t thread_2;

            pthread_create(&thread_2, NULL, my_stupid_function, (void*)arr_);
             CPU_ZERO(&cpuset);
            CPU_SET(2, &cpuset);
            pthread_setaffinity_np(thread_2, sizeof(cpuset), &cpuset);
            pthread_join(thread_2, NULL);
            std::this_thread::sleep_for(1000ms);
       } 
    return 0;
}