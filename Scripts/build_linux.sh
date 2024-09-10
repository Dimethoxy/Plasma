#!/usr/bin/env bash

# Build the project by running the Make build script in the LinuxMakefile directory as Relase

cd Builds/LinuxMakefile
make CONFIG=Release
echo "Build complete"