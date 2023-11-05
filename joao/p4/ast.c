#include <stdlib.h>
#include <stdio.h>
#include "ast.h"


// create a node of a given category with a given lexical symbol
struct node *newnode(enum category category, char *token) {
    struct node *new = malloc(sizeof(struct node));
    new->category = category;
    new->token = token;
    new->children = malloc(sizeof(struct node_list));
    new->children->node = NULL;
    new->children->next = NULL;
    return new;
}

// append a node to the list of children of the parent node
void addchild(struct node *parent, struct node *child) {
    struct node_list *new = malloc(sizeof(struct node_list));
    new->node = child;
    new->next = NULL;
    struct node_list *children = parent->children;
    while(children->next != NULL)
        children = children->next;
    children->next = new;
}


void show(struct node *node, int depth) {
    // if (node == NULL) return;
    for (int i = 0; i < depth; i++) printf("__");
    categoryMap(node->category);
    if (node->token) {
        printf("(%s)\n", node->token);
    }
    else {
        printf("\n");
    }
    struct node_list *aux = node->children->next;
    
    while (aux != NULL) {
        show(aux->node, depth + 1);
        aux = aux->next;
    }
}

// enum category { , , , , , , , , , , , , , , , Div };

void categoryMap(int en) {
    switch (en)
    {
    case 0:
        printf("Program");
        break;
    
    case 1:
        printf("Function");
        break;
    
    case 2:
        printf("Parameters");
        break;
    
    case 3:
        printf("Parameter");
        break;
    
    case 4:
        printf("Arguments");
        break;
    
    case 5:
        printf("Integer");
        break;
    
    case 6:
        printf("Double");
        break;
    
    case 7:
        printf("Identifier");
        break;
    
    case 8:
        printf("Natural");
        break;
    
    case 9:
        printf("Decimal");
        break;
    
    case 10:
        printf("Call");
        break;
    
    case 11:
        printf("If");
        break;
    
    case 12:
        printf("Add");
        break;
    
    case 13:
        printf("Sub");
        break;
    
    case 14:
        printf("Mul");
        break;
    
    case 15:
        printf("Div");
        break;
    }
}
