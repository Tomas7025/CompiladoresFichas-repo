#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"
#include "codegen.h"

int temporary = 1;   // sequence of temporary registers in a function

extern struct symbol_list *global_scope;

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
    printf("\ndefine void @_global_vars_init() {\n");
    global_cur = global_scope;
    int temp = -1;
    while ((global_cur = global_cur->next) != NULL) {
        if (global_cur->node->category == Declaration && countchildren(global_cur->node) ==3) {
            temp = codegen_expression(getchild(global_cur->node, 2));
            if ((map_cat_typ(getchild(global_cur->node, 0)->category) == double_type) && (getchild(global_cur->node, 2)->type != double_type)){
                printf("  %%%d = sitofp i32 %%%d to double\n", temporary, temp);
                temp = temporary;
                temporary++;
            }
            printf("  store %s %%%d, %s* %s\n", type_to_llvm(map_cat_typ(getchild(global_cur->node, 0)->category)), temp, type_to_llvm(map_cat_typ(getchild(global_cur->node, 0)->category)), global_cur->node->llvm_name);
        }
    }
    printf("  ret void\n}\n\n");
    return 0;
}

// code generation begins here, with the AST root node
void codegen_program(struct node *program) {
    // pre-declared I/O functions
    printf("declare i32 @_read(i32)\n");
    printf("declare i32 @_write(i32)\n");
    // printf("declare i32 @_set(i32, i32)\n");
    // printf("declare i32 @_get(i32)\n\n");

    codegen_global_vars(global_scope);
    //printf("call void @_global_vars_init()\n");

    // generate code for each function
    struct node_list *function = program->children;
    while((function = function->next) != NULL) {
        switch (function->node->category) {
            case FuncDeclaration:
                codegen_function_declaration(function->node);
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

    // generate the entry point which calls main(integer) if it exists
    struct symbol_list *entry = search_symbol(global_scope, "main");
    if(entry != NULL && entry->node->category == FuncDefinition)
    printf("define i32 @main() {\n"
            "   call void @_global_vars_init()\n"
            "   %%1 = call i32 @_main(i32 0)\n"
            "   ret i32 %%1\n"
            "}\n"
          );
}

int codegen_parameters(struct node* param_list, int is_def){
    enum type param_type;
    struct node_list* cursor = param_list->children;
    while ((cursor = cursor->next) != NULL) {
        param_type = map_cat_typ(getchild(cursor->node, 0)->category);
        if (param_type != void_type) {    
            printf("%s", type_to_llvm(param_type));
            if(is_def && cursor->node->token)
                printf(" %s", cursor->node->token);
            if (cursor->next)
                printf(", ");
        }
    }

    return 0;
}



int codegen_function_declaration(struct node *function_declaration) {
    printf("declare %s @_%s(", type_to_llvm(map_cat_typ(getchild(function_declaration, 0)->category)), getchild(function_declaration, 1)->token);
    codegen_parameters(getchild(function_declaration, 2), 0);
    printf(")\n\n");
    return 0;
}

int codegen_function_definition(struct node *function) {
    temporary = 1;
    printf("define %s @_%s(", type_to_llvm(map_cat_typ(getchild(function, 0)->category)), getchild(function, 1)->token);
    codegen_parameters(getchild(function, 2), 1);
    printf(") {\n");
    
    // codegen_function(getchild(function, 3));

    if (map_cat_typ(getchild(function, 0)->category) != void_type)
        printf("  ret %s %%%d\n", type_to_llvm(map_cat_typ(getchild(function, 0)->category)), temporary++);
    else
        printf("  ret void\n");
    printf("}\n\n");

    return 0;  
}

int codegen_function(struct node* function_body) {
    struct node_list* cursor = function_body->children;

    while ((cursor = cursor->next) != NULL) {
        codegen_statement(cursor->node);
    }
    return 0;
}

int codegen_statement(struct node* statement) {
    switch (statement->category) {
            case StatList:
                // codegen_function(statement);
                break;
            case If:
                // codegen_if(statement);
                break;
            case While:
                // codegen_while(statement);
                break;
            case Return:
                // codegen_return(statement);
                break;
            default:
                codegen_expression(statement);
                break;
    }
    return 0;
}
/*  -> 0 - no cast
    -> > 0 cast right side
	-> < 0 cast left side
*/
int cast2double(struct node* expression, int op1, int op2) {
    int count = 0;
    if (getchild(expression, 0)->type == double_type || getchild(expression, 1)->type == double_type) {
        if (getchild(expression, 0)->type != double_type){
            printf("  %%%d = sitofp i32 %%%d to double\n", temporary++, op1);
            count--;
        }

        if (getchild(expression, 1)->type != double_type){
            printf("  %%%d = sitofp i32 %%%d to double\n", temporary++, op2);
            count++;
        }
    }
    return count;
}

int codegen_expression(struct node *expression) {
    int op1 = -1, op2 = -1, aux;
    enum type op1_type, op2_type;

    switch (expression->category) {
        case Natural:
        case ChrLit:
        case Short:
            printf("  %%%d = add i32 %s, 0\n", temporary, expression->token);
            return temporary++;
    
        case Decimal:
            printf("  %%%d = fadd double %s, 0.0\n", temporary, expression->token);
            return temporary++;
        
        case Add:
            op1 = codegen_expression(getchild(expression, 0));
            op2 = codegen_expression(getchild(expression, 1));
            aux = cast2double(expression, op1, op2);

			if (aux)
				printf("  %%%d = fadd double %%%d, %%%d\n", temporary, temporary-1, (aux < 0) ? op2 : op1);
            else
				printf("  %%%d = add %s %%%d, %%%d\n", temporary, type_to_llvm(getchild(expression, 0)->type), op1, op2);

            return temporary++;

        case Sub:
            op1 = codegen_expression(getchild(expression, 0));
            op2 = codegen_expression(getchild(expression, 1));
            aux = cast2double(expression, op1, op2);
            op1_type = getchild(expression, 0)->type;
            op2_type = getchild(expression, 1)->type;

			if (aux)
				printf("  %%%d = fsub double %%%d, %%%d\n", temporary, (aux > 0) ? op1 : temporary-1, (aux < 0) ? op2 : temporary-1 );
            else
				printf("  %%%d = %s %s %%%d, %%%d\n", temporary, (op1_type == double_type ? "fsub" : "sub"), type_to_llvm(op1_type), op1, op2);
			
			return temporary++;

        default:
            return temporary;
    }
    
    return -1;
}

