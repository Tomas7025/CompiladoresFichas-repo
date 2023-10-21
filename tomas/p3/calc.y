%{
#include <stdio.h>
extern int yylex(void);
void yyerror(char *);
extern char *yytext;
%}

%left ','
%token NATURAL
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%%

calculator: expression                  { printf("%d\n", $1); }
          | calculator ',' expression   { printf("%d\n", $3); }
          ;

expression: NATURAL                     { $$ = $1; }
          | '-' expression %prec UMINUS { $$ = -$2; }
          | expression '+' expression   { $$ = $1 + $3; }
          | expression '-' expression   { $$ = $1 - $3; }
          | expression '*' expression   { $$ = $1 * $3; }
          | expression '/' expression   { $$ = $1 / $3; }
          | '(' expression ')'          { $$ = $2; }
          ;

%%

void yyerror(char *error) {
    printf("%s '%s'\n", error, yytext);
}
