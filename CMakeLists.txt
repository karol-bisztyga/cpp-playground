PROJECT(CppApp C CXX)

cmake_minimum_required(VERSION 3.21)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_CXX_STANDARD 14)
set(PACKAGE_NAME "main")

find_package(lib1 REQUIRED)

#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/lib1)

#add_library(lib1 SHARED IMPORTED) # or STATIC instead of SHARED
#set_target_properties(lib1 PROPERTIES
#  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/lib1.so"
#  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/lib/lib1/src"
#)

#include_directories(lib/lib1)

# CLIENT
add_executable(
  ${PACKAGE_NAME}

  src/main.cpp
)


target_link_libraries(
  ${PACKAGE_NAME}
  
  #lib/lib1/cmake/liblib1.a
  lib1::lib1
)

install(
  TARGETS ${PACKAGE_NAME}
  RUNTIME DESTINATION bin/
)
