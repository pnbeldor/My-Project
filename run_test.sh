#! /bin/sh

#cd out/build;
GTEST_COLOR=1 ctest --test-dir out/build/Module1 --output-on-faillure -j12 #--repeat until-fail./MyProject
