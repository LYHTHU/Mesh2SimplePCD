cmake_minimum_required(VERSION 3.14)
project(Mesh2SimplePCD)

set(CMAKE_CXX_STANDARD 14)

add_executable(Mesh2SimplePCD main.cpp MeshSimplify.cpp MeshSimplify.h Mesh2PCD.cpp Mesh2PCD.h)