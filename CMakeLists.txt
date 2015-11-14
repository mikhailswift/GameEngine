cmake_minimum_required(VERSION 3.2.2) # CMake version check
project(GameEngine)               # Create project "simple_example"
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # Enable c++11 standard

set(SOURCE_FILES src/main.cpp src/GameWindow.h src/GameWindow.cpp src/GameWindow.h src/GameEngine.cpp src/GameEngine.h src/Game.cpp src/Game.h)            # Add main.cpp file of project root directory as source file
add_executable(GameEngine ${SOURCE_FILES})       # Add executable target with source files listed in SOURCE_FILES variable
INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(GameEngine ${SDL2_LIBRARIES})