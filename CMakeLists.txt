PROJECT(CppApp C CXX)

cmake_minimum_required(VERSION 3.20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_CXX_STANDARD 17)
set(PACKAGE_NAME "main")

find_package (SQLite3 REQUIRED)

include_directories(${SQLite3_INCLUDE_DIRS})

add_executable(
  ${PACKAGE_NAME}

  src/main.cpp
)

target_link_libraries (${PACKAGE_NAME} ${SQLite3_LIBRARIES})

install(
  TARGETS ${PACKAGE_NAME}
  RUNTIME DESTINATION bin/
)
