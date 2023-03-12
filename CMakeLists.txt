cmake_minimum_required(VERSION 3.7)

project(a.out)

add_executable(a.out src/main.cpp)

target_include_directories(a.out PRIVATE include/)