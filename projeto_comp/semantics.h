#ifndef _SEMANTICS_H
#define _SEMANTICS_H

#include "ast.h"

int check_program(struct node *program);

struct symbol_list {
	char *identifier;
	enum type type;
	struct node *node;
	struct symbol_list *next;
	struct symbol_list *scope;
};

void show_symbol_table();
extern char *category_m[];

#endif