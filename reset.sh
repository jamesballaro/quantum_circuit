#!/bin/bash

debug =""
# Parse arguments
while getopts ":d:" opt; do
  case $opt in
    d) debug="$OPTARG" ;;
    \?) echo "Invalid option: -$OPTARG" >&2; exit 1 ;;
    :) echo "Option -$OPTARG requires an argument." >&2; exit 1 ;;
  esac
done

rm -rf cmake-build
cmake -S . -B cmake-build
cd cmake-build
make

# Run the executable with the optional debug flag
if [[ -n "$debug" ]]; then
    "$debug" ./build/quantum_circuit 
else
    ./build/quantum_circuit
fi