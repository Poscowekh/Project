cmake_minimum_required (VERSION 2.6)
project(Model)

include_directories(headers)

add_executable(Matrix
	Main.cpp
	Matrix.cpp)
