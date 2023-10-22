cmake_minimum_required(VERSION 3.24)
project(guid VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include("CMakeDependentOption")

add_subdirectory(guid)
add_subdirectory(main)