cmake_minimum_required(VERSION 3.23)
project(kubazip)

set(CMAKE_CXX_STANDARD 17)

set(KUBAZIP_SRC
        zip.c
        zip.h
        miniz.h)

add_library(kubazip ${KUBAZIP_SRC})