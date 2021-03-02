#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <mutex>
#include <pthread.h>
#include <thread>

using namespace std::chrono_literals;

struct data{
    int a;
    int b;
    int c;
    int d;
    int e;
};

std::vector<data> result_serial;
std::vector<data> result_parallel;
std::vector<data> result_openmp;

std::mutex mylock;

int iteration = 5000000;
int thread_number = 4;

std::vector<data> container;


std::chrono::high_resolution_clock::time_point before;
std::chrono::high_resolution_clock::time_point after;

void serial_filtering()
{
    for(int i = 0; i < container.size(); i++)
    {
        if(container[i].a > 40 && container[i].b > 30 && container[i].c > 80 && container[i].d > 20 && container[i].e > 20)
        {
            result_serial.push_back(container[i]);
        }
    }
}

void * parallel_filtering(void* iteration_)
{
    int iteration = *(int*)iteration_;
    for(int i = iteration; i < container.size(); i = i + thread_number)
    {
        if(container[i].a > 40 && container[i].b > 30 && container[i].c > 80 && container[i].d > 20 && container[i].e > 20)
        {
            mylock.lock();
            result_parallel.push_back(container[i]);
            mylock.unlock();
        }
    }

    return NULL;
}

void openmp_filtering()
{
    #pragma omp parallel for 
    for(int i = 0; i < container.size(); i++)
    {
        if(container[i].a > 40 && container[i].b > 30 && container[i].c > 80 && container[i].d > 20 && container[i].e > 20)
        {
            #pragma omp critical 
            {
                result_openmp.push_back(container[i]);
            }
        }
    }
}

int main()
{

    std::this_thread::sleep_for(500ms);

    srand(time(NULL));

    

    std::cout << "Creating Elements..." << std::flush;
    for(int i = 0; i < iteration; i++)
    {
        data d = data();
        d.a = rand() % 100;
        d.b = rand() % 100;
        d.c = rand() % 100;
        d.d = rand() % 100;
        d.e = rand() % 100;

        container.push_back(d);
    }
    std::cout << "Done" << std::endl;

    before = std::chrono::high_resolution_clock::now();
    serial_filtering();
    after = std::chrono::high_resolution_clock::now();
    std::cout << "Serial Execution: " << std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count() << std::endl;

    
    before = std::chrono::high_resolution_clock::now();
    pthread_t threads[thread_number];

    int * iterations = new int[4]{0,1,2,3};


    for(int i = 0; i < thread_number; i++)
    {
       
        pthread_create(&threads[i], NULL, parallel_filtering, (void*)&iterations[i]);
    }

    for(int i = 0; i < thread_number; i++)
    {
        pthread_join(threads[i], NULL);
    }
    after = std::chrono::high_resolution_clock::now();
    std::cout << "Parallel Execution: " << std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count() << std::endl;

    before = std::chrono::high_resolution_clock::now();
    openmp_filtering();
    after = std::chrono::high_resolution_clock::now();
    std::cout << "OpenMP Execution: " << std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count() << std::endl;

    

    return 0;
}