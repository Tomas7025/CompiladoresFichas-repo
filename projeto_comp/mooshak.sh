#!/bin/bash
rm -f uccompiler lex.yy.c y.tab.c y.tab.h y.output
yacc -dv  uccompiler.y
lex uccompiler.l
cc y.tab.c lex.yy.c -o uccompiler
if [[ $# -eq 1 ]]; then
./uccompiler < ../c/meta2/$1.uc | diff -ya ../c/meta2/$1.out -
fi