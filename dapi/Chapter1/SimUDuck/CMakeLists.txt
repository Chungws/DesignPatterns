project (Content)

cmake_minimum_required(VERSION 3.23)

add_subdirectory(lib)

add_executable(program main.cc)

target_link_libraries(program content)