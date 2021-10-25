PROJECT(CppApp C CXX)

include(FetchContent)

cmake_minimum_required(VERSION 3.16)

FetchContent_Declare(Sodium
  GIT_REPOSITORY https://github.com/robinlinden/libsodium-cmake.git
)
set(SODIUM_DISABLE_TESTS ON)
FetchContent_MakeAvailable(Sodium)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall --std=c++11 -O3 -fPIC")
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -O3 -fPIC")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_CXX_STANDARD 14)
set(PACKAGE_NAME "main")

include_directories(
  lib/libopaque-cmake/src
  lib/libopaque-cmake/src/aux
)

set_source_files_properties(lib/libopaque-cmake/src/common.c PROPERTIES LANGUAGE CXX )
set_source_files_properties(lib/libopaque-cmake/src/opaque.c PROPERTIES LANGUAGE CXX )
set_source_files_properties(lib/libopaque-cmake/src/aux/kdf_hkdf_sha256.c PROPERTIES LANGUAGE CXX )

add_executable(
  ${PACKAGE_NAME}
  lib/libopaque-cmake/src/common.c
  lib/libopaque-cmake/src/opaque.c
  lib/libopaque-cmake/src/aux/kdf_hkdf_sha256.c

  src/main.cpp
)

target_link_libraries(
  ${PACKAGE_NAME}
  sodium
)

install(
  TARGETS ${PACKAGE_NAME}
  RUNTIME DESTINATION bin/
)
