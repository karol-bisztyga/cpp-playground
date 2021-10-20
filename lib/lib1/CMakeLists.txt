PROJECT(lib1 C CXX)

include(FetchContent)

cmake_minimum_required(VERSION 3.16)

set(PACKAGE_NAME "lib1")
set(CMAKE_CXX_STANDARD 14)

FetchContent_Declare(Sodium
  GIT_REPOSITORY https://github.com/robinlinden/libsodium-cmake.git
)
set(SODIUM_DISABLE_TESTS ON)
FetchContent_MakeAvailable(Sodium)

add_library(
  ${PACKAGE_NAME}
  STATIC
  src/hey.cpp
)
add_library(${PACKAGE_NAME}::${PACKAGE_NAME} ALIAS ${PACKAGE_NAME})

target_include_directories(
  ${PACKAGE_NAME}
  PUBLIC
  src
)

target_link_libraries(
  ${PACKAGE_NAME}
  
  sodium
)

include(GNUInstallDirs)

install(
  TARGETS ${PACKAGE_NAME} sodium
  EXPORT ${PACKAGE_NAME}_targets
  INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

export(
  EXPORT ${PACKAGE_NAME}_targets
  NAMESPACE ${PACKAGE_NAME}::
  FILE "${CMAKE_INSTALL_LIBDIR}/cmake/${PACKAGE_NAME}/${PACKAGE_NAME}-config.cmake"
)
