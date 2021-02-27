#include<iostream>
#include<chrono>
#include <stdlib.h>     
#include <time.h> 
#include <fstream>
#include <thread>
#include <pthread.h>

using namespace std::chrono_literals;

struct matrices_container{
    int **a;
    int **b;
    int **c;
}*matrices;

int64_t data_200_int_matrix_multiplication_serial()
{
    srand(time(NULL));
    const int matrix_size = 200;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_500_int_matrix_multiplication_serial()
{
    srand(time(NULL));
    const int matrix_size = 500;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_800_int_matrix_multiplication_serial()
{
    srand(time(NULL));
    const int matrix_size = 800;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_1000_int_matrix_multiplication_serial()
{
    srand(time(NULL));
    const int matrix_size = 1000;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_2000_int_matrix_multiplication_serial()
{
    srand(time(NULL));
    const int matrix_size = 2000;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}

int64_t data_200_double_matrix_multiplication_serial()
{
    srand(time(NULL));
    const int matrix_size = 200;
    
    double **a = new double*[matrix_size];
    double **b = new double*[matrix_size];

    double **c = new double*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new double[matrix_size];
        b[i] = new double[matrix_size];
        c[i] = new double[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (double)rand() / RAND_MAX;
            b[i][j] = (double)rand() / RAND_MAX;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_500_double_matrix_multiplication_serial()
{
    srand(time(NULL));
    const int matrix_size = 500;
    
    double **a = new double*[matrix_size];
    double **b = new double*[matrix_size];

    double **c = new double*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new double[matrix_size];
        b[i] = new double[matrix_size];
        c[i] = new double[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (double)rand() / RAND_MAX;
            b[i][j] = (double)rand() / RAND_MAX;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_800_double_matrix_multiplication_serial()
{
    srand(time(NULL));
    const int matrix_size = 800;
    
    double **a = new double*[matrix_size];
    double **b = new double*[matrix_size];

    double **c = new double*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new double[matrix_size];
        b[i] = new double[matrix_size];
        c[i] = new double[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (double)rand() / RAND_MAX;
            b[i][j] = (double)rand() / RAND_MAX;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_1000_double_matrix_multiplication_serial()
{
    srand(time(NULL));
    const int matrix_size = 1000;
    
    double **a = new double*[matrix_size];
    double **b = new double*[matrix_size];

    double **c = new double*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new double[matrix_size];
        b[i] = new double[matrix_size];
        c[i] = new double[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (double)rand() / RAND_MAX;
            b[i][j] = (double)rand() / RAND_MAX;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_2000_double_matrix_multiplication_serial()
{
    srand(time(NULL));
    const int matrix_size = 2000;
    
    double **a = new double*[matrix_size];
    double **b = new double*[matrix_size];

    double **c = new double*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new double[matrix_size];
        b[i] = new double[matrix_size];
        c[i] = new double[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (double)rand() / RAND_MAX;
            b[i][j] = (double)rand() / RAND_MAX;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}

void* multiply_int_parallel_pthreads_2_200(void* iteration_)
{
    int iteration = *((int*)iteration_);
    
    for(int i = iteration; i < 200; i = i + 2)
    {
        for(int j = 0; j < 200; j++)
        {
            for(int k = 0; k < 200; k++)
            {
                matrices->c[i][j] += matrices->a[i][k] * matrices->b[k][j];
            }  
        }
    }
    return NULL;
}
void* multiply_int_parallel_pthreads_2_500(void* iteration_)
{
    int iteration = *((int*)iteration_);
    
    for(int i = iteration; i < 500; i = i + 2)
    {
        for(int j = 0; j < 500; j++)
        {
            for(int k = 0; k < 500; k++)
            {
                matrices->c[i][j] += matrices->a[i][k] * matrices->b[k][j];
            }  
        }
    }
    return NULL;
}
void* multiply_int_parallel_pthreads_2_800(void* iteration_)
{
    int iteration = *((int*)iteration_);
    
    for(int i = iteration; i < 800; i = i + 2)
    {
        for(int j = 0; j < 800; j++)
        {
            for(int k = 0; k < 800; k++)
            {
                matrices->c[i][j] += matrices->a[i][k] * matrices->b[k][j];
            }  
        }
    }
    return NULL;
}
void* multiply_int_parallel_pthreads_2_1000(void* iteration_)
{
    int iteration = *((int*)iteration_);
    
    for(int i = iteration; i < 1000; i = i + 2)
    {
        for(int j = 0; j < 1000; j++)
        {
            for(int k = 0; k < 1000; k++)
            {
                matrices->c[i][j] += matrices->a[i][k] * matrices->b[k][j];
            }  
        }
    }
    return NULL;
}
void* multiply_int_parallel_pthreads_2_2000(void* iteration_)
{
    int iteration = *((int*)iteration_);
    
    for(int i = iteration; i < 2000; i = i + 2)
    {
        for(int j = 0; j < 2000; j++)
        {
            for(int k = 0; k < 2000; k++)
            {
                matrices->c[i][j] += matrices->a[i][k] * matrices->b[k][j];
            }  
        }
    }
    return NULL;
}

void* multiply_int_parallel_pthreads_4_200(void* iteration_)
{
    int iteration = *((int*)iteration_);
    
    for(int i = iteration; i < 200; i = i + 4)
    {
        for(int j = 0; j < 200; j++)
        {
            for(int k = 0; k < 200; k++)
            {
                matrices->c[i][j] += matrices->a[i][k] * matrices->b[k][j];
            }  
        }
    }
    return NULL;
}
void* multiply_int_parallel_pthreads_4_500(void* iteration_)
{
    int iteration = *((int*)iteration_);
    
    for(int i = iteration; i < 500; i = i + 4)
    {
        for(int j = 0; j < 500; j++)
        {
            for(int k = 0; k < 500; k++)
            {
                matrices->c[i][j] += matrices->a[i][k] * matrices->b[k][j];
            }  
        }
    }
    return NULL;
}
void* multiply_int_parallel_pthreads_4_800(void* iteration_)
{
    int iteration = *((int*)iteration_);
    
    for(int i = iteration; i < 800; i = i + 4)
    {
        for(int j = 0; j < 800; j++)
        {
            for(int k = 0; k < 800; k++)
            {
                matrices->c[i][j] += matrices->a[i][k] * matrices->b[k][j];
            }  
        }
    }
    return NULL;
}
void* multiply_int_parallel_pthreads_4_1000(void* iteration_)
{
    int iteration = *((int*)iteration_);
    
    for(int i = iteration; i < 1000; i = i + 4)
    {
        for(int j = 0; j < 1000; j++)
        {
            for(int k = 0; k < 1000; k++)
            {
                matrices->c[i][j] += matrices->a[i][k] * matrices->b[k][j];
            }  
        }
    }
    return NULL;
}
void* multiply_int_parallel_pthreads_4_2000(void* iteration_)
{
    int iteration = *((int*)iteration_);
    
    for(int i = iteration; i < 2000; i = i + 4)
    {
        for(int j = 0; j < 2000; j++)
        {
            for(int k = 0; k < 2000; k++)
            {
                matrices->c[i][j] += matrices->a[i][k] * matrices->b[k][j];
            }  
        }
    }
    return NULL;
}

void* multiply_int_parallel_pthreads_12_200(void* iteration_)
{
    int iteration = *((int*)iteration_);
    
    for(int i = iteration; i < 200; i = i + 12)
    {
        for(int j = 0; j < 200; j++)
        {
            for(int k = 0; k < 200; k++)
            {
                matrices->c[i][j] += matrices->a[i][k] * matrices->b[k][j];
            }  
        }
    }
    return NULL;
}
void* multiply_int_parallel_pthreads_12_500(void* iteration_)
{
    int iteration = *((int*)iteration_);
    
    for(int i = iteration; i < 500; i = i + 12)
    {
        for(int j = 0; j < 500; j++)
        {
            for(int k = 0; k < 500; k++)
            {
                matrices->c[i][j] += matrices->a[i][k] * matrices->b[k][j];
            }  
        }
    }
    return NULL;
}
void* multiply_int_parallel_pthreads_12_800(void* iteration_)
{
    int iteration = *((int*)iteration_);
    
    for(int i = iteration; i < 800; i = i + 12)
    {
        for(int j = 0; j < 800; j++)
        {
            for(int k = 0; k < 800; k++)
            {
                matrices->c[i][j] += matrices->a[i][k] * matrices->b[k][j];
            }  
        }
    }
    return NULL;
}
void* multiply_int_parallel_pthreads_12_1000(void* iteration_)
{
    int iteration = *((int*)iteration_);
    
    for(int i = iteration; i < 1000; i = i + 12)
    {
        for(int j = 0; j < 1000; j++)
        {
            for(int k = 0; k < 1000; k++)
            {
                matrices->c[i][j] += matrices->a[i][k] * matrices->b[k][j];
            }  
        }
    }
    return NULL;
}
void* multiply_int_parallel_pthreads_12_2000(void* iteration_)
{
    int iteration = *((int*)iteration_);
    
    for(int i = iteration; i < 2000; i = i + 12)
    {
        for(int j = 0; j < 2000; j++)
        {
            for(int k = 0; k < 2000; k++)
            {
                matrices->c[i][j] += matrices->a[i][k] * matrices->b[k][j];
            }  
        }
    }
    return NULL;
}

int64_t data_200_int_matrix_multiplication_pthreads_2()
{
    srand(time(NULL));
    const int matrix_size = 200;
    const int thread_number = 2;

    matrices = (matrices_container*)malloc(sizeof(matrices_container));

    matrices->a = new int*[matrix_size];
    matrices->b = new int*[matrix_size];
    matrices->c = new int*[matrix_size];
    
    for(int i = 0; i < matrix_size; i++)
    {
        matrices->a[i] = new int[matrix_size];
        matrices->b[i] = new int[matrix_size];
        matrices->c[i] = new int[matrix_size];

        for(int j = 0; j < matrix_size; j++)
        {
            matrices->a[i][j] = (rand() % RAND_MAX) + 1;
            matrices->b[i][j] = (rand() % RAND_MAX) + 1;
            matrices->c[i][j] = 0;
        }
    }

    pthread_t threads[thread_number];

    int * iterator = new int[thread_number];

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < thread_number; i++)
    {
        iterator[i] = i;
        pthread_create(&threads[i], NULL, multiply_int_parallel_pthreads_2_200, (void*)&iterator[i]);
    }

    for(int i = 0; i < thread_number; i++)
    {
        pthread_join(threads[i], NULL);
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] matrices->a[i];
        delete[] matrices->b[i];
        delete[] matrices->c[i];
    }

    delete[] matrices->a;
    delete[] matrices->b;
    delete[] matrices->c;

    delete matrices;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}
int64_t data_500_int_matrix_multiplication_pthreads_2()
{
    srand(time(NULL));
    const int matrix_size = 500;
    const int thread_number = 2;

    matrices = (matrices_container*)malloc(sizeof(matrices_container));

    matrices->a = new int*[matrix_size];
    matrices->b = new int*[matrix_size];
    matrices->c = new int*[matrix_size];
    
    for(int i = 0; i < matrix_size; i++)
    {
        matrices->a[i] = new int[matrix_size];
        matrices->b[i] = new int[matrix_size];
        matrices->c[i] = new int[matrix_size];

        for(int j = 0; j < matrix_size; j++)
        {
            matrices->a[i][j] = (rand() % RAND_MAX) + 1;
            matrices->b[i][j] = (rand() % RAND_MAX) + 1;
            matrices->c[i][j] = 0;
        }
    }

    pthread_t threads[thread_number];

    int * iterator = new int[thread_number];

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < thread_number; i++)
    {
        iterator[i] = i;
        pthread_create(&threads[i], NULL, multiply_int_parallel_pthreads_2_500, (void*)&iterator[i]);
    }

    for(int i = 0; i < thread_number; i++)
    {
        pthread_join(threads[i], NULL);
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] matrices->a[i];
        delete[] matrices->b[i];
        delete[] matrices->c[i];
    }

    delete[] matrices->a;
    delete[] matrices->b;
    delete[] matrices->c;

    delete matrices;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}
int64_t data_800_int_matrix_multiplication_pthreads_2()
{
    srand(time(NULL));
    const int matrix_size = 800;
    const int thread_number = 2;

    matrices = (matrices_container*)malloc(sizeof(matrices_container));

    matrices->a = new int*[matrix_size];
    matrices->b = new int*[matrix_size];
    matrices->c = new int*[matrix_size];
    
    for(int i = 0; i < matrix_size; i++)
    {
        matrices->a[i] = new int[matrix_size];
        matrices->b[i] = new int[matrix_size];
        matrices->c[i] = new int[matrix_size];

        for(int j = 0; j < matrix_size; j++)
        {
            matrices->a[i][j] = (rand() % RAND_MAX) + 1;
            matrices->b[i][j] = (rand() % RAND_MAX) + 1;
            matrices->c[i][j] = 0;
        }
    }

    pthread_t threads[thread_number];

    int * iterator = new int[thread_number];

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < thread_number; i++)
    {
        iterator[i] = i;
        pthread_create(&threads[i], NULL, multiply_int_parallel_pthreads_2_800, (void*)&iterator[i]);
    }

    for(int i = 0; i < thread_number; i++)
    {
        pthread_join(threads[i], NULL);
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] matrices->a[i];
        delete[] matrices->b[i];
        delete[] matrices->c[i];
    }

    delete[] matrices->a;
    delete[] matrices->b;
    delete[] matrices->c;

    delete matrices;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}
int64_t data_1000_int_matrix_multiplication_pthreads_2()
{
    srand(time(NULL));
    const int matrix_size = 1000;
    const int thread_number = 2;

    matrices = (matrices_container*)malloc(sizeof(matrices_container));

    matrices->a = new int*[matrix_size];
    matrices->b = new int*[matrix_size];
    matrices->c = new int*[matrix_size];
    
    for(int i = 0; i < matrix_size; i++)
    {
        matrices->a[i] = new int[matrix_size];
        matrices->b[i] = new int[matrix_size];
        matrices->c[i] = new int[matrix_size];

        for(int j = 0; j < matrix_size; j++)
        {
            matrices->a[i][j] = (rand() % RAND_MAX) + 1;
            matrices->b[i][j] = (rand() % RAND_MAX) + 1;
            matrices->c[i][j] = 0;
        }
    }

    pthread_t threads[thread_number];

    int * iterator = new int[thread_number];

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < thread_number; i++)
    {
        iterator[i] = i;
        pthread_create(&threads[i], NULL, multiply_int_parallel_pthreads_2_1000, (void*)&iterator[i]);
    }

    for(int i = 0; i < thread_number; i++)
    {
        pthread_join(threads[i], NULL);
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] matrices->a[i];
        delete[] matrices->b[i];
        delete[] matrices->c[i];
    }

    delete[] matrices->a;
    delete[] matrices->b;
    delete[] matrices->c;

    delete matrices;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}
int64_t data_2000_int_matrix_multiplication_pthreads_2()
{
    srand(time(NULL));
    const int matrix_size = 2000;
    const int thread_number = 2;

    matrices = (matrices_container*)malloc(sizeof(matrices_container));

    matrices->a = new int*[matrix_size];
    matrices->b = new int*[matrix_size];
    matrices->c = new int*[matrix_size];
    
    for(int i = 0; i < matrix_size; i++)
    {
        matrices->a[i] = new int[matrix_size];
        matrices->b[i] = new int[matrix_size];
        matrices->c[i] = new int[matrix_size];

        for(int j = 0; j < matrix_size; j++)
        {
            matrices->a[i][j] = (rand() % RAND_MAX) + 1;
            matrices->b[i][j] = (rand() % RAND_MAX) + 1;
            matrices->c[i][j] = 0;
        }
    }

    pthread_t threads[thread_number];

    int * iterator = new int[thread_number];

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < thread_number; i++)
    {
        iterator[i] = i;
        pthread_create(&threads[i], NULL, multiply_int_parallel_pthreads_2_2000, (void*)&iterator[i]);
    }

    for(int i = 0; i < thread_number; i++)
    {
        pthread_join(threads[i], NULL);
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] matrices->a[i];
        delete[] matrices->b[i];
        delete[] matrices->c[i];
    }

    delete[] matrices->a;
    delete[] matrices->b;
    delete[] matrices->c;

    delete matrices;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}

int64_t data_200_int_matrix_multiplication_pthreads_4()
{
    srand(time(NULL));
    const int matrix_size = 200;
    const int thread_number = 4;

    matrices = (matrices_container*)malloc(sizeof(matrices_container));

    matrices->a = new int*[matrix_size];
    matrices->b = new int*[matrix_size];
    matrices->c = new int*[matrix_size];
    
    for(int i = 0; i < matrix_size; i++)
    {
        matrices->a[i] = new int[matrix_size];
        matrices->b[i] = new int[matrix_size];
        matrices->c[i] = new int[matrix_size];

        for(int j = 0; j < matrix_size; j++)
        {
            matrices->a[i][j] = (rand() % RAND_MAX) + 1;
            matrices->b[i][j] = (rand() % RAND_MAX) + 1;
            matrices->c[i][j] = 0;
        }
    }

    pthread_t threads[thread_number];

    int * iterator = new int[thread_number];

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < thread_number; i++)
    {
        iterator[i] = i;
        pthread_create(&threads[i], NULL, multiply_int_parallel_pthreads_4_200, (void*)&iterator[i]);
    }

    for(int i = 0; i < thread_number; i++)
    {
        pthread_join(threads[i], NULL);
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] matrices->a[i];
        delete[] matrices->b[i];
        delete[] matrices->c[i];
    }

    delete[] matrices->a;
    delete[] matrices->b;
    delete[] matrices->c;

    delete matrices;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}
int64_t data_500_int_matrix_multiplication_pthreads_4()
{
    srand(time(NULL));
    const int matrix_size = 500;
    const int thread_number = 4;

    matrices = (matrices_container*)malloc(sizeof(matrices_container));

    matrices->a = new int*[matrix_size];
    matrices->b = new int*[matrix_size];
    matrices->c = new int*[matrix_size];
    
    for(int i = 0; i < matrix_size; i++)
    {
        matrices->a[i] = new int[matrix_size];
        matrices->b[i] = new int[matrix_size];
        matrices->c[i] = new int[matrix_size];

        for(int j = 0; j < matrix_size; j++)
        {
            matrices->a[i][j] = (rand() % RAND_MAX) + 1;
            matrices->b[i][j] = (rand() % RAND_MAX) + 1;
            matrices->c[i][j] = 0;
        }
    }

    pthread_t threads[thread_number];

    int * iterator = new int[thread_number];

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < thread_number; i++)
    {
        iterator[i] = i;
        pthread_create(&threads[i], NULL, multiply_int_parallel_pthreads_4_500, (void*)&iterator[i]);
    }

    for(int i = 0; i < thread_number; i++)
    {
        pthread_join(threads[i], NULL);
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] matrices->a[i];
        delete[] matrices->b[i];
        delete[] matrices->c[i];
    }

    delete[] matrices->a;
    delete[] matrices->b;
    delete[] matrices->c;

    delete matrices;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}
