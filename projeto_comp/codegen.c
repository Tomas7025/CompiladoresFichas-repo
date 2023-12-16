#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"
#include "codegen.h"

int temporary = 1;   // sequence of temporary registers in a function
// int label_counter = 1;  // sequence of labels in all functions

extern struct symbol_list *global_scope;

int number_len(int number) {
	if (number == 0) return 1;
	int cont = 0;
	while(number != 0){
		cont++;
		number /= 10;
	}
	return cont;
}

char* type_to_llvm(enum type tipo){
	switch(tipo){ // MADE BY AMILCARS E JOHNS
		case char_type: 
		case short_type: 
		case integer_type: 
			return "i32";
		case double_type: 
			return "double";
		case void_type: 
			return "void";
		default:
			return "error";
	}
}

int codegen_global_vars(struct symbol_list *global_scope) {
	struct symbol_list *global_cur = global_scope;

	printf("\n");
	while ((global_cur = global_cur->next) != NULL) {
		if (global_cur->node->category == Declaration) {
			global_cur->node->llvm_name = (char*)malloc(sizeof(char)*(strlen(getchild(global_cur->node, 1)->token)+2));
			sprintf(global_cur->node->llvm_name, "@%s", getchild(global_cur->node, 1)->token);
			printf("%s = global %s %s\n", global_cur->node->llvm_name, type_to_llvm(map_cat_typ(getchild(global_cur->node, 0)->category)), (getchild(global_cur->node, 0)->category == Double) ? "0.0" : "0");
		
		}
	}
	printf("\ndefine void @global_vars_init() {\n");
	global_cur = global_scope;
	int temp = -1;
	while ((global_cur = global_cur->next) != NULL) {
		if (global_cur->node->category == Declaration && countchildren(global_cur->node) ==3) {
			temp = codegen_expression(getchild(global_cur->node, 2), global_scope, 1);
			if ((map_cat_typ(getchild(global_cur->node, 0)->category) == double_type) && (getchild(global_cur->node, 2)->type != double_type)){
				printf("	%%%d = sitofp i32 %%%d to double\n", temporary, temp);
				temp = temporary;
				temporary++;
			}
			printf("	store %s %%%d, %s* %s\n", type_to_llvm(map_cat_typ(getchild(global_cur->node, 0)->category)), temp, type_to_llvm(map_cat_typ(getchild(global_cur->node, 0)->category)), global_cur->node->llvm_name);
		}
	}
	printf("	ret void\n}\n\n");
	// printf('declare i32 @printf(i8*, ...)\n@.doubleprint = private unnamed_addr constant [4 x i8] c"%f\0A\00"\n@.intprint = private unnamed_addr constant [4 x i8] c"%d\0A\00"\n\n');
	return 0;
}

// code generation begins here, with the AST root node
void codegen_program(struct node *program) {
	// pre-declared I/O functions
	printf("declare i32 @read(i32)\n");
	printf("declare i32 @write(i32)\n");
	printf("declare i32 @putchar(i32)\n");
	printf("declare i32 @getchar()\n");


	// printf("declare i32 @set(i32, i32)\n");
	// printf("declare i32 @get(i32)\n\n");

	codegen_global_vars(global_scope);
	
	// generate code for each function
	struct node_list *function = program->children;
	while((function = function->next) != NULL) {
		switch (function->node->category) {
			case FuncDeclaration:
				// codegen_function_declaration(function->node);
				break;

			case FuncDefinition:
				codegen_function_definition(function->node);
				break;
			
			case Declaration:
				break;

			default:
				printf("This shouldn't happen ://\n");
				break;
		}
	}
// r < ../../
	// generate the entry point which calls main(integer) if it exists
	struct symbol_list *entry = search_symbol(global_scope, "main");
	if(entry != NULL && entry->node->category == FuncDefinition)
	printf("define i32 @main() {\n"
			"	 call void @global_vars_init()\n"
			"	 call i32 @_main()\n"
			"	 ret i32 0\n"
			"}\n"
		  );
}

