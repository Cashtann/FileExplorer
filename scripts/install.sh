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
QT_INSTALLER=qt-unified-linux-x64-online.run

# Download and install Qt if not already installed
if [ ! -d "$QT_INSTALL_DIR/$QT_VERSION" ]; then
    echo "Downloading Qt Online Installer..."
    wget https://download.qt.io/official_releases/online_installers/$QT_INSTALLER
    chmod +x $QT_INSTALLER

    echo "Running Qt Online Installer in non-interactive mode..."
    ./qt-unified-linux-x64-online.run --script qt-noninteractive.qs
    rm qt-unified-linux-x64-online.run
fi

# Set Qt environment variables
export PATH=$QT_INSTALL_DIR/$QT_VERSION/gcc_64/bin:$PATH
export CMAKE_PREFIX_PATH=$QT_INSTALL_DIR/$QT_VERSION/gcc_64

# Create build directory
mkdir -p build
cd build

# Run CMake to configure the project
cmake ..

# Build the project
cmake --build .