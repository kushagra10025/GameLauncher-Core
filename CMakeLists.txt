cmake_minimum_required(VERSION 3.23)
project(GameLauncher_Core)

set(CMAKE_CXX_STANDARD 17)

set(GLC_SRC
        src/main.cpp
        src/FileSystemHandler.cpp
        src/JSONParseHandler.cpp
        src/ArchiveHandler.cpp
        src/FileSystemHandler.h
        src/JSONParseHandler.h
        src/ArchiveHandler.h)

add_subdirectory(external/kubazip/)

add_executable(${PROJECT_NAME} ${GLC_SRC})

target_link_libraries(${PROJECT_NAME} kubazip)

target_include_directories(${PROJECT_NAME}
        PUBLIC external/)