cmake_minimum_required(VERSION 3.13)
project(filler)

set(CMAKE_C_STANDARD 99)

include_directories(inc)
include_directories(libft)
aux_source_directory(src sources)
add_executable(filler ${sources} main.c)
