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

int codegen_expression(struct node *expression) {
    int tmp = -1, op1 = -1, op2 = -1;
    switch(expression->category) {
        case Natural:
            tmp = codegen_natural(expression);
            break;
        case Identifier:
            printf("  %%%d = add i32 %%%s, 0\n", temporary, expression->token);
            tmp = temporary++;
            break;
        
        case Add:
            op1 = codegen_expression(getchild(expression, 0));
            op2 = codegen_expression(getchild(expression, 1));

            printf("  %%%d = add i32 %%%d, %%%d\n", temporary, temporary-2, temporary-3);
            tmp = temporary++;
            break;
        
        case Sub:
            op1 = codegen_expression(getchild(expression, 0));
            op2 = codegen_expression(getchild(expression, 1));

            printf("  %%%d = sub i32 %%%d, %%%d\n", temporary, op1, op2);
            tmp = temporary++;
            break;
        
        case Mul:
            op1 = codegen_expression(getchild(expression, 0));
            op2 = codegen_expression(getchild(expression, 1));

            printf("  %%%d = mul i32 %%%d, %%%d\n", temporary, op1, op2);
            tmp = temporary++;
            break;
        
        case Div:
            op1 = codegen_expression(getchild(expression, 0));
            op2 = codegen_expression(getchild(expression, 1));

            printf("  %%%d = div i32 %%%d, %%%d\n", temporary, op1, op2);
            tmp = temporary++;
            break;

        case Call:
            codegen_call(expression);
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

int codegen_call(struct node *call) {
    struct node *arguments = getchild(call, 1);
    struct node *argument;
    int curr = 0;

    printf("  %%%d = call i32 @%s(", temporary, getchild(call, 0)->token);
    while((argument = getchild(arguments, curr++)) != NULL) {
        if(curr > 1)
            printf(", ");
        printf("i32 %%%s", argument->token);
    }
    printf(")\n");
    return temporary++;
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
