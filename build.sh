#!/bin/bash

# Create build directory
echo "build file"
mkdir -p build

if [ $1 = "release" ]; then
    echo "Building release...."
    cd build
    cmake ..
    make
elif [ $1 = "debug" ]; then
    echo "Building debug...."
    cd build
    cmake .. -D ENABLE_SANITIZER="true" \
        -D SANITIZER_ADDRESS="ON" \
        -D SANITIZER_MEMORY="ON" \
        -D SANITIZER_UNDIFINED_BEHAVIOUR="ON"
    make
elif [ $1 = "clean" ]; then
    echo "Cleaning build directory"
    rm -rf build
else
    echo "Unkown option"
fi