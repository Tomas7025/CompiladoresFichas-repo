#ifndef _CODEGEN_H
#define _CODEGEN_H

#include "ast.h"
#include "semantics.h"

int codegen_function_declaration(struct node *function_declaration);

void codegen_program(struct node *program);

int codegen_global_vars(struct symbol_list *global_scope);
int codegen_function_definition(struct node *function_definition);
int codegen_parameters(struct node* param_list, int is_def);
int codegen_function(struct node* function_body, struct symbol_list* scope, int print_flag);
int codegen_statement(struct node* statement, struct symbol_list* scope, int print_flag);
int codegen_expression(struct node *expression, struct symbol_list* scope, int print_flag);



int cast2double(struct node* expression, int op1, int op2, int print_flag);
int number_len(int number);

#endif 