int codegen_parameters(struct node* param_list, int is_def) {
	enum type param_type;
	struct node_list* cursor = param_list->children;
	while ((cursor = cursor->next) != NULL) {
		param_type = map_cat_typ(getchild(cursor->node, 0)->category);
		if (param_type != void_type) {
			printf("%s", type_to_llvm(param_type));
			if(is_def && getchild(cursor->node, 1)->token) {
				printf(" %%%s", getchild(cursor->node, 1)->token);
				cursor->node->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary-1)+2));
				sprintf(cursor->node->llvm_name, "%%%s", getchild(cursor->node, 1)->token);
			}
			if (cursor->next)
				printf(", ");
		}
	}

	return 0;
}

int codegen_function_declaration(struct node *function_declaration) {
	if (strcmp(getchild(function_declaration, 1)->token, "main") != 0)
		printf("declare %s @%s(", type_to_llvm(map_cat_typ(getchild(function_declaration, 0)->category)), getchild(function_declaration, 1)->token);
	else {
		printf("declare %s @%s(", type_to_llvm(map_cat_typ(getchild(function_declaration, 0)->category)), getchild(function_declaration, 1)->token);
	}
	codegen_parameters(getchild(function_declaration, 2), 0);
	printf(")\n\n");
	return 0;
}

int codegen_function_definition(struct node *function) {
	struct node_list *args_cursor = getchild(function, 2)->children;
	temporary = 1;
	if (strcmp(getchild(function, 1)->token, "main") != 0)
		printf("define %s @%s(", type_to_llvm(map_cat_typ(getchild(function, 0)->category)), getchild(function, 1)->token);
	else
		printf("define %s @_%s(", type_to_llvm(map_cat_typ(getchild(function, 0)->category)), getchild(function, 1)->token);
	codegen_parameters(getchild(function, 2), 1);
	printf(") {\n");
	

	if (getchild(args_cursor->next->node, 0)->category != Void) {
		while ((args_cursor = args_cursor->next)) {
			printf("	%%%d = alloca %s\n", temporary++, (getchild(args_cursor->node, 0)->category == Double ? "double" : "i32"));
			printf("	store %s %s, %s* %%%d\n", type_to_llvm(map_cat_typ(getchild(args_cursor->node, 0)->category)), args_cursor->node->llvm_name, type_to_llvm(map_cat_typ(getchild(args_cursor->node, 0)->category)), temporary-1);
			free(args_cursor->node->llvm_name);
			args_cursor->node->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary-1)+2));
			sprintf(args_cursor->node->llvm_name, "%%%d", temporary-1);
		}
	}


	struct symbol_list* scope = search_symbol(global_scope, getchild(function, 1)->token)->scope;
	codegen_function(getchild(function, 3), scope, 1); 

	if (map_cat_typ(getchild(function, 0)->category) != void_type)
		printf("	ret %s %s\n", type_to_llvm(map_cat_typ(getchild(function, 0)->category)), (getchild(function, 0)->category == Double) ? "0.0" : "0");
	else
		printf("	ret void\n");

	printf("}\n\n");

	return 0;  
}

int codegen_function(struct node* function_body, struct symbol_list* scope, int print_flag) {
	struct node_list* cursor = function_body->children;

	while ((cursor = cursor->next) != NULL) {
		codegen_statement(cursor->node, scope, print_flag); 
	}
	return 0;
}

