cmake_minimum_required(VERSION 3.13)
project(filler)

set(CMAKE_C_STANDARD 99)

include_directories(inc)
include_directories(Libft/)
include_directories(~/.brew/include/)
include_directories(vis/inc)
include_directories(${SDL2_INCLUDE_DIRS})
aux_source_directory(src sources)
aux_source_directory(${PROJECT_SOURCE_DIR}/vis/src visualizer)

add_executable(filler ${visualizer})

find_package(SDL2 REQUIRED)
target_link_libraries(filler ${PROJECT_SOURCE_DIR}/Libft/libft.a)
target_link_libraries(filler /Users/mshagga/.brew/lib/libSDL2.a)
target_link_libraries(filler /Users/mshagga/.brew/lib/libSDL2_ttf.a)
target_link_libraries(filler ${SDL2_LIBRARIES})