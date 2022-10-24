cmake_minimum_required(VERSION 3.23)
project(Pong)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 23)
add_executable(Pong main.cpp Game.cpp Game.h TextureManager.h TextureManager.cpp GameObject.cpp GameObject.h Map.cpp Map.h TextManager.cpp TextManager.h Boll.cpp Boll.h)

target_link_libraries(Pong ${SDL2_LIBRARIES} SDL2_image SDL2_ttf)
