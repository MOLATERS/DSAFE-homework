cmake_minimum_required(VERSION 3.23)
project(lab2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(lab2
        huffman.c
        huffmantree.h)
