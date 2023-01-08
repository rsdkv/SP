cmake_minimum_required(VERSION 3.19)
project(SP C)

set(CMAKE_C_STANDARD 99)

add_executable(SP program/encrypt.c program/decrypt.c)
