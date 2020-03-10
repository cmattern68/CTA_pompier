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
  ./Sources/Engine/Shape/
  ./Sources/Engine/Shape/RectangleShape/
  ./Sources/Engine/Shape/CircleShape/
  ./Sources/Engine/Texture/
  ./Sources/Engine/Text/
  ./Sources/Engine/Button/
  ./Sources/Engine/Button/SpriteButton
)

set(ENGINE_SRC    
    ./Sources/Engine/Window/Window.cpp
    ./Sources/Engine/Event/Event.cpp
    ./Sources/Engine/Shape/RectangleShape/RectangleShape.cpp
    ./Sources/Engine/Shape/CircleShape/CircleShape.cpp
    ./Sources/Engine/Texture/Texture.cpp
    ./Sources/Engine/Text/Text.cpp
    ./Sources/Engine/Button/SpriteButton/SpriteButton.cpp
)

#
# Shared Sources & Inc
#

set(SHARED_INC
    ./Sources/Game/Shared/CallPopup
)

set(SHARED_SRC
./Sources/Game/Shared/CallPopup/CallPopup.cpp
)

#
# Game Sources & Inc
#

set(GAME_INC
    ./Sources/Main/
    ./Sources/Core/
    ./Sources/Game/
    ./Sources/Game/Navbar/
    ./Sources/Game/SceneryManager/
    ./Sources/Game/Scene/
    ./Sources/Game/Scene/MissionOverview/
    ./Sources/Game/Scene/Settings/
)

set(GAME_SRC
    ./Sources/Main/Main.cpp
    ./Sources/Core/Core.cpp 
    ./Sources/Game/Game.cpp
    ./Sources/Game/Navbar/Navbar.cpp
    ./Sources/Game/SceneryManager/SceneryManager.cpp
    ./Sources/Game/Scene/AScene.cpp
    ./Sources/Game/Scene/MissionOverview/MissionOverview.cpp
    ./Sources/Game/Scene/Settings/Settings.cpp
)

add_executable(CTA_Pompier ${ENGINE_SRC} ${SHARED_SRC} ${GAME_SRC})
target_include_directories(CTA_Pompier PUBLIC ${ENGINE_INC} ${SHARED_INC} ${GAME_INC})
if(SFML_FOUND)
  target_include_directories(CTA_Pompier PUBLIC ${SFML_INCLUDE_DIRS})
  target_link_libraries(CTA_Pompier PUBLIC ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} sfml-graphics sfml-audio sfml-window sfml-system)
endif()
