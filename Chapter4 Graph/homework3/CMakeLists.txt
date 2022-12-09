cmake_minimum_required(VERSION 3.23)
project(homework3 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(homework3
        BuildAndSearch.c
        graph.h
        yuan.c)
