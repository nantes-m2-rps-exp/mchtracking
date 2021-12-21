cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(mchtracking LANGUAGES C CXX)

include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(GNUInstallDirs)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/stage/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/stage/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/stage/bin)

set(BUILD_SHARED_LIBS ON)
option(BUILD_PYTHON_BINDINGS "Build Python bindings" ON)

include(dependencies/CMakeLists.txt)

add_subdirectory(src)

