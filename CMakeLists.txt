cmake_minimum_required(VERSION 3.10)
project(Mesh2SimplePCD)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE "Release")

find_package(CGAL)

add_executable(Mesh2SimplePCD main.cpp MeshSimplify.cpp MeshSimplify.h Mesh2PCD.cpp Mesh2PCD.h)

target_link_libraries(Mesh2SimplePCD CGAL::CGAL)