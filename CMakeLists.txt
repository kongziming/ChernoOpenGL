cmake_minimum_required(VERSION 3.10.0)

project(OpenGLStudy)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};${CMAKE_SOURCE_DIR}/dependencies/glfw/glfw/lib/cmake)

find_package(glfw3)
find_package(OpenGL REQUIRED)

add_definitions(-DGLEW_STATIC)
include_directories(${CMAKE_SOURCE_DIR}/dependencies/glew/include)
link_directories(${CMAKE_SOURCE_DIR}/dependencies/glew/lib/Release/x64)

add_subdirectory(src)
