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
%token<token> IDENTIFIER NATURAL DECIMAL CHARLIT
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


expression:
    | IDENTIFIER  {;}
    | NATURAL     {;}
    | DECIMAL     {;}
    | CHARLIT     {;}
    | '(' expression ')' {;}

    | IDENTIFIER '(' arguments ')' {;}
    | IDENTIFIER '(' ')' {;}
    
    | PLUS expression %prec LOW {;}
    | MINUS expression %prec LOW {;}
    | NOT expression {;}
    
    | expression EQ expression {;}
    | expression NE expression {;}
    | expression LE expression {;}
    | expression GE expression {;}
    | expression LT expression {;}
    | expression GT expression {;}
    
    | expression PLUS expression {;}
    | expression MINUS expression {;}
    | expression MULL expression {;}
    | expression DIV expression {;}
    | expression MOD expression {;}
    
    | expression AND expression {;}
    | expression OR expression {;}
    | expression BITWISEOR expression {;}
    | expression BITWISEAND expression {;}
    | expression BITWISEXOR expression {;}


arguments:
    | expression {;}
    | arguments ',' expression {;}

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
