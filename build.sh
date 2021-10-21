#!/bin/bash

set -e

# build the lib first
echo "BUILDING LIB"
pushd lib/libopaque-cmake
./build.sh
popd # lib/libopaque-cmake

echo "BUILDING MAIN"
rm -rf cmake
mkdir cmake

pushd cmake
cmake .. -DCMAKE_PREFIX_PATH=lib/libopaque-cmake/cmake/
make
popd

# run
# ./cmake/bin/main
