cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 11)
project(Sudoku_TheGame  CXX)

include(tools/cmake/sanitizer.cmake)
option(
    ENABLE_SANITIZER
    "Enable sanitizer"
    FALSE)

add_subdirectory(src)