int64_t data_800_int_matrix_multiplication_pthreads_4()
{
    srand(time(NULL));
    const int matrix_size = 800;
    const int thread_number = 4;

    matrices = (matrices_container*)malloc(sizeof(matrices_container));

    matrices->a = new int*[matrix_size];
    matrices->b = new int*[matrix_size];
    matrices->c = new int*[matrix_size];
    
    for(int i = 0; i < matrix_size; i++)
    {
        matrices->a[i] = new int[matrix_size];
        matrices->b[i] = new int[matrix_size];
        matrices->c[i] = new int[matrix_size];

        for(int j = 0; j < matrix_size; j++)
        {
            matrices->a[i][j] = (rand() % RAND_MAX) + 1;
            matrices->b[i][j] = (rand() % RAND_MAX) + 1;
            matrices->c[i][j] = 0;
        }
    }

    pthread_t threads[thread_number];

    int * iterator = new int[thread_number];

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < thread_number; i++)
    {
        iterator[i] = i;
        pthread_create(&threads[i], NULL, multiply_int_parallel_pthreads_4_800, (void*)&iterator[i]);
    }

    for(int i = 0; i < thread_number; i++)
    {
        pthread_join(threads[i], NULL);
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] matrices->a[i];
        delete[] matrices->b[i];
        delete[] matrices->c[i];
    }

    delete[] matrices->a;
    delete[] matrices->b;
    delete[] matrices->c;

    delete matrices;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}
