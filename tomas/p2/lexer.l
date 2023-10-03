digit               [0-9]
indentifier_body    [a-z0-9A-Z_]
keywords            integer|double|if|then|else
toIgnore            " "|\t|\n
punctuationMarks    [()=,\*\+-;{}]
strings_body        [a-zA-Z0-9_ ]
%X COMMENT STRLIT
%{
    #define YY_USER_ACTION \
    { \
        if (yyleng != 1) \
            colum_number += yyleng; \
        else if (yytext[0] == '\n') { \
            printf("BREAK_LINE\n"); \
            colum_number = 0; \
            line_number++; \
        } else \
            colum_number++; \
    } 

    #define UPPER_CASE(str) \
        { \
            for(int i = 0; str[i] != 0; i++) { \
                if (str[i] >= 'a' && str[i] <= 'z') { \
                    str[i] = str[i] - 'a' + 'A'; \
                } \
            } \
        }

    #define UNRECOGNIZED_CHAR printf("Unrecognized character '%c' (line %d, column %d)\n", yytext[0], line_number, colum_number);

    int colum_number = 0, line_number = 1;
%}
%%
{keywords}                                { UPPER_CASE(yytext); printf("%s\n", yytext); }
[a-zA-Z]{indentifier_body}*               { printf("IDENTIFIER(%s)\n", yytext); }
{digit}+                                  { printf("NATURAL(%s)\n", yytext); }
{digit}*"."{digit}+                       { printf("DECIMAL(%s)\n", yytext); }
\"                                        { BEGIN STRLIT; }
<STRLIT>{strings_body}*\"                 { printf("STRLIT(%s)\n", yytext), BEGIN INITIAL; }
<STRLIT>[^a-zA-Z0-9_ \f\"]{strings_body}*\"  { UNRECOGNIZED_CHAR; BEGIN INITIAL; }
<STRLIT>{strings_body}                    { ; }
<STRLIT>[^a-zA-Z0-9_ \f\"]                { UNRECOGNIZED_CHAR; }
{punctuationMarks}                        { printf("%s\n", yytext); }
"/*"                                      { BEGIN COMMENT; }
<COMMENT>.|\n                             { ; }
<COMMENT>"*/"                             { BEGIN INITIAL; }
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
