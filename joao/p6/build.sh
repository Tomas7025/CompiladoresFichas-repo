#!/bin/sh
rm -f petit lex.yy.c y.tab.c y.tab.h
yacc -d -v -t -g --report=all petit.y
lex petit.l
cc -g -o petit lex.yy.c y.tab.c ast.c semantics.c codegen.c -Wall -Wno-unused-function
