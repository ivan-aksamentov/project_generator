#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include <plchldr/plchldr.h>

namespace py = pybind11;

float py_cuda_sum(const py::array_t<float>& a) {
  const auto sum = cuda_sum(std::vector<float>(a.data(), a.data() + a.size()));
  return sum;
}

PYBIND11_MODULE(pyplchldr, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
    )pbdoc";

    m.def("add", &add, R"pbdoc(
        Add two numbers
    )pbdoc");

    m.def("day_of_week_today", &day_of_week_today, R"pbdoc(
        Get today's day of week
    )pbdoc");


    m.def("cuda_sum", &py_cuda_sum, R"pbdoc(
        Sum an array
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
