cmake_minimum_required(VERSION 3.5)

project(cells LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include_directories(include/)

set(SOURCES
        source/main.cpp
        source/ParticleSystem.cpp
        source/Particle.cpp
    )

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

find_package(CanvasLib REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} CanvasLib)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} OpenGL::GL)

install(TARGETS cells
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
