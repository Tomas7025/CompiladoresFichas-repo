#include <stdlib.h>
#include <stdio.h>
#include "ast.h"
#include "semantics.h"

char *category_m[] = category_map;
extern struct node_list *gc;

extern struct symbol_list *search_symbol_categ(struct symbol_list *table, char *identifier, enum category category);
extern struct symbol_list *global_scope;


// create a node of a given category with a given lexical symbol
struct node *newnode(enum category category, char *token) {
    struct node *new = malloc(sizeof(struct node));
    new->category = category;
    new->token = token;
    new->children = malloc(sizeof(struct node_list));
    new->children->node = NULL;
    new->children->next = NULL;
    new->type = no_type;
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
    printf("%s", category_m[node->category]);
  } else {    
    printf("%s(%s)", category_m[node->category], node->token);
  }
  if (node->type != no_type) {
    printf(" - %s\n", type_name(node->type));
  } else {
    printf("\n");
  }
  struct node_list *child = node->children;

  if (node->category == Call) {
    struct node_list *params_cursor = getchild(search_symbol_categ(global_scope, child->next->node->token, FuncDeclaration)->node, 2)->children;

    for(int i = 0; i < depth + 1; i++){
      printf("..");
    }
    printf("%s(%s) - %s(", category_m[child->next->node->category], child->next->node->token, type_name(child->next->node->type));
    
    while ((params_cursor = params_cursor->next) != NULL) {
      printf("%s", type_name(map_cat_typ(getchild(params_cursor->node, 0)->category)));
      if (params_cursor->next != NULL)
        printf(",");
    }
    printf(")\n");
    child = child->next;
  }

  while((child = child->next) != NULL){
    show(child->node, depth + 1);
  }
}

void clear() {
  struct node_list *cursor = gc;
  struct node_list *sub_aux, *sub_cursor;
  struct node_list *aux;
  while (cursor) {
    
    if (cursor->node) {                           // Caso o node do cursor nao seja NULL
      sub_cursor = cursor->node->children;        // Apaga a sua lista children
      while (sub_cursor) {
        sub_aux = sub_cursor->next;
        free(sub_cursor);
        sub_cursor = sub_aux;
      }
    }
    aux = cursor->next;

    free(cursor->node);
    free(cursor);
    cursor = aux;
  }
}

void add_gc(struct node *node) {
  struct node_list *cursor = gc;
  while (cursor->next) cursor = cursor->next;                                       // avanca para o final do gc
  struct node_list *temp = (struct node_list *)malloc(sizeof(struct node_list));    // alloc no novo node de node_list
  temp->node = node;                                                                // node desse novo passa a ser node
  temp->next = NULL;                                                                // o proximo é NULL
  cursor->next = temp;                                                              
}

// get a pointer to a specific child, numbered 0, 1, 2, ...
struct node *getchild(struct node *parent, int position) {
    struct node_list *children = parent->children;
    while((children = children->next) != NULL)
        if(position-- == 0)
            return children->node;
    return NULL;
}

// count the children of a node
int countchildren(struct node *node) {
    int i = 0;
    while(getchild(node, i) != NULL)
        i++;
    return i;
}