int64_t data_1000_int_matrix_multiplication_pthreads_4()
{
    srand(time(NULL));
    const int matrix_size = 1000;
    const int thread_number = 4;

    matrices = (matrices_container*)malloc(sizeof(matrices_container));

    matrices->a = new int*[matrix_size];
    matrices->b = new int*[matrix_size];
    matrices->c = new int*[matrix_size];
    
    for(int i = 0; i < matrix_size; i++)
    {
        matrices->a[i] = new int[matrix_size];
        matrices->b[i] = new int[matrix_size];
        matrices->c[i] = new int[matrix_size];

        for(int j = 0; j < matrix_size; j++)
        {
            matrices->a[i][j] = (rand() % RAND_MAX) + 1;
            matrices->b[i][j] = (rand() % RAND_MAX) + 1;
            matrices->c[i][j] = 0;
        }
    }

    pthread_t threads[thread_number];

    int * iterator = new int[thread_number];

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < thread_number; i++)
    {
        iterator[i] = i;
        pthread_create(&threads[i], NULL, multiply_int_parallel_pthreads_4_1000, (void*)&iterator[i]);
    }

    for(int i = 0; i < thread_number; i++)
    {
        pthread_join(threads[i], NULL);
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] matrices->a[i];
        delete[] matrices->b[i];
        delete[] matrices->c[i];
    }

    delete[] matrices->a;
    delete[] matrices->b;
    delete[] matrices->c;

    delete matrices;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}
