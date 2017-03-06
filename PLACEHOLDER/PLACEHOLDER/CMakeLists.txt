cmake_minimum_required(VERSION PLACEHOLDER_CMAKE_VERSION)

project(PLACEHOLDER)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(definitions
    ${GLOBAL_DEFINITIONS}
    ${Qt_DEFINITIONS}
    ${libPLACEHOLDER_DEFINITIONS}
)

set(uis

)

if(DEFINED uis)
    qt5_wrap_ui(ui_headers ${uis})
endif()

set(headers
    ${ui_headers}
)

set(sources
    src/main.cpp
)

set(include_dirs
    ${AUTOGEN_TARGETS_FOLDER}
    ${AUTOMOC_TARGETS_FOLDER}
    ${AUTOUIC_TARGETS_FOLDER}
    ${Qt_INCLUDE_DIRS}
    ${libPLACEHOLDER_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set(libraries
    Qt5::Widgets
    ${libPLACEHOLDER_LIBRARIES}
)

set(resources

)

set(styles

)

add_definitions(${definitions})
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

source_group("Source Files" FILES ${headers})
source_group("Source Files" FILES ${sources})
