cmake_minimum_required (VERSION 3.0)

# Name our project
project (RobotController)

# Create a variable that holds the path to our libwiringPi.so file
set (WPI_PATH /home/stoffer/Development/RaspberryPi/tools/wiringPi/wiringPi)

# Add the local ‘include’ directory and the wiringPi directory to grab headers
include_directories (include ${WPI_PATH})

# Actually find the wiringPi library object
find_library(WPI_LIB wiringPi HINTS ${WPI_PATH} NO_CMAKE_FIND_ROOT_PATH)
# Alert the user if we do not find it
if(NOT WPI_LIB)
 message(FATAL_ERROR “wiringPi library not found”)
endif()

# Have CMake find our pthreads library within our toolchain (required for this library)
#set(THREADS_PREFER_PTHREAD_FLAG ON)
#find_package(Threads REQUIRED)

# Add all the *.c files in our source directory to our executable output
FILE(GLOB SRC_FILES src/*.cpp src/exceptions/*.cpp src/sensors/*.cpp src/actuators/*.cpp)
add_executable(RobotController ${SRC_FILES})

# Link the pre-compiled wiringPi library to the executable we just declared 
target_link_libraries(RobotController ${WPI_LIB} pthread)

 
