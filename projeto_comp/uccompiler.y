/* START definitions section -- C code delimited by %{ ... %} and token declarations */

%{

#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
extern int yylex(void);
void yyerror(char *);
extern char *yytext;

struct node *program;
extern int errors;
extern char *category_m[];
%}


%union{
    char *token;
    struct node *node;
}

%token CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI RESERVED
%token<token> IDENTIFIER NATURAL DECIMAL CHRLIT
%type<node> functions_and_declarations function_defenition function_body declarations_and_statements function_declaration function_declarator parameter_list parameter_declaration declaration declarator_repetition typespec declarator statement statement_repetition expression expression_repetition

%nonassoc LOGIC
%nonassoc ELSE

%left COMMA
%left ARGS
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

%locations
%{
    #define LOCATE(node, line, column) { \
        node->token_line = line; \
        node->token_column = column; \
    }
%}

/* START grammar rules section -- BNF grammar */

%%

functions_and_declarations: function_defenition                     { if (errors > 0) { break; }
                                                                      $$ = program = newnode(Program, NULL); 
                                                                      addchild($$, $1);
                                                                    }
    | function_declaration                                          { if (errors > 0) { break; }
                                                                      $$ = program = newnode(Program, NULL); 
                                                                      addchild($$, $1);
                                                                    }
    | declaration                                                   { if (errors > 0) { break; }
                                                                      $$ = $1; 
                                                                      $$->category = Program;
                                                                      program = $$;
                                                                    }
    | functions_and_declarations function_defenition                { if (errors > 0) { break; }
                                                                      addchild($1, $2);
                                                                      $$ = $1;
                                                                    }
    | functions_and_declarations function_declaration               { if (errors > 0) { break; }
                                                                      addchild($1, $2);
                                                                      $$ = $1;
                                                                    }
    | functions_and_declarations declaration                        { if (errors > 0) { break; }
                                                                      struct node_list *aux = $1->children->next;   //Aponta para o 1o de $1
                                                                      while(aux->next) { aux = aux->next; }         //Avança aux para apontar para o ultimo elemento
                                                                      aux->next = $2->children->next;               //Liga ao 1o de funcBody
                                                                      // free($2->children);
                                                                      // free($2);
                                                                      
                                                                      // addchild($1, $2);
                                                                      // $$ = $1;
                                                                    }
    ;


function_defenition: typespec function_declarator function_body     { if (errors > 0) { break; }
                                                                      $$ = $2; 
                                                                      $$->category = FuncDefinition;
                                                                      // Insere typespec no inicio
                                                                      struct node_list *temp = (struct node_list *)malloc(sizeof(struct node_list));
                                                                      temp->node = $1;
                                                                      temp->next = $$->children->next;
                                                                      $$->children->next = temp;
                                                                      
                                                                      addchild($$, $3);
                                                                    }
    ;


function_body: LBRACE declarations_and_statements RBRACE     { if (errors > 0) { break; }
                                                               if($2 != NULL)
                                                                $$ = $2;
                                                               else
                                                                $$ = newnode(FuncBody, NULL);
                                                             }
    | LBRACE RBRACE                                          {if (errors > 0) { break; }
                                                              $$ = newnode(FuncBody, NULL); }
    ;


declarations_and_statements: declaration                     { if (errors > 0) { break; }
                                                               $$ = $1; }
    | statement                                              { if (errors > 0) { break; }
                                                               if ($1 != NULL) {
                                                                $$ = newnode(FuncBody, NULL);
                                                                addchild($$, $1);
                                                               } else
                                                                $$ = NULL;
                                                             }
    | declarations_and_statements declaration                { if (errors > 0) { break; }
                                                               if($1 == NULL)
                                                                $$ = newnode(FuncBody, NULL);
                                                               struct node_list *aux = $$->children; 
                                                               while (aux->next != NULL) {
                                                                aux = aux->next;
                                                               }
                                                               aux->next = $2->children->next;
                                                              //  free($2->children);
                                                              //  free($2);
                                                             }
    | declarations_and_statements statement                  { if (errors > 0) { break; }
                                                                if($1 != NULL){
                                                                $$ = $1;
                                                                if($2 != NULL) addchild($$, $2);
                                                               } else {
                                                                if ($2 != NULL) {
                                                                  $$ = newnode(FuncBody, NULL);
                                                                  addchild($$, $2);
                                                                } else
                                                                  $$ = NULL;
                                                               }
                                                             }
    ;


