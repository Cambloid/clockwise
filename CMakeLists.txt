cmake_minimum_required(VERSION 3.1.0)

set (CMAKE_CXX_STANDARD 11)

project(CoreTrack)


# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)


# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(OpenCV REQUIRED)


add_subdirectory(External/ZittelmenEngine)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/Source")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/External/ZittelmenEngine/Source")

file(GLOB_RECURSE coretrack_SRCS
    "Source/*.h"
    "Source/*.cpp"
    "Source/*.hpp"
    "Source/*.ui"
)

# Tell CMake to create the helloworld executable
add_executable(CoreTrack WIN32 ${coretrack_SRCS})

# Use the Widgets module from Qt 5
target_link_libraries(CoreTrack 
    ${OpenCV_LIBS} 
    Qt5::Widgets
    Qt5::WinMain
    ZittelmenEngine
)

