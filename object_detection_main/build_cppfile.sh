#!/bin/sh
if [ -e build ] ; then
    rm -rf build
fi
mkdir build
cd build
sudo cmake -DCMAKE_C_COMPILER=/usr/local/bin/gcc -DCMAKE_CXX_COMPILER=/usr/local/bin/g++ ..
sudo make 
