cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR)

project(TitanGame CXX)

add_subdirectory(MACE)

file(GLOB_RECURSE SRC "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")

add_executable(TitanGame ${SRC} ${HEADERS})

target_link_libraries(TitanGame LINK_PUBLIC MACE)
target_include_directories(TitanGame PUBLIC ${MACE_INCLUDES})

file (GLOB_RECURSE resources "res/*.*")
foreach(resource ${resources})
 get_filename_component(filename ${resource} NAME)
 get_filename_component(dir ${resource} DIRECTORY)
 get_filename_component(dirname ${dir} NAME)
 
 set (output "")
 
 while(NOT ${dirname} STREQUAL resources)
  get_filename_component(path_component ${dir} NAME)
  set (output "${path_component}/${output}")
  get_filename_component(dir ${dir} DIRECTORY)
  get_filename_component(dirname ${dir} NAME)
 endwhile()
 
 set(output "${CMAKE_CURRENT_BINARY_DIR}/res/${output}/${filename}")
 
 add_custom_command(
  COMMENT "Moving updated resource-file '${filename}'"
  OUTPUT ${output}
  DEPENDS ${resource}
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  ${resource}
  ${output}
 )
 add_custom_target(${filename} ALL DEPENDS ${resource} ${output})
endforeach()