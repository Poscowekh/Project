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

file(MAKE_DIRECTORY data)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../data/res.xml DESTINATION data)
configure_file(../data/res.xml res.xml COPYONLY)

add_executable(Game_Unix
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
    ../src/Presenter/Game_presenter.cpp
    ../src/View/Game_view.cpp
    ../src/Menu/Menu.cpp
    #../src/Events/Events.cpp
)


target_link_libraries(Game_Unix ${OXYGINE_CORE_LIBS})

add_executable(Game_Win.exe
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
    ../src/Presenter/Game_presenter.cpp
    ../src/View/Game_view.cpp
    ../src/Menu/Menu.cpp
    #../src/Events/Events.cpp
)


target_link_libraries(Game_Win.exe ${OXYGINE_CORE_LIBS})

