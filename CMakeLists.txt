cmake_minimum_required(VERSION 3.31.3)

project(MyProject
VERSION 1.0
DESCRIPTION "Create a cmake project that will be modified later"
LANGUAGES C CXX)

#set(CMAKE_SYSTEM_NAME Linux)
#set(CMAKE_SYSTEM_PROCESSOR x86)

#set(triple x86_64-pc-linux-gnu)
#set(CMAKE_C_COMPILER /usr/bin/clang)
#set(CMAKE_C_COMPILER_TARGET ${triple})
#set(CMAKE_CXX_COMPILER /usr/bin/clang++)
#set(CMAKE_CXX_COMPILER_TARGET ${triple})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "-Wall;-Werror")
include(CTest)

enable_testing()


set(FLATBUFFERS_MAX_PARSING_DEPTH 16)
configure_file(MyProjectConfig.h.in MyProjectConfig.h)

add_subdirectory(Module1)
add_subdirectory(Module2)
add_subdirectory(Definitions/Generated)
#add_subdirectory(external/CMake)
add_subdirectory(external/glfw)
add_subdirectory(external/lvgl)
add_subdirectory(external/googletest)
add_subdirectory(external/flatbuffers)
add_subdirectory(external/Catch2)
add_subdirectory(external/doctest)
#add_subdirectory(external/protobuf)
#add_subdirectory(external/redis)
add_subdirectory(external/hiredis)
add_subdirectory(external/redis-cpp)
#add_subdirectory(external/leveldb)
#add_subdirectory(external/mbedtls)
#add_subdirectory(external/simpleBLE)
#add_subdirectory(external/openssl)
#add_subdirectory(external/GUIslice)
#add_subdirectory(${FLATBUFFERS_SRC_DIR}
#                 ${CMAKE_CURRENT_BINARY_DIR}/flatbuffers-build
#                 EXCLUDE_FROM_ALL)

list(APPEND EXTRA_INCLUDES Module1/include)

#target_include_directories(${PROJECT_NAME} PUBLIC Module1 Module1/src)

add_executable(${PROJECT_NAME} main.cpp)

# DOWNLOAD ALL SUBMODULES
find_package(GIT QUIET)

if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    option(GIT SUBMODULE "Check submodules during build" ON)
    if(GIT SUBMODULE)
        message(STATUS "Submodules update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)

        if (NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_BINARY_DIR}
    PUBLIC external/glfw/include
    PUBLIC external/googletest/googlemock/include
    PUBLIC external/lvgl
    PUBLIC Module1/include
    PUBLIC external/hiredis
    PUBLIC external/flatbuffers/include
    PUBLIC external/doctest
    PUBLIC external/protobuf
    PUBLIC Definitions/Generated
    PUBLIC external/leveldb/include
    PUBLIC external/simpleBLE
    PUBLIC external/Catch2
    #public external/GUIslice
)

target_link_directories(${PROJECT_NAME}
    PUBLIC Module1/src
    PUBLIC external/glfw/src
    PUBLIC external/lvgl/src
    PUBLIC external/doctest
    PUBLIC external/mbedtls/
    PUBLIC external/Catch2/src
    public external/leveldb
)

target_link_libraries(${PROJECT_NAME} gtest NearlyMath glfw lvgl hiredis flatbuffers)
