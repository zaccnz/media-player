cmake_minimum_required(VERSION 3.15)
project(media-player)

add_subdirectory(libs/raylib EXCLUDE_FROM_ALL)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME} src/main.c)

target_link_libraries(${PROJECT_NAME} raylib)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()