project(EventSubscription)

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)

add_executable(program main.cc)

target_link_libraries(program eventsubscription)