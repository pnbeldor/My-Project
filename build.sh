#! /bin/sh

./out/build/external/flatbuffers/flatc --cpp -c --java -o ./Definitions/Generated/ ./Definitions/FlatBufferDef/example.fbs

cd out/build ; make
