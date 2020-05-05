cmake_minimum_required (VERSION 2.6)

project(Model)

include_directories(headers)

add_executable(Main
	Main.cpp
	Snake.cpp
	Matrix.cpp
	Block.cpp
	Food.cpp
)
