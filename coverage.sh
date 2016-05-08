#!/bin/bash

cd build

# generate makefile
cmake -G Ninja -D CMAKE_CXX_FLAGS="-std=c++0x --coverage" ../ 

# supprime les données de coverage
lcov -z -d .

# compilation
ninja

# test unitaire 
../tests/run_tests.sh

# generation des données de coverage
lcov -c -d . -o research_pacs.info
 
# suppression des donnÃƒÂ©es inutiles
lcov -r research_pacs.info '/usr*' -d . -o research_pacs.info
lcov -r research_pacs.info 'tests/*' -d . -o research_pacs.info

# création d'une page web
genhtml -o lcov research_pacs.info

export WORKSPACE=$PWD
cppcheck -q --xml --xml-version=2 --enable=all --inconclusive -i ${WORKSPACE}/tests/tools/ ${WORKSPACE}/src/ ${WORKSPACE}/tests/ 2> ${WORKSPACE}/cppcheck.xml

