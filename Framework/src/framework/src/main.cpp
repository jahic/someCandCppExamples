#include <framework/base/multiply_parallel.hpp>
#include <framework/base/sum_parallel.hpp>
#include <framework/base/complex_parallel.hpp>
#include <framework/base/grayscale_parallel.hpp>


#include <framework/benchmark/benchmark.hpp>
#include <framework/generators/generator.hpp>


#include <framework/base/inverse_parallel.hpp>


int main()
{
  auto matrices_a = framework::generator::generate_inputs<int32_t>({7});
  auto matrices_b = framework::generator::generate_inputs_zero<int32_t>({7});

  framework::settings input_settings_one   = framework::settings(2_THREADS, SCHEDULING_STRATEGY::SCHEDULING_TS, 19_PRIORITY, AFFINITY::FALSE, PARALLELIZATION_STRATEGY::PTHREADS);
  framework::settings input_settings_two   = framework::settings(4_THREADS, SCHEDULING_STRATEGY::SCHEDULING_TS, 21_PRIORITY, AFFINITY::TRUE, std::vector<int>{0, 2, 4, 6}, PARALLELIZATION_STRATEGY::PTHREADS);
  framework::settings input_settings_three = framework::settings(6_THREADS, SCHEDULING_STRATEGY::SCHEDULING_TS, 45_PRIORITY, AFFINITY::TRUE, std::vector<int>{0, 2, 4, 6}, PARALLELIZATION_STRATEGY::PTHREADS);
  framework::settings input_settings_four  = framework::settings(4_THREADS, PARALLELIZATION_STRATEGY::OPENMP);
  framework::settings input_settings_five  = framework::settings(PARALLELIZATION_STRATEGY::SERIAL);
 
  framework::benchmark<int32_t> benchmark_adjoint_parallel(new framework::base::inverse_parallel<int32_t>(), matrices_a, matrices_b, std::vector<framework::settings>{input_settings_one, input_settings_two, input_settings_three, input_settings_four, input_settings_five});

  benchmark_adjoint_parallel.execute_all<TIME_FORMAT::MILLI>();


  return 0;
}

