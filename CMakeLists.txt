cmake_minimum_required(VERSION 3.20)
project(Logger)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_subdirectory(logger)

add_executable(logger_exec main.cpp)
target_link_libraries(logger_exec logger_lib)