int64_t data_2000_int_matrix_multiplication_pthreads_4()
{
    srand(time(NULL));
    const int matrix_size = 2000;
    const int thread_number = 4;

    matrices = (matrices_container*)malloc(sizeof(matrices_container));

    matrices->a = new int*[matrix_size];
    matrices->b = new int*[matrix_size];
    matrices->c = new int*[matrix_size];
    
    for(int i = 0; i < matrix_size; i++)
    {
        matrices->a[i] = new int[matrix_size];
        matrices->b[i] = new int[matrix_size];
        matrices->c[i] = new int[matrix_size];

        for(int j = 0; j < matrix_size; j++)
        {
            matrices->a[i][j] = (rand() % RAND_MAX) + 1;
            matrices->b[i][j] = (rand() % RAND_MAX) + 1;
            matrices->c[i][j] = 0;
        }
    }

    pthread_t threads[thread_number];

    int * iterator = new int[thread_number];

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < thread_number; i++)
    {
        iterator[i] = i;
        pthread_create(&threads[i], NULL, multiply_int_parallel_pthreads_4_2000, (void*)&iterator[i]);
    }

    for(int i = 0; i < thread_number; i++)
    {
        pthread_join(threads[i], NULL);
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] matrices->a[i];
        delete[] matrices->b[i];
        delete[] matrices->c[i];
    }

    delete[] matrices->a;
    delete[] matrices->b;
    delete[] matrices->c;

    delete matrices;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}

