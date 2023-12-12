#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"
#include "codegen.h"

int temporary = 1;   // sequence of temporary registers in a function

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
    printf("\ndefine void @_global_vars_init() {\n");
    global_cur = global_scope;
    int temp = -1;
    while ((global_cur = global_cur->next) != NULL) {
        if (global_cur->node->category == Declaration && countchildren(global_cur->node) ==3) {
            temp = codegen_expression(getchild(global_cur->node, 2), global_scope);
            if ((map_cat_typ(getchild(global_cur->node, 0)->category) == double_type) && (getchild(global_cur->node, 2)->type != double_type)){
                printf("  %%%d = sitofp i32 %%%d to double\n", temporary, temp);
                temp = temporary;
                temporary++;
            }
            printf("  store %s %%%d, %s* %s\n", type_to_llvm(map_cat_typ(getchild(global_cur->node, 0)->category)), temp, type_to_llvm(map_cat_typ(getchild(global_cur->node, 0)->category)), global_cur->node->llvm_name);
        }
    }
    printf("  ret void\n}\n\n");
    // printf('declare i32 @printf(i8*, ...)\n@.doubleprint = private unnamed_addr constant [4 x i8] c"%f\0A\00"\n@.intprint = private unnamed_addr constant [4 x i8] c"%d\0A\00"\n\n');
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
            "   call i32 @_main()\n"
            "   ret i32 0\n"
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
                printf(" %%%s", cursor->node->token);
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
    printf("define %s @_%s(", type_to_llvm(map_cat_typ(getchild(function, 0)->category)), getchild(function, 1)->token);
    codegen_parameters(getchild(function, 2), 1);
    printf(") {\n");
    
    struct symbol_list* scope = search_symbol(global_scope, getchild(function, 1)->token)->scope;
    codegen_function(getchild(function, 3), scope); 

    if (map_cat_typ(getchild(function, 0)->category) != void_type)
        printf("  ret %s %s\n", type_to_llvm(map_cat_typ(getchild(function, 0)->category)), (getchild(function, 0)->category == Double) ? "0.0" : "0");
    else
        printf("  ret void\n");


    printf("}\n\n");

    return 0;  
}

int codegen_function(struct node* function_body, struct symbol_list* scope) {
    struct node_list* cursor = function_body->children;

    while ((cursor = cursor->next) != NULL) {
        codegen_statement(cursor->node, scope); 
    }
    return 0;
}

int codegen_statement(struct node* statement, struct symbol_list* scope) {
    struct node* temp;
    switch (statement->category) {
        case StatList:
            codegen_function(statement, scope); 
            break;
        case If:
            // codegen_if(statement, scope); 
            break;
        case While:
            // codegen_while(statement, scope); 
            break;
        case Return:
            // codegen_return(statement, scope);
            if (getchild(statement, 0)->type != void_type) {
                codegen_expression(getchild(statement, 0), scope);
                printf("  ret %s %s\n", type_to_llvm(getchild(statement, 0)->type), getchild(statement, 0)->llvm_name);
            }
            else
                printf("  ret void\n");
            break;

        case Declaration:
            temp = getchild(statement, 0);
            printf("  %%%d = alloca %s\n", temporary++, (temp->category == Double ? "double" : "i32"));
            statement->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary-1)+2));
            sprintf(statement->llvm_name, "%%%d", temporary-1);
            
            if (countchildren(statement) == 3) {
                codegen_expression(getchild(statement, 2), scope);
                printf("  store %s %%%d, %s* %s\n", (temp->category == Double ? "double" : "i32"), temporary-1, (temp->category == Double ? "double" : "i32"), statement->llvm_name);
            }
            break;
        default:
            codegen_expression(statement, scope); 
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

