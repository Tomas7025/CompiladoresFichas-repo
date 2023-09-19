digit   [0-9]
fchar [a-z]
body [a-z0-9A-Z]
keywords integer|double|if|then|else
toIgnore " "|\n|\t
punctuationMarks [()=,\*\+-]

%%
{keywords}                  { printf("Token 4- %s\n", yytext); }
{digit}+                    { printf("NATURAL(%s)\n", yytext); }
{digit}*"."{digit}+         { printf("DECIMAL(%s)\n", yytext); }
{fchar}{body}*              { printf("IDENTIFIER(%s)\n", yytext); }
{toIgnore}                  {;}
{punctuationMarks}          { printf("%s", yytext); }
.                           { printf("error... %d", yyleng); } 
%%
extern int yylex();
int main() {
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}
