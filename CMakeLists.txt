PROJECT(CppApp C CXX)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_CXX_STANDARD 14)
set(PACKAGE_NAME "main")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/libopaque-cmake)

include_directories(
  lib/libopaque-cmake/src
  lib/libopaque-cmake/src/aux
)

# CLIENT
add_executable(
  ${PACKAGE_NAME}

  src/main.cpp
)


target_link_libraries(
  ${PACKAGE_NAME}
  
  libopaque-cmake
)

install(
  TARGETS ${PACKAGE_NAME}
  RUNTIME DESTINATION bin/
)
