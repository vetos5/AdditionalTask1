cmake_minimum_required(VERSION 3.28)
project(Custom_Container)

set(CMAKE_CXX_STANDARD 17)

add_executable(Custom_Container main.cpp
        Figure.h
        Parallelepiped.h
        List.h
        Sphere.h)
