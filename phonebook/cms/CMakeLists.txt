cmake_minimum_required(VERSION 3.23)
project(cms)

set(CMAKE_CXX_STANDARD 14)

add_executable(cms main.cpp contact_properties.cpp contact_properties.h directory.cpp directory.h)
