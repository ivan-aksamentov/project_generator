cmake_minimum_required(VERSION 3.8)
cmake_policy(SET CMP0069 NEW)

project(plchldr_tests)

find_package(GoogleTest REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

add_executable(${PROJECT_NAME}
    test_plchldr.cpp
)

target_compile_definitions(${PROJECT_NAME}
    PUBLIC -DAPP_NAME="${PROJECT_NAME}"
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE plchldr
    PRIVATE GoogleTest
)

add_test(${PROJECT_NAME} ${PROJECT_NAME})
