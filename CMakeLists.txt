cmake_minimum_required(VERSION 4.0)
project(untitled3)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled3 main.cpp
        graph.h
        graph_grid.cpp
        graph_grid.h
        priority_queue.cpp
        priority_queue.h
        dispatch.cpp
        dispatch.h
)
