cmake_minimum_required(VERSION 3.17)
project(Snake)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Snake main.cpp Wall.cpp Wall.h Snake.cpp Snake.h Food.cpp Food.h)