function_declaration: typespec function_declarator SEMI      { if (errors > 0) { break; }
                                                               $$ = $2;
                                                               $$->category = FuncDeclaration;
                                                               // Insere typespec no inicio
                                                               struct node_list *temp = (struct node_list *)malloc(sizeof(struct node_list));
                                                               temp->node = $1;
                                                               temp->next = $$->children->next;
                                                               $$->children->next = temp;
                                                             }
    ;


function_declarator: IDENTIFIER LPAR parameter_list RPAR    { if (errors > 0) { break; }
                                                              $$ = newnode(Null, NULL);
                                                              addchild($$, newnode(Identifier, $1));
                                                              addchild($$, $3);

                                                              LOCATE(getchild($$, 0), @1.first_line, @1.first_column);
                                                            }
    ;


parameter_list: parameter_declaration                       { if (errors > 0) { break; }
                                                              $$ = newnode(ParamList, NULL); 
                                                              addchild($$, $1);
                                                            }
    | parameter_list COMMA parameter_declaration            { if (errors > 0) { break; }
                                                              addchild($1, $3); 
                                                              $$ = $1;
                                                            }
    
parameter_declaration: typespec IDENTIFIER                  { if (errors > 0) { break; }
                                                              $$ = newnode(ParamDeclaration, NULL); 
                                                              addchild($$, $1);
                                                              addchild($$, newnode(Identifier, $2));

                                                              LOCATE($$, @2.first_line, @2.first_column);
                                                            }
    | typespec                                              { if (errors > 0) { break; }
                                                              $$ = newnode(ParamDeclaration, NULL); 
                                                              addchild($$, $1);
                                                            }
    
