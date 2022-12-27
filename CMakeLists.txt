cmake_minimum_required(VERSION 3.15)

# Project name
project(CPP_Algorithm_Example VERSION 0.0.1)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Define library Google Test
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/release-1.8.1.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Define library
add_subdirectory(AlgorithmExample)

# Define unit tests executable
add_subdirectory(AlgorithmExampleTest)
