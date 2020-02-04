cmake_minimum_required(VERSION 3.13)
project(filler)

set(CMAKE_C_STANDARD 99)

include_directories(inc)
include_directories(Libft/)
aux_source_directory(src sources)
add_executable(filler ${sources})

target_link_libraries(filler ${PROJECT_SOURCE_DIR}/Libft/libft.a)