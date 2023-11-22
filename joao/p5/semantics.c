#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"

int semantic_errors = 0;

struct symbol_list *symbol_table;

void check_parameters(struct node *params) {
    struct node_list* param = params->children;
    struct node *id;
    while ((param = param->next)) {
        id = getchild(param->node, 1);
        if(search_symbol(symbol_table, id->token) == NULL) {
            insert_symbol(symbol_table, id->token, id->type, param->node);
        }
        else {
            printf("Identifier %s (%d:%d) already declared\n", id->token, id->token_line, id->token_column);
            semantic_errors++;
        }
    }
}

char *category_name_[] = names;

void check_expression(struct node *expr) {
    // printf("Category: %s\n", category_name_[expr->category]);
    switch (expr->category) {
        case Call:
            if (!search_symbol(symbol_table, getchild(expr, 0)->token) || search_symbol(symbol_table, getchild(expr, 0)->token)->node->category != Function) {
                printf("Function %s (%d:%d) undeclared\n", getchild(expr, 0)->token, getchild(expr, 0)->token_line, getchild(expr, 0)->token_column);
            }
            else {
                struct node *argms = getchild(expr, 1);
                struct node *params = getchild(search_symbol(symbol_table, getchild(expr, 0)->token)->node, 1);
                if(params != NULL && countchildren(argms) != countchildren(params)) {
                    printf("Calling %s (%d:%d) with incorrect argms\n", getchild(expr, 0)->token, getchild(expr, 0)->token_line, getchild(expr, 0)->token_column);
                    semantic_errors++;
                }
            }

        default:
    }       
}

void check_function(struct node *function) {
    struct node *id = getchild(function, 0);
    if(search_symbol(symbol_table, id->token) == NULL) {
        insert_symbol(symbol_table, id->token, no_type, function);
    } else {
        printf("Identifier %s (%d:%d) already declared\n", id->token, id->token_line, id->token_column);
        semantic_errors++;
    }
    check_parameters(getchild(function, 1));
    check_expression(getchild(function, 2));
}

// semantic analysis begins here, with the AST root node
int check_program(struct node *program) {
    symbol_table = (struct symbol_list *) malloc(sizeof(struct symbol_list));
    symbol_table->next = NULL;
    struct node_list *child = program->children;
    while((child = child->next) != NULL)
        check_function(child->node);
    return semantic_errors;
}

// insert a new symbol in the list, unless it is already there
struct symbol_list *insert_symbol(struct symbol_list *table, char *identifier, enum type type, struct node *node) {
    struct symbol_list *new = (struct symbol_list *) malloc(sizeof(struct symbol_list));
    new->identifier = strdup(identifier);
    new->type = type;
    new->node = node;
    new->next = NULL;
    struct symbol_list *symbol = table;
    while(symbol != NULL) {
        if(symbol->next == NULL) {
            symbol->next = new;    /* insert new symbol at the tail of the list */
            break;
        } else if(strcmp(symbol->next->identifier, identifier) == 0) {
            free(new);
            return NULL;           /* return NULL if symbol is already inserted */
        }
        symbol = symbol->next;
    }
    return new;
}

// look up a symbol by its identifier
struct symbol_list *search_symbol(struct symbol_list *table, char *identifier) {
    struct symbol_list *symbol;
    for(symbol = table->next; symbol != NULL; symbol = symbol->next)
        if(strcmp(symbol->identifier, identifier) == 0)
            return symbol;
    return NULL;
}

void show_symbol_table() {
    struct symbol_list *symbol;
    for(symbol = symbol_table->next; symbol != NULL; symbol = symbol->next)
        printf("Symbol %s : %s\n", symbol->identifier, type_name(symbol->type));
}
