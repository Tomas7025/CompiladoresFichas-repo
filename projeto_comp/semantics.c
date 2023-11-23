#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"

int semantic_errors = 0;

struct symbol_list* global_scope;
struct symbol_list** scope_stack;

int check_function(struct node *node, struct symbol_list *scope);

// insert a new symbol in the list, unless it is already there
struct symbol_list *insert_symbol(struct symbol_list *table, char *identifier, enum type type, struct node *node) {
    struct symbol_list *new = (struct symbol_list *) malloc(sizeof(struct symbol_list));
    new->identifier = strdup(identifier);
    new->type = type;
    new->node = node;
    new->next = NULL;
    new->scope = NULL;
    struct symbol_list *symbol = table;
    while(symbol != NULL) {
        if(symbol->next == NULL) {
            symbol->next = new;    /* insert new symbol at the tail of the list */
            break;
        } else if(strcmp(symbol->next->identifier, identifier) == 0 && (symbol->next->node->category == node->category)) {
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

// look up a symbol by its identifier
struct symbol_list *search_symbol_categ(struct symbol_list *table, char *identifier, enum category category) {
    struct symbol_list *symbol;
    for(symbol = table->next; symbol != NULL; symbol = symbol->next) {
        if ((category == FuncDeclaration || category == FuncDefinition) && (symbol->node->category == FuncDeclaration || symbol->node->category == FuncDefinition)) {
            if (strcmp(symbol->identifier, identifier) == 0)
                return symbol;
        }
        else if (category == Declaration && symbol->node->category == Declaration) {
            if (strcmp(symbol->identifier, identifier) == 0)
                return symbol;
        }
    }
    return NULL;
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

    struct symbol_list *found;
    struct node_list *aux = program->children;
    while ((aux = aux->next) != NULL) {
        switch (aux->node->category) {
            case (FuncDeclaration):
                if ((found = search_symbol_categ(global_scope, getchild(aux->node, 1)->token, aux->node->category)) != NULL) {

                    //! if (found->node->category == FuncDefinition) 
                    //! ERRO
                }
                else {
                    insert_symbol(global_scope, getchild(aux->node, 1)->token, aux->node->type, aux->node);
                }

                break;
            case (FuncDefinition):
                if ((found = search_symbol_categ(global_scope, getchild(aux->node, 1)->token, aux->node->category)) != NULL) {
                    if(found->node->category != FuncDefinition) {
                        // ! falta checkar se a funcDeclation tem assinatura igual a funcDefinition
                        found->scope = (struct symbol_list *) malloc(sizeof(struct symbol_list));
                        found->scope->identifier = strdup(getchild(aux->node, 1)->token);
                        found->scope->type = no_type;
                        found->scope->node = aux->node;
                        found->scope->next = NULL;

                        if(getchild(getchild(getchild(aux->node, 2),0),0)->category != Void){
                            struct node_list *aux2 = getchild(aux->node, 2)->children;
                            while ((aux2 = aux2->next) != NULL){
                                insert_symbol(found->scope, getchild(aux2->node, 1)->token, aux2->node->type, aux2->node);
                            }
                        }

                        //? check_func passar o scope da funcDeclaration
                        check_function(aux->node, found->scope);
                    } else {
                        //! ERRO
                    }
                }
                else {
                    insert_symbol(global_scope, getchild(aux->node, 1)->token, aux->node->type, aux->node);
                    found = search_symbol_categ(global_scope, getchild(aux->node, 1)->token, aux->node->category);
                    found->scope = (struct symbol_list *) malloc(sizeof(struct symbol_list));
                    found->scope->identifier = strdup(getchild(aux->node, 1)->token);
                    found->scope->node = aux->node;
                    found->scope->next = NULL;

                    if(getchild(getchild(getchild(aux->node, 2),0),0)->category != Void){
                        struct node_list *aux2 = getchild(aux->node, 2)->children;
                        while ((aux2 = aux2->next) != NULL){
                            insert_symbol(found->scope, getchild(aux2->node, 1)->token, aux2->node->type, aux2->node);
                        }
                    }

                    //? check_func passar o scope da funcDeclaration
                    check_function(aux->node, found->scope);
                }
                break;
            case (Declaration):
                if ((found = search_symbol_categ(global_scope, getchild(aux->node, 1)->token, aux->node->category)) != NULL) {
                    //! ERRO
                }
                else {
                    insert_symbol(global_scope, getchild(aux->node, 1)->token, aux->node->type, aux->node);
                }
                break;
        }
    }
    
    //struct symbol_list *symbol = global_scope;
    //while ((symbol = symbol->next) != NULL)
    //{
    //    printf("Symbol: %s %d\n", symbol->identifier, symbol->node->category);
    //    if (symbol->scope != NULL){
    //        struct symbol_list *symbol2 = symbol->scope;
    //        while ((symbol2 = symbol2->next) != NULL)
    //        {
    //            printf("\tSCOPE %s: %s %d\n", symbol->identifier, symbol2->identifier, symbol2->node->category);
    //        }
    //    }
    //}
    show_symbol_table();

    return semantic_errors;
}


int check_function(struct node *node, struct symbol_list *scope) {
    printf("check_function\n");
    struct symbol_list *found;
    struct node_list *aux = getchild(node, 3)->children;
    while ((aux = aux->next) != NULL) {
        switch (aux->node->category) {
            case Declaration:
                if ((found = search_symbol(scope, getchild(aux->node, 1)->token)) != NULL) {
                    //! ERRO
                }
                else {
                    insert_symbol(scope, getchild(aux->node, 1)->token, aux->node->type, aux->node);
                }
                break;
        }
    }
    return 0;
}

void show_symbol_table() {
    struct symbol_list *symbol = global_scope;
    printf("===== Global Symbol Table =====\n");
    while ((symbol = symbol->next) != NULL){
        switch (symbol->node->category)
        {
        case Declaration:
            printf("%s\t%s\n", symbol->identifier, category_m[getchild(symbol->node, 0)->category]);
            break;
        
        default:
            printf("%s\t%s(", symbol->identifier, category_m[getchild(symbol->node, 0)->category]);
            struct node_list *aux = getchild(symbol->node, 2)->children;
            while ((aux = aux->next) != NULL) {
                printf("%s", category_m[getchild(aux->node, 0)->category]);
                if (aux->next != NULL) {
                    printf(", ");
                }
            }
            printf(")\n");
            break;
        }
    }
    printf("\n");
    symbol = global_scope;
    while ((symbol = symbol->next) != NULL) {
        if (symbol->node->category == FuncDefinition) {
            printf("===== Function %s Symbol Table =====\n", symbol->identifier);
            printf("return\t%s\n", category_m[getchild(symbol->node, 0)->category]);
            struct symbol_list *symbol2 = symbol->scope;
            while ((symbol2 = symbol2->next) != NULL){
                if (symbol2->node->category == Declaration)
                    printf("%s\t%s\n", symbol2->identifier, category_m[getchild(symbol2->node, 0)->category]);
                else
                    printf("%s\t%s\tparam\n", symbol2->identifier, category_m[getchild(symbol2->node, 0)->category]);
            }
            printf("\n");
        }
        
    }
    
}
