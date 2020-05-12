cmake_minimum_required(VERSION 2.8.4)
project(untitled5)

set(CMAKE_CXX_STANDARD 14)
link_directories(/usr/lib64/mysql/)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -O3 -pthread" )
add_executable(untitled5 main.cpp)
target_link_libraries(untitled5 mysqlclient)
