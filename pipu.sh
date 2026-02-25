#!/bin/bash

COMMAND=$1

if [ -z "$COMMAND" ]; then
    echo "Error: commands:"
    echo "- build"
    echo "- make"
    echo "- run"
    exit 1
fi

if [ "$COMMAND" == "build" ]; then
    rm -rf build
    mkdir build
    cd build
    cmake ..
    make
    exit 1
fi

if [ "$COMMAND" == "make" ]; then
    cd build
    make
    ./engine3d
    exit 1
fi

if [ "$COMMAND" == "run" ]; then
    ./build/engine3d
    exit 1
fi