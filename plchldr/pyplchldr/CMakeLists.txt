cmake_minimum_required(VERSION 3.8)
cmake_policy(SET CMP0069 NEW)

project(pyplchldr)

find_package(pybind11 REQUIRED)
pybind11_add_module(pyplchldr src/pyplchldr.cpp)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

target_link_libraries(${PROJECT_NAME}
    PUBLIC common
    PUBLIC plchldr
)
