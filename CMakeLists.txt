cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR)

project(TitanGame CXX)

add_subdirectory(MACE)

file(GLOB_RECURSE SRC "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")

add_executable(TitanGame ${SRC} ${HEADERS})

target_link_libraries(TitanGame LINK_PUBLIC MACE)
target_include_directories(TitanGame PUBLIC ${MACE_INCLUDES})
target_include_directories(TitanGame PUBLIC ${HEADERS})