cmake_minimum_required(VERSION 3.16)
include(ExternalProject)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

project(EmbeddedFwTest)

add_executable(auto_id main.c)
add_subdirectory(src)
target_link_libraries(auto_id autoid)
