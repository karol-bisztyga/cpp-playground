#!/bin/bash

set -e

# build the lib first
echo "BUILDING LIB"
pushd lib
rm -rf libopaque-cmake
git clone https://github.com/karol-bisztyga/libopaque-cmake.git
popd # lib

echo "BUILDING MAIN"
rm -rf cmake
mkdir cmake

pushd cmake
cmake .. -DCMAKE_PREFIX_PATH=lib/lib1/cmake/
make
popd

# run
# ./cmake/bin/main
