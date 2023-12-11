#ifndef _CODEGEN_H
#define _CODEGEN_H

#include "ast.h"
#include "semantics.h"

void codegen_program(struct node *program);

int codegen_global_vars(struct symbol_list *global_scope);

int codegen_function_definition(struct node *function_definition);
int codegen_function_declaration(struct node *function_declaration);

int codegen_parameters(struct node* param_list, int is_def);
int codegen_function(struct node* function_body, struct symbol_list* scope);
int codegen_statement(struct node* statement, struct symbol_list* scope);
int codegen_declaration(struct node *declaration, struct symbol_list* scope);
int codegen_if(struct node *if_statement, struct symbol_list* scope);
int codegen_while(struct node *while_statement, struct symbol_list* scope);
int codegen_return(struct node *return_statement, struct symbol_list* scope);

int codegen_expression(struct node *expression, struct symbol_list* scope);
int codegen_function_call(struct node *function_call, struct symbol_list* scope);
int codegen_assignment(struct node *assignment, struct symbol_list* scope);

int cast2double(struct node* expression, int op1, int op2);
int number_len(int number);

#endif 