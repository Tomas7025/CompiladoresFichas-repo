#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"

int semantic_errors = 0;

struct symbol_list* global_scope;

int check_function(struct node *node, struct symbol_list *scope, int flag);
int check_expression(struct node *node, struct symbol_list *scope);


//map category into enum types
enum type map_cat_typ(enum category category) {
    switch (category) {
        case Int:
            return integer_type;
        case Short:
            return short_type;
        case Void:
            return void_type;
        case Double:
            return double_type; 
        case Char:
            return char_type;
        default:
            return undefined_type;
    }
}


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


int check_program(struct node *program) {
    global_scope = (struct symbol_list *) malloc(sizeof(struct symbol_list));
    global_scope->identifier = strdup("global");
    global_scope->type = no_type;
    global_scope->node = NULL;
    global_scope->next = NULL;
    
    struct node* put = newnode(FuncDeclaration, "putchar");
    addchild(put, newnode(Int, NULL));
    addchild(put, newnode(Identifier, "putchar"));
    addchild(put, newnode(ParamList, NULL));
    addchild(getchild(put, 2), newnode(ParamDeclaration, NULL));
    addchild(getchild(getchild(put, 2), 0), newnode(Int, NULL));

    insert_symbol(global_scope, "putchar", integer_type, put);

    put = newnode(FuncDeclaration, "getchar");
    addchild(put, newnode(Int, NULL));
    addchild(put, newnode(Identifier, "putchar"));
    addchild(put, newnode(ParamList, NULL));
    addchild(getchild(put, 2), newnode(ParamDeclaration, NULL));
    addchild(getchild(getchild(put, 2), 0), newnode(Void, NULL));

    insert_symbol(global_scope, "getchar", integer_type, put);


    struct symbol_list *found;
    struct node_list *aux = program->children;

    while ((aux = aux->next) != NULL) {
        switch (aux->node->category) {
            case FuncDeclaration:
                if ((found = search_symbol(global_scope, getchild(aux->node, 1)->token)) != NULL) {
                    if (!valid_void(aux->node)) 
                        break;
                    
                    if (found->node->category == Declaration) {
                        printf("Line %d, column %d: Symbol %s already defined\n", aux->node->token_line, aux->node->token_column, getchild(aux->node, 1)->token);
                        semantic_errors++;
                        break;
                    }

                    valid_signature(found->node, aux->node);
                    break;
                }
                else {
                    if (valid_void(aux->node))
                        insert_symbol(global_scope, getchild(aux->node, 1)->token, map_cat_typ(getchild(aux->node, 0)->category), aux->node);
                }

                break;
            case FuncDefinition:
                if ((found = search_symbol(global_scope, getchild(aux->node, 1)->token)) != NULL) {
                    if(found->node->category == FuncDeclaration) {
                        // == 0 <=> houve erro
                        if (!valid_signature(found->node, aux->node))
                            break;
                        found->node = aux->node;
                        found->scope = (struct symbol_list *) malloc(sizeof(struct symbol_list));
                        found->scope->identifier = strdup(getchild(aux->node, 1)->token);
                        found->scope->type = map_cat_typ(getchild(aux->node, 0)->category);
                        found->scope->node = NULL;
                        found->scope->next = NULL;

                        if(getchild(getchild(getchild(aux->node, 2),0),0)->category != Void){
                            struct node_list *aux2 = getchild(aux->node, 2)->children;
                            while ((aux2 = aux2->next) != NULL){
                                insert_symbol(found->scope, getchild(aux2->node, 1)->token, map_cat_typ(getchild(aux2->node, 0)->category), aux2->node);
                            }
                        }

                        // check_func passar o scope da funcDeclaration
                        check_function(aux->node, found->scope, 0);
                    } else {
                        //! ERRO
                        // ??? Pergunta 9
                        // == 0 <=> houve erro
                        if (!valid_void(aux->node))
                            break;
                        printf("Line %d, column %d: Symbol %s already defined\n", getchild(aux->node, 1)->token_line, getchild(aux->node, 1)->token_column, getchild(aux->node, 1)->token);
                    }
                }
                else {
                    insert_symbol(global_scope, getchild(aux->node, 1)->token, map_cat_typ(getchild(aux->node, 0)->category), aux->node);
                    found = search_symbol(global_scope, getchild(aux->node, 1)->token);
                    found->scope = (struct symbol_list *) malloc(sizeof(struct symbol_list));
                    found->scope->identifier = strdup(getchild(aux->node, 1)->token);
                    found->scope->node = aux->node;
                    found->scope->next = NULL;
                    found->scope->type = map_cat_typ(getchild(aux->node, 0)->category);

                    if(getchild(getchild(getchild(aux->node, 2),0),0)->category != Void){
                        struct node_list *aux2 = getchild(aux->node, 2)->children;
                        while ((aux2 = aux2->next) != NULL){
                            insert_symbol(found->scope, getchild(aux2->node, 1)->token, map_cat_typ(getchild(aux2->node, 0)->category), aux2->node);
                        }
                    }

                    // check_func passar o scope da funcDeclaration
                    check_function(aux->node, found->scope, 0);
                }
                break;
            case Declaration:
                if (countchildren(aux->node) == 3)
                    check_expression(getchild(aux->node, 2), global_scope);

                if (getchild(aux->node, 0)->category == Void) {
                    printf("Line %d, column %d: Invalid use of void type in declaration\n", getchild(aux->node, 1)->token_line, getchild(aux->node, 1)->token_column);
                    break;
                }
                
                if ((found = search_symbol(global_scope, getchild(aux->node, 1)->token)) != NULL) {
                    //! ERRO
                    printf("Line %d, column %d: Symbol %s already defined\n", aux->node->token_line, aux->node->token_column, getchild(aux->node, 1)->token);
                }
                else {
                    if (countchildren(aux->node) == 3) {
                        if ((getchild(aux->node, 0)->category == Int || getchild(aux->node, 0)->category == Char ||
                            getchild(aux->node, 0)->category == Short) && (getchild(aux->node, 2)->type == void_type || getchild(aux->node, 2)->type == double_type)) {

                            printf("Line %d, column %d: Conflicting types (got %s, expected %s)\n", getchild(aux->node, 1)->token_line, getchild(aux->node, 1)->token_column, type_name(getchild(aux->node, 2)->type), type_name(map_cat_typ(getchild(aux->node, 0)->category)));
                            semantic_errors++;
                        }
                        else if (getchild(aux->node, 0)->category == Double && getchild(aux->node, 2)->type == void_type) {
                            printf("Line %d, column %d: Conflicting types (got %s, expected %s)\n", getchild(aux->node, 1)->token_line, getchild(aux->node, 1)->token_column, type_name(getchild(aux->node, 2)->type), type_name(map_cat_typ(getchild(aux->node, 0)->category)));
                            semantic_errors++;
                        }
                    }

                    insert_symbol(global_scope, getchild(aux->node, 1)->token, map_cat_typ(getchild(aux->node, 0)->category), aux->node);
                }
                break;
            default:
                break;
        }
    }
    
    return semantic_errors;
}

