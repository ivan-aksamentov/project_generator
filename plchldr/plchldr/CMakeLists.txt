cmake_minimum_required(VERSION 3.8)
cmake_policy(SET CMP0069 NEW)

project(plchldr)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

find_package(Boost REQUIRED)

if(${plchldr_USE_INTEL_TBB})
    find_package(TBB REQUIRED)
endif()

add_library(${PROJECT_NAME} STATIC
            include/plchldr/plchldr.h
            src/plchldr.cpp
            src/plchldr.cu)

target_compile_definitions(${PROJECT_NAME}
    PUBLIC -D${PROJECT_NAME}=1
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC Boost::boost
    PUBLIC Boost::disable_autolinking
    PUBLIC common
)

set_target_properties(${PROJECT_NAME} PROPERTIES
                      CUDA_SEPARABLE_COMPILATION ON
                      POSITION_INDEPENDENT_CODE ON)
