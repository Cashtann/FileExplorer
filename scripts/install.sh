#!/bin/bash

# Exit on any error
set -e

# Install necessary tools
echo "Installing gcc, g++, and CMake..."
sudo apt-get update
sudo apt-get install -y build-essential cmake wget

# Set Qt version and installation directory
QT_VERSION=6.4.0
QT_DIR=$HOME/Qt/$QT_VERSION
QT_URL=https://download.qt.io/archive/qt/6.4/6.4.0/qt-opensource-linux-x64-6.4.0.run

# Download and install Qt if not already installed
if [ ! -d "$QT_DIR" ]; then
    echo "Downloading Qt $QT_VERSION..."
    wget $QT_URL -O qt-installer.run
    chmod +x qt-installer.run

    echo "Installing Qt $QT_VERSION..."
    ./qt-installer.run --script qt-noninteractive.qs
    rm qt-installer.run
fi

# Set Qt environment variables
export PATH=$QT_DIR/gcc_64/bin:$PATH
export CMAKE_PREFIX_PATH=$QT_DIR/gcc_64

# Create build directory
cd FileExplorer
mkdir -p build
cd build

# Run CMake to configure the project
cmake ..

# Build the project
cmake --build .