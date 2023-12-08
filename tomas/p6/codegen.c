#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"
#include "codegen.h"

int temporary;   // sequence of temporary registers in a function

extern struct symbol_list *symbol_table;

int codegen_natural(struct node *natural) {
    printf("  %%%d = add i32 %s, 0\n", temporary, natural->token);
    return temporary++;
}

int codegen_identifie(struct node *identifier) {
    printf("  %%%d = add i32 %%%s, 0\n", temporary, identifier->token);
    return temporary++;
}

int codegen_multiplication(struct node* multiplication) {
    int op1 = codegen_expression(getchild(multiplication, 0));
    int op2 = codegen_expression(getchild(multiplication, 1));
    printf("  %%%d = mul i32 %%%d, %%%d\n", temporary, op1, op2);
    return temporary++;
}

int codegen_addition(struct node* addition) {
    int op1 = codegen_expression(getchild(addition, 0));
    int op2 = codegen_expression(getchild(addition, 1));
    printf("  %%%d = add i32 %%%d, %%%d\n", temporary, op1, op2);
    return temporary++;
}

int codegen_subtraction(struct node* subtraction) {
    int op1 = codegen_expression(getchild(subtraction, 0));
    int op2 = codegen_expression(getchild(subtraction, 1));
    printf("  %%%d = sub i32 %%%d, %%%d\n", temporary, op1, op2);
    return temporary++;
}

int codegen_division(struct node* division) {
    int op1 = codegen_expression(getchild(division, 0));
    int op2 = codegen_expression(getchild(division, 1));
    printf("  %%%d = sdiv i32 %%%d, %%%d\n", temporary, op1, op2);
    return temporary++;
}

int codegen_call(struct node* call_to_func) {
    int count = 0;
    int *indexs = NULL;
    struct node_list *arguments = getchild(call_to_func, 1)->children->next;
    while(arguments != NULL) {
        if(count == 0)
            indexs = (int *)malloc(sizeof(int));
        else
            indexs = (int *)realloc(indexs, sizeof(int) * (count+1));
        indexs[count++] = codegen_expression(arguments->node);
        arguments = arguments->next;
    }
    arguments = call_to_func->children->next->next;
    printf("  %%%d = call i32 @_%s(", temporary, call_to_func->children->next->node->token);
    for (int i = 0; i < count; i++) {
        if(i > 0)
            printf(", ");
        printf("i32 %%%d", indexs[i]);
    }
    printf(")\n");
    // free memory
    free(indexs);

    return temporary++;
}

int codegen_if(struct node *if_statement) {
    int op1 = codegen_expression(getchild(if_statement, 0)), aux;
    printf("  %%%d = alloca i32\n", aux = temporary++);
    printf("  %%%d = icmp ne i32 %%%d, 0\n", temporary++, op1);
    printf("  br i1 %%%d, label %%LABELthen%d, label %%LABELelse%d\n", temporary-1, op1, op1);
    printf("LABELthen%d:\n", op1);
    int op2 = codegen_expression(getchild(if_statement, 1));
    printf("  store i32 %%%d, i32* %%%d\n", op2, aux);
    printf("  br label %%LABELfi%d\n", op1);
    printf("LABELelse%d:\n", op1);
    int op3 = codegen_expression(getchild(if_statement, 2));
    printf("  store i32 %%%d, i32* %%%d\n", op3, aux);
    printf("  br label %%LABELfi%d\n", op1);
    printf("LABELfi%d:\n", op1);
    printf("  %%%d = load i32, i32* %%%d\n", temporary++, aux);
    return temporary;
}

int codegen_expression(struct node *expression) {
    int tmp = -1;
    
    switch(expression->category) {
        case Natural:
            tmp = codegen_natural(expression);
            break;
        case Identifier:
            tmp = codegen_identifie(expression);
            break;
        case Mul:
            tmp = codegen_multiplication(expression);
            break;
        case Add:
            tmp = codegen_addition(expression);
            break;
        case Sub:
            tmp = codegen_subtraction(expression);
            break;
        case Div:
            tmp = codegen_division(expression);
            break;
        case Call:
            tmp = codegen_call(expression);
            break;
        case If:
            tmp = codegen_if(expression);
            break;
        default:
            break;
    }
    return tmp;
}

void codegen_parameters(struct node *parameters) {
    struct node *parameter;
    int curr = 0;
    while((parameter = getchild(parameters, curr++)) != NULL) {
        if(curr > 1)
            printf(", ");
        printf("i32 %%%s", getchild(parameter, 1)->token);
    }
}

void codegen_function(struct node *function) {
    temporary = 1;
    printf("define i32 @_%s(", getchild(function, 0)->token);
    codegen_parameters(getchild(function, 1));
    printf(") {\n");
    codegen_expression(getchild(function, 2));
    printf("  ret i32 %%%d\n", temporary-1);
    printf("}\n\n");
}

// code generation begins here, with the AST root node
void codegen_program(struct node *program) {
    // pre-declared I/O functions
    printf("declare i32 @_read(i32)\n");
    printf("declare i32 @_write(i32)\n\n");

    // generate code for each function
    struct node_list *function = program->children;
    while((function = function->next) != NULL)
        codegen_function(function->node);

    // generate the entry point which calls main(integer) if it exists
    struct symbol_list *entry = search_symbol(symbol_table, "main");
    if(entry != NULL && entry->node->category == Function)
        printf("define i32 @main() {\n"
               "  %%1 = call i32 @_main(i32 0)\n"
               "  ret i32 %%1\n"
               "}\n");
}
