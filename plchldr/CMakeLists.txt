cmake_minimum_required(VERSION 3.8)
cmake_policy(SET CMP0069 NEW)

project(plchldr_all)
enable_language(CUDA)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/cool-cmake-config ${CMAKE_MODULE_PATH})

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

# Libraries
add_subdirectory(common)

add_subdirectory(plchldr)
add_dependencies(plchldr common)

# Executables
add_subdirectory(plchldr_cli)
add_dependencies(plchldr_cli plchldr common)

add_subdirectory(plchldr_gui)
add_dependencies(plchldr_gui plchldr common)

add_subdirectory(pyplchldr)
add_dependencies(plchldr plchldr common)

# Tests
set(${PROJECT_NAME}_BUILD_TESTS ON CACHE BOOL "Build unit tests")
if(${${PROJECT_NAME}_BUILD_TESTS})
    add_subdirectory(plchldr_tests)
    add_dependencies(plchldr_tests plchldr common)
endif()

set(${PROJECT_NAME}_BUILD_BENCHMARKS ON CACHE BOOL "Build benchmarks")
if(${${PROJECT_NAME}_BUILD_BENCHMARKS})
    add_subdirectory(plchldr_bench)
    add_dependencies(plchldr_bench plchldr common)
endif()