int check_statement(struct node *node, struct symbol_list *scope) {
    struct symbol_list *found;
    switch (node->category) {
        case Declaration:
            if (countchildren(node) == 3)
                check_expression(getchild(node, 2), scope);
            if (getchild(node, 0)->category == Void) {
                printf("Line %d, column %d: Invalid use of void type in declaration\n", getchild(node, 0)->token_line, getchild(node, 0)->token_column);
                break;
            }

            if ((found = search_symbol(scope, getchild(node, 1)->token)) != NULL) {
                //! ERRO
                printf("Line %d, column %d: Symbol %s already defined\n", getchild(node, 1)->token_line, getchild(node, 1)->token_column, getchild(node, 1)->token);
            }
            else {
                if (countchildren(node) == 3) {
                        if ((getchild(node, 0)->category == Int || getchild(node, 0)->category == Char || getchild(node, 0)->category == Short) && (getchild(node, 2)->type == void_type || getchild(node, 2)->type == double_type)) {
                            printf("Line %d, column %d: Conflicting types (got %s, expected %s)\n", getchild(node, 1)->token_line, getchild(node, 1)->token_column, type_name(getchild(node, 2)->type), type_name(map_cat_typ(getchild(node, 0)->category)));
                            semantic_errors++;
                        }
                        else if (getchild(node, 0)->category == Double && getchild(node, 2)->type == void_type) {
                            printf("Line %d, column %d: Conflicting types (got %s, expected %s)\n", getchild(node, 1)->token_line, getchild(node, 1)->token_column, type_name(getchild(node, 2)->type), type_name(map_cat_typ(getchild(node, 0)->category)));
                            semantic_errors++;
                        }
                    }
                insert_symbol(scope, getchild(node, 1)->token, map_cat_typ(getchild(node, 0)->category), node);
            }
            break;
        case If:
            // DEBUG: printf("if %d %d\n", node->token_line, node->token_column);
            check_expression(getchild(node, 0), scope);
            if (getchild(node, 1) != NULL && getchild(node, 1)->category != Null) {
                if (getchild(node, 1)->category == StatList) 
                    check_function(getchild(node, 1), scope, 1);
                else
                    check_statement(getchild(node, 1), scope);
            }
            if (getchild(node, 2) != NULL && getchild(node, 2)->category != Null) {
                if (getchild(node, 2)->category == StatList)
                    check_function(getchild(node, 2), scope, 1);
                else 
                    check_statement(getchild(node, 2), scope);
            }
            break;
        case While:
            // DEBUG: printf("while %d %d\n", node->token_line, node->token_column);
            check_expression(getchild(node, 0), scope);
            if (getchild(node, 1) != NULL && getchild(node, 1)->category != Null) {
                if (getchild(node, 1)->category == StatList)
                    check_function(getchild(node, 1), scope, 1);
                else 
                    check_statement(getchild(node, 1), scope);
            }
            break;
        case Return:
            // DEBUG: printf("return %d %d\n", node->token_line, node->token_column);
            if (getchild(node, 0)->category != Null){
                check_expression(getchild(node, 0), scope);
                if (getchild(node, 0)->type > scope->type || (getchild(node, 0)->type == void_type && scope->type != void_type)) {
                    printf("Line %d, column %d: Conflicting types (got %s, expected %s)\n", getchild(node, 0)->token_line, getchild(node, 0)->token_column, type_name(getchild(node, 0)->type), type_name(scope->type));
                    semantic_errors++;
                }
            } else {
                if (scope->type != void_type) {
                    printf("Line %d, column %d: Conflicting types (got void, expected %s)\n", node->token_line, node->token_column, type_name(scope->type));
                    semantic_errors++;
                }
            }
            break;
        case StatList:
            if (node != NULL)
                check_function(node, scope, 1);
            break;
        default:
            // DEBUG: printf("expr %d %d\n", node->token_line, node->token_column);
            check_expression(node, scope);
            break;
    }
    return 0;
}


