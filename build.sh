#!/bin/bash

set -e

# build lib
pushd lib/rust
cargo build
popd # lib/rust

echo "BUILDING MAIN"
rm -rf cmake
mkdir cmake

pushd cmake
cmake .. -DCMAKE_PREFIX_PATH=lib/lib1/cmake/
make
popd

# run
# ./cmake/bin/main