int codegen_expression(struct node *expression, struct symbol_list* scope) {
    int op1 = -1, op2 = -1, aux;
    enum type op1_type, op2_type;
    struct node* op1_node, *op2_node;
    struct symbol_list *found;
    struct node_list* temp_node_list, *temp_node_list2;
    
    switch (expression->category) {
        case Natural:
        case ChrLit:
        case Short:
            printf("  %%%d = add i32 %s, 0\n", temporary, expression->token);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
            return temporary++;

        case Decimal:
            printf("  %%%d = fadd double %s, 0.0\n", temporary, expression->token);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
            return temporary++;

        case Add:
            op1 = codegen_expression(getchild(expression, 0), scope);
            op2 = codegen_expression(getchild(expression, 1), scope);
            aux = cast2double(expression, op1, op2);

			if (aux)
				printf("  %%%d = fadd double %%%d, %%%d\n", temporary, temporary-1, (aux < 0) ? op2 : op1);
            else
				printf("  %%%d = add %s %%%d, %%%d\n", temporary, type_to_llvm(getchild(expression, 0)->type), op1, op2);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
            return temporary++;

        case Sub:
            op1 = codegen_expression(getchild(expression, 0), scope);
            op2 = codegen_expression(getchild(expression, 1), scope);
            aux = cast2double(expression, op1, op2);
            op1_type = getchild(expression, 0)->type;
            op2_type = getchild(expression, 1)->type;

			if (aux)
				printf("  %%%d = fsub double %%%d, %%%d\n", temporary, (aux > 0) ? op1 : temporary-1, (aux < 0) ? op2 : temporary-1 );
            else
				printf("  %%%d = %s %s %%%d, %%%d\n", temporary, (op1_type == double_type ? "fsub" : "sub"), type_to_llvm(op1_type), op1, op2);
			expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
			return temporary++;

        case Mul:
            op1 = codegen_expression(getchild(expression, 0), scope);
            op2 = codegen_expression(getchild(expression, 1), scope);
            aux = cast2double(expression, op1, op2);

			if (aux)
				printf("  %%%d = fmul double %%%d, %%%d\n", temporary, temporary-1, (aux < 0) ? op2 : op1);
            else
				printf("  %%%d = mul %s %%%d, %%%d\n", temporary, type_to_llvm(getchild(expression, 0)->type), op1, op2);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
            return temporary++;

        case Div:
            op1 = codegen_expression(getchild(expression, 0), scope);
            op2 = codegen_expression(getchild(expression, 1), scope);
            aux = cast2double(expression, op1, op2);
            op1_type = getchild(expression, 0)->type;
            op2_type = getchild(expression, 1)->type;

			if (aux)
				printf("  %%%d = fdiv double %%%d, %%%d\n", temporary, (aux > 0) ? op1 : temporary-1, (aux < 0) ? op2 : temporary-1 );
            else
				printf("  %%%d = %s %s %%%d, %%%d\n", temporary, (op1_type == double_type ? "fdiv" : "sdiv"), type_to_llvm(op1_type), op1, op2);
			expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
			return temporary++;
        
        case Mod:
            op1 = codegen_expression(getchild(expression, 0), scope);
            op2 = codegen_expression(getchild(expression, 1), scope);
            aux = cast2double(expression, op1, op2);
            op1_type = getchild(expression, 0)->type;
            op2_type = getchild(expression, 1)->type;

			if (aux)
				printf("  %%%d = frem double %%%d, %%%d\n", temporary, (aux > 0) ? op1 : temporary-1, (aux < 0) ? op2 : temporary-1 );
            else
				printf("  %%%d = %s %s %%%d, %%%d\n", temporary, (op1_type == double_type ? "frem" : "srem"), type_to_llvm(op1_type), op1, op2);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
			return temporary++;
        
        case Or:
            op1 = codegen_expression(getchild(expression, 0), scope);
            op2 = codegen_expression(getchild(expression, 1), scope);

            printf("  %%%d = icmp ne i32 %%%d, 0\n", temporary++, op1);           // temporary-2
            printf("  %%%d = icmp ne i32 %%%d, 0\n", temporary++, op2);           // temporary-1
            
            printf("  %%%d = or i1 %%%d, %%%d\n", temporary, temporary-2, temporary-1);
            temporary++;
            printf("  %%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
            return temporary++;

        case And:
            op1 = codegen_expression(getchild(expression, 0), scope);
            op2 = codegen_expression(getchild(expression, 1), scope);

            printf("  %%%d = icmp ne i32 %%%d, 0\n", temporary++, op1);           // temporary-2
            printf("  %%%d = icmp ne i32 %%%d, 0\n", temporary++, op2);           // temporary-1
            
            printf("  %%%d = and i1 %%%d, %%%d\n", temporary, temporary-2, temporary-1);
            temporary++;
            printf("  %%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
            return temporary++;

        case BitWiseAnd:
            op1 = codegen_expression(getchild(expression, 0), scope);
            op2 = codegen_expression(getchild(expression, 1), scope);

            printf("  %%%d = and i32 %%%d, %%%d\n", temporary, op1, op2);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
			return temporary++;

        case BitWiseOr:
            op1 = codegen_expression(getchild(expression, 0), scope);
            op2 = codegen_expression(getchild(expression, 1), scope);

            printf("  %%%d = or i32 %%%d, %%%d\n", temporary, op1, op2);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
			return temporary++;
        
        case BitWiseXor:
            op1 = codegen_expression(getchild(expression, 0), scope);
            op2 = codegen_expression(getchild(expression, 1), scope);

            printf("  %%%d = xor i32 %%%d, %%%d\n", temporary, op1, op2);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
			return temporary++;

        case Eq:
            op1 = codegen_expression(getchild(expression, 0), scope);
            op2 = codegen_expression(getchild(expression, 1), scope);
            op1_type = getchild(expression, 0)->type;
            aux = cast2double(expression, op1, op2);

			if (aux)                                              // o que levou cast, o que nao levou 
				printf("  %%%d = fcmp eq double %%%d, %%%d\n", temporary, temporary-1, (aux < 0) ? op2 : op1);
            else
				printf("  %%%d = %s eq %s %%%d, %%%d\n", temporary, (op1_type == double_type ? "fcmp" : "icmp"), type_to_llvm(getchild(expression, 0)->type), temporary-1, (aux < 0) ? op2 : op1);

            temporary++;
            printf("  %%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
            return temporary++;
        
        case Ne:
            op1 = codegen_expression(getchild(expression, 0), scope);
            op2 = codegen_expression(getchild(expression, 1), scope);
            op1_type = getchild(expression, 0)->type;
            aux = cast2double(expression, op1, op2);

			if (aux)                                              // o que levou cast, o que nao levou 
				printf("  %%%d = fcmp ne double %%%d, %%%d\n", temporary, temporary-1, (aux < 0) ? op2 : op1);
            else
				printf("  %%%d = %s ne %s %%%d, %%%d\n", temporary, (op1_type == double_type ? "fcmp" : "icmp"), type_to_llvm(getchild(expression, 0)->type), temporary-1, (aux < 0) ? op2 : op1);

            temporary++;
            printf("  %%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
            return temporary++;
        
        case Le:
            op1 = codegen_expression(getchild(expression, 0), scope);
            op2 = codegen_expression(getchild(expression, 1), scope);
            op1_type = getchild(expression, 0)->type;
            aux = cast2double(expression, op1, op2);

			if (aux)                                              // o que levou cast, o que nao levou 
				printf("  %%%d = fcmp sle double %%%d, %%%d\n", temporary, (aux > 0) ? op1 : temporary-1, (aux < 0) ? op2 : temporary-1 );
            else
				printf("  %%%d = %s sle %s %%%d, %%%d\n", temporary, (op1_type == double_type ? "fcmp" : "icmp"), type_to_llvm(op1_type), op1, op2);

            temporary++;
            printf("  %%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
            return temporary++;
        
        case Ge:
            op1 = codegen_expression(getchild(expression, 0), scope);
            op2 = codegen_expression(getchild(expression, 1), scope);
            op1_type = getchild(expression, 0)->type;
            aux = cast2double(expression, op1, op2);

			if (aux)                                              // o que levou cast, o que nao levou 
				printf("  %%%d = fcmp sge double %%%d, %%%d\n", temporary, (aux > 0) ? op1 : temporary-1, (aux < 0) ? op2 : temporary-1 );
            else
				printf("  %%%d = %s sge %s %%%d, %%%d\n", temporary, (op1_type == double_type ? "fcmp" : "icmp"), type_to_llvm(op1_type), op1, op2);

            temporary++;
            printf("  %%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
            return temporary++;

        case Lt:
            op1 = codegen_expression(getchild(expression, 0), scope);
            op2 = codegen_expression(getchild(expression, 1), scope);
            op1_type = getchild(expression, 0)->type;
            aux = cast2double(expression, op1, op2);

			if (aux)                                              // o que levou cast, o que nao levou 
				printf("  %%%d = fcmp slt double %%%d, %%%d\n", temporary, (aux > 0) ? op1 : temporary-1, (aux < 0) ? op2 : temporary-1 );
            else
				printf("  %%%d = %s slt %s %%%d, %%%d\n", temporary, (op1_type == double_type ? "fcmp" : "icmp"), type_to_llvm(op1_type), op1, op2);

            temporary++;
            printf("  %%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
            return temporary++;
        
        case Gt:
            op1 = codegen_expression(getchild(expression, 0), scope);
            op2 = codegen_expression(getchild(expression, 1), scope);
            op1_type = getchild(expression, 0)->type;
            aux = cast2double(expression, op1, op2);

			if (aux)                                              // o que levou cast, o que nao levou 
				printf("  %%%d = fcmp sgt double %%%d, %%%d\n", temporary, (aux > 0) ? op1 : temporary-1, (aux < 0) ? op2 : temporary-1 );
            else
				printf("  %%%d = %s sgt %s %%%d, %%%d\n", temporary, (op1_type == double_type ? "fcmp" : "icmp"), type_to_llvm(op1_type), op1, op2);

            temporary++;
            printf("  %%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
            return temporary++;


        case Plus:
            op1 = codegen_expression(getchild(expression, 0), scope);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(op1)+2));
            sprintf(expression->llvm_name, "%%%d", op1);
            return op1;

        case Minus:
            op1_node = getchild(expression, 0);

            op1 = codegen_expression(op1_node, scope);

			printf("  %%%d = %s %s %s, %%%d\n", temporary, (op1_node->type == double_type ? "fsub" : "sub"), type_to_llvm(op1_node->type), (op1_node->type == double_type ? "0.0" : "0"), op1);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
            return temporary++;
        
        case Not:
			op1 = codegen_expression(getchild(expression, 0), scope);
            printf("  %%%d = icmp eq i32 %%%d, 0\n", temporary++, op1);
            printf("  %%%d = zext i1 %%%d to i32\n", temporary, temporary-1);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
			return temporary++;

        case Identifier:
            if((found = search_symbol(scope, expression->token)))
                printf("  %%%d = load %s, %s* %s\n", temporary, type_to_llvm(expression->type), type_to_llvm(expression->type), found->node->llvm_name);
            else 
                printf("  %%%d = load %s, %s* %s\n", temporary, type_to_llvm(expression->type), type_to_llvm(expression->type), search_symbol(global_scope, expression->token)->node->llvm_name);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(temporary)+2));
            sprintf(expression->llvm_name, "%%%d", temporary);
            return temporary++;
        
        case Store:
            op2 = codegen_expression(getchild(expression, 1), scope);
            if((found = search_symbol(scope, getchild(expression, 0)->token))) // store i32 %10, i32* %1
                printf("  store %s %%%d, %s* %s\n", type_to_llvm(expression->type), op2, type_to_llvm(expression->type), found->node->llvm_name);
            else 
                printf("  store %s %%%d, %s* %s\n", type_to_llvm(expression->type), op2, type_to_llvm(expression->type), search_symbol(global_scope, expression->token)->node->llvm_name);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(op2)+2));
            sprintf(expression->llvm_name, "%%%d", op2);
            return temporary-1;
        
        case Comma:
            op1 = codegen_expression(getchild(expression, 0), scope); // 1+1, a = 1;
            op2 = codegen_expression(getchild(expression, 1), scope);
            expression->llvm_name = (char*)malloc(sizeof(char)*(number_len(op2)+2));
            sprintf(expression->llvm_name, "%%%d", op2);
            return temporary-1;
        
        // case Call:
        //     temp_node_list = expression->children->next;
        //     while ((temp_node_list = temp_node_list->next) != NULL) {
        //         codegen_expression(temp_node_list->node, scope);
        //     }
        //     temp_node_list2 = getchild(search_symbol(global_scope, getchild(expression, 0)->token)->node, 2)->children;
        //     temp_node_list = expression->children->next;
            
        default:
            return temporary;
    }
    
    return -1;
}

// void print() {
//     print("call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), double %%4)", )
// }