int codegen_statement(struct node* statement, struct symbol_list* scope, int print_flag) {
	struct node* temp;
	int checkpoint, else_label, end_label;
	int start_label, while_init, while_final;

	
	switch (statement->category) {
		case StatList:
			codegen_function(statement, scope, print_flag); 
			break; 

		case If:
			// codegen_if(statement, scope);
			codegen_expression(getchild(statement, 0), scope, print_flag);
			if (print_flag)
				printf("	%%%d = icmp ne i32 %%%d, 0\n", temporary, temporary-1);
			temporary++;

			if (print_flag)
				printf("	br i1 %%%d, label %%%d, label ", temporary-1, temporary);
			temporary++;

			checkpoint = temporary;

			else_label = codegen_statement(getchild(statement, 1), scope, 0);	// print off
			temporary++;

			end_label = codegen_statement(getchild(statement, 2), scope, 0); 	// print off
			// Nao se incrementa pq vai-se voltar pro checkpoint e vai

			temporary = checkpoint;

			if (print_flag) printf("%%%d\n", else_label);

			// Then block
			if (print_flag) printf("%d:\n", checkpoint-1);
			codegen_statement(getchild(statement, 1), scope, print_flag);
			if (print_flag) printf("	br label %%%d\n", end_label);

			// Else block
			if (print_flag) printf("%d:\n", else_label);
			temporary++;
			codegen_statement(getchild(statement, 2), scope, print_flag);
			if (print_flag) printf("	br label %%%d\n", end_label);

			// End block
			if (print_flag) printf("%d:\n", end_label);
			temporary++;
			break;

		case While:

			start_label = temporary++;
			codegen_expression(getchild(statement, 0), scope, 0);
			// %x = icmp ne i32 %0, 0
			temporary++;
			// WHILE_INIT
			while_init = temporary;
			temporary++;
			codegen_statement(getchild(statement, 1), scope, 0);
			while_final = temporary++;

			if (print_flag) {
				temporary = start_label;
				printf("	br label %%%d\n", start_label);			
				printf("%d:\n", start_label);
				temporary++;
				codegen_expression(getchild(statement, 0), scope, print_flag);
				printf("	%%%d = icmp ne i32 %%%d, 0\n", temporary, temporary-1);
				temporary++;
				printf("	br i1 %%%d, label %%%d, label %%%d\n", temporary-1, while_init, while_final);
				printf("%d:\n", while_init);
				temporary++;
				codegen_statement(getchild(statement, 1), scope, print_flag);
				printf("	br label %%%d\n", start_label);
				printf("%d:\n", while_final);
				temporary++;
			}

			break;

		case Return:
			// codegen_return(statement, scope);
			if (getchild(statement, 0)->type != void_type && getchild(statement, 0)->category != Null) {
				codegen_expression(getchild(statement, 0), scope, print_flag);
				
				if (print_flag)
					printf("	ret %s %%%d\n", type_to_llvm(getchild(statement, 0)->type), temporary-1);
			}
			else
				if (print_flag) printf("	ret void\n");
			
			temporary++;	//!!!
			break;

		case Declaration:
			temp = getchild(statement, 0);
			
			if (print_flag) 
				printf("	%%%d = alloca %s\n", temporary++, (temp->category == Double ? "double" : "i32"));
			statement->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary-1)+2));
			sprintf(statement->llvm_name, "%%%d", temporary-1);
			
			if (countchildren(statement) == 3) {
				codegen_expression(getchild(statement, 2), scope, print_flag);
				
				if (print_flag) 
					printf("	store %s %%%d, %s* %s\n", (temp->category == Double ? "double" : "i32"), temporary-1, (temp->category == Double ? "double" : "i32"), statement->llvm_name);
			}
			break;

		default:
			codegen_expression(statement, scope, print_flag); 
			break;
	}
	return temporary;
}
/*  -> 0 - no cast
	-> > 0 cast right side
	-> < 0 cast left side
*/
int cast2double(struct node* expression, int op1, int op2) {
	int count = 0;
	if (getchild(expression, 0)->type == double_type || getchild(expression, 1)->type == double_type) {
		if (getchild(expression, 0)->type != double_type){
			printf("	%%%d = sitofp i32 %%%d to double\n", temporary++, op1);
			count--;
		}

		if (getchild(expression, 1)->type != double_type){
			printf("	%%%d = sitofp i32 %%%d to double\n", temporary++, op2);
			count++;
		}
	}
	return count;
}

int chrlit2int(char *str) {
	int conversion;
	if (*(str + 1) != '\\') 
		return *(str + 1);

	else {
		switch (*(str + 2)) {
			case 'n':
				return 10;
			case 't':
				return 9;
			case '\\':
			case '\'':
			case '\"':
				return *(str + 2);
			default:
				sscanf((str + 2), "%3o", &conversion);
				return conversion;
		}
	}
	return -1;
}

