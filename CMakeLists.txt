cmake_minimum_required(VERSION 3.15)
project(AssaultCubeCheat LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    as_cube_cheat/main.cpp
    as_cube_cheat/health.cpp
    as_cube_cheat/ammo.cpp
    as_cube_cheat/globals.cpp
)

set(HEADERS
    as_cube_cheat/globals.hpp
)

add_executable(AssaultCubeCheat
    ${SOURCES}
    ${HEADERS}
)

