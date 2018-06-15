#include <benchmark/benchmark.h>

#include <plchldr/plchldr.h>

static void bench_add(benchmark::State& state) {
  const auto n = state.range(0);

  for (auto _ : state) {
    add(1, n);
  }

  state.SetComplexityN(state.range(0));
}

BENCHMARK(bench_add)
    ->RangeMultiplier(2)
    ->Range(0, 1000000)
    ->Complexity(benchmark::oN)
    ->Unit(benchmark::kNanosecond);

BENCHMARK_MAIN();
