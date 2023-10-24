%{
#include <stdio.h>
extern int yylex(void);
void yyerror(char *);
extern char *yytext;
extern int previus_l_number;
extern int previus_c_number;
%}

%token NATURAL IF THEN ELSE
%nonassoc LOGIC
%left ','
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%%

calculator: expression                  { printf("%d", $1); }
          | calculator ',' expression   { printf(", %d", $3); }
          ;

expression: NATURAL                     { $$ = $1; }
          | '-' expression %prec UMINUS { $$ = -$2; }
          | expression '+' expression   { $$ = $1 + $3; }
          | expression '-' expression   { $$ = $1 - $3; }
          | expression '*' expression   { $$ = $1 * $3; }
          | expression '/' expression   { $$ = $1 / $3; }
          | '(' expression ')'          { $$ = $2; }
          | IF expression THEN expression ELSE expression %prec LOGIC { $$ = $2 ? $4 : $6; }
          ;

%%

void yyerror(char *error) {
    printf("%s '%s', line number: %d column number: %d\n", error, yytext, previus_l_number, previus_c_number);
}
