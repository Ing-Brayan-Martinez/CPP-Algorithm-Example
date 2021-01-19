cmake_minimum_required(VERSION 3.15)
project(list)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(list
               src/main.cpp)