int check_function(struct node *node, struct symbol_list *scope, int is_stat_list) {
    struct node_list *aux;
    
    if (is_stat_list == 0)
        aux = getchild(node, 3)->children;
    else if (is_stat_list == 1)
        aux = node->children;    

    while ((aux = aux->next) != NULL) {
        check_statement(aux->node, scope);
    }
    return 0;
}


int check_expression(struct node *node, struct symbol_list *scope){
    struct symbol_list *found;
    struct node_list *aux;

    struct node_list *arg_cursor;
    struct node_list *param_cursor;

    int arg_c = 0, param_c = 0;
    
    switch (node->category) {
        case Store: // for some reason o store se for undef = undef ele so da erro no check expression
            check_expression(getchild(node, 0), scope);
            check_expression(getchild(node, 1), scope);
            if (getchild(node, 0)->category != Identifier) {
                printf("Line %d, column %d: Lvalue required\n", getchild(node, 0)->token_line, getchild(node, 0)->token_column);
            }
            else if ((getchild(node, 0)->type == integer_type || getchild(node, 0)->type == short_type || getchild(node, 0)->type == char_type) && (getchild(node, 1)->type == double_type || getchild(node, 1)->type == void_type || getchild(node, 1)->type == undefined_type)) {
                printf("Line %d, column %d: Operator = cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type));
                semantic_errors++;
            }
            else if (getchild(node, 0)->type == double_type && (getchild(node, 1)->type == void_type || getchild(node, 1)->type == undefined_type)){
                printf("Line %d, column %d: Operator = cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type));
                semantic_errors++;
            }
            else if (getchild(node, 1)->type == void_type || getchild(node, 0)->type == undefined_type){
                printf("Line %d, column %d: Operator = cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type));
                semantic_errors++;
            }
            node->type = getchild(node, 0)->type;
            break;
    
        case Comma:
            check_expression(getchild(node, 0), scope);
            check_expression(getchild(node, 1), scope);
            if (getchild(node, 0)->type == undefined_type || getchild(node, 1)->type == undefined_type){
                printf("Line %d, column %d: Operator , cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type)); 
                node->type = undefined_type;
                semantic_errors++;
            }else
                node->type = getchild(node, 1)->type;
            break;
        
        case Add:
            //TODO: Checkar se é void || undef
            check_expression(getchild(node, 0), scope);
            check_expression(getchild(node, 1), scope);
            if (getchild(node, 0)->type == void_type || getchild(node, 0)->type == undefined_type || getchild(node, 1)->type == void_type || getchild(node, 1)->type == undefined_type) {
                printf("Line %d, column %d: Operator + cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type));
                node->type = undefined_type;
                semantic_errors++;
            } else {
                node->type = (getchild(node, 0)->type > getchild(node, 1)->type) ? getchild(node, 0)->type : getchild(node, 1)->type;
            }
            break;
        
        case Sub:
            //TODO: Checkar se é void || undef
            check_expression(getchild(node, 0), scope);
            check_expression(getchild(node, 1), scope);
            if (getchild(node, 0)->type == void_type || getchild(node, 0)->type == undefined_type || getchild(node, 1)->type == void_type || getchild(node, 1)->type == undefined_type) {
                printf("Line %d, column %d: Operator - cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type));
                node->type = undefined_type;
                semantic_errors++;
            } else {
                node->type = (getchild(node, 0)->type > getchild(node, 1)->type) ? getchild(node, 0)->type : getchild(node, 1)->type;
            }
            break;
    
        case Mul:
            //TODO: Checkar se é void || undef
            check_expression(getchild(node, 0), scope);
            check_expression(getchild(node, 1), scope);
            if (getchild(node, 0)->type == void_type || getchild(node, 0)->type == undefined_type || getchild(node, 1)->type == void_type || getchild(node, 1)->type == undefined_type) {
                printf("Line %d, column %d: Operator * cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type));
                node->type = undefined_type;
                semantic_errors++;
            } else {
                node->type = (getchild(node, 0)->type > getchild(node, 1)->type) ? getchild(node, 0)->type : getchild(node, 1)->type;
            }
            break;
        
        case Div:
            //TODO: Checkar se é void || undef
            check_expression(getchild(node, 0), scope);
            check_expression(getchild(node, 1), scope);
            if (getchild(node, 0)->type == void_type || getchild(node, 0)->type == undefined_type || getchild(node, 1)->type == void_type || getchild(node, 1)->type == undefined_type) {
                printf("Line %d, column %d: Operator / cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type));
                node->type = undefined_type;
                semantic_errors++;
            } else {
                node->type = (getchild(node, 0)->type > getchild(node, 1)->type) ? getchild(node, 0)->type : getchild(node, 1)->type;
            }
            break;
        
        case Mod:
            //TODO: Checkar se é void || undef || double
            check_expression(getchild(node, 0), scope);
            check_expression(getchild(node, 1), scope);
            if (getchild(node, 0)->type == void_type || getchild(node, 0)->type == undefined_type || getchild(node, 1)->type == void_type || getchild(node, 1)->type == undefined_type || getchild(node, 0)->type == double_type || getchild(node, 1)->type == double_type) {
                printf("Line %d, column %d: Operator %% cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type));
                semantic_errors++;
            }
            node->type = integer_type;
            break;
    
        case Or:
            check_expression(getchild(node, 0), scope);
            check_expression(getchild(node, 1), scope);
            if (getchild(node, 0)->type == void_type || getchild(node, 0)->type == undefined_type || getchild(node, 1)->type == void_type || getchild(node, 1)->type == undefined_type || getchild(node, 0)->type == double_type || getchild(node, 1)->type == double_type) {
                printf("Line %d, column %d: Operator || cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type));
                semantic_errors++;
            }
            node->type = integer_type;
            break;
    
        case And:
            check_expression(getchild(node, 0), scope);
            check_expression(getchild(node, 1), scope);
            if (getchild(node, 0)->type == void_type || getchild(node, 0)->type == undefined_type || getchild(node, 1)->type == void_type || getchild(node, 1)->type == undefined_type || getchild(node, 0)->type == double_type || getchild(node, 1)->type == double_type) {
                printf("Line %d, column %d: Operator && cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type));
                semantic_errors++;
            }
            node->type = integer_type;
            break;
    
        case BitWiseAnd:
            check_expression(getchild(node, 0), scope);
            check_expression(getchild(node, 1), scope);
            if (getchild(node, 0)->type == void_type || getchild(node, 0)->type == undefined_type || getchild(node, 1)->type == void_type || getchild(node, 1)->type == undefined_type || getchild(node, 0)->type == double_type || getchild(node, 1)->type == double_type) {
                printf("Line %d, column %d: Operator & cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type));
                semantic_errors++;
            }
            node->type = integer_type;
            break;
    
        case BitWiseOr:
            check_expression(getchild(node, 0), scope);
            check_expression(getchild(node, 1), scope);
            if (getchild(node, 0)->type == void_type || getchild(node, 0)->type == undefined_type || getchild(node, 1)->type == void_type || getchild(node, 1)->type == undefined_type || getchild(node, 0)->type == double_type || getchild(node, 1)->type == double_type) {
                printf("Line %d, column %d: Operator | cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type));
                semantic_errors++;
            }
            node->type = integer_type;
            break;
    
        case BitWiseXor:
            check_expression(getchild(node, 0), scope);
            check_expression(getchild(node, 1), scope);
            if (getchild(node, 0)->type == void_type || getchild(node, 0)->type == undefined_type || getchild(node, 1)->type == void_type || getchild(node, 1)->type == undefined_type || getchild(node, 0)->type == double_type || getchild(node, 1)->type == double_type) {
                printf("Line %d, column %d: Operator ^ cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type));
                semantic_errors++;
            }
            node->type = integer_type;
            break;
    
        case Eq:
            check_expression(getchild(node, 0), scope);
            check_expression(getchild(node, 1), scope);
            if (getchild(node, 0)->type == void_type || getchild(node, 1)->type == void_type ||
             ((getchild(node, 1)->type != getchild(node, 0)->type) && (getchild(node, 0)->type == undefined_type || getchild(node, 1)->type == undefined_type))) {
                printf("Line %d, column %d: Operator == cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type));
                semantic_errors++;
            }
            node->type = integer_type;
            break;
    
        case Ne:
            check_expression(getchild(node, 0), scope);
            check_expression(getchild(node, 1), scope);
            if (getchild(node, 0)->type == void_type || getchild(node, 1)->type == void_type ||
             ((getchild(node, 1)->type != getchild(node, 0)->type) && (getchild(node, 0)->type == undefined_type || getchild(node, 1)->type == undefined_type))) {
                printf("Line %d, column %d: Operator != cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type));
                semantic_errors++;
            }
            node->type = integer_type;
            break;
    
        case Le:
            check_expression(getchild(node, 0), scope);
            check_expression(getchild(node, 1), scope);
            if (getchild(node, 0)->type == void_type || getchild(node, 1)->type == void_type ||
             ((getchild(node, 1)->type != getchild(node, 0)->type) && (getchild(node, 0)->type == undefined_type || getchild(node, 1)->type == undefined_type))) {
                printf("Line %d, column %d: Operator <= cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type)); 
                semantic_errors++;
            }
            node->type = integer_type;
            break;
    
        case Ge:
            check_expression(getchild(node, 0), scope);
            check_expression(getchild(node, 1), scope);
            if (getchild(node, 0)->type == void_type || getchild(node, 1)->type == void_type ||
             ((getchild(node, 1)->type != getchild(node, 0)->type) && (getchild(node, 0)->type == undefined_type || getchild(node, 1)->type == undefined_type))) {
                printf("Line %d, column %d: Operator >= cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type)); 
                semantic_errors++;
            }
            node->type = integer_type;
            break;
    
        case Lt:
            check_expression(getchild(node, 0), scope);
            check_expression(getchild(node, 1), scope);
            if (getchild(node, 0)->type == void_type || getchild(node, 1)->type == void_type ||
             ((getchild(node, 1)->type != getchild(node, 0)->type) && (getchild(node, 0)->type == undefined_type || getchild(node, 1)->type == undefined_type))) {
                printf("Line %d, column %d: Operator < cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type)); 
                semantic_errors++;
            }
            node->type = integer_type;
            break;
    
        case Gt:
            check_expression(getchild(node, 0), scope);
            check_expression(getchild(node, 1), scope);
            if (getchild(node, 0)->type == void_type || getchild(node, 1)->type == void_type ||
             ((getchild(node, 1)->type != getchild(node, 0)->type) && (getchild(node, 0)->type == undefined_type || getchild(node, 1)->type == undefined_type))) {
                printf("Line %d, column %d: Operator > cannot be applied to types %s, %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type), type_name(getchild(node, 1)->type)); 
                semantic_errors++;
            }
            node->type = integer_type;
            break;   
    
        case Plus:
            check_expression(getchild(node, 0), scope);
            if (getchild(node, 0)->type == void_type || getchild(node, 0)->type == undefined_type) {
                printf("Line %d, column %d: Operator + cannot be applied to type %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type));
                semantic_errors++;
            }
            node->type = getchild(node, 0)->type;
            break;
    
        case Minus:
            check_expression(getchild(node, 0), scope);
            if (getchild(node, 0)->type == undefined_type || getchild(node, 0)->type == void_type) {
                printf("Line %d, column %d: Operator - cannot be applied to type %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type));
                semantic_errors++;
            }
            node->type = getchild(node, 0)->type;
            
            break;
        
        case Not:
            check_expression(getchild(node, 0), scope);
            if (getchild(node, 0)->type == void_type || getchild(node, 0)->type == undefined_type || getchild(node, 0)->type == double_type) {
                printf("Line %d, column %d: Operator ! cannot be applied to type %s\n", node->token_line, node->token_column, type_name(getchild(node, 0)->type));
                semantic_errors++;
            }
            node->type = integer_type;
            break;
    
        case Call:
            aux = node->children->next;
            while ((aux = aux->next) != NULL) {
                check_expression(aux->node, scope);
            }

            found = search_symbol(global_scope, getchild(node, 0)->token);
            
            if(found != NULL) {
                arg_cursor = node->children->next;
                param_cursor = getchild(found->node, 2)->children;

                while ((arg_cursor = arg_cursor->next) != NULL) {
                    if (arg_cursor->node->type != void_type)
                        arg_c++;
                }
                
                while ((param_cursor = param_cursor->next) != NULL) {
                    if (getchild(param_cursor->node, 0)->type != void_type)
                        param_c++;
                }

                if (arg_c != param_c) {
                    //printf("Line %d, column %d: Wrong number of arguments to function %s (got %d, required %d)\n", node->token_line, node->token_column, found->identifier, arg_c, param_c);

                }

                node->children->next->node->type = found->type;
                node->type = found->type;
            }
            else {
                node->children->next->node->type = undefined_type;
                node->type = undefined_type;
                //! ERRO
            }

            break;
    
        case Identifier:
            found = search_symbol(scope, node->token);
            if (found != NULL)
                node->type = found->type;
            else if ((found = search_symbol(global_scope, node->token)) != NULL)
                node->type = found->type;
            
            else {
                node->type = undefined_type;
                // ! teste
                printf("Line %d, column %d: Unknown symbol %s\n", node->token_line, node->token_column, node->token);
                semantic_errors++;
            }
            // printf("DEBUG: %s, %s\n", node->token, type_name(node->type));
            break;
    
        case Natural:
            node->type = integer_type;
            break;
    
        case ChrLit:
            node->type = integer_type; 
            break;
    
        case Decimal:
            node->type = double_type;
            break;

        case Short:
            node->type = short_type;
            break;

        default:
            break;
    }
    return semantic_errors;
}

void show_symbol_table() {
    struct symbol_list *symbol = global_scope;
    printf("===== Global Symbol Table =====\n");
    while ((symbol = symbol->next) != NULL){
        switch (symbol->node->category)
        {
        case Declaration:
            printf("%s\t%s\n", symbol->identifier, map_typ(getchild(symbol->node, 0)->category));
            break;
        
        default:
            printf("%s\t%s(", symbol->identifier, map_typ(getchild(symbol->node, 0)->category));
            struct node_list *aux = getchild(symbol->node, 2)->children;
            while ((aux = aux->next) != NULL) {
                printf("%s", map_typ(getchild(aux->node, 0)->category));
                if (aux->next != NULL) {
                    printf(",");
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
            printf("return\t%s\n", map_typ(getchild(symbol->node, 0)->category));
            struct symbol_list *symbol2 = symbol->scope;
            while ((symbol2 = symbol2->next) != NULL){
                if (symbol2->node->category == Declaration)
                    printf("%s\t%s\n", symbol2->identifier, map_typ(getchild(symbol2->node, 0)->category));
                else
                    printf("%s\t%s\tparam\n", symbol2->identifier, map_typ(getchild(symbol2->node, 0)->category));
            }
            printf("\n");
        }
    }
    
}



int valid_void(struct node *new) {
    // return:
    //     0 => Erro
    //     1 => Sucesso

    struct node_list *new_cursor;

    new_cursor = getchild(new, 2)->children;

    while ((new_cursor = new_cursor->next)) {
        if (getchild(new_cursor->node, 0)->category == Void && (new_cursor->next != NULL || new_cursor != getchild(new, 2)->children->next)) {
            printf("Line %d, column %d: Invalid use of void type in declaration\n", getchild(new_cursor->node, 0)->token_line, getchild(new_cursor->node, 0)->token_column);
            semantic_errors++;
            return 0;
        }
    }

    return 1;
}

int valid_signature(struct node* original, struct node *new) {
    // conf_f (conflit flag):
    //      -1 -> nao ha erros
	//      0 -> conf type

    int orig_c, new_c;
    int conf_flag = -1;
    int both_decs = (original->category == FuncDeclaration && new->category == FuncDeclaration) ? 1 : 0;
    struct node_list *orig_cursor = getchild(original, 2)->children->next;
    struct node_list *new_cursor = getchild(new, 2)->children->next;

    // valid_void 0 <=> error, invalid void
    if (!valid_void(new))
        return 0;

    for (; orig_cursor != NULL && new_cursor != NULL; orig_cursor = orig_cursor->next, new_cursor = new_cursor->next) {
        orig_c = countchildren(orig_cursor->node);
        new_c = countchildren(new_cursor->node);
        if (both_decs && (orig_c != new_c || (new_c == 2 && (strcmp(getchild(orig_cursor->node, 1)->token, getchild(new_cursor->node, 1)->token) != 0)))) {
            printf("Line %d, column %d: Symbol %s already defined\n", getchild(new, 1)->token_line, getchild(new, 1)->token_column, getchild(new, 1)->token);
            semantic_errors++;
            return 0;
        }
        if (getchild(orig_cursor->node, 0)->category != getchild(new_cursor->node, 0)->category) 
            conf_flag = 0;
    }

    if (conf_flag == 0 || orig_cursor != NULL || new_cursor != NULL || getchild(original, 0)->category != getchild(new, 0)->category) {
        printf("Line %d, column %d: Conflicting types (got ", getchild(new, 1)->token_line, getchild(new, 1)->token_column);
        print_signature(new);
        printf(", expected ");
        print_signature(original);
        printf(")\n");
        semantic_errors++;
        return 0;
    }

    return 1;
}