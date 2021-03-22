#include <framework/base/multiply_parallel.hpp>

#include <framework/benchmark/benchmark.hpp>
#include <framework/generators/generator.hpp>


int main()
{

  auto matrices_a = framework::generator::generate_inputs<int>({200, 500});
  auto matrices_b = framework::generator::generate_inputs<int>({200, 500});

  framework::settings input_settings_one   = framework::settings(2_THREADS, SCHEDULING_STRATEGY::SCHEDULING_TS, 19_PRIORITY, AFFINITY::FALSE, PARALLELIZATION_STRATEGY::PTHREADS);
  framework::settings input_settings_two   = framework::settings(4_THREADS, SCHEDULING_STRATEGY::SCHEDULING_TS, 21_PRIORITY, AFFINITY::TRUE, std::vector<int>{0, 2, 4, 6}, PARALLELIZATION_STRATEGY::PTHREADS);
  framework::settings input_settings_three = framework::settings(12_THREADS, PARALLELIZATION_STRATEGY::PTHREADS);

  framework::benchmark<int> benchmark_multiply_parallel(new framework::base::multiply_parallel<int>(), matrices_a, matrices_b, std::vector<framework::settings>{input_settings_one, input_settings_two, input_settings_three});

  benchmark_multiply_parallel.execute_all<TIME_FORMAT::MILLI>();
  

   
  return 0;
}

