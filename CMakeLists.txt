cmake_minimum_required(VERSION 3.22)
project(raf)

set(CMAKE_CXX_STANDARD 14)

add_executable(raf main.cpp myHash.cpp myHash.h IGraph.cpp IGraph.h MatrixGraph.cpp MatrixGraph.h ListGraph.cpp ListGraph.h Graph.h)
