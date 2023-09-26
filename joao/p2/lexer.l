digit           [0-9]
keywords        integer|double|if|then|else
ignore          " "|\n|\t|\r
punct           [()=,\*/+-]

%X COMMENT

%{
    int l = 1;
    int c = 1;
%}

%%
"/*"                        { BEGIN COMMENT; }
<COMMENT>"*/"               { BEGIN 0; }
<COMMENT>.|\n               { ; }
\"\"
\n                          { l++; c = 1; }
{keywords}                  { printf("%s\n", yytext); c++; }
{ignore}                    { c++; }
{punct}                     { printf("%s\n", yytext); c++;}
{digit}+                    { printf("NATURAL(%s)\n", yytext); c++; }
{digit}*"."{digit}+         { printf("DECIMAL(%s)\n", yytext); c++; }
[a-zA-Z][0-9a-zA-Z]*	    { printf("IDENTIFIER(%s)\n", yytext); c++; }
.                           { printf("Unrecognized character \'%s\' (line %d, column %d)\n", yytext, l, c); c++; }
%%
extern int yylex();
int main() {
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}
