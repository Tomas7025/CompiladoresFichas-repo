/* START definitions section -- C code delimited by %{ ... %} and token declarations */

%{

#include "ast.h"

int yylex(void);
void yyerror(char *);

struct node *program;

%}

%token LBRACE RBRACE SEMI IDENTIFIER LPAR RPAR COMMA CHAR INT VOID SHORT DOUBLE ASSIGN IF ELSE WHILE RETURN PLUS MINUS MUL DIV MOD OR BITWISEAND BITWISEOR BITWISEXOR EQ NE LE GE LT GT NOT NATURAL CHRLIT DECIMAL

%left COMMA
%left PLUS MINUS
%left MUL DIV MOD

%union{
    char *lexeme;
    struct node *node;
}

/* START grammar rules section -- BNF grammar */

%%

FunctionsAndDeclarations: FunctionDefinition                                    { /* ... */ }
                        | FunctionDeclaration                                   { /* ... */ }
                        | Declaration                                           { /* ... */ }
                        | FunctionsAndDeclarations FunctionDefinition           { /* ... */ }
                        | FunctionsAndDeclarations FunctionDeclaration          { /* ... */ }
                        | FunctionsAndDeclarations Declaration                  { /* ... */ }
                        ;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody                    { /* ... */ }
                  ;

FunctionBody: LBRACE RBRACE                                                     { /* ... */ }
            | LBRACE DeclarationsAndStatements RBRACE                           { /* ... */ }
            ;   

DeclarationsAndStatements: Statement DeclarationsAndStatements                  { /* ... */ }
                         | Declaration DeclarationsAndStatements                { /* ... */ }
                         | Statement                                            { /* ... */ }
                         | Declaration                                          { /* ... */ }
                         ;  


FunctionDeclaration: TypeSpec FunctionDeclarator SEMI       { /* ... */ }
                    ;   

FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR      { /* ... */ }
                  ; 

ParameterList: ParameterDeclaration                         { /* ... */ }
             | ParameterList COMMA ParameterDeclaration     { /* ... */ }
             ;

ParameterDeclaration: TypeSpec                              { /* ... */ }
                    | TypeSpec IDENTIFIER                   { /* ... */ }
                    ;

Declaration: TypeSpec Declarators SEMI                      { /* ... */ }       //! Comecei a inventar aqui
                                                                                //!
Declarators : Declarator                                    { /* ... */ }       //!
            | Declarators COMMA Declarator                  { /* ... */ }       //!
            ;                                                                   //!

TypeSpec: CHAR                                              { /* ... */ }                                             
        | INT                                               { /* ... */ }      
        | VOID                                              { /* ... */ }
        | SHORT                                             { /* ... */ }
        | DOUBLE                                            { /* ... */ }
        ;

Declarator: IDENTIFIER                                      { /* ... */ }
          | IDENTIFIER ASSIGN Expr                          { /* ... */ }
          ;

Statement: Expr SEMI                                        { /* ... */ }
         | SEMI                                             { /* ... */ }
         | LBRACE RBRACE                                    { /* ... */ }
         | LBRACE Statements RBRACE                         { /* ... */ }
         | IF LPAR Expr RPAR Statement                      { /* ... */ }
         | IF LPAR Expr RPAR Statement ELSE Statement       { /* ... */ }
         | WHILE LPAR Expr RPAR Statement                   { /* ... */ }
         | RETURN SEMI                                      { /* ... */ }
         | RETURN Expr SEMI                                 { /* ... */ }
         ;

Statements: Statement                                       { /* ... */ }    //! Aqui tmb
          | Statements Statement                            { /* ... */ }    //!
          ;                                                                  //!

Expr: Expr ASSIGN Expr                                      { /* ... */ }
    | Expr COMMA Expr                                       { /* ... */ }
    | Expr PLUS Expr                                        { /* ... */ }
    | Expr MINUS Expr                                       { /* ... */ }
    | Expr MUL Expr                                         { /* ... */ }
    | Expr DIV Expr                                         { /* ... */ }
    | Expr MOD Expr                                         { /* ... */ }
    | Expr OR Expr                                          { /* ... */ }
    | Expr BITWISEAND Expr                                  { /* ... */ }
    | Expr BITWISEOR Expr                                   { /* ... */ }
    | Expr BITWISEXOR Expr                                  { /* ... */ }
    | Expr EQ Expr                                          { /* ... */ }
    | Expr NE Expr                                          { /* ... */ }
    | Expr LE Expr                                          { /* ... */ }
    | Expr GE Expr                                          { /* ... */ }
    | Expr LT Expr                                          { /* ... */ }
    | Expr GT Expr                                          { /* ... */ }
    | PLUS Expr                                             { /* ... */ }
    | MINUS Expr                                            { /* ... */ }
    | NOT Expr                                              { /* ... */ }
    | IDENTIFIER LPAR RPAR                                  { /* ... */ }
    | IDENTIFIER LPAR Exprs RPAR                            { /* ... */ }
    | IDENTIFIER                                            { /* ... */ }
    | NATURAL                                               { /* ... */ }
    | CHRLIT                                                { /* ... */ }
    | DECIMAL                                               { /* ... */ }
    | LPAR Expr RPAR                                        { /* ... */ }
    ;

Exprs: Expr                                                 { /* ... */ }   //! Aqui tmb
     | Exprs COMMA Expr                                     { /* ... */ }   //!
     ;                                                                      //!


%%

/* START subroutines section */

// all needed functions are collected in the .l and ast.* files
