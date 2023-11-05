#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

char *category_m[] = category_map;
extern struct node_list *gc;


// create a node of a given category with a given lexical symbol
struct node *newnode(enum category category, char *token) {
    struct node *new = malloc(sizeof(struct node));
    new->category = category;
    new->token = token;
    new->children = malloc(sizeof(struct node_list));
    new->children->node = NULL;
    new->children->next = NULL;

    add_gc(new);

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
    // printf("new->category(%s)\n", category_m[new->node->category]);
}


void show(struct node *node, int depth){
  if (node == NULL) return;
  for(int i = 0; i < depth; i++){
    printf("..");
  }
  if(!node->token){
    printf("%s\n", category_m[node->category]);
  } else {    
    printf("%s(%s)\n", category_m[node->category], node->token);
  }
  struct node_list *child = node->children;
  while(child != NULL){
    show(child->node, depth + 1);
    child = child->next;
  }
}

void clear(struct node *node) {
  if (node == NULL) return;
  struct node_list *cursor = node->children->next;   // 1o elemento de node
  struct node_list *aux;
  while (cursor) {
    clear(cursor->node);            // Chama clear para os seus filhos
    aux = cursor->next;             // Guarda o seguinte
    free(cursor);                   // Liberta o atual
    cursor = aux;                   // cursor avança
  }
  free(node->children);
  free(node);
}

void add_gc(struct node *node) {
  struct node_list *cursor = gc;
  while (cursor->next) cursor = cursor->next;                                       // avanca para o final do gc
  struct node_list *temp = (struct node_list *)malloc(sizeof(struct node_list));    // alloc no novo node de node_list
  temp->node = node;                                                                // node desse novo passa a ser node
  temp->next = NULL;           
  cursor->next = temp;                                                     // o proximo é NULL
}