int64_t data_200_int_matrix_multiplication_pthreads_12()
{
    srand(time(NULL));
    const int matrix_size = 200;
    const int thread_number = 12;

    matrices = (matrices_container*)malloc(sizeof(matrices_container));

    matrices->a = new int*[matrix_size];
    matrices->b = new int*[matrix_size];
    matrices->c = new int*[matrix_size];
    
    for(int i = 0; i < matrix_size; i++)
    {
        matrices->a[i] = new int[matrix_size];
        matrices->b[i] = new int[matrix_size];
        matrices->c[i] = new int[matrix_size];

        for(int j = 0; j < matrix_size; j++)
        {
            matrices->a[i][j] = (rand() % RAND_MAX) + 1;
            matrices->b[i][j] = (rand() % RAND_MAX) + 1;
            matrices->c[i][j] = 0;
        }
    }

    pthread_t threads[thread_number];

    int * iterator = new int[thread_number];

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < thread_number; i++)
    {
        iterator[i] = i;
        pthread_create(&threads[i], NULL, multiply_int_parallel_pthreads_12_200, (void*)&iterator[i]);
    }

    for(int i = 0; i < thread_number; i++)
    {
        pthread_join(threads[i], NULL);
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] matrices->a[i];
        delete[] matrices->b[i];
        delete[] matrices->c[i];
    }

    delete[] matrices->a;
    delete[] matrices->b;
    delete[] matrices->c;

    delete matrices;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}
