cmake_minimum_required(VERSION 3.10.0)
project(miFraud0 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")



include_directories(include)
add_executable(miFraud0 src/Location.cpp src/VectorLocation.cpp src/ArrayLocation.cpp src/main.cpp)

