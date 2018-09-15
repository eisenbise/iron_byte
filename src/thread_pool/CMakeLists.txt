cmake_minimum_required(VERSION 3.0)

set(MODULE thread_pool)
project(${MODULE})

file(GLOB source *.cxx)


add_library(${MODULE} SHARED ${source})
add_executable(${MODULE}_test ${source})

target_link_libraries(${MODULE} pthread)
target_link_libraries(${MODULE}_test pthread)


set(CMAKE_INSTALL_PREFIX ../..)
install(TARGETS ${MODULE} DESTINATION lib)