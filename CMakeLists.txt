cmake_minimum_required(VERSION 3.21)
project(breakout)
add_subdirectory(sdk/SFML)
include_directories(sdk/SFML/include)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME}
        sfml-system
        sfml-window
        sfml-graphics
        sfml-network
        sfml-audio)
