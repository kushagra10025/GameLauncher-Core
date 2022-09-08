cmake_minimum_required(VERSION 3.23)
project(GameLauncher_Core)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameLauncher_Core src/main.cpp src/FileSystemHandler.cpp src/FileSystemHandler.h src/JSONPraseHandler.cpp src/JSONPraseHandler.h)

target_include_directories(${PROJECT_NAME}
        PUBLIC external/)