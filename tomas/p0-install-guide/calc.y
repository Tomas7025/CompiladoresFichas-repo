%{
    #include <stdio.h>
    void yyerror (char *);
    int yylex(void);
%}

%token <name> NAME;
%token <value> NUMBER;
%type <value> expression;

%union {
    char *name;
    int value;
}

%%

statement: NAME '=' expression    { printf("pretending to assign %s the value %d\n",
                                                                        $1, $3); } ;
    | expression                  { printf("= %d\n", $1); }
    ;
expression: expression '+' NUMBER { $$ = $1 + $3;
                                    printf ("Recognized '+' expression.\n");
                                  }
    | expression '-' NUMBER       { $$ = $1 - $3; 
                                    printf ("Recognized '-' expression.\n");
                                  }
    | NUMBER                      { $$ = $1; 
                                    printf ("Recognized a number.\n");
                                  }
    ;

%%

int main () {
    yyparse();
    return 0;
}


