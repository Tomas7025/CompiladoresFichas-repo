#!/usr/bin/env sh

echo "Cleaning up..."
rm -f lex.yy.c
rm -f y.tab.c
rm -f y.tab.h
rm -f calc
rm -f middle.s
rm -f helloworld 

if [ $# -gt 0 ] && [ "$1" = "clean" ]
then
  exit 0
fi

lexbin=flex
if ! hash $lexbin 2> /dev/null
then
  echo "Lex not found."
  exit 1
else
  echo "Lex found ($($lexbin --version | head -n1))."
fi

yaccbin=bison
if ! hash $yaccbin 2> /dev/null
then
  echo "YACC/Bison not found."
  exit 1
else 
  echo "YACC/Bison found ($($yaccbin --version | head -n1))."
fi

llcbin=llc-14
if ! hash $llcbin 2> /dev/null
then
  llcbin=llc
  if ! hash $llcbin 2> /dev/null
  then
    echo "LLVM Compiler not found."
    exit 1
  else
    echo "LLVM Compiler found ($($llcbin --version | grep version))."
  fi
else
  echo "LLVM Compiler found ($($llcbin --version | grep version))."
fi

clangbin=clang-14
if ! hash $clangbin 2> /dev/null
then 
  clangbin=clang
  if ! hash $clangbin 2> /dev/null
  then
    echo "Clang not found."
    exit 1
  else
    echo "Clang found ($($clangbin --version | head -n1))."
  fi
else
  echo "Clang found ($($clangbin --version | head -n1))."
fi

# Lex
if $lexbin calc.l && [ -f "lex.yy.c" ]; then
  echo "Lex compiled 'calc.l' successfully."
else
  echo "Lex failed to compile 'calc.l'."
  exit 1
fi

# Yacc
if $yaccbin -y -d calc.y && [ -f "y.tab.c" ] && [ -f "y.tab.h" ]; then
  echo "YACC compiled 'calc.y' successfully."
else
  echo "YACC failed to compile 'calc.y'."
  exit 1
fi

# Clang (lex/yacc)
if $clangbin lex.yy.c y.tab.c -o calc && [ -f "calc" ]; then
  echo "Clang compiled 'calc' successfully."
else
  echo "Clang failed to compile 'calc'."
  exit 1
fi

# LLVM
if $llcbin -o=middle.s helloworld.ll && [ -f "middle.s" ]; then
  echo "LLVM compiled 'helloworld.ll' successfully."
else
  echo "LLVM failed to compile 'helloworld.ll'."
  exit 1
fi

if $clangbin -no-pie -o helloworld middle.s  && [ -f "helloworld" ]; then
  echo "Clang compiled 'helloworld' successfully."
else
  echo "Clang failed to compile 'helloworld'."
  exit 1
fi

if ! ./helloworld; then
  echo "The LLVM Hello World example did not execute successfully."
fi
