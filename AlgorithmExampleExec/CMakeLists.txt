cmake_minimum_required(VERSION 3.28)

# Project name
project(AlgorithmExampleExec LANGUAGES CXX)

# Force CMake to attempt scanning even if the compiler is being quiet about it
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define a executable
add_executable(AlgorithmExampleExec src/main.cpp)

# Link libraries
target_link_libraries(AlgorithmExampleExec AlgorithmExample)
