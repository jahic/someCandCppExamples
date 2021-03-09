#include<iostream>
#include<pthread.h>
#include<sched.h>
#include<chrono>


void * my_function(void*)
{

    int policy;

    sched_param param;

    std::cout << pthread_getschedparam(pthread_self(), &policy, &param) << std::endl;

    std::cout << policy << std::endl;

    std::cout << param.sched_priority << std::endl;

    while(true){};
    return NULL;
}

int main(int argc, char ** argv)
{   
    pthread_t my_thread;

    sched_param param;
    param.sched_priority = 19;

    pthread_create(&my_thread, NULL, my_function, NULL);

    pthread_setschedparam(my_thread, SCHED_RR, &param);


    pthread_join(my_thread, NULL);

    return 0;
}