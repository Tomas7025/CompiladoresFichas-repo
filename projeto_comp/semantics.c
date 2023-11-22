#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"

int semantic_errors = 0;

struct symbol_list* global_scope;
struct symbol_list** scope_stack;

int checl_sym(struct node *tst, struct symbol_list *table) {
    int result = 0;
    while ((table = table->next) != NULL) {
        if (strcmp(table->identifier, tst->token) == 0 && table->node->category == tst->category) {
            result = 1;
            break;
        }
    }
    
    return result;
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
        } else if( == 0) {
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

int count_number_of_params(struct node *node) {
    int n_params = 0;
    struct node_list *aux = getchild(node, 2)->children;
    while ((aux = aux->next) != NULL) {
        n_params++;
    }
    return n_params;
}

int check_void_in_list (struct node_list *list) {
    int void_found = 0;
    struct node_list *aux = list;
    while ((aux = aux->next) != NULL) {
        if (getchild(aux->node, 0)->category == Void) {
            printf("Line , column : Invalid use of void type in declaration\n");
            semantic_errors++;
            void_found = 1;
        }
    }
    return void_found;
}

int check_program(struct node *program) {
    global_scope = (struct symbol_list *) malloc(sizeof(struct symbol_list));
    global_scope->identifier = strdup("global");
    global_scope->type = Void;
    global_scope->node = NULL;
    global_scope->next = NULL;
    
    scope_stack = (struct symbol_list **) malloc(sizeof(struct symbol_list *));
    scope_stack[0] = global_scope;
    
    struct node_list *aux = program->children;
    while ((aux = aux->next) != NULL) {
        if 
    }
    return semantic_errors;
}
