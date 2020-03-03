##
## EPITECH PROJECT, 2019
## CPP_babel_2019
## File description:
## CMakeList.txt
##

cmake_minimum_required(VERSION 3.5)

project(CTA_Pompier)
add_definitions(-W -Wall -Wextra -Wfatal-errors -Wpedantic -ansi -g)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../)

set(GAME_INC
    ./Sources/Main/
)

set(GAME_SRC
    ./Sources/Main/Main.cpp
)

add_executable(CTA_Pompier ${GAME_SRC})
target_include_directories(CTA_Pompier PUBLIC ${GAME_INC})
