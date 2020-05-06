cmake_minimum_required (VERSION 2.6)
project(Snake)

include_directories(../data data)
##########################################################
#########################OXYGINE##########################
add_subdirectory(../../oxygine-framework oxygine-framework)

add_definitions(${OXYGINE_DEFINITIONS})
include_directories(${OXYGINE_INCLUDE_DIRS})

link_directories(${OXYGINE_LIBRARY_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OXYGINE_CXX_FLAGS}")
###########################E#N#D############################


add_executable(EmptyOxygine 
    ../src/example.cpp 
    ../src/main.cpp
    ../src/ViewHelper.cpp

    ../src/Model/Matrix.cpp
    ../src/Model/Snake.cpp
    ../src/Model/Block.cpp
    ../src/Model/Food.cpp
    ../src/Model/Graph.cpp
    ../src/Model/Node.cpp
    ../src/Model/Tests.cpp
)

target_link_libraries(EmptyOxygine ${OXYGINE_CORE_LIBS})



