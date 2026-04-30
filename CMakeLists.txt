cmake_minimum_required(VERSION 3.15)
project(queens-solver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(queens-solver
    src/main.cpp
    src/grid.cpp
    src/solver.cpp
)

target_include_directories(queens-solver PRIVATE src)