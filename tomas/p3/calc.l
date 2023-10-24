%{
#include "y.tab.h"
int yyparse(void);

#define YY_USER_ACTION \
    { \
        previus_l_number = line_number; \
        previus_c_number = colum_number; \
        for(int i = 0; yytext[i] != 0; i++) { \
            if (yytext[i] == '\n') { \
                line_number++; \
                colum_number = 1; \
            } else { \
                colum_number++; \
            } \
        } \
    } 
    int previus_l_number = 1;
    int previus_c_number = 1;
    int line_number = 1;
    int colum_number = 1;
%}
digit   [0-9]
%%

{digit}+                { yylval = atoi(yytext); return NATURAL; }
[()=,*/+-]              { return yytext[0]; }
"if"                    { yylval = atoi(yytext); return IF; }
"then"                  { yylval = atoi(yytext); return THEN; }
"else"                  { yylval = atoi(yytext); return ELSE; }
\n                      { return 0; } 
[ \t]                   { ; }
.                       { printf("Unrecognized character %s, %d, %d\n", yytext, previus_l_number, previus_c_number); }
%%

int main() {
    yyparse();
    return 0;
}
int yywrap() {
    return 1;
}
