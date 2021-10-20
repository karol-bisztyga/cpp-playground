#!/bin/bash

set -e

# build the lib first
echo "BUILDING LIB"
pushd lib/lib1
./build.sh
popd # lib/lib1

echo "BUILDING MAIN"
rm -rf cmake
mkdir cmake

pushd cmake
cmake .. -DCMAKE_PREFIX_PATH=lib/lib1/cmake/
make
popd

# run
# ./cmake/bin/main
