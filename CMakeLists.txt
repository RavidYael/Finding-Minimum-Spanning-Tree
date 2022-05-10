cmake_minimum_required(VERSION 3.21)
project(Finding_Minimum_Spanning_Tree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Finding_Minimum_Spanning_Tree
        DisjointSet.cpp
        DisjointSet.h)
