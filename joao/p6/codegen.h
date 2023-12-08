#ifndef _CODEGEN_H
#define _CODEGEN_H

#include "ast.h"

void codegen_program(struct node *program);
int codegen_expression(struct node *expression);
int codegen_call(struct node *call);
int codegen_if(struct node *if_node);

#endif