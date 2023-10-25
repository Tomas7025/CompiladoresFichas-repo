/* START definitions section -- C code delimited by %{ ... %} and token declarations */

%{

#include "ast.h"

int yylex(void);
void yyerror(char *);
void show(struct node *node, int depth);
struct node *program;

char l_category[][20] = { "Program", "Function", "Parameters", "Parameter", "Arguments", "Integer", "Double", "Identifier", "Natural", "Decimal", "Call", "If", "Add", "Sub", "Mul", "Div" };

%}

%token INTEGER DOUBLE IF THEN ELSE
%token<token> IDENTIFIER NATURAL DECIMAL
%type<node> program parameters parameter arguments expression

%left LOW
%left '+' '-'
%left '*' '/'

%union{
    char *token;
    struct node *node;
}

/* START grammar rules section -- BNF grammar */

%%

program: IDENTIFIER '(' parameters ')' '=' expression
    | program IDENTIFIER '(' parameters ')' '=' expression
                                    { if (program == NULL){
                                        $$ = program = newnode(Program, NULL);
                                        struct node *function = newnode(Function, NULL);
                                        addchild(function, newnode(Identifier, $1));
                                        addchild(function, $3);
                                        addchild(function, $6);
                                        addchild($$, function);
                                        show($$, 0);
                                      } else {
                                        $$ = program; 
                                        struct node *function = newnode(Function, NULL);
                                        addchild(function, newnode(Identifier, $2));
                                        addchild(function, $4);
                                        addchild(function, $7);
                                        addchild($$, function);
                                        show(function, 1);
                                      }
                                    }
    ;

parameters: parameter               { $$ = newnode(Parameters, NULL);
                                      addchild($$, $1);
                                    }
    | parameters ',' parameter      { addchild($$, $3);
                                    }
    ;

parameter: INTEGER IDENTIFIER       { $$ = newnode(Parameter, NULL);
                                      addchild($$, newnode(Integer, NULL));
                                      addchild($$, newnode(Identifier, $2));
                                    } 
    | DOUBLE IDENTIFIER             { $$ = newnode(Parameter, NULL);
                                      addchild($$, newnode(Double, NULL));
                                      addchild($$, newnode(Identifier, $2));
                                    }
    ;

arguments: expression               { $$ = newnode(Arguments, NULL);
                                      addchild($$, $1);
                                    }
    | arguments ',' expression      { addchild($$, $3); 
                                    }
    ;

expression: IDENTIFIER              { $$ = newnode(Identifier, $1); }
    | NATURAL                       { $$ = newnode(Natural, $1); }
    | DECIMAL                       { $$ = newnode(Decimal, $1); }
    | IDENTIFIER '(' arguments ')'  { $$ = newnode(Call, NULL);
                                      addchild($$, newnode(Identifier, $1));
                                      addchild($$, $3);
                                    }
    | IF expression THEN expression ELSE expression  %prec LOW
                                    { $$ = newnode(If, NULL);
                                      //addchild($$, newnode(If, $1)); // TODO: VER SE FAZ SENTIDO GUARDAR OS LITERAIS IF THEN ELSE (PROVALEMENTE NÃO)
                                      addchild($$, $2);
                                      //addchild($$, newnode(If, $3));
                                      addchild($$, $4);
                                      //addchild($$, newnode(If, $5));
                                      addchild($$, $6);
                                    }
    | expression '+' expression     { $$ = newnode(Add, NULL);
                                      addchild($$, $1);
                                      addchild($$, $3);
                                    }
    | expression '-' expression     { $$ = newnode(Sub, NULL);
                                      addchild($$, $1);
                                      addchild($$, $3);
                                    }
    | expression '*' expression     { $$ = newnode(Mul, NULL);
                                      addchild($$, $1);
                                      addchild($$, $3);
                                    }
    | expression '/' expression     { $$ = newnode(Div, NULL);
                                      addchild($$, $1);
                                      addchild($$, $3);
                                    }
    | '(' expression ')'            { //$$ = newnode(Parameter, NULL);
                                      //addchild($$, $2);
                                      $$ = $2;
                                    }  
    ;

%%

/* START subroutines section */
void show(struct node *node, int depth){
  if (node == NULL) return;
  for(int i = 0; i < depth; i++){
    printf("__");
  }
  if(node->category == Program || node->category ==  Function || node->category ==  Parameters || node->category == Parameter || node->category == Arguments || node->category == Integer || node->category == Double || node->category == Call || node->category == If || node->category == Add || node->category == Sub || node->category == Mul || node->category == Div){
    printf("%s\n", l_category[node->category]);
  } else {    
    printf("%s(%s)\n", l_category[node->category], node->token);
  }
  struct node_list *l_child = node->children;
  while(l_child != NULL){
    show(l_child->node, depth + 1);
    l_child = l_child->next;
  }
}
// all needed functions are collected in the .l and ast.* files
