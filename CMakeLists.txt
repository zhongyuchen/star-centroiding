cmake_minimum_required(VERSION 3.12)
project(star-centroiding)

find_package(OpenCV)
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(star-centroiding main.cpp code/extraction.cpp code/extraction.h)

target_link_libraries( star-centroiding ${OpenCV_LIBS} )
