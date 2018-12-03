cmake_minimum_required(VERSION 3.10)
project(OpenGL_Class)

set(CMAKE_CXX_STANDARD 14)

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )
add_executable(OpenGL_Class InputManager.cpp LightManager.cpp pch.cpp Object.cpp OpenGLClass.cpp Player.cpp RootManager.cpp StageManager.cpp Star.cpp Transform.cpp Vector3.cpp Utility.cpp)

target_link_libraries(OpenGL_Class ${GLUT_LIBRARY} ${OPENGL_LIBRARY})