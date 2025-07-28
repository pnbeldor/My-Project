#! /bin/sh

#cd external/CMake; mkdir build && cd build;
#./bootstrap

cd ./external/protobuf
mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build .

cd ../../../;
cd ./external/mbedtls
mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build .

cd ../../../;
cd ./external/leveldb
mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build .

cd ../../../;
cd ./external/simpleBLE
mkdir -p build && cd build
#cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build .

cd ../../../
cd ./external/openssl
mkdir -p build && cd build
#cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build .

cd ../../../
cd ./external/GUIslice
mkdir -p build && cd build
#cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build .

cd ../../../
mkdir -p out/build
cmake -Dprotobuf_BUILD_TESTS=OFF -S . -B out/build
