#!/bin/bash

set -e

echo "BUILDING MAIN"
rm -rf target
mkdir target

pushd target
cmake ..
make
popd

# run
./target/bin/main
