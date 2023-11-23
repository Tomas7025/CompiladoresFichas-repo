#!/bin/bash
rm -f uccompiler lex.yy.c y.tab.c y.tab.h y.output
yacc -dv uccompiler.y
lex uccompiler.l
cc -g y.tab.c lex.yy.c ast.c semantics.c -o  uccompiler
if [[ $# -eq 1 ]]; then
./uccompiler -t < ../c/meta3/$1.uc | diff -ya ../c/meta3/$1.out -
fi
