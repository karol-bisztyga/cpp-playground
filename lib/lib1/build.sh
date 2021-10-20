#!/bin/bash

set -e

rm -rf cmake
mkdir cmake

pushd cmake
cmake ..
make
popd
