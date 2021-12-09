cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(challenge VERSION 1.0)

file(GLOB_RECURSE SRC_FILES sources/*.cpp)

add_executable(challenge ${SRC_FILES})
target_include_directories(challenge PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)