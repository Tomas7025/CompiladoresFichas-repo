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
        if (yy_start != COMMENT) { \
            if (yyleng != 1) \
                colum_number += yyleng; \
            else if (yytext[0] == '\n') { \
                colum_number = 0; \
                line_number++; \
            } else \
                colum_number++; \
        } \
    } 
    
    int colum_number = 0, line_number = 1;
%}
%%
{keywords}                  { printf("%s\n", yytext); }
[a-z]{indentifier_body}*    { printf("IDENTIFIER(%s)\n", yytext); }
{digit}+                    { printf("NATURAL(%s)\n", yytext); }
{digit}*"."{digit}+         { printf("DECIMAL(%s)\n", yytext); }
"/*"                        { BEGIN COMMENT; }
<COMMENT>.                  { ; }
<COMMENT>"*/"               { BEGIN INITIAL; }
{punctuationMarks}          { printf("%s\n", yytext); }
"\""                        { BEGIN STRLIT; }
<STRLIT>{ strings_body }*"\""    { printf("STRLIT(\"%s\")", yytext); BEGIN 0; }
<STRLIT>[^\"]               { printf("Unrecognized character '%s' (line %d, column %d)\n", yytext, line_number, colum_number); }
<STRLIT>"\""                { BEGIN 0; }
{toIgnore}                  { ; }
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

