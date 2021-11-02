PROJECT(CppApp C CXX)

cmake_minimum_required(VERSION 3.21)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_CXX_STANDARD 14)
set(PACKAGE_NAME "main")


file(GLOB LIBRARIES "lib/rust/target/debug/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

# CLIENT
add_executable(
  ${PACKAGE_NAME}

  src/main.cpp
)


target_link_libraries(
  ${PACKAGE_NAME}
  
  ${LIBRARIES}
)

install(
  TARGETS ${PACKAGE_NAME}
  RUNTIME DESTINATION bin/
)
