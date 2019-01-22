cmake_minimum_required(VERSION 3.13)
project(Game_of_Life)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

add_executable(Game_of_Life main.cpp Game.hpp Cell.cpp Cell.h Grid.hpp)