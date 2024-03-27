cmake_minimum_required(VERSION 3.19)

set(CMAKE_VERBOSE_MAKEFILE on)

project(dr-zlib LANGUAGES C)

include(FetchContent)
FetchContent_Declare(
        zlib-ng
        GIT_REPOSITORY git@github.com:zlib-ng/zlib-ng.git
        GIT_TAG origin/develop
        OVERRIDE_FIND_PACKAGE
)

find_package(zlib-ng)

add_library(dr-zlib SHARED
        main.c)

set_property(TARGET dr-zlib PROPERTY CMAKE_C_STANDARD 23)
set_property(TARGET dr-zlib PROPERTY CMAKE_CXX_STANDARD 23)
set_property(TARGET dr-zlib PROPERTY CMAKE_C_STANDARD_REQUIRED True)

include_directories(SYSTEM ../include)

add_compile_options(-Wall -Wextra)
add_compile_options(-fpic)
add_compile_options(-flto)