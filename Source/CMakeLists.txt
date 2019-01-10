cmake_minimum_required(VERSION 3.1.0)


# seems not to work
#if(POLICY CMP0020)
#  cmake_policy(PUSH)
#  cmake_policy(SET CMP0020 NEW)
#  cmake_policy(POP)
#endif()

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


file(GLOB_RECURSE coretrack_SRCS
    "*.h"
    "*.cpp"
    "*.ui"
)


# Tell CMake to create the helloworld executable
add_executable(CoreTrack WIN32 ${coretrack_SRCS})


# Use the Widgets module from Qt 5
target_link_libraries(CoreTrack 
    ${OpenCV_LIBS} 
    Qt5::Widgets
    Qt5::WinMain
)
