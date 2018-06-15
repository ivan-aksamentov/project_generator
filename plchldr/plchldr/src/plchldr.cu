#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

float cuda_sum(const std::vector<float>& data) {
  thrust::device_vector<float> d_data = data;
  return thrust::reduce(d_data.cbegin(), d_data.cend(), 0);
}
