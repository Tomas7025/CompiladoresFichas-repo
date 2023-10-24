#!/bin/bash

lex calc.l

if [ $1 = "-v" ]; then
	yacc -dv calc.y
else
	yacc -d calc.y
fi

gcc y.tab.c lex.yy.c -o calc

