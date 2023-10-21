#!/bin/bash

lex calc.l

if [ $1 = "-v" ]; then
	yacc -dv calc.y
else
	yacc -v calc.y
fi

cc y.tab.c lex.yy.c -o calc

