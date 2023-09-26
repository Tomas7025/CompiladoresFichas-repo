digit   [0-9]
fchar [a-z]
body [a-z0-9A-Z]
keywords integer|double|if|then|else
toIgnore " "|\t|\n
punctuationMarks [()=,\*\+-]
%{
    #define YY_USER_ACTION \
    { \
        if (yyleng != 1) \
            colum_number += yyleng; \
        else if (yytext[0] == '\n') { \
            colum_number = 0; \
            line_number++; \
        } else \
            colum_number++; \
    } 
    
    int colum_number = 0, line_number = 1;
%}
%%
{keywords}                  { printf("%s\n", yytext); }
{digit}+                    { printf("NATURAL(%s)\n", yytext); }
{digit}*"."{digit}+         { printf("DECIMAL(%s)\n", yytext); }
{fchar}{body}*              { printf("IDENTIFIER(%s)\n", yytext); }
{toIgnore}                  { ; }
{punctuationMarks}          { printf("%s\n", yytext); }
.                           { printf("Unrecognized character '%s' (line %d, column %d)\n", yytext, line_number, colum_number); } 
%%
extern int yylex();
int main() {
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}
