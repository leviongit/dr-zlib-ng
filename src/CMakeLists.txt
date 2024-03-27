cmake_minimum_required(VERSION 3.19.0)

project(LANGUAGES C)

add_library(mruby-min-zlib-ng SHARED
        main.c)

include_directories(mruby-min-zlib-ng SYSTEM ../../include/)

add_subdirectory(../zlib-ng build)

add_compile_options(mruby-min-zlib-ng -Wall -Wextra)
