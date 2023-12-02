#ifndef _SEMANTICS_H
#define _SEMANTICS_H

#include "ast.h"

struct symbol_list *search_symbol(struct symbol_list *table, char *identifier);
int check_program(struct node *program);
int valid_signature(struct node* original, struct node *new);
int valid_void(struct node *new);
#define map_typ(x) (x == Int ? "int" : (x == Double ? "double" : (x == Short ? "short" : (x == Char ? "char" : "void"))))

struct symbol_list {
	char *identifier;
	enum type type;
	struct node *node;
	struct symbol_list *next;
	struct symbol_list *scope;
};

void show_symbol_table();
enum type map_cat_typ(enum category category);

#endif