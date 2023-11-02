/* START definitions section -- C code delimited by %{ ... %} and token declarations */

%{

#include "ast.h"

int yylex(void);
void yyerror(char *);
void show(struct node *node, int depth);
struct node *program;

char l_category[][20] = { "Program", "Function", "Parameters", "Parameter", "Arguments", "Integer", "Double", "Identifier", "Natural", "Decimal", "Call", "If", "Add", "Sub", "Mul", "Div" };

%}


%union{
    char *token;
    struct node *node;
}

// CHAR, ELSE, WHILE, IF, INT, SHORT, DOUBLE, RETURN, VOID, BITWISEAND, BITWISEOR, BITWISEXOR, AND, MUL, COMMA, DIV, EQ, GE, GT, LBRACE, LE,   
// tratar dos reservads
%token  CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI 
%token<token> IDENTIFIER NATURAL DECIMAL CHRLIT
%type<node> functions_and_declarations function_defenition function_body declarations_and_statements function_declaration function_declarator parameter_list parameter_declaration declaration declarator_repetition typespec declarator statement statement_repetition expression

%nonassoc LOGIC
%nonassoc ELSE

%left COMMA
%right ASSIGN
%left OR
%left AND
%left BITWISEOR
%left BITWISEXOR
%left BITWISEAND
%left EQ NE
%left GT GE LT LE
%left PLUS MINUS
%left MUL DIV MOD
%right NOT


/* START grammar rules section -- BNF grammar */

%%

functions_and_declarations: function_defenition {;}
    | function_declaration {;}
    | declaration {;}
    //| function_defenition functions_and_declarations {;}
    //| function_declaration functions_and_declarations {;}
    //| declaration functions_and_declarations {;}
    | functions_and_declarations function_defenition {;}
    | functions_and_declarations function_declaration {;}
    | functions_and_declarations declaration {;}
    ;


function_defenition: typespec function_declarator function_body {;}
    ;


function_body: LBRACE declarations_and_statements RBRACE {;}
    | LBRACE RBRACE {;}
    ;


declarations_and_statements: declaration {;}
    | statement {;}
    | declaration declarations_and_statements {;}
    | statement declarations_and_statements {;}
    ;


function_declaration: typespec function_declarator SEMI {;}
    ;


function_declarator: IDENTIFIER LPAR parameter_list RPAR {;}
    ;


parameter_list: parameter_declaration {;}
    //| parameter_declaration COMMA parameter_list {;}
    | parameter_list COMMA parameter_declaration {;}
    ;

parameter_declaration: typespec IDENTIFIER {;}
    | typespec {;}
    ;

declaration: typespec declarator_repetition SEMI {;}
    ;

declarator_repetition: declarator {;}
    //| declarator COMMA declarator_repetition {;}
    | declarator_repetition COMMA declarator  {;}
    ;

typespec: CHAR {;}
    | INT {;}
    | VOID {;}
    | SHORT {;}
    | DOUBLE {;}
    ;


declarator: IDENTIFIER {;}
    | IDENTIFIER ASSIGN expression {;}
    ;

statement: RETURN SEMI {;}
    | RETURN expression SEMI {;}
    | WHILE LPAR expression RPAR statement {;}
    | IF LPAR expression RPAR statement %prec LOGIC {;}
    | IF LPAR expression RPAR statement ELSE statement {;}
    | LBRACE statement_repetition RBRACE {;}
    | LBRACE RBRACE {;}
    | expression SEMI {;}
    | SEMI {;} 
    ;

statement_repetition: statement {;}
    //| statement statement_repetition {;}
    | statement_repetition statement {;}
    ;

expression: IDENTIFIER  {;}
    | NATURAL     {;}
    | CHRLIT     {;}
    | DECIMAL     {;}
    | LPAR expression RPAR {;}

    | IDENTIFIER LPAR expression RPAR {;}
    | IDENTIFIER LPAR RPAR {;}
    
    | PLUS expression {;}
    | MINUS expression {;}
    | NOT expression {;}
    
    | expression EQ expression {;}
    | expression NE expression {;}
    | expression LE expression {;}
    | expression GE expression {;}
    | expression LT expression {;}
    | expression GT expression {;}
    
    | expression OR expression {;}
    | expression AND expression {;}
    | expression BITWISEAND expression {;}
    | expression BITWISEOR expression {;}
    | expression BITWISEXOR expression {;}

    | expression PLUS expression {;}
    | expression MINUS expression {;}
    | expression MUL expression {;}
    | expression DIV expression {;}
    | expression MOD expression {;}

    | expression ASSIGN expression {;}
    | expression COMMA expression {;}
    ;


%%

///* START subroutines section */
//void show(struct node *node, int depth){
//  if (node == NULL) return;
//  for(int i = 0; i < depth; i++){
//    printf("__");
//  }
//  if(node->category == Program || node->category ==  Function || node->category ==  Parameters || node->category == Parameter || node->category == Arguments || node->category == Integer || node->category == Double || node->category == Call || node->category == If || node->category == Add || node->category == Sub || node->category == Mul || node->category == Div){
//    printf("%s\n", l_category[node->category]);
//  } else {    
//    printf("%s(%s)\n", l_category[node->category], node->token);
//  }
//  struct node_list *l_child = node->children;
//  while(l_child != NULL){
//    show(l_child->node, depth + 1);
//    l_child = l_child->next;
//  }
//}
//// all needed functions are collected in the .l and ast.* files
//