digit               [0-9]
indentifier_body    [a-z0-9A-Z_]
keywords            double|if|else|char|void|return|while|short|int
to_ignore            " "|\t|\n|\r
exp                 [eE][+-]?[0-9]+
char_body           [a-zA-Z0-9_]|\\\\|\\n|\\t|\\\'|\\\"|\\[0-7]{1,3}
%X COMMENT STRLIT
%{
    #define YY_USER_ACTION \
    { \
        for(int i = 0; yytext[i] != 0; i++) { \
            if (yytext[i] == '\n') { \
                line_number++; \
                colum_number = 1; \
            } else { \
                colum_number++; \
            } \
        } \
    } 

    #define UPPER_CASE(str) \
        { \
            for(int i = 0; str[i] != 0; i++) { \
                if (str[i] >= 'a' && str[i] <= 'z') { \
                    str[i] = str[i] - 'a' + 'A'; \
                } \
            } \
        }

    #define UNRECOGNIZED_CHAR(n_l, n_C) { \
        printf("Unrecognized character %c (line %d, column %d)\n", yytext[0], n_l, n_C); \
    }

    int colum_number = 1, line_number = 1;
%}
%%
{keywords}                                                      { UPPER_CASE(yytext); printf("%s\n", yytext); }
[a-zA-Z]{indentifier_body}*                                     { printf("IDENTIFIER(%s)\n", yytext); }
{digit}+                                                        { printf("NATURAL(%s)\n", yytext); }
[0-9]+\.[0-9]*{exp}?|\.[0-9]+{exp}?|[0-9]+{exp}                 { printf("DECIMAL(%s)\n", yytext); }
'{char_body}'                                                   { printf("CHARACTER(%s)\n", yytext); }
'([^'])*\n                                                      { printf("Line %d, column %d: unterminated character\n", line_number, colum_number); }
'[^char_body|\n|\']'|\'\'                                       { printf("Line %d, column %d: invalid character constant\n", line_number, colum_number); }
'[^\n|\']*'                                                     { printf("Line %d, column %d: invalid character format\n", line_number, colum_number); }
"/*"                                                            { BEGIN COMMENT; }
<COMMENT>.|\n                                                   { ; }
<COMMENT>"*/"                                                   { BEGIN INITIAL; }
<COMMENT><<EOF>>                                                { printf("Line %d, column %d: unterminated comment\n", line_number, colum_number); BEGIN INITIAL; }
{to_ignore}                                                     { ; }
.                                                               { UNRECOGNIZED_CHAR(line_number-1, colum_number-1); }
%%
extern int yylex();
int main() {
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}
