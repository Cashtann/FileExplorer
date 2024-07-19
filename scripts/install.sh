#!/bin/bash

# Exit on any error
set -e

# Install necessary tools
echo "Installing gcc, g++, and CMake..."
sudo apt-get update
sudo apt-get install -y build-essential cmake wget

# Set Qt version and installation directory
QT_VERSION=6.4.0
QT_INSTALL_DIR=$HOME/Qt

# Download and install Qt if not already installed
if [ ! -d "$QT_INSTALL_DIR/$QT_VERSION" ]; then
    echo "Downloading and installing Qt $QT_VERSION..."
    wget https://download.qt.io/official_releases/qt/${QT_VERSION%.*}/$QT_VERSION/qt-opensource-linux-x64-$QT_VERSION.run
    chmod +x qt-opensource-linux-x64-$QT_VERSION.run
    ./qt-opensource-linux-x64-$QT_VERSION.run --script qt-noninteractive.qs
    rm qt-opensource-linux-x64-$QT_VERSION.run
fi

# Set Qt environment variables
export PATH=$QT_INSTALL_DIR/$QT_VERSION/gcc_64/bin:$PATH
export CMAKE_PREFIX_PATH=$QT_INSTALL_DIR/$QT_VERSION/gcc_64

# Create build directory
cd FileExplorer
mkdir -p build
cd build

# Run CMake to configure the project
cmake ..

# Build the project
cmake --build .