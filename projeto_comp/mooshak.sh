#!/bin/bash
rm -f uccompiler lex.yy.c y.tab.c y.tab.h y.output
yacc -dv uccompiler.y
lex uccompiler.l
cc -g -Wall -Wextra -Wno-unused-function y.tab.c lex.yy.c ast.c semantics.c -o uccompiler
if [[ $# -eq 1 ]]; then
./uccompiler -s < ../c/meta3/$1.uc | diff -ya ../c/meta3/$1.out -
fi
if [[ $# -eq 2 ]]; then
./uccompiler -s < ../c/meta3/$1.c | diff -ya ../c/meta3/$1.out -
fi