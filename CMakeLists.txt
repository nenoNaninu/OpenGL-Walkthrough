cmake_minimum_required(VERSION 3.5)
project(OpenGL_Walkthrough)

set(CMAKE_CXX_STANDARD 14)

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )
add_executable(OpenGL_Walkthrough InputManager.cpp LightManager.cpp pch.cpp Object.cpp main.cpp Player.cpp RootManager.cpp StageManager.cpp Star.cpp Transform.cpp Vector3.cpp Utility.cpp)

target_link_libraries(OpenGL_Walkthrough ${GLUT_LIBRARY} ${OPENGL_LIBRARY})