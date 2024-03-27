cmake_minimum_required(VERSION 3.19)

set(CMAKE_VERBOSE_MAKEFILE on)

project(dr-zlib LANGUAGES C)

add_library(dr-zlib SHARED
        main.c)

set_property(TARGET dr-zlib PROPERTY CMAKE_C_STANDARD 23)
set_property(TARGET dr-zlib PROPERTY CMAKE_CXX_STANDARD 23)
set_property(TARGET dr-zlib PROPERTY CMAKE_C_STANDARD_REQUIRED True)

include_directories(SYSTEM ../include)

add_subdirectory(zlib-ng EXCLUDE_FROM_ALL)

add_compile_options(-Wall -Wextra)
add_compile_options(-fpic)
add_compile_options(-flto)