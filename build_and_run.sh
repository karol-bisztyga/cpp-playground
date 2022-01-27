#!/bin/bash

set -e

echo "BUILDING MAIN"
rm -rf cmake
mkdir cmake

pushd cmake
cmake ..
make
popd

# run
./cmake/bin/main
