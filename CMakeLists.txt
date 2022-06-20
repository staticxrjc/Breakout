cmake_minimum_required(VERSION 3.18)
project(template VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_subdirectory(src)
include_directories(inc)
IF (WIN32)
    # set stuff for windows
    add_subdirectory(sdk/SFML)
    include_directories(sdk/SFML/include)
ELSE()
    find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
ENDIF()

add_executable(${PROJECT_NAME} src/main.cpp)

add_library(
        engine STATIC
        src/engine.cpp
        inc/engine.h
        src/block.cpp
        inc/block.h
        src/player.cpp
        inc/player.h
        src/ball.cpp
        inc/ball.h
        src/vector2.cpp
        inc/vector2.h
        src/boundingBox.cpp
        inc/boundingBox.h
)

target_link_libraries(${PROJECT_NAME} 
    engine
    sfml-system
    sfml-window
    sfml-graphics
    sfml-network
    sfml-audio)