declaration: typespec declarator_repetition SEMI            { if (errors > 0) { break; }
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
    | error SEMI                                            { }
    
declarator_repetition: declarator                           { if (errors > 0) { break; }            
                                                              $$ = newnode(FuncBody, NULL);
                                                              addchild($$, $1);            
                                                            }
    | declarator_repetition COMMA declarator                { if (errors > 0) { break; }
                                                              addchild($1, $3); 
                                                              $$ = $1;
                                                            }
    
typespec: CHAR                                              { if (errors > 0) { break; }
                                                              $$ = newnode(Char, NULL); }
    | INT                                                   { if (errors > 0) { break; }
                                                              $$ = newnode(Int, NULL); }   //printf("transformou em typespec\n")
    | VOID                                                  { if (errors > 0) { break; }
                                                              $$ = newnode(Void, NULL); 
                                                              LOCATE($$, @1.first_line, @1.first_column);
                                                            }
    | SHORT                                                 { if (errors > 0) { break; }
                                                              $$ = newnode(Short, NULL); }
    | DOUBLE                                                { if (errors > 0) { break; }
                                                              $$ = newnode(Double, NULL); }
    
declarator: IDENTIFIER ASSIGN expression                    { if (errors > 0) { break; }
                                                              $$ = newnode(Declaration, NULL);      
                                                              addchild($$, newnode(Identifier, $1));
                                                              addchild($$, $3);

                                                              LOCATE($$, @1.first_line, @1.first_column);
                                                            }
    | IDENTIFIER                                            { if (errors > 0) { break; }
                                                              $$ = newnode(Declaration, NULL);             // Declaration
                                                              addchild($$, newnode(Identifier, $1));       //   | ID    

                                                              LOCATE($$, @1.first_line, @1.first_column);           
                                                            } 
    ;

statement: expression SEMI                                   { if (errors > 0) { break; }$$ = $1; }
    | SEMI                                                    { if (errors > 0) { break; }$$ = NULL; }
    | LBRACE statement_repetition RBRACE                     { if (errors > 0) { break; }$$ = $2; }
    | LBRACE RBRACE                                           { if (errors > 0) { break; }$$ = NULL; }

    | IF LPAR expression RPAR statement %prec LOGIC          { if (errors > 0) { break; }
                                                               $$ = newnode(If, NULL);
                                                               addchild($$, $3);
                                                               if ($5 == NULL) 
                                                                 addchild($$, newnode(Null, NULL));
                                                                else
                                                                 addchild($$, $5);
                                                               
                                                               addchild($$, newnode(Null, NULL));
                                                               LOCATE($$, @1.first_line, @1.first_column);
                                                             }
    | IF LPAR expression RPAR statement ELSE statement       { if (errors > 0) { break; }
                                                               $$ = newnode(If, NULL);
                                                               addchild($$, $3);
                                                               
                                                               if ($5 == NULL) 
                                                                 addchild($$, newnode(Null, NULL));
                                                                else
                                                                 addchild($$, $5);
                                                               
                                                               if ($7 == NULL) 
                                                                 addchild($$, newnode(Null, NULL));
                                                                else
                                                                 addchild($$, $7);

                                                              LOCATE($$, @1.first_line, @1.first_column);
                                                             }
    | WHILE LPAR expression RPAR statement                   { if (errors > 0) { break; }
                                                               $$ = newnode(While, NULL);
                                                               addchild($$, $3);
                                                               if ($5 == NULL) 
                                                                 addchild($$, newnode(Null, NULL));
                                                                else
                                                                 addchild($$, $5);
                                                                LOCATE($$, @1.first_line, @1.first_column);
                                                             }
    | RETURN expression SEMI                                 { if (errors > 0) { break; }
                                                               $$ = newnode(Return, NULL);
                                                               addchild($$, $2);
                                                               LOCATE($$, @1.first_line, @1.first_column);
                                                             }
    | RETURN SEMI                                            { if (errors > 0) { break; }
                                                               $$ = newnode(Return, NULL);
                                                               addchild($$, newnode(Null, NULL));
                                                               LOCATE($$, @1.first_line, @1.first_column);
                                                             }
    | LBRACE error RBRACE                                    { }

    
    | IF LPAR expression RPAR error SEMI %prec LOGIC          { }
    | IF LPAR expression RPAR error SEMI ELSE statement       { }
    | IF LPAR expression RPAR statement ELSE error SEMI       { }
    | IF LPAR expression RPAR error SEMI ELSE error SEMI      { }
    | WHILE LPAR expression RPAR error SEMI                   { }
    ;

statement_repetition: statement             { if (errors > 0) { break; } $$ = $1; }
    | statement_repetition statement        { if (errors > 0) { break; }
                                              if($2 != NULL){
                                                if ($1 != NULL && $1->category == StatList)  {
                                                  addchild($1, $2);
                                                  $$ = $1;
                                                } else if ($1 != NULL) {
                                                  $$ = newnode(StatList, NULL);
                                                  addchild($$, $1);
                                                  addchild($$, $2);
                                                } else {
                                                  $$ = $2;
                                                }
                                              } else {
                                                $$ = $1;
                                              }
                                            }

    | statement_repetition error SEMI       { }
    | error SEMI                            { }
    ;

expression: expression ASSIGN expression    { if (errors > 0) { break; }
                                              $$ = newnode(Store, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3);

                                              LOCATE($$, @2.first_line, @2.first_column);
                                            }
    | expression COMMA expression           { if (errors > 0) { break; }
                                              $$ = newnode(Comma, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                              // printf("->COMMA<-\n");
                                              LOCATE($$, @2.first_line, @2.first_column);

                                            }

    | expression PLUS expression            { if (errors > 0) { break; }
                                              $$ = newnode(Add, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                              LOCATE($$, @2.first_line, @2.first_column);
                                            }
    | expression MINUS expression           { if (errors > 0) { break; }
                                              $$ = newnode(Sub, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                              LOCATE($$, @2.first_line, @2.first_column);
                                            }
    | expression MUL expression             { if (errors > 0) { break; }
                                              $$ = newnode(Mul, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                              LOCATE($$, @2.first_line, @2.first_column);
                                            }
    | expression DIV expression             { if (errors > 0) { break; }
                                              $$ = newnode(Div, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                              LOCATE($$, @2.first_line, @2.first_column);
                                            }
    | expression MOD expression             { if (errors > 0) { break; }
                                              $$ = newnode(Mod, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                              LOCATE($$, @2.first_line, @2.first_column);
                                            }
    
    | expression OR expression              { if (errors > 0) { break; }
                                              $$ = newnode(Or, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                              LOCATE($$, @2.first_line, @2.first_column);
                                            }
    | expression AND expression             { if (errors > 0) { break; }
                                              $$ = newnode(And, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                              LOCATE($$, @2.first_line, @2.first_column);
                                            }
    | expression BITWISEAND expression      { if (errors > 0) { break; }
                                              $$ = newnode(BitWiseAnd, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                              LOCATE($$, @2.first_line, @2.first_column);
                                            }
    | expression BITWISEOR expression       { if (errors > 0) { break; }
                                              $$ = newnode(BitWiseOr, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                              LOCATE($$, @2.first_line, @2.first_column);
                                            }
    | expression BITWISEXOR expression      { if (errors > 0) { break; }
                                              $$ = newnode(BitWiseXor, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                              LOCATE($$, @2.first_line, @2.first_column);
                                            }
    
    | expression EQ expression              { if (errors > 0) { break; }
                                              $$ = newnode(Eq, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                              LOCATE($$, @2.first_line, @2.first_column);
                                            }
    | expression NE expression              { if (errors > 0) { break; } 
                                              $$ = newnode(Ne, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3);
                                              LOCATE($$, @2.first_line, @2.first_column);
                                            }
    | expression LE expression              { if (errors > 0) { break; } 
                                              $$ = newnode(Le, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                              LOCATE($$, @2.first_line, @2.first_column);
                                            }
    | expression GE expression              { if (errors > 0) { break; } 
                                              $$ = newnode(Ge, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                              LOCATE($$, @2.first_line, @2.first_column);
                                            }
    | expression LT expression              { if (errors > 0) { break; } 
                                              $$ = newnode(Lt, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                              LOCATE($$, @2.first_line, @2.first_column);
                                            }
    | expression GT expression              { if (errors > 0) { break; } 
                                              $$ = newnode(Gt, NULL);
                                              addchild($$, $1); 
                                              addchild($$, $3); 
                                              LOCATE($$, @2.first_line, @2.first_column);
                                            }
    
    | PLUS expression %prec POLARITY        { if (errors > 0) { break; } 
                                              $$ = newnode(Plus, NULL);
                                              addchild($$, $2); 
                                              LOCATE($$, @1.first_line, @1.first_column);
                                            }
    | MINUS expression %prec POLARITY       { if (errors > 0) { break; } 
                                              $$ = newnode(Minus, NULL);
                                              addchild($$, $2);
                                              LOCATE($$, @1.first_line, @1.first_column); 
                                            }
    | NOT expression                        { if (errors > 0) { break; } 
                                              $$ = newnode(Not, NULL);
                                              addchild($$, $2);  
                                              LOCATE($$, @1.first_line, @1.first_column);
                                            }

    | IDENTIFIER LPAR expression_repetition RPAR       { if (errors > 0) { break; }
                                                         $$ = $3;
                                                         struct node_list *temp = (struct node_list *) malloc(sizeof(struct node_list));
                                                         temp->node = newnode(Identifier, $1);
                                                         temp->next = $3->children->next;
                                                         $3->children->next = temp;

                                                         LOCATE($$, @1.first_line, @1.first_column);
                                                       }
    | IDENTIFIER LPAR RPAR                  { if (errors > 0) { break; }
                                              $$ = newnode(Call, NULL); 
                                              addchild($$, newnode(Identifier, $1));

                                              LOCATE($$, @1.first_line, @1.first_column);
                                            }

    | IDENTIFIER                            { if (errors > 0) { break; }
                                              $$ = newnode(Identifier, $1); 
                                              LOCATE($$, @1.first_line, @1.first_column);
                                            }
    | NATURAL                               { if (errors > 0) { break; }
                                              $$ = newnode(Natural, $1); 
                                              LOCATE($$, @1.first_line, @1.first_column);
                                            }
    | CHRLIT                                { if (errors > 0) { break; }
                                              $$ = newnode(ChrLit, $1);
                                              LOCATE($$, @1.first_line, @1.first_column);
                                            }
    | DECIMAL                               { if (errors > 0) { break; }
                                              $$ = newnode(Decimal, $1);
                                              LOCATE($$, @1.first_line, @1.first_column);
                                            }
    | LPAR expression RPAR                  { if (errors > 0) { break; }
                                              $$ = $2; }

    | IDENTIFIER LPAR error RPAR            { ; }
    | LPAR error RPAR                       { ; }
    ;

expression_repetition: expression %prec ARGS                  { if (errors > 0) { break; }
                                                                $$ = newnode(Call, NULL);
                                                                addchild($$, $1);
                                                              }
  | expression_repetition COMMA expression                    { if (errors > 0) { break; }
                                                                $$ = $1;
                                                                addchild($$, $3);
                                                              }
  ;

%%



/* 
Declaration −→ error SEMI
Statement −→ error SEMI
Statement −→ LBRACE error RBRACE
Expression −→ IDENTIFIER LPAR error RPAR
Expression −→ LPAR error RPAR
*/
