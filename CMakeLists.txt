PROJECT(CppApp C CXX)

cmake_minimum_required(VERSION 3.20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_CXX_STANDARD 17)
set(PACKAGE_NAME "main")

add_executable(
  ${PACKAGE_NAME}

  src/main.cpp
)

install(
  TARGETS ${PACKAGE_NAME}
  RUNTIME DESTINATION bin/
)
