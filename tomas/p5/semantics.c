#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"

int semantic_errors = 0;

struct symbol_list *symbol_table;

void check_function(struct node *function);
int check_program(struct node *program);
struct symbol_list* check_parameters(struct node* parameters);
void check_call(struct node* call, struct symbol_list* scope);
void check_expression(struct node* expression, struct symbol_list* scope);

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

void show_symbol_table() {
    struct symbol_list *symbol;
    for(symbol = symbol_table->next; symbol != NULL; symbol = symbol->next)
        printf("Symbol %s : %s\n", symbol->identifier, type_name(symbol->type));
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

void check_function(struct node *function) {
    struct node *id = getchild(function, 0);
    if(search_symbol(symbol_table, id->token) == NULL) {
        insert_symbol(symbol_table, id->token, no_type, function);
    } else {
        printf("Identifier %s already declared\n", id->token);
        semantic_errors++;
    }
    
    struct symbol_list* scope_func = check_parameters(getchild(function, 1));
    check_expression(getchild(function, 2), scope_func);
    // free scope_func memory
    struct symbol_list *temp = scope_func;
    while (temp != NULL) {
        temp = temp->next;
        free(scope_func);
        scope_func = temp;
    }
}

struct symbol_list* check_parameters(struct node* parameters) {
    struct node_list *child = parameters->children;
    struct symbol_list *scope = (struct symbol_list *) malloc(sizeof(struct symbol_list));
    scope->next = NULL;
    while((child = child->next) != NULL){
        //child->node->type = (getchild(child->node, 0)->category == 5 ? 0 : 1);
        if (!insert_symbol(scope, getchild(child->node, 1)->token, (getchild(child->node, 0)->category == 5 ? 0 : 1), getchild(child->node, 1))) {
            printf("Identifier %s already declared line: %d column %d\n", getchild(child->node, 1)->token, getchild(child->node, 1)->token_line, getchild(child->node, 1)->token_column);
            semantic_errors++;
        }
    }
    return scope;  
}

void check_call(struct node* call, struct symbol_list* scope){
    struct node *id = getchild(call, 0);
    struct symbol_list *symbol = search_symbol(symbol_table, id->token);
    if (symbol == NULL) {
        printf("Identifier %s not declared line: %d column %d\n", id->token, id->token_line, id->token_column);
        semantic_errors++;
    } else {
        struct node_list* temp = getchild(call, 1)->children;
        while ((temp = temp->next) != NULL){
            check_expression(temp->node, scope);
        }
        int call_args = 0, func_args = 0;
        struct node_list *child = getchild(call, 1)->children;
        while((child = child->next) != NULL){
            call_args++;
        }
        child = getchild(symbol->node, 1)->children;
        while((child = child->next) != NULL){
            func_args++;
        }
        if (call_args != func_args) {
            printf("Function %s called with wrong number of arguments line: %d column %d\n", id->token, id->token_line, id->token_column);
            semantic_errors++;
        }
        struct node_list *call_child = getchild(call, 1)->children;
        struct node_list *func_child = getchild(symbol->node, 1)->children;
        while ((call_child = call_child->next) != NULL && (func_child = func_child->next) != NULL) {
            if (call_child->node->type != func_child->node->type) {
                printf("Function %s called with wrong type of arguments line: %d column %d\n", id->token, id->token_line, id->token_column);
                semantic_errors++;
            }
        }
    }
}

void check_expression(struct node* expression, struct symbol_list* scope){
    
    switch (expression->category) {
        case Call:
            check_call(expression, scope);
            break;
        case Identifier:
            if (search_symbol(scope, expression->token) == NULL) {
                printf("Identifier %s not declared line: %d column %d\n", expression->token, expression->token_line, expression->token_column);
                semantic_errors++;
            }
            expression->type = no_type;
            break;
        case If:
            check_expression(getchild(expression, 0), scope);
            check_expression(getchild(expression, 1), scope);
            check_expression(getchild(expression, 2), scope);
            if (getchild(expression, 1)->type == double_type || getchild(expression, 2)->type == double_type || getchild(expression, 1)->type == no_type || getchild(expression, 2)->type == no_type)
                expression->type = double_type;
            else
                expression->type = integer_type;
            break;
        case Add:
            check_expression(getchild(expression, 0), scope);
            check_expression(getchild(expression, 1), scope);
            if (getchild(expression, 0)->type == double_type || getchild(expression, 1)->type == double_type || getchild(expression, 0)->type == no_type || getchild(expression, 1)->type == no_type)
                expression->type = double_type;
            else
                expression->type = integer_type;
            break;
        case Sub:
            check_expression(getchild(expression, 0), scope);
            check_expression(getchild(expression, 1), scope);
            if (getchild(expression, 0)->type == double_type || getchild(expression, 1)->type == double_type || getchild(expression, 0)->type == no_type || getchild(expression, 1)->type == no_type)
                expression->type = double_type;
            else
                expression->type = integer_type;
            break;
        case Mul:
            check_expression(getchild(expression, 0), scope);
            check_expression(getchild(expression, 1), scope);
            if (getchild(expression, 0)->type == double_type || getchild(expression, 1)->type == double_type || getchild(expression, 0)->type == no_type || getchild(expression, 1)->type == no_type)
                expression->type = double_type;
            else
                expression->type = integer_type;
            break;
        case Div:
            check_expression(getchild(expression, 0), scope);
            check_expression(getchild(expression, 1), scope);
            if (getchild(expression, 0)->type == double_type || getchild(expression, 1)->type == double_type || getchild(expression, 0)->type == no_type || getchild(expression, 1)->type == no_type)
                expression->type = double_type;
            else
                expression->type = integer_type;
            break;
        case Natural:
            expression->type = integer_type;
            break;
        case Double:
            expression->type = double_type;
            break;
        default:
            printf("Expression not recognized\n");
            break;
    }   
}

/* 
if(getchild(expression, 0)->category == Call || getchild(expression, 1)->category == Call){
                printf("Error line %d column %d not allowe use function calls in arithemitic operators\n", expression->token_line, expression->token_column);
                semantic_errors++;
            }
if(getchild(expression, 0)->category == Call || getchild(expression, 1)->category == Call){
                printf("Error line %d column %d not allowe use function calls in arithemitic operators\n", expression->token_line, expression->token_column);
                semantic_errors++;
            }
if(getchild(expression, 0)->category == Call || getchild(expression, 1)->category == Call){
                printf("Error line %d column %d not allowe use function calls in arithemitic operators\n", expression->token_line, expression->token_column);
                semantic_errors++;
            }
if(getchild(expression, 0)->category == Call || getchild(expression, 1)->category == Call){
                printf("Error line %d column %d not allowe use function calls in arithemitic operators\n", expression->token_line, expression->token_column);
                semantic_errors++;
            }
*/