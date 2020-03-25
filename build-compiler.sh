#!/bin/sh

CXX="g++"
CXXFLAGS="-Wall -Werror `` -l boost_filesystem"
SOURCES="src/compiler/compiler.cc"
OUT="WARD_COMPILER"
BUILDCOMMAND="${CXX} ${CXXFLAGS} ${SOURCES} -o ${OUT}.OUT"

${BUILDCOMMAND}
