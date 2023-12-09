#ifndef _CODEGEN_H
#define _CODEGEN_H

#include "ast.h"
#include "semantics.h"

void codegen_program(struct node *program);

int codegen_global_vars(struct symbol_list *global_scope);

int codegen_function_definition(struct node *function_definition);
int codegen_function_declaration(struct node *function_declaration);

int codegen_function(struct node* function);
int codegen_statement(struct node* statement);
int codegen_declaration(struct node *declaration);
int codegen_if(struct node *if_statement);
int codegen_while(struct node *while_statement);
int codegen_return(struct node *return_statement);

int codegen_expression(struct node *expression);
int codegen_function_call(struct node *function_call);
int codegen_assignment(struct node *assignment);


#endif 