int64_t data_500_int_matrix_multiplication_pthreads_12()
{
    srand(time(NULL));
    const int matrix_size = 500;
    const int thread_number = 12;

    matrices = (matrices_container*)malloc(sizeof(matrices_container));

    matrices->a = new int*[matrix_size];
    matrices->b = new int*[matrix_size];
    matrices->c = new int*[matrix_size];
    
    for(int i = 0; i < matrix_size; i++)
    {
        matrices->a[i] = new int[matrix_size];
        matrices->b[i] = new int[matrix_size];
        matrices->c[i] = new int[matrix_size];

        for(int j = 0; j < matrix_size; j++)
        {
            matrices->a[i][j] = (rand() % RAND_MAX) + 1;
            matrices->b[i][j] = (rand() % RAND_MAX) + 1;
            matrices->c[i][j] = 0;
        }
    }

    pthread_t threads[thread_number];

    int * iterator = new int[thread_number];

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < thread_number; i++)
    {
        iterator[i] = i;
        pthread_create(&threads[i], NULL, multiply_int_parallel_pthreads_12_500, (void*)&iterator[i]);
    }

    for(int i = 0; i < thread_number; i++)
    {
        pthread_join(threads[i], NULL);
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] matrices->a[i];
        delete[] matrices->b[i];
        delete[] matrices->c[i];
    }

    delete[] matrices->a;
    delete[] matrices->b;
    delete[] matrices->c;

    delete matrices;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}
int64_t data_800_int_matrix_multiplication_pthreads_12()
{
    srand(time(NULL));
    const int matrix_size = 800;
    const int thread_number = 12;

    matrices = (matrices_container*)malloc(sizeof(matrices_container));

    matrices->a = new int*[matrix_size];
    matrices->b = new int*[matrix_size];
    matrices->c = new int*[matrix_size];
    
    for(int i = 0; i < matrix_size; i++)
    {
        matrices->a[i] = new int[matrix_size];
        matrices->b[i] = new int[matrix_size];
        matrices->c[i] = new int[matrix_size];

        for(int j = 0; j < matrix_size; j++)
        {
            matrices->a[i][j] = (rand() % RAND_MAX) + 1;
            matrices->b[i][j] = (rand() % RAND_MAX) + 1;
            matrices->c[i][j] = 0;
        }
    }

    pthread_t threads[thread_number];

    int * iterator = new int[thread_number];

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < thread_number; i++)
    {
        iterator[i] = i;
        pthread_create(&threads[i], NULL, multiply_int_parallel_pthreads_12_800, (void*)&iterator[i]);
    }

    for(int i = 0; i < thread_number; i++)
    {
        pthread_join(threads[i], NULL);
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] matrices->a[i];
        delete[] matrices->b[i];
        delete[] matrices->c[i];
    }

    delete[] matrices->a;
    delete[] matrices->b;
    delete[] matrices->c;

    delete matrices;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}
int64_t data_1000_int_matrix_multiplication_pthreads_12()
{
    srand(time(NULL));
    const int matrix_size = 1000;
    const int thread_number = 12;

    matrices = (matrices_container*)malloc(sizeof(matrices_container));

    matrices->a = new int*[matrix_size];
    matrices->b = new int*[matrix_size];
    matrices->c = new int*[matrix_size];
    
    for(int i = 0; i < matrix_size; i++)
    {
        matrices->a[i] = new int[matrix_size];
        matrices->b[i] = new int[matrix_size];
        matrices->c[i] = new int[matrix_size];

        for(int j = 0; j < matrix_size; j++)
        {
            matrices->a[i][j] = (rand() % RAND_MAX) + 1;
            matrices->b[i][j] = (rand() % RAND_MAX) + 1;
            matrices->c[i][j] = 0;
        }
    }

    pthread_t threads[thread_number];

    int * iterator = new int[thread_number];

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < thread_number; i++)
    {
        iterator[i] = i;
        pthread_create(&threads[i], NULL, multiply_int_parallel_pthreads_12_1000, (void*)&iterator[i]);
    }

    for(int i = 0; i < thread_number; i++)
    {
        pthread_join(threads[i], NULL);
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] matrices->a[i];
        delete[] matrices->b[i];
        delete[] matrices->c[i];
    }

    delete[] matrices->a;
    delete[] matrices->b;
    delete[] matrices->c;

    delete matrices;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}
