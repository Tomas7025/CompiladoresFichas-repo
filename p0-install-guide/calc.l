%{
#include <string.h>
#include "y.tab.h"
%}

%%
[a-zA-Z]+ { yylval.name = strdup(yytext); 
            printf ("scanned the identifier %s\n", yylval.name);
            return NAME;
          }
[0-9]+    { yylval.value = atoi(yytext); 
            printf ("scanned the number %d\n", yylval.value);
            return NUMBER;
          }
[ \t]     { printf ("skipped whitespace\n"); }
\n        { printf ("reached end of line\n");
            return 0;
          }
.         {   printf ("found other data \"%s\"\n", yytext);
            return yytext[0];
            /* so yacc can see things like '+', '-', and '=' */
          }
%%

int yywrap() {
    return 1;
}

void yyerror (char *msg) {
    fprintf (stderr, "YACC: %s\n", msg);
    return;
}


