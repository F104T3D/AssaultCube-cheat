cmake_minimum_required(VERSION 3.15)
project(AssaultCubeCheat LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directory with headers
include_directories("${CMAKE_SOURCE_DIR}/as_cube cheat")

# Source files
set(SOURCES
    "${CMAKE_SOURCE_DIR}/as_cube_cheat/main.cpp"
    "${CMAKE_SOURCE_DIR}/as_cube_cheat/health.cpp"
    "${CMAKE_SOURCE_DIR}/as_cube_cheat/ammo.cpp"
    "${CMAKE_SOURCE_DIR}/as_cube_cheat/globals.cpp"
)

# Build executable
add_executable(AssaultCubeCheat ${SOURCES})
