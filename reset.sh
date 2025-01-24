#!/bin/bash

rm -rf cmake-build
cmake -S . -B cmake-build
cd cmake-build
make
./build/quantum_circuit