int octal2int(char *str) {
	int conversion;
	if (*(str) == '0') {
		sscanf(str, "%o", &conversion);
		return conversion;
	}

	return -1;
}

int codegen_expression(struct node *expression, struct symbol_list* scope, int print_flag) {
	int op1 = -1, op2 = -1, aux;
	enum type op1_type;				//, op2_type;
	struct node* op1_node;			//, *op2_node;
	struct symbol_list *found;
	struct node_list* temp_node_list, *temp_node_list2;

	// !!!
	int right_side, checkpoint;
	
	switch (expression->category) {
		case ChrLit:
			if (print_flag){
				printf("	%%%d = add i32 %d, 0\n", temporary, chrlit2int(expression->token));
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			}
			return temporary++;
		case Natural:
		case Short:
			if (print_flag) {
				if (*(expression->token) == '0')
					printf("	%%%d = add i32 %d, 0\n", temporary, octal2int(expression->token));

				else
					printf("	%%%d = add i32 %s, 0\n", temporary, expression->token);

				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			}
			return temporary++;

		case Decimal:
			if (print_flag) {
				if (*(expression->token) == '.')
					printf("	%%%d = fadd double 0%s, 0.0\n", temporary, expression->token);
				else
					printf("	%%%d = fadd double %s, 0.0\n", temporary, expression->token);
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			}
			return temporary++;

		case Add:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag);
			op2 = codegen_expression(getchild(expression, 1), scope, print_flag);
			aux = cast2double(expression, op1, op2);
			if (print_flag) {
				if (aux)
					printf("	%%%d = fadd double %%%d, %%%d\n", temporary, temporary-1, (aux < 0) ? op2 : op1);
				else
					printf("	%%%d = add %s %%%d, %%%d\n", temporary, type_to_llvm(getchild(expression, 0)->type), op1, op2);
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			}
			return temporary++;

		case Sub:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag);
			op2 = codegen_expression(getchild(expression, 1), scope, print_flag);
			aux = cast2double(expression, op1, op2);
			if (print_flag) {
				op1_type = getchild(expression, 0)->type;
				// op2_type = getchild(expression, 1)->type;
				
				if (aux)
					printf("	%%%d = fsub double %%%d, %%%d\n", temporary, (aux > 0) ? op1 : temporary-1, (aux < 0) ? op2 : temporary-1);
				else
					printf("	%%%d = %s %s %%%d, %%%d\n", temporary, (op1_type == double_type ? "fsub" : "sub"), type_to_llvm(op1_type), op1, op2);
				
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			}
			return temporary++;

		case Mul:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag);
			op2 = codegen_expression(getchild(expression, 1), scope, print_flag);
			aux = cast2double(expression, op1, op2);
			if (print_flag) {
				if (aux)
					printf("	%%%d = fmul double %%%d, %%%d\n", temporary, temporary-1, (aux < 0) ? op2 : op1);
				else
					printf("	%%%d = %s %s %%%d, %%%d\n", temporary, (getchild(expression, 0)->type == double_type ? "fmul" : "mul"), type_to_llvm(getchild(expression, 0)->type), op1, op2);
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			}
			return temporary++;

		case Div:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag);
			op2 = codegen_expression(getchild(expression, 1), scope, print_flag);
			aux = cast2double(expression, op1, op2);
			if (print_flag) {
				op1_type = getchild(expression, 0)->type;
				// op2_type = getchild(expression, 1)->type;
	
				if (aux)
					printf("	%%%d = fdiv double %%%d, %%%d\n", temporary, (aux > 0) ? op1 : temporary-1, (aux < 0) ? op2 : temporary-1 );
				else
					printf("	%%%d = %s %s %%%d, %%%d\n", temporary, (op1_type == double_type ? "fdiv" : "sdiv"), type_to_llvm(op1_type), op1, op2);
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			}
			return temporary++;
		
		case Mod:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag);
			op2 = codegen_expression(getchild(expression, 1), scope, print_flag);
			aux = cast2double(expression, op1, op2);
			if (print_flag){
				op1_type = getchild(expression, 0)->type;
				// op2_type = getchild(expression, 1)->type;

				if (aux)
					printf("	%%%d = frem double %%%d, %%%d\n", temporary, (aux > 0) ? op1 : temporary-1, (aux < 0) ? op2 : temporary-1 );
				else
					printf("	%%%d = %s %s %%%d, %%%d\n", temporary, (op1_type == double_type ? "frem" : "srem"), type_to_llvm(op1_type), op1, op2);
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			}
			return temporary++;
		
		case Or:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag);
			if (print_flag) {
				printf("	%%%d = alloca i32\n", temporary);
				right_side = temporary++;
				printf("	store i32 0, i32* %%%d\n", temporary-1);
				printf("	%%%d = icmp eq i32 %%%d, 0\n", temporary++, op1);
				printf("	br i1 %%%d, label %%%d, label ", temporary-1, temporary);
			} else temporary += 2;

			temporary++;

			checkpoint = temporary;

			op2 = codegen_expression(getchild(expression, 1), scope, 0);
			if (print_flag) {
				printf("%%%d\n", op2+3);
				printf("%d:\n", op1+3);
			}

			temporary = checkpoint;
			op2 = codegen_expression(getchild(expression, 1), scope, print_flag);

			if (print_flag) {
				printf("	%%%d = icmp ne i32 %%%d, 0\n", temporary++, op2);
				printf("	%%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
			} else temporary++;

			temporary++;
			
			if (print_flag) {
				printf("	store i32 %%%d, i32* %%%d\n", temporary-1, right_side);
				printf("	br label %%%d\n", op2+3);
				printf("%d:\n", op2+3);
			}
			temporary++;

			if (print_flag) {
				printf("	%%%d = load i32, i32* %%%d\n", temporary++, right_side);
				printf("	%%%d = or i32 %%%d, %%%d\n", temporary, op1, temporary-1);
			} else temporary++;
			
			temporary++;

			if (print_flag) {
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary-1);
			}

			return temporary-1;

			// op1 = codegen_expression(getchild(expression, 0), scope, print_flag);
			// op2 = codegen_expression(getchild(expression, 1), scope, print_flag);

			// if (print_flag){
			// 	printf("	%%%d = icmp ne i32 %%%d, 0\n", temporary++, op1);           // temporary-2
			// 	printf("	%%%d = icmp ne i32 %%%d, 0\n", temporary++, op2);           // temporary-1

			// 	printf("	%%%d = or i1 %%%d, %%%d\n", temporary, temporary-2, temporary-1);
			// 	temporary++;
			// 	printf("	%%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
			// 	expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
			// 	sprintf(expression->llvm_name, "%%%d", temporary);
			// } else temporary+=3;
			// return temporary++;

		case And:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag);
			if (print_flag) {printf("	%%%d = alloca i32\n", temporary);
				right_side = temporary++;
				printf("	store i32 1, i32* %%%d\n", temporary-1);
				printf("	%%%d = icmp ne i32 %%%d, 0\n", temporary++, op1);
				printf("	br i1 %%%d, label %%%d, label ", temporary-1, temporary);
			} else temporary += 2;

			temporary++;

			checkpoint = temporary;

			op2 = codegen_expression(getchild(expression, 1), scope, 0);
			if (print_flag) {
				printf("%%%d\n", op2+3);
				printf("%d:\n", op1+3);
			}

			temporary = checkpoint;
			op2 = codegen_expression(getchild(expression, 1), scope, print_flag);

			if (print_flag) {
				printf("	%%%d = icmp ne i32 %%%d, 0\n", temporary++, op2);
				printf("	%%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
			} else temporary++;

			temporary++;
			
			if (print_flag) {
				printf("	store i32 %%%d, i32* %%%d\n", temporary-1, right_side);
				printf("	br label %%%d\n", op2+3);
				printf("%d:\n", op2+3);
			}
			temporary++;

			if (print_flag) {
				printf("	%%%d = load i32, i32* %%%d\n", temporary++, right_side);
				printf("	%%%d = and i32 %%%d, %%%d\n", temporary, op1, temporary-1);
			} else temporary++;

			temporary++;

			if (print_flag) {
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary-1);
			}

			return temporary-1;


		case BitWiseAnd:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag);
			op2 = codegen_expression(getchild(expression, 1), scope, print_flag);
			
			if (print_flag){
				printf("	%%%d = and i32 %%%d, %%%d\n", temporary, op1, op2);
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			}
			return temporary++;

		case BitWiseOr:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag);
			op2 = codegen_expression(getchild(expression, 1), scope, print_flag);

			if (print_flag) {
				printf("	%%%d = or i32 %%%d, %%%d\n", temporary, op1, op2);
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			}
			return temporary++;
		
		case BitWiseXor:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag);
			op2 = codegen_expression(getchild(expression, 1), scope, print_flag);
			
			if (print_flag){
				printf("	%%%d = xor i32 %%%d, %%%d\n", temporary, op1, op2);
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			}
			return temporary++;

		case Eq:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag);
			op2 = codegen_expression(getchild(expression, 1), scope, print_flag);
			op1_type = getchild(expression, 0)->type;
			aux = cast2double(expression, op1, op2);
			
			if (print_flag) {
				if (aux)                                              // o que levou cast, o que nao levou 
					printf("	%%%d = fcmp oeq double %%%d, %%%d\n", temporary, temporary-1, (aux < 0) ? op2 : op1);
				else if (op1_type == double_type)
					printf("	%%%d = fcmp oeq %s %%%d, %%%d\n", temporary, type_to_llvm(getchild(expression, 0)->type), temporary-1, (aux < 0) ? op2 : op1);
				else
					printf("	%%%d = icmp eq %s %%%d, %%%d\n", temporary, type_to_llvm(getchild(expression, 0)->type), temporary-1, (aux < 0) ? op2 : op1);


				// printf("	%%%d = %s %s %s %%%d, %%%d\n", temporary, (op1_type == double_type ? "fcmp" : "icmp"), (op1_type == double_type ? "oeq" : "eq"), type_to_llvm(getchild(expression, 0)->type), temporary-1, (aux < 0) ? op2 : op1);
				
				temporary++;
				printf("	%%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			} else temporary++;

			return temporary++;
		
		case Ne:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag);
			op2 = codegen_expression(getchild(expression, 1), scope, print_flag);
			op1_type = getchild(expression, 0)->type;
			aux = cast2double(expression, op1, op2);

			if (print_flag){
				if (aux)                                              // o que levou cast, o que nao levou 
					printf("	%%%d = fcmp one double %%%d, %%%d\n", temporary, temporary-1, (aux < 0) ? op2 : op1);
				
				else if (op1_type == double_type)
					printf("	%%%d = fcmp one %s %%%d, %%%d\n", temporary, type_to_llvm(getchild(expression, 0)->type), temporary-1, (aux < 0) ? op2 : op1);
				else
					printf("	%%%d = icmp ne %s %%%d, %%%d\n", temporary, type_to_llvm(getchild(expression, 0)->type), temporary-1, (aux < 0) ? op2 : op1);

				temporary++;
				printf("	%%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			} else temporary++;
			return temporary++;
		
		case Le:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag);
			op2 = codegen_expression(getchild(expression, 1), scope, print_flag);
			op1_type = getchild(expression, 0)->type;
			aux = cast2double(expression, op1, op2);

			if (print_flag) { 
				if (aux)                                              // o que levou cast, o que nao levou 
					printf("	%%%d = fcmp ole double %%%d, %%%d\n", temporary, (aux > 0) ? op1 : temporary-1, (aux < 0) ? op2 : temporary-1 );
				
				else if (op1_type == double_type)
					printf("	%%%d = fcmp ole %s %%%d, %%%d\n", temporary, type_to_llvm(getchild(expression, 0)->type), op1, op2);
				else
					printf("	%%%d = icmp sle %s %%%d, %%%d\n", temporary, type_to_llvm(getchild(expression, 0)->type), op1, op2);

				temporary++;
				printf("	%%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			} else temporary++;

			return temporary++;
		
		case Ge:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag);
			op2 = codegen_expression(getchild(expression, 1), scope, print_flag);
			op1_type = getchild(expression, 0)->type;
			aux = cast2double(expression, op1, op2);

			if (print_flag){
				if (aux)                                              // o que levou cast, o que nao levou 
					printf("	%%%d = fcmp oge double %%%d, %%%d\n", temporary, (aux > 0) ? op1 : temporary-1, (aux < 0) ? op2 : temporary-1 );
				
				else if (op1_type == double_type)
					printf("	%%%d = fcmp oge %s %%%d, %%%d\n", temporary, type_to_llvm(getchild(expression, 0)->type), op1, op2);
				else
					printf("	%%%d = icmp sge %s %%%d, %%%d\n", temporary, type_to_llvm(getchild(expression, 0)->type), op1, op2);

				temporary++;
				printf("	%%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			} else temporary++;
			return temporary++;

		case Lt:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag);
			op2 = codegen_expression(getchild(expression, 1), scope, print_flag);
			op1_type = getchild(expression, 0)->type;
			aux = cast2double(expression, op1, op2);

			if (print_flag) {
				if (aux)                                              // o que levou cast, o que nao levou 
					printf("	%%%d = fcmp olt double %%%d, %%%d\n", temporary, (aux > 0) ? op1 : temporary-1, (aux < 0) ? op2 : temporary-1 );
				
				else if (op1_type == double_type)
					printf("	%%%d = fcmp olt %s %%%d, %%%d\n", temporary, type_to_llvm(getchild(expression, 0)->type), op1, op2);
				else
					printf("	%%%d = icmp slt %s %%%d, %%%d\n", temporary, type_to_llvm(getchild(expression, 0)->type), op1, op2);

				temporary++;
				printf("	%%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			} else temporary++;

			return temporary++;
		
		case Gt:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag);
			op2 = codegen_expression(getchild(expression, 1), scope, print_flag);
			op1_type = getchild(expression, 0)->type;
			aux = cast2double(expression, op1, op2);
			if (print_flag){
				// Houve cast
				if (aux)                                              // o que levou cast, o que nao levou 
					printf("	%%%d = fcmp ogt double %%%d, %%%d\n", temporary, (aux > 0) ? op1 : temporary-1, (aux < 0) ? op2 : temporary-1 );
				
				// Nao houve cast
				else if (op1_type == double_type)
					printf("	%%%d = fcmp ogt %s %%%d, %%%d\n", temporary, type_to_llvm(getchild(expression, 0)->type), op1, op2);
				else
					printf("	%%%d = icmp sgt %s %%%d, %%%d\n", temporary, type_to_llvm(getchild(expression, 0)->type), op1, op2);

				temporary++;
				printf("	%%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			} else temporary++;

			return temporary++;


		case Plus:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag);
			if (print_flag){
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(op1)+2));
				sprintf(expression->llvm_name, "%%%d", op1);
			}
			return op1;

		case Minus:
			op1_node = getchild(expression, 0);

			op1 = codegen_expression(op1_node, scope, print_flag);

			if (print_flag) {
				printf("	%%%d = %s %s %s, %%%d\n", temporary, (op1_node->type == double_type ? "fsub" : "sub"), type_to_llvm(op1_node->type), (op1_node->type == double_type ? "0.0" : "0"), op1);
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			}
			return temporary++;
		
		case Not:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag);

			if (print_flag) {
				printf("	%%%d = icmp eq i32 %%%d, 0\n", temporary++, op1);
				printf("	%%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			} else temporary++;
			
			return temporary++;

		case Identifier:
			if (print_flag) {	
				if((found = search_symbol(scope, expression->token)))
					printf("	%%%d = load %s, %s* %s\n", temporary, type_to_llvm(expression->type), type_to_llvm(expression->type), found->node->llvm_name);
				else 
					printf("	%%%d = load %s, %s* %s\n", temporary, type_to_llvm(expression->type), type_to_llvm(expression->type), search_symbol(global_scope, expression->token)->node->llvm_name);
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
				sprintf(expression->llvm_name, "%%%d", temporary);
			}
			return temporary++;
		
		case Store:
			op2 = codegen_expression(getchild(expression, 1), scope, print_flag);
			//cast to double
			if (getchild(expression, 1)->type != double_type && getchild(expression, 0)->type == double_type) {
				if (print_flag)
					printf("	%%%d = sitofp i32 %%%d to double\n", temporary, op2);

				op2 = temporary;
				temporary++;
			}
			
			if (print_flag) {
				if((found = search_symbol(scope, getchild(expression, 0)->token))) // store i32 %10, i32* %1
					printf("	store %s %%%d, %s* %s\n", type_to_llvm(expression->type), op2, type_to_llvm(expression->type), found->node->llvm_name);
				else 
					printf("	store %s %%%d, %s* %s\n", type_to_llvm(expression->type), op2, type_to_llvm(expression->type), search_symbol(global_scope, getchild(expression, 0)->token)->node->llvm_name);
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(op2)+2));
				sprintf(expression->llvm_name, "%%%d", op2);
			}
			return temporary-1;
		
		case Comma:
			op1 = codegen_expression(getchild(expression, 0), scope, print_flag); // 1+1, a = 1;
			op2 = codegen_expression(getchild(expression, 1), scope, print_flag);
			if (print_flag) {
				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(op2)+2));
				sprintf(expression->llvm_name, "%%%d", op2);
			}
			return temporary-1;
		
		case Call:
			temp_node_list = expression->children->next->next;
			temp_node_list2 = getchild(search_symbol(global_scope, getchild(expression, 0)->token)->node, 2)->children->next;

			for (;temp_node_list != NULL && temp_node_list2 != NULL ; temp_node_list = temp_node_list->next, temp_node_list2 = temp_node_list2->next ) {
				codegen_expression(temp_node_list->node, scope, print_flag);
				if (map_cat_typ(getchild(temp_node_list2->node, 0)->category) == double_type && temp_node_list->node->type != double_type) {
					if (print_flag){
					printf("	%%%d = sitofp i32 %%%d to double\n", temporary, temporary-1);
					free(temp_node_list->node->llvm_name);
					temp_node_list->node->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
					sprintf(temp_node_list->node->llvm_name, "%%%d", temporary);
					}
					temporary++;
				}
			}
			op1_node = search_symbol(global_scope, getchild(expression, 0)->token)->node;
			temp_node_list = expression->children->next->next;
			temp_node_list2 = getchild(search_symbol(global_scope, getchild(expression, 0)->token)->node, 2)->children->next;
			if (print_flag) {
				if (getchild(op1_node, 0)->category != Void)
					printf("	%%%d = call %s @%s(", temporary++, type_to_llvm(map_cat_typ(getchild(op1_node, 0)->category)),  getchild(op1_node, 1)->token);
				else
					printf("	call %s @%s(", type_to_llvm(map_cat_typ(getchild(op1_node, 0)->category)),  getchild(op1_node, 1)->token);

				for (;temp_node_list != NULL && temp_node_list2 != NULL ; temp_node_list = temp_node_list->next, temp_node_list2 = temp_node_list2->next ) {
					printf("%s %s", type_to_llvm(map_cat_typ(getchild(temp_node_list2->node, 0)->category)), temp_node_list->node->llvm_name);
					if (temp_node_list->next != NULL)
						printf(", ");
				}
				printf(")\n");

				expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary-1)+2));
				sprintf(expression->llvm_name, "%%%d", temporary-1);

			} else if (getchild(op1_node, 0)->category != Void) temporary++;

			return temporary-1;
			
		default:
			return temporary;
	}
	
	return -1;
}

// void print() {
//     print("call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), double %%4)", )
// }