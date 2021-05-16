cmake_minimum_required(VERSION 3.15)
project(hello_word)

set(CMAKE_CXX_STANDARD 20)

add_executable(main src/main.cpp, src/funcion.h, src/funcion.cpp)