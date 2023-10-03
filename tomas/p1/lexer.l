digit   [0-9]
indentifier_body [a-z0-9A-Z_]
keywords integer|double|if|then|else
toIgnore " "|\t|\n
punctuationMarks [()=,\*\+-;{}]
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
    
    #define UPPER_CASE(str) \
    { \
        for(int i = 0; str[i] != 0; i++) { \
            if (str[i] >= 'a' && str[i] <= 'z') { \
                str[i] = str[i] - 'a' + 'A'; \
            } \
        } \
    }
    
    int colum_number = 0, line_number = 1;
    
%}
%%
{keywords}                  { UPPER_CASE(yytext); printf("%s\n", yytext); }
[a-z]{indentifier_body}*                { printf("IDENTIFIER(%s)\n", yytext); }
{digit}+                    { printf("NATURAL(%s)\n", yytext); }
{digit}*"."{digit}+         { printf("DECIMAL(%s)\n", yytext); }
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
