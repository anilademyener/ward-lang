#!/bin/sh

CXX="g++"
CXXFLAGS="-Wall -Werror `` -l boost_filesystem"
SOURCES="src/compiler/compiler.cc"
OUT="WARD_COMPILER"
BUILDCOMMAND="${CXX} ${CXXFLAGS} ${SOURCES} -o ${OUT}.OUT"

rm -rf ${OUT}.out
${BUILDCOMMAND}
if [[ -f ${OUT}.OUT ]]; then
  clear
  echo ""
  echo "COMPILED"
  echo ""
else
  echo ""
  echo "ERROR"
  echo ""
fi
