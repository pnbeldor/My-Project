#cmake_minimum_required(VERSION 3.27)

#project(MyProject VERSION 1.0)

list(APPEND EXTRA_INCLUDES src)
add_library(NearlyMath STATIC NearlyMath.cpp)

target_include_directories(NearlyMath INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
