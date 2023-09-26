digit               [0-9]
indentifier_body    [a-z0-9A-Z_]
keywords            integer|double|if|then|else
toIgnore            " "|\t|\n
punctuationMarks    [()=,\*\+-]
strings_body        [a-zA-Z0-9_ \n\f\r]
%X COMMENT STRLIT
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
    
    #define UNRECOGNIZED_CHAR printf("Unrecognized character '%c' (line %d, column %d)\n", yytext[0], line_number, colum_number);
    
    int colum_number = 0, line_number = 1;
%}
%%
{keywords}                                { printf("%s\n", yytext); }
[a-zA-Z]{indentifier_body}*               { printf("IDENTIFIER(%s)\n", yytext); }
{digit}+                                  { printf("NATURAL(%s)\n", yytext); }
{digit}*"."{digit}+                       { printf("DECIMAL(%s)\n", yytext); }
"/*"                                      { BEGIN COMMENT; }
<COMMENT>.|\n                             { ; }
<COMMENT>"*/"                             { BEGIN INITIAL; }
\"                                        { BEGIN STRLIT, printf("%d %d ok\n", line_number, colum_number); }
<STRLIT>{strings_body}*\"                 { printf("Acabou de aparecer uma string.\n"), BEGIN INITIAL; }
<STRLIT>[^a-zA-Z0-9_ \n\f\r\"]{strings_body}*\"  { BEGIN INITIAL, printf("%s, deu mal\n", yytext); }
<STRLIT>{strings_body}                    { ; }
<STRLIT>.                                 { UNRECOGNIZED_CHAR; }
{punctuationMarks}                        { printf("%s\n", yytext); }
{toIgnore}                                { ; }
.                                         { UNRECOGNIZED_CHAR; } 
%%
extern int yylex();
int main() {
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}
