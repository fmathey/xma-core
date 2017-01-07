cmake_minimum_required(VERSION 3.6)

project(XMACoreTests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(${PROJECT_SOURCE_DIR}/sources)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/tests/main.cpp)