# Yet another CMake bolerplate

Utilty to scaffold CMake projects

## Features included:

 - Modern CMake with `IMPORTED` targets
 - C++17
 - CUDA with elements of C++14
 - Boost
 - Intel TBB
 - Qt 5
 - unit tests with Google Test/Mock
 - benchmarks with Google Benchmark
 - python bindings with pybind11
 - Hacky adavanced compiler flags and optimizations (can be easily disabled)

## Getting started

Run

```
 python3 generate.py --name <project_name>
```

It will generate a directory named `<project_name>/`, 
initialize an empty git repository and setup required submodules (see `plchldr/.gitmodules`).

Newly generated project will contain the following components:

Directory | Content |
----|-------------
`<project_name>/`       | Core static library (meant to contain the most of the logic)
`<project_name>_bench/` | benchmarks (with [google/benchmark](https://github.com/google/benchmark))
`<project_name>_cli/`   | command-line application that uses the `<project_name>` library above
`<project_name>_gui/`   | GUI application (with Qt) that uses the `<project_name>` library above
`<project_name>_tests/` | unit tests (with [google/googletest](https://github.com/google/googletest))
`py<project_name>/`     | python bindings for the `<project_name>` library above (with [pybind11](https://github.com/pybind/pybind11/releases))

Every module contains some basic C++ "Hello world" code, tests and benchmars,
in order to check how it all builds and runs right away.
This code is not meant to be used in the new project itself and is meant to be replaced with your own stuff.

## Hacking

Check root `CMakeLists.txt` and play with the following options:

```
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS 0)
set(CMAKE_C_EXTENSIONS 0)

include(CoolCFlags)
include(CoolCXXFlags)
include(CoolCUDAFlags)
include(CoolSanitizers)
include(CoolNativeArch)
include(CoolVectorize)
include(CoolAssocMath)
include(CoolFastMath)
include(CoolLTO)
```

You are also invited to take a look at `cmake/cool-cmake-config` directory
that contains [cool-cmake-config](https://github.com/ivan-aksamentov/cool-cmake-config.git) as a git submodule.

