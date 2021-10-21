PROJECT(CppApp C CXX)

cmake_minimum_required(VERSION 3.20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_CXX_STANDARD 14)
set(PACKAGE_NAME "main")

find_package(lib1 REQUIRED)

# CLIENT
add_executable(
  ${PACKAGE_NAME}

  src/main.cpp
)


target_link_libraries(
  ${PACKAGE_NAME}
  
  lib1::lib1
)

install(
  TARGETS ${PACKAGE_NAME}
  RUNTIME DESTINATION bin/
)
