cmake_minimum_required(VERSION 3.10.0)
project(CNN VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCES_DIR src)
set(INCLUDE_DIRECTORIES include)
set(CMAKE_VERBOSE_MAKEFILE ON)
include_directories(${INCLUDE_DIRECTORIES})
add_executable(${PROJECT_NAME} ${SOURCES_DIR}/cnn.cpp ${SOURCES_DIR}/main.cpp)

