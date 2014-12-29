#!/bin/sh
mkdir build
cd build
sudo cmake -DCMAKE_C_COMPILER=/usr/local/bin/gcc -DCMAKE_CXX_COMPILER=/usr/local/bin/g++ ..
sudo make 
