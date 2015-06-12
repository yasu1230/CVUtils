cmake_minimum_required(VERSION 2.8.4)
project(CVUtils)

# Required packages
find_package( OpenCV 2.4 REQUIRED )

# Build settings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")

# Add example directory
#add_subdirectory(examples)

# Add test directory
add_subdirectory(tests)
