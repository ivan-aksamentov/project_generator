cmake_minimum_required(VERSION 3.8)
cmake_policy(SET CMP0069 NEW)

project(plchldr_gui)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

if(APPLE AND WITH_MACOSX_BUNDLE)
    set(EXECUTABLE_SETTINGS MACOSX_BUNDLE ../pyplchldr/pyplchldr.cpp)
endif()

add_executable(${PROJECT_NAME} ${EXECUTABLE_SETTINGS}
    src/main.cpp
    src/main_window.cpp
    src/main_window.h
    src/main_window.ui
    ../assets/QDarkStyleSheet/qdarkstyle/style.qrc
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt5::Widgets
    PRIVATE plchldr
)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE -DAPP_NAME="${PROJECT_NAME}"
)

source_group("Source Files" FILES ${headers})
source_group("Source Files" FILES ${sources})
