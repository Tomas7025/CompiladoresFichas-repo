digit   [0-9]
fchar [a-z]
body [a-z0-9A-Z]
keywords integer|double|if|then|else
toIgnore " "|\t
punctuationMarks [()=,\*\+-]
%{
    int colum_number = 1, line_number = 1;
%}
%%
{keywords}                  { printf("%s\n", yytext), colum_number += yyleng; }
{digit}+                    { printf("NATURAL(%s)\n", yytext), colum_number += yyleng; }
{digit}*"."{digit}+         { printf("DECIMAL(%s)\n", yytext), colum_number += yyleng; }
{fchar}{body}*              { printf("IDENTIFIER(%s)\n", yytext), colum_number += yyleng; }
{toIgnore}                  { colum_number += yyleng; }
{punctuationMarks}          { printf("%s\n", yytext); }
"\n"                        { line_number++, colum_number = 1; }
.                           { printf("Unrecognized character '%s' (line %d, column %d)\n", yytext, line_number, colum_number), colum_number += yyleng; } 
%%
extern int yylex();
int main() {
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}
