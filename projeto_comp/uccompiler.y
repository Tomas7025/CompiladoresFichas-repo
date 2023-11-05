/* START definitions section -- C code delimited by %{ ... %} and token declarations */

%{

#include "ast.h"
#include <stdio.h>
extern int yylex(void);
void yyerror(char *);
extern char *yytext;

struct node *program;
extern char *category_m[];

%}


%union{
    char *token;
    struct node *node;
}

// tratar dos reservads
%token CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI RESERVED
%token<token> IDENTIFIER NATURAL DECIMAL CHRLIT
%type<node> functions_and_declarations function_defenition function_body declarations_and_statements function_declaration function_declarator parameter_list parameter_declaration declaration declarator_repetition typespec declarator statement statement_repetition expression

%nonassoc LOGIC
%nonassoc ELSE

%left COMMA
%right ASSIGN
%left OR
%left AND
%left BITWISEOR
%left BITWISEXOR
%left BITWISEAND
%left EQ NE
%left GT GE LT LE
%left PLUS MINUS
%left MUL DIV MOD
%right NOT

%nonassoc POLARITY

/* START grammar rules section -- BNF grammar */

%%

functions_and_declarations: function_defenition                     { $$ = program = newnode(Program, NULL); 
                                                                      addchild($$, $1);
                                                                    }
    | function_declaration                                          { $$ = program = newnode(Program, NULL); 
                                                                      addchild($$, $1);
                                                                    }
    | declaration                                                   { $$ = program = newnode(Program, NULL); 
                                                                      addchild($$, $1);
                                                                    }
    | functions_and_declarations function_defenition                { addchild($1, $2);
                                                                      $$ = $1;
                                                                    }
    | functions_and_declarations function_declaration               { addchild($1, $2);
                                                                      $$ = $1;
                                                                    }
    | functions_and_declarations declaration                        { addchild($1, $2);
                                                                      $$ = $1;
                                                                    }
    ;


function_defenition: typespec function_declarator function_body     { $$ = $2; 
                                                                      $$->category = FuncDefinition;
                                                                      // Insere typespec no inicio
                                                                      struct node_list *temp = (struct node_list *)malloc(sizeof(struct node_list));
                                                                      temp->node = $1;
                                                                      temp->next = $$->children->next;
                                                                      $$->children->next = temp;
                                                                      
                                                                      addchild($$, $3);
                                                                    }
    ;


function_body: LBRACE declarations_and_statements RBRACE     { $$ = $2;}
    | LBRACE RBRACE                                          { $$ = newnode(FuncBody, NULL); }
    ;


declarations_and_statements: declaration                     { $$ = $1; }
    | statement                                              { $$ = newnode(FuncBody, NULL);
                                                               addchild($$, $1);
                                                             }
    | declarations_and_statements declaration                { struct node_list *aux = $$->children; 
                                                               while (aux->next != NULL) {
                                                                aux = aux->next;
                                                               }
                                                               aux->next = $2->children->next;
                                                               free($2->children);
                                                               free($2);
                                                             }
    | declarations_and_statements statement                  { $$ = $1;
                                                               addchild($$, $2);
                                                             }
    ;


function_declaration: typespec function_declarator SEMI      { $$ = $2;
                                                               $$->category = FuncDeclaration;
                                                               // Insere typespec no inicio
                                                               struct node_list *temp = (struct node_list *)malloc(sizeof(struct node_list));
                                                               temp->node = $1;
                                                               temp->next = $$->children->next;
                                                               $$->children->next = temp;
                                                             }
    ;


function_declarator: IDENTIFIER LPAR parameter_list RPAR     { $$ = newnode(Null, NULL);
                                                               addchild($$, newnode(Identifier, $1));
                                                               addchild($$, $3);
                                                             }
    ;


parameter_list: parameter_declaration                        { $$ = newnode(ParamList, NULL); 
                                                               addchild($$, $1);
                                                             }
    | parameter_list COMMA parameter_declaration             { addchild($1, $3); 
                                                               $$ = $1;
                                                             }
    ;

parameter_declaration: typespec IDENTIFIER                   { $$ = newnode(ParamDeclaration, NULL); 
                                                               addchild($$, $1);
                                                               addchild($$, newnode(Identifier, $2));
                                                             }
    | typespec                                               { $$ = newnode(ParamDeclaration, NULL); 
                                                               addchild($$, $1);
                                                             }
    ;

declaration: typespec declarator_repetition SEMI             {
                                                                struct node_list *aux = $2->children->next;                                         // Aponta para o primeiro filho do node FuncBody

                                                                while(aux != NULL){                                                                 // Percorre os filhos dele
                                                                    struct node_list* temp = (struct node_list*)malloc(sizeof(struct node_list));   // Cria um novo node_list
                                                                    temp->node = $1;                                                                // Que guarda o TypeSpec
                                                                    temp->next = aux->node->children->next;                                         // E que aponta para o antigo 1o node
                                                                    aux->node->children->next = temp;                                               // O 1o node passa a ser o temp (TypeSpec)
                                                                    
                                                                    aux = aux->next;                                                                // Avança para o proximo filho FuncBody
                                                                }
                                                                $$ = $2;                                                                            // Passa para $$ o FuncBody
                                                             }
    | error SEMI                                             {;}
    ;

declarator_repetition: declarator                            {             
                                                               $$ = newnode(FuncBody, NULL);
                                                               addchild($$, $1);            
                                                             }
    | declarator_repetition COMMA declarator                 { addchild($1, $3); 
                                                               $$ = $1;
                                                             }
    ;

