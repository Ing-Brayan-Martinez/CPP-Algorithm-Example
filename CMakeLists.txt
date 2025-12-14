cmake_minimum_required(VERSION 3.20)

# Project name
project(CPP_Algorithm_Example VERSION 0.0.1)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing from execution in the CLI
enable_testing()

# Define library Google Test (latest stable version)
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.16.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Define library
add_subdirectory(AlgorithmExample)

# Define unit tests executable
add_subdirectory(AlgorithmExampleTest)
