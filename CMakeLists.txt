cmake_minimum_required(VERSION 3.27)
project(zadanie1)

set(CMAKE_CXX_STANDARD 23)

set(MAIN_FILE src/main.cpp

        lib/Matrix4x4.h
        src/Matrix4x4.cpp)

file(GLOB SOURCES "src/*.cpp")

include_directories(lib)

add_executable(Zad1 ${MAIN_FILE} ${SOURCES})