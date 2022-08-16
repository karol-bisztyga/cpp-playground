PROJECT(CppApp C CXX)

cmake_minimum_required(VERSION 3.20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_CXX_STANDARD 17)
set(PACKAGE_NAME "main")

include(cmake/corrosion_cxx.cmake)
add_subdirectory(corrosion)

add_executable(
  ${PACKAGE_NAME}

  src/main.cpp
)

add_library_rust(PATH rust_lib NAMESPACE cpp_playground)

target_link_libraries(${PACKAGE_NAME} PUBLIC cpp_playground::rust_lib)

install(
  TARGETS ${PACKAGE_NAME}
  RUNTIME DESTINATION bin/
)
