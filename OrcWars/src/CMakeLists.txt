cmake_minimum_required (VERSION 2.6)
project(Snake)


include_directories(../data data)
##########################################################
#########################OXYGINE##########################
add_subdirectory(../../../oxygine-framework oxygine-framework)

add_definitions(${OXYGINE_DEFINITIONS})
include_directories(${OXYGINE_INCLUDE_DIRS})

link_directories(${OXYGINE_LIBRARY_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OXYGINE_CXX_FLAGS}")
###########################E#N#D############################

add_executable(EmptyOxygine 
    example.cpp 
    main.cpp
    ViewHelper.cpp
)

add_subdirectory(Model)

target_link_libraries(EmptyOxygine ${OXYGINE_CORE_LIBS})



