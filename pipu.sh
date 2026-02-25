#!/bin/bash

set -e

COMMAND=$1

if [ -z "$COMMAND" ]; then
    echo "Usage:"
    echo "  ./engine.sh build"
    echo "  ./engine.sh make"
    echo "  ./engine.sh run"
    exit 1
fi

if [ "$COMMAND" = "build" ]; then
    echo "🔨 Building project..."
    rm -rf build
    mkdir build
    cd build
    cmake ..
    make
    exit 0
fi

if [ "$COMMAND" = "make" ]; then
    echo "⚙ Rebuilding..."
    if [ ! -d "build" ]; then
        echo "Build folder not found. Run ./engine.sh build first."
        exit 1
    fi
    cd build
    make
    exit 0
fi

if [ "$COMMAND" = "run" ]; then
    echo "🚀 Running..."
    if [ ! -f "build/engine3d" ]; then
        echo "Executable not found. Build first."
        exit 1
    fi
    ./build/engine3d
    exit 0
fi

echo "Unknown command: $COMMAND"
exit 1