cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)

project(graphics_fun VERSION 0.1.0 LANGUAGES CXX C)

include(FetchContent)
set(FETCHCONTENT_QUIET TRUE)
set(CMAKE_VERBOSE_MAKEFILE OFF)
if (CMAKE_VERSION VERSION_GREATER "3.24.0")
    # Avoid warnings in CMake 3.24.0:
    cmake_policy(SET CMP0135 NEW)
endif()

find_package(OpenGL REQUIRED)
include(cmake/CompilerWarnings.cmake)

add_library(project_options INTERFACE)
set_target_properties(project_options PROPERTIES
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
target_compile_features(project_options INTERFACE cxx_std_20)
set_project_warnings(project_options)

set(source_code
    source/GLApp.cpp source/GLApp.h
    source/glCheck.cpp source/glCheck.h
    source/GLHandle.h
    source/GLShader.cpp source/GLShader.h
    source/ImGuiHelper.cpp source/ImGuiHelper.h
    source/IProgram.h
    source/main.cpp
    source/Tutorial_0.cpp source/Tutorial_0.h
)

add_executable(graphics_fun ${source_code})
target_link_libraries(graphics_fun INTERFACE project_options)
target_include_directories(graphics_fun PRIVATE source)
include(cmake/ExternalDependencies.cmake)
target_link_libraries(graphics_fun PRIVATE dependencies)
