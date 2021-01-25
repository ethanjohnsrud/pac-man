project(pacman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXXX_FLAGS} -Wall -std=c++14")

add_executable(pacman gameplay.cpp)
