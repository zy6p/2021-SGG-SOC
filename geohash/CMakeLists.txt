cmake_minimum_required(VERSION 3.19)
project(geohash)

set(CMAKE_CXX_STANDARD 20)

add_executable(geohash main.cpp geohash.cpp geohash.h)