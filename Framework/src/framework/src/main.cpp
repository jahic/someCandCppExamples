#include<iostream>
#include<rclcpp/rclcpp.hpp>
#include<pthread.h>
#include<vector>
#include<array>
#include<iomanip>
#include<chrono>
#include<thread>
#include<math.h>


#include<framework/multiply_parallel.hpp>

/*
#define NUM_THREADS 4

struct iterators
{
  std::vector<double>::iterator my_begin;
  std::vector<double>::iterator my_end;

};


void* summer(void * iterators_)
{

  double sum = 0;

  iterators* i = (iterators*)iterators_;

  for(auto it = i->my_begin; it < i->my_end; it++)
  {
    sum += *it * 5 * pow(2, 4) * sin(3) * cos(*it * 4 * sqrt(3));
  }
  
  

  double* ye = new double;
  *ye = sum;


  return (void*)ye;

}


double summer(std::vector<double> my_big_sum)
{
  double sum = 0.0;

  for(int i = 0; i < my_big_sum.size(); i++)
  {
    sum += my_big_sum[i] * 5 * pow(2, 4) * sin(3) * cos(my_big_sum[i] * 4 * sqrt(3));
  }
}





template<typename T>
std::vector<T>* my_vector;
*/




 





int main()
{
  
  std::vector<double> matrix_a;
  std::vector<double> matrix_b;
  //std::vector<double> matrix_b{1,2,3,4,5,6,7,8,9};
  std::vector<double> matrix_result;


  for(int i = 0; i < 800 * 800; i++)
  {
    matrix_a.push_back(i);
    matrix_b.push_back(i);
  }


  settings settings_ = settings(2_THREADS, SCHEDULING_STRATEGY::SCHEDULING_TS, 19_PRIORITY, AFFINITY::FALSE, PARALLELIZATION_STRATEGY::PTHREADS);
  settings settings2_ = settings(4_THREADS, SCHEDULING_STRATEGY::SCHEDULING_TS, 19_PRIORITY, AFFINITY::FALSE, PARALLELIZATION_STRATEGY::PTHREADS);
/*
  multiply_parallel<int> a(matrix_a, matrix_b, matrix_result, settings_);
*/

  std::vector<settings> settingss_{settings_, settings2_};

  std::vector<std::vector<double> > inputs_a{generator<double>::generate(200), generator<double>::generate(500), generator<double>::generate(800)};
  std::vector<std::vector<double> > inputs_b{generator<double>::generate(200), generator<double>::generate(500), generator<double>::generate(800)};

  //benchmark<double> benchmark_ = benchmark<double>(new multiply_parallel<double>(), generator<double>::generate(800), generator<double>::generate(800), settings_);


  benchmark<double> benchmark_ = benchmark<double>(new multiply_parallel<double>(), inputs_a, inputs_b, settingss_); 


  benchmark_.execute_all<TIME_FORMAT::NANO>();

  //std::cout << benchmark_.execute().count() << std::endl;
  

  /*
  for(int i = 0; i < 9; i++)
  {
    std::cout << matrix_result[i] << std::endl;
  }
*/
  
  //function(2threads);
 
  /*

  

  std::vector<double> my_big_sum;

  my_big_sum.reserve(1000000);

  for(int i = 0; i < my_big_sum.capacity(); i++)
  {
    my_big_sum.push_back(i+1);
  }


  
  while(true)
  {
    std::this_thread::sleep_for(std::chrono::operator""ms(500));
    
    std::chrono::high_resolution_clock::time_point before = std::chrono::high_resolution_clock::now();

    
    pthread_t threads[NUM_THREADS];
    iterators** my_iterator = new iterators*[NUM_THREADS];
    void** my_results = new void*[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++)
    {
      my_iterator[i] = new iterators();
      my_iterator[i]->my_begin = (i * (my_big_sum.size() / NUM_THREADS)) + my_big_sum.begin();

      if(i == NUM_THREADS - 1)
        my_iterator[i]->my_end = my_big_sum.end();
      else
        my_iterator[i]->my_end = ((i + 1) * (my_big_sum.size() / NUM_THREADS)) + my_big_sum.begin();

      pthread_create(&threads[i], NULL, summer, (void*)my_iterator[i]);
    }

    for(int i = 0; i < NUM_THREADS; i++)
    {
      pthread_join(threads[i], &my_results[i]);
    }
    
    

   //summer(my_big_sum);
    std::chrono::high_resolution_clock::time_point after = std::chrono::high_resolution_clock::now();
    double sum = 0;
    for(int i = 0; i < NUM_THREADS; i++)
    {
      sum += *(double*)(*(my_results + i));
    }

    



    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(after-before).count() << std::endl;

    */

  
   
  return 0;
}

