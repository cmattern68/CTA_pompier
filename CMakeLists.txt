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
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(SFML_STATIC_LIBRARIES FALSE)
find_package(SFML 2.5.1 REQUIRED COMPONENTS audio graphics window system)

#
# Engine Sources & Inc
#

set(ENGINE_INC    
    ./Sources/Engine/Window/
    ./Sources/Engine/Event/
)

set(ENGINE_SRC    
    ./Sources/Engine/Window/Window.cpp
    ./Sources/Engine/Event/Event.cpp
)

#
# Game Sources & Inc
#

set(GAME_INC
    ./Sources/Main/
    ./Sources/Core/
    ./Sources/Engine/Window/
    ./Sources/Engine/Event/
)

set(GAME_SRC
    ./Sources/Main/Main.cpp
    ./Sources/Core/Core.cpp
    ./Sources/Engine/Window/Window.cpp
    ./Sources/Engine/Event/Event.cpp
)

add_executable(CTA_Pompier ${ENGINE_SRC} ${GAME_SRC})
target_include_directories(CTA_Pompier PUBLIC ${ENGINE_INC} ${GAME_INC})
if(SFML_FOUND)
  target_include_directories(CTA_Pompier PUBLIC ${SFML_INCLUDE_DIRS})
  target_link_libraries(CTA_Pompier PUBLIC ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} sfml-graphics sfml-audio sfml-window sfml-system)
endif()
