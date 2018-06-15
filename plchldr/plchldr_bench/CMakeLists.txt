cmake_minimum_required(VERSION 3.8)
cmake_policy(SET CMP0069 NEW)

project(plchldr_bench)

find_package(Threads REQUIRED)
find_package(benchmark REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

add_executable(${PROJECT_NAME}
               bench_plchldr.cpp
)

target_compile_definitions(${PROJECT_NAME}
    PUBLIC -D${PROJECT_NAME}=1
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE plchldr
    PRIVATE benchmark::benchmark
)

add_test(${PROJECT_NAME} ${PROJECT_NAME})