int64_t data_2000_int_matrix_multiplication_pthreads_12()
{
    srand(time(NULL));
    const int matrix_size = 2000;
    const int thread_number = 12;

    matrices = (matrices_container*)malloc(sizeof(matrices_container));

    matrices->a = new int*[matrix_size];
    matrices->b = new int*[matrix_size];
    matrices->c = new int*[matrix_size];
    
    for(int i = 0; i < matrix_size; i++)
    {
        matrices->a[i] = new int[matrix_size];
        matrices->b[i] = new int[matrix_size];
        matrices->c[i] = new int[matrix_size];

        for(int j = 0; j < matrix_size; j++)
        {
            matrices->a[i][j] = (rand() % RAND_MAX) + 1;
            matrices->b[i][j] = (rand() % RAND_MAX) + 1;
            matrices->c[i][j] = 0;
        }
    }

    pthread_t threads[thread_number];

    int * iterator = new int[thread_number];

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < thread_number; i++)
    {
        iterator[i] = i;
        pthread_create(&threads[i], NULL, multiply_int_parallel_pthreads_12_2000, (void*)&iterator[i]);
    }

    for(int i = 0; i < thread_number; i++)
    {
        pthread_join(threads[i], NULL);
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] matrices->a[i];
        delete[] matrices->b[i];
        delete[] matrices->c[i];
    }

    delete[] matrices->a;
    delete[] matrices->b;
    delete[] matrices->c;

    delete matrices;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}

