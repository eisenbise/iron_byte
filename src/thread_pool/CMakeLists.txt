cmake_minimum_required(VERSION 3.0)

set(MODULE thread_pool)
project(${MODULE})

file(GLOB source *.cxx)

add_library(${MODULE} SHARED ${source})

set(CMAKE_INSTALL_PREFIX ../..)
install(TARGETS ${MODULE} DESTINATION lib)