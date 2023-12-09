#!/bin/bash

# Mensagem de compilação
echo "Compilando..."
rm -f uccompiler lex.yy.c y.tab.c y.tab.h

# Compilação com verificação de erros
yacc -d -v -t -g --report=all uccompiler.y || exit 1
lex uccompiler.l || exit 1
cc -o uccompiler lex.yy.c y.tab.c ast.c semantics.c codegen.c -Wall -Wno-unused-function || exit 1

# Verificação de argumentos
if [ $# -eq 0 ]; then
    echo "Uso: $0 <arquivo_de_entrada>"
    exit 1
fi

# Compilação do arquivo de entrada
echo "Gerando código intermediário..."
./uccompiler < "$1" > output.ll || exit 1

echo "Gerando código de máquina..."
llc output.ll -o output.s || exit 1

echo "Compilando código final..."
cc -o output output.s io.c || exit 1

# Mensagem de conclusão

echo "Compilação concluída com sucesso!"
