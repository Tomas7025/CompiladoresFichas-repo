#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"

int semantic_errors = 0;

struct symbol_list* global_scope;
struct symbol_list** scope_stack;

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

int check_signature(struct node *node, struct symbol_list *symbol) {
    struct node_list *aux, *aux2;

    if (getchild(node, 0)->category != getchild(symbol->node, 0)->category) {
        return 1;
    } else if (count_number_of_params(node) != count_number_of_params(symbol->node)) {
        return 1;
    } else {
        // check the type of each parameter
        aux = getchild(node, 2)->children;
        aux2 = getchild(symbol->node, 2)->children;
        int controlo_param = 0;
        for (aux = aux->next, aux2 = aux2->next; aux != NULL && aux2 != NULL; aux = aux->next, aux2 = aux2->next ) {
            if (getchild(aux->node, 0)->category != getchild(aux2->node, 0)->category) {
                controlo_param++;
                break;
            }
        }
        if (controlo_param > 0) {
            return 1;
        }
    }
    return 0;
}

int check_program(struct node *program) {
    global_scope = (struct symbol_list *) malloc(sizeof(struct symbol_list));
    global_scope->identifier = strdup("global");
    global_scope->type = no_type;
    global_scope->node = NULL;
    global_scope->next = NULL;
    scope_stack = (struct symbol_list **) malloc(sizeof(struct symbol_list *));
    scope_stack[0] = global_scope;
    
    struct node_list* aux = program->children;
    while ((aux = aux->next) != NULL){
        switch (aux->node->category) {
            case Declaration:
                /*
                declaration
                    : header (NULL)
                    : type_specifier
                    : identifier
                    : [expression] 
                */
                if (getchild(aux->node, 0)->category == Void) {
                    printf("Line , column : Invalid use of void type in declaration\n");
                    semantic_errors++;
                } else if(!insert_symbol(global_scope, getchild(aux->node, 1)->token, aux->node->type, aux->node)) {

                    struct symbol_list *temp = global_scope, *t2;
                    while ((temp = temp->next) != NULL) {
                        if (strcmp(temp->identifier, getchild(aux->node, 1)->token) == 0) {
                            switch (aux->node->category) {
                                case Declaration:
                                    printf("Semantic error: variable %s already declared in line column\n", getchild(aux->node, 1)->token);
                                    break;
                                default:
                                    printf("Line , column : Conflicting types (got %s, expected %s(", type_name(getchild(aux->node, 0)->category), type_name(getchild(temp->node, 0)->category));
                                    t2 = getchild(aux->node, 2)->children;
                                    while ((t2 = t2->next) != NULL) {
                                        printf("%s", type_name(getchild(t2->node, 0)->category));
                                        if (t2->next != NULL) {
                                            printf(", ");
                                        }
                                    }
                                    printf("))\n");
                                    break;
                            }
                            semantic_errors++;
                        }
                    }
                }
                break;
            case FuncDeclaration:
                /*
                funcDeclaration     <- aux->node
                    : header (NULL)
                    : type_specifier
                    : identifier
                    : ParamList     <- getchild(aux->node, 2) 
                        : header (NULL)
                        : Param          <- getchild(getchild(aux->node, 2), 0)
                            : header (NULL)
                            : type_specifier
                            : identifier   <- getchild(getchild(aux->node, 2), 0)->children->next->next
                        : ...
                */
                if (check_void_in_list(getchild(aux->node, 2)->children) == 0 || (getchild(aux->node, 2)->children->next->next == NULL && ( getchild(getchild(aux->node, 2), 0)->children->next->node->category == Void && getchild(getchild(aux->node, 2), 0)->children->next->next == NULL ))) {
                    if (!insert_symbol(global_scope, getchild(aux->node, 1)->token, aux->node->type, aux->node)) {
                        struct symbol_list *temp = global_scope;
                        int already_defined = 0;
                        while ((temp = temp->next) != NULL) {
                            if (strcmp(temp->identifier, getchild(aux->node, 1)->token) == 0) {
                                if (temp->node->category == Declaration){
                                    printf("Confliting types\n");
                                } else {
                                    if(check_signature(aux->node, temp) == 1) {
                                        printf("Conting types\n");
                                    } else 
                                        break;
                                }
                                
                            }
                        }
                    }
                }
                break;
            case FuncDefinition:
                
                break;
            default:
                break;
        }
    }
    
}

