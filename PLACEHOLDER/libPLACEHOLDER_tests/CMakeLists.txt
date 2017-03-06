cmake_minimum_required(VERSION PLACEHOLDER_CMAKE_VERSION)

project(libPLACEHOLDER_tests)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

find_package(Threads REQUIRED)
find_package(GoogleTest REQUIRED)

enable_testing()

set(definitions
    ${GLOBAL_DEFINITIONS}
    ${libPLACEHOLDER_DEFINITIONS}
    ${GoogleTest_DEFINITIONS}
)

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cpp)

set(include_dirs
    ${GoogleTest_INCLUDE_DIRS}
    ${libPLACEHOLDER_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(libraries
    ${GoogleTest_LIBRARIES}
    ${libPLACEHOLDER_LIBRARIES}
)


include_directories(${include_dirs})

set (everything
    ${headers} ${sources} ${uis} ${resources} ${styles}
)

if(APPLE AND NOT DISABLE_BUNDLE)
    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${everything})
else()
    add_executable(${PROJECT_NAME} ${everything})
endif()

target_link_libraries(${PROJECT_NAME} ${libraries})
target_compile_definitions(${PROJECT_NAME} PRIVATE ${definitions})

add_test(${PROJECT_NAME} ${PROJECT_NAME})