typespec: CHAR                                               { $$ = newnode(Char, NULL); }
    | INT                                                    { $$ = newnode(Int, NULL); }   //printf("transformou em typespec\n")
    | VOID                                                   { $$ = newnode(Void, NULL); }
    | SHORT                                                  { $$ = newnode(Short, NULL); }
    | DOUBLE                                                 { $$ = newnode(Double, NULL); }
    ;

declarator: IDENTIFIER ASSIGN expression                     {  $$ = newnode(Declaration, NULL);      
                                                                addchild($$, newnode(Identifier, $1));
                                                                addchild($$, $3);
                                                             }
    | IDENTIFIER                                             { 
                                                               $$ = newnode(Declaration, NULL);             // Declaration
                                                               addchild($$, newnode(Identifier, $1));       //   | ID               
                                                             } 
    ;

statement: expression SEMI                                   { $$ = $1; }
    | SEMI                                                   { $$ = newnode(Null, NULL); }
    | LBRACE statement_repetition RBRACE                     { $$ = $2; }
    | LBRACE RBRACE                                          { $$ = newnode(Null, NULL); }
    | IF LPAR expression RPAR statement %prec LOGIC          { $$ = newnode(If, NULL);
                                                               addchild($$, $3);
                                                               addchild($$, $5);
                                                               addchild($$, newnode(Null, NULL));
                                                             }
    | IF LPAR expression RPAR statement ELSE statement       { $$ = newnode(If, NULL);
                                                               addchild($$, $3);
                                                               addchild($$, $5);
                                                               addchild($$, $7);
                                                             }
    | WHILE LPAR expression RPAR statement                   { $$ = newnode(While, NULL);
                                                               addchild($$, $3);
                                                               addchild($$, $5);
                                                             }
    | RETURN expression SEMI                                 { $$ = newnode(Return, NULL);
                                                               addchild($$, $2);
                                                             }
    | RETURN SEMI                                            { $$ = newnode(Return, NULL);
                                                               addchild($$, newnode(Null, NULL));
                                                             }
    | LBRACE error RBRACE                                    {;}

    
    | IF LPAR expression RPAR error SEMI %prec LOGIC          {;}
    | IF LPAR expression RPAR error SEMI ELSE statement       {;}
    | IF LPAR expression RPAR statement ELSE error SEMI       {;}
    | IF LPAR expression RPAR error SEMI ELSE error SEMI      {;}
    | WHILE LPAR expression RPAR error SEMI                   {;}
    ;

statement_repetition: statement             { $$ = $1; }
    | statement_repetition statement        { if ($1->category == StatList)  {
                                                addchild($1, $2);
                                                $$ = $1;
                                              } else {
                                                $$ = newnode(StatList, NULL);
                                                addchild($$, $1);
                                                addchild($$, $2);
                                              }
                                            }

    | statement_repetition error SEMI       {;}
    | error SEMI                            {;}
    ;

expression: expression ASSIGN expression    { $$ = newnode(Store, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                            }
    | expression COMMA expression           { $$ = newnode(Comma, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                            }

    | expression PLUS expression            { $$ = newnode(Add, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                            }
    | expression MINUS expression           { $$ = newnode(Sub, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                            }
    | expression MUL expression             { $$ = newnode(Mul, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                            }
    | expression DIV expression             { $$ = newnode(Div, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                            }
    | expression MOD expression             { $$ = newnode(Mod, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                            }
    
    | expression OR expression              { $$ = newnode(Or, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                            }
    | expression AND expression             { $$ = newnode(And, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                            }
    | expression BITWISEAND expression      { $$ = newnode(BitWiseAnd, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                            }
    | expression BITWISEOR expression       { $$ = newnode(BitWiseOr, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                            }
    | expression BITWISEXOR expression      { $$ = newnode(BitWiseXor, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                            }
    
    | expression EQ expression              { $$ = newnode(Eq, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                            }
    | expression NE expression              { $$ = newnode(Ne, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                            }
    | expression LE expression              { $$ = newnode(Le, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                            }
    | expression GE expression              { $$ = newnode(Ge, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                            }
    | expression LT expression              { $$ = newnode(Lt, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                            }
    | expression GT expression              { $$ = newnode(Gt, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                            }
    
    | PLUS expression %prec POLARITY        { $$ = newnode(Plus, NULL);
                                              addchild($$, $2); 
                                            }
    | MINUS expression %prec POLARITY       { $$ = newnode(Minus, NULL);
                                              addchild($$, $2); 
                                            }
    | NOT expression                        { $$ = newnode(Not, NULL);
                                              addchild($$, $2);  
                                            }

    | IDENTIFIER LPAR expression RPAR       { $$ = newnode(Call, NULL); 
                                              addchild($$, newnode(Identifier, $1));
                                              addchild($$, $3); 
                                            }
    | IDENTIFIER LPAR RPAR                  { $$ = newnode(Call, NULL); 
                                              addchild($$, newnode(Identifier, $1));
                                            }

    | IDENTIFIER                            { $$ = newnode(Identifier, $1); }
    | NATURAL                               { $$ = newnode(Natural, $1); }
    | CHRLIT                                { $$ = newnode(ChrLit, $1); }
    | DECIMAL                               { $$ = newnode(Decimal, $1); }
    | LPAR expression RPAR                  { $$ = $2; }

    | IDENTIFIER LPAR error RPAR            { $$ = newnode(Error, NULL); }
    | LPAR error RPAR                       { $$ = newnode(Error, NULL); }
    ;


%%



/* 
Declaration −→ error SEMI
Statement −→ error SEMI
Statement −→ LBRACE error RBRACE
Expression −→ IDENTIFIER LPAR error RPAR
Expression −→ LPAR error RPAR
*/
