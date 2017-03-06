cmake_minimum_required(VERSION PLACEHOLDER_CMAKE_VERSION)

project(libPLACEHOLDER)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

find_package(Boost REQUIRED)

if(${PLACEHOLDER_USE_INTEL_TBB})
    find_package(TBB REQUIRED)
endif()

set(definitions
    ${GLOBAL_DEFINITIONS}
    ${Boost_DEFINITIONS}
    ${TBB_DEFINITIONS}
)

set(public_headers
    include/libPLACEHOLDER/libPLACEHOLDER.h
)

set(headers
    ${public_headers}

)

set(sources
    src/libPLACEHOLDER.cpp
)

set(public_include_dirs
    ${Boost_INCLUDE_DIR}
    ${TBB_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(include_dirs
    ${public_include_dirs}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set(libraries
    ${Boost_LIBRARIES}
    ${TBB_LIBRARIES}
)

include_directories(${include_dirs})
add_library(${PROJECT_NAME} STATIC ${headers} ${sources})
target_link_libraries(${PROJECT_NAME} ${libraries})
target_compile_definitions(${PROJECT_NAME} PRIVATE ${definitions})

set(${PROJECT_NAME}_DEFINITIONS
    ${definitions}
    CACHE INTERNAL "${PROJECT_NAME}: Definitions" FORCE)

set(${PROJECT_NAME}_INCLUDE_DIRS
    ${public_include_dirs}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)

set(${PROJECT_NAME}_LIBRARIES
    ${libraries}
    CACHE INTERNAL "${PROJECT_NAME}: Libraries" FORCE)

source_group("Source Files" FILES ${headers})
source_group("Source Files" FILES ${sources})
source_group("Include Files" FILES ${public_headers})
