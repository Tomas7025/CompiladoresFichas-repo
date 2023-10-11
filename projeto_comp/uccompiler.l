/* João Pedro Henriques dos Santos nº2021236820 Tomás Sousa Azougado nº2021237129 */

digit               [0-9]
indentifier_body    [a-z0-9A-Z_]
keywords            double|if|else|char|void|return|while|short|int
to_ignore           " "|\t|\n|\r
exp                 [eE][+-]?[0-9]+
esc                 \\\\|\\n|\\t|\\\'|\\\"|\\[0-7]{1,3}
punctuation         \,|\;|\(|\)|\{|\}
operators           \+|\-|\*|\/|\%|\&|\||\^|\!|\=|\<|\>|\=\=|\>\=|\<\=|\!\=|\|\||\&\&

reserved            break|\+\+|--|\[|\]|auto|case|const|continue|default|do|enum|extern|inline|volatile|_Bool|_Complex|for|long|sizeof|register|float|goto|restrict|signed|static|struct|switch|typedef|union|unsigned|_Imaginary

%X COMMENT

%{
    #include <string.h>

    int feedback = 0;

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
 
    #define UPPER_CASE(str) \
        { \
            for(int i = 0; str[i] != 0; i++) { \
                if (str[i] >= 'a' && str[i] <= 'z') { \
                    str[i] = str[i] - 'a' + 'A'; \
                } \
            } \
        }

    int previus_l_number = 1;
    int previus_c_number = 1;
    int line_number = 1;
    int colum_number = 1;
    int aux, aux2;
    
    char *map_tokens[] = {
        "BITWISEAND", "&",
        "BITWISEOR", "|",
        "BITWISEXOR", "^",
        "AND", "&&",
        "ASSIGN", "=",
        "MUL", "*",
        "COMMA", ",",
        "DIV", "/",
        "EQ", "==",
        "GE", ">=",
        "GT", ">",
        "LBRACE", "{",
        "LE", "<=",
        "LPAR", "(",
        "LT", "<",
        "MINUS", "-",
        "MOD", "%",
        "NE", "!=",
        "NOT", "!",
        "OR", "||",
        "PLUS", "+",
        "RBRACE", "}",
        "RPAR", ")",
        "SEMI", ";"
    };

    int map_tk() {
        for(int i = 0; i < sizeof(map_tokens) / sizeof(char*); i += 2) {
            if (strcmp(yytext, map_tokens[i + 1]) == 0) {
                return i;
            }
        }
        return -1;
    }
%}
%%

{reserved}                                                      { if (feedback) printf("RESERVED(%s)\n", yytext); }
{keywords}                                                      { if (feedback) { UPPER_CASE(yytext); printf("%s\n", yytext); } }

[a-zA-Z_]{indentifier_body}*                                    { if (feedback) printf("IDENTIFIER(%s)\n", yytext); }
{digit}+                                                        { if (feedback) printf("NATURAL(%s)\n", yytext); }
[0-9]+\.[0-9]*{exp}?|\.[0-9]+{exp}?|[0-9]+{exp}                 { if (feedback) printf("DECIMAL(%s)\n", yytext); }
'({esc}|[^\\\n'])'                                              { if (feedback) printf("CHRLIT(%s)\n", yytext); }

'(\\[^\n]|[^\\\n'])*'                                           { printf("Line %d, column %d: invalid char constant (%s)\n", previus_l_number, previus_c_number, yytext); }
'(\\[^\n]|[^\\\n'])*\\?                                         { printf("Line %d, column %d: unterminated char constant\n", previus_l_number, previus_c_number); }

"/*"                                                            { BEGIN COMMENT; aux = previus_l_number; aux2 = previus_c_number; }
<COMMENT>.|\n                                                   { ; }
<COMMENT>"*/"                                                   { BEGIN INITIAL; }
<COMMENT><<EOF>>                                                { printf("Line %d, column %d: unterminated comment\n", aux, aux2); BEGIN INITIAL; }

{punctuation}                                                   { if (feedback) printf("%s\n", map_tokens[map_tk()]); }
{operators}                                                     { if (feedback) printf("%s\n", map_tokens[map_tk()]); }
\/\/.*                                                          { ; }
{to_ignore}                                                     { ; }
.                                                               { printf("Line %d, column %d: unrecognized character (%c)\n", previus_l_number, previus_c_number, yytext[0]); }

%%

extern int yylex();
int main(int argc, char *argv[]) {

    if (argc >= 2 && strcmp(argv[1], "-l") == 0) {
        feedback = 1;
    }

    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}