int64_t data_200_int_matrix_multiplication_openmp_2()
{
    srand(time(NULL));
    const int matrix_size = 200;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    
    #pragma omp parallel for num_threads(2) collapse(3)
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_500_int_matrix_multiplication_openmp_2()
{
    srand(time(NULL));
    const int matrix_size = 500;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    
    #pragma omp parallel for num_threads(2) collapse(3)
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_800_int_matrix_multiplication_openmp_2()
{
    srand(time(NULL));
    const int matrix_size = 800;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    
    #pragma omp parallel for num_threads(2) collapse(3)
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_1000_int_matrix_multiplication_openmp_2()
{
    srand(time(NULL));
    const int matrix_size = 1000;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    
    #pragma omp parallel for num_threads(2) collapse(3)
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_2000_int_matrix_multiplication_openmp_2()
{
    srand(time(NULL));
    const int matrix_size = 2000;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    
    #pragma omp parallel for num_threads(2) collapse(3)
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}

int64_t data_200_int_matrix_multiplication_openmp_4()
{
    srand(time(NULL));
    const int matrix_size = 200;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    
    #pragma omp parallel for num_threads(4) collapse(3)
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_500_int_matrix_multiplication_openmp_4()
{
    srand(time(NULL));
    const int matrix_size = 500;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    
    #pragma omp parallel for num_threads(4) collapse(3)
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_800_int_matrix_multiplication_openmp_4()
{
    srand(time(NULL));
    const int matrix_size = 800;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    
    #pragma omp parallel for num_threads(4) collapse(3)
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_1000_int_matrix_multiplication_openmp_4()
{
    srand(time(NULL));
    const int matrix_size = 1000;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    
    #pragma omp parallel for num_threads(4) collapse(3)
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_2000_int_matrix_multiplication_openmp_4()
{
    srand(time(NULL));
    const int matrix_size = 2000;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    
    #pragma omp parallel for num_threads(4) collapse(3)
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}

int64_t data_200_int_matrix_multiplication_openmp_12()
{
    srand(time(NULL));
    const int matrix_size = 200;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    
    #pragma omp parallel for num_threads(12) collapse(3)
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_500_int_matrix_multiplication_openmp_12()
{
    srand(time(NULL));
    const int matrix_size = 500;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    
    #pragma omp parallel for num_threads(12) collapse(3)
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_800_int_matrix_multiplication_openmp_12()
{
    srand(time(NULL));
    const int matrix_size = 800;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    
    #pragma omp parallel for num_threads(12) collapse(3)
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_1000_int_matrix_multiplication_openmp_12()
{
    srand(time(NULL));
    const int matrix_size = 1000;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    
    #pragma omp parallel for num_threads(12) collapse(3)
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}
int64_t data_2000_int_matrix_multiplication_openmp_12()
{
    srand(time(NULL));
    const int matrix_size = 2000;
    
    int **a = new int*[matrix_size];
    int **b = new int*[matrix_size];

    int **c = new int*[matrix_size];

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = new int[matrix_size];
        b[i] = new int[matrix_size];
        c[i] = new int[matrix_size];
        for(int j = 0; j < matrix_size; j++)
        {
            a[i][j] = (rand() % RAND_MAX) + 1;
            b[i][j] = (rand() % RAND_MAX) + 1;
            c[i][j] = 0;          
        }
    }

    auto before = std::chrono::high_resolution_clock::now();
    
    #pragma omp parallel for num_threads(12) collapse(3)
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            for(int k = 0; k < matrix_size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }  
        }
    }
    auto after = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < matrix_size; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count();
}


void run_tests()
{   
    std::cout << "Starting Tests...\n";
    std::this_thread::sleep_for(1000ms);
    
    std::ofstream ofs;
    ofs.open("./../matrix_multiplication_results.txt");

    ofs <<"Matrix Size;Serial Int;Serial Double;Pthread 2 Threads Int;Pthread 4 Threads Int;Pthread 12 Threads Int;OpenMP 2 Threads Int;OpenMP 4 Threads Int;OpenMP 12 Threads Int;\n";

    std::cout << "Running tests for   200x200 Matrix..." << std::flush;
    ofs << "200x200;"   << data_200_int_matrix_multiplication_serial()          << "ms;"
                        << data_200_double_matrix_multiplication_serial()       << "ms;"
                        << data_200_int_matrix_multiplication_pthreads_2()      << "ms;"
                        << data_200_int_matrix_multiplication_pthreads_4()      << "ms;"
                        << data_200_int_matrix_multiplication_pthreads_12()     << "ms;"
                        << data_200_int_matrix_multiplication_openmp_2()        << "ms;"
                        << data_200_int_matrix_multiplication_openmp_4()        << "ms;"
                        << data_200_int_matrix_multiplication_openmp_12()       << "ms;\n";
    std::cout << "Done\n";

    std::cout << "Running tests for   500x500 Matrix..." << std::flush;
    ofs << "500x500;"   << data_500_int_matrix_multiplication_serial()          << "ms;"
                        << data_500_double_matrix_multiplication_serial()       << "ms;"
                        << data_500_int_matrix_multiplication_pthreads_2()      << "ms;"
                        << data_500_int_matrix_multiplication_pthreads_4()      << "ms;"
                        << data_500_int_matrix_multiplication_pthreads_12()     << "ms;"
                        << data_500_int_matrix_multiplication_openmp_2()        << "ms;"
                        << data_500_int_matrix_multiplication_openmp_4()        << "ms;"
                        << data_500_int_matrix_multiplication_openmp_12()       << "ms;\n";
    std::cout << "Done\n";

    std::cout << "Running tests for   800x800 Matrix..." << std::flush;
    ofs << "800x800;"   << data_800_int_matrix_multiplication_serial()          << "ms;"
                        << data_800_double_matrix_multiplication_serial()       << "ms;"
                        << data_800_int_matrix_multiplication_pthreads_2()      << "ms;"
                        << data_800_int_matrix_multiplication_pthreads_4()      << "ms;"
                        << data_800_int_matrix_multiplication_pthreads_12()     << "ms;"
                        << data_800_int_matrix_multiplication_openmp_2()        << "ms;"
                        << data_800_int_matrix_multiplication_openmp_4()        << "ms;"
                        << data_800_int_matrix_multiplication_openmp_12()       << "ms;\n";
    std::cout << "Done\n";

    std::cout << "Running tests for 1000x1000 Matrix..." << std::flush;
    ofs << "1000x1000;" << data_1000_int_matrix_multiplication_serial()         << "ms;"
                        << data_1000_double_matrix_multiplication_serial()      << "ms;"
                        << data_1000_int_matrix_multiplication_pthreads_2()     << "ms;"
                        << data_1000_int_matrix_multiplication_pthreads_4()     << "ms;"
                        << data_1000_int_matrix_multiplication_pthreads_12()    << "ms;"
                        << data_1000_int_matrix_multiplication_openmp_2()       << "ms;"
                        << data_1000_int_matrix_multiplication_openmp_4()       << "ms;"
                        << data_1000_int_matrix_multiplication_openmp_12()      << "ms;\n";
    std::cout << "Done\n";

    
    std::cout << "Running tests for 2000x2000 Matrix..." << std::flush;
    ofs << "2000x2000;" << data_2000_int_matrix_multiplication_serial()         << "ms;"
                        << data_2000_double_matrix_multiplication_serial()      << "ms;"
                        << data_2000_int_matrix_multiplication_pthreads_2()     << "ms;"
                        << data_2000_int_matrix_multiplication_pthreads_4()     << "ms;"
                        << data_2000_int_matrix_multiplication_pthreads_12()    << "ms;"
                        << data_2000_int_matrix_multiplication_openmp_2()       << "ms;"
                        << data_2000_int_matrix_multiplication_openmp_4()       << "ms;"
                        << data_2000_int_matrix_multiplication_openmp_12()      << "ms\n"; 
                        
    std::cout << "Done\n";
    
    ofs.close(); 
    
}

int main()
{
    run_tests();
    return 0;
}