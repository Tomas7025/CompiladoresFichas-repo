/* START definitions section -- C code delimited by %{ ... %} and token declarations */

%{

//#include "ast.h"

int yylex(void);
void yyerror(char *);

struct node *program;

// char l_category[][20] = { "Program", "Function", "Parameters", "Parameter", "Arguments", "Integer", "Double", "Identifier", "Natural", "Decimal", "Call", "If", "Add", "Sub", "Mul", "Div" };

%}


%union{
    char *token;
    struct node *node;
}

// CHAR, ELSE, WHILE, IF, INT, SHORT, DOUBLE, RETURN, VOID, BITWISEAND, BITWISEOR, BITWISEXOR, AND, MUL, COMMA, DIV, EQ, GE, GT, LBRACE, LE,   
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


/* START grammar rules section -- BNF grammar */

%%

functions_and_declarations: function_defenition                     {;}
    | function_declaration                                          {;}
    | declaration                                                   {;}
    | functions_and_declarations function_defenition                {;}
    | functions_and_declarations function_declaration               {;}
    | functions_and_declarations declaration                        {;}
    ;


function_defenition: typespec function_declarator function_body     {;}
    ;


function_body: LBRACE declarations_and_statements RBRACE     {;}
    | LBRACE RBRACE                                          {;}
    ;


declarations_and_statements: declaration                     {;}
    | statement                                              {;}
    | declaration declarations_and_statements                {;}
    | statement declarations_and_statements                  {;}
    ;


function_declaration: typespec function_declarator SEMI      {;}
    ;


function_declarator: IDENTIFIER LPAR parameter_list RPAR     {;}
    ;


parameter_list: parameter_declaration                        {;}
    | parameter_list COMMA parameter_declaration             {;}
    ;

parameter_declaration: typespec IDENTIFIER                   {;}
    | typespec                                               {;}
    ;

declaration: typespec declarator_repetition SEMI             {;}
    | error SEMI                                             {;}
    ;

declarator_repetition: declarator                            {;}
    | declarator_repetition COMMA declarator                 {;}
    ;

typespec: CHAR                                               {;}
    | INT                                                    {;}
    | VOID                                                   {;}
    | SHORT                                                  {;}
    | DOUBLE                                                 {;}
    ;

declarator: IDENTIFIER ASSIGN expression                     {;}
    | IDENTIFIER                                             {;}
    ;

statement: expression SEMI                                   {;}
    | SEMI                                                   {;}
    | LBRACE statement_repetition RBRACE                     {;}
    | LBRACE RBRACE                                          {;}
    | IF LPAR expression RPAR statement %prec LOGIC          {;}
    | IF LPAR expression RPAR statement ELSE statement       {;}
    | WHILE LPAR expression RPAR statement                   {;}
    | RETURN expression SEMI                                 {;}
    | RETURN SEMI                                            {;}


    | LBRACE error RBRACE                                    {;}
    | WHILE LPAR expression RPAR error                       {;}
    | IF LPAR expression RPAR error %prec LOGIC              {;}    
    | IF LPAR expression RPAR statement ELSE error           {;}    
    | IF LPAR expression RPAR error ELSE statement           {;}    
    | IF LPAR expression RPAR error ELSE error               {;}
    //| RETURN error SEMI                                             {;}
    ;

statement_repetition: statement             {;}
    | statement_repetition statement        {;}
    | statement_repetition error            {;}
    ;

expression: expression ASSIGN expression    {;}
    | expression COMMA expression           {;}

    | expression PLUS expression            {;}
    | expression MINUS expression           {;}
    | expression MUL expression             {;}
    | expression DIV expression             {;}
    | expression MOD expression             {;}
    
    | expression OR expression              {;}
    | expression AND expression             {;}
    | expression BITWISEAND expression      {;}
    | expression BITWISEOR expression       {;}
    | expression BITWISEXOR expression      {;}
    
    | expression EQ expression              {;}
    | expression NE expression              {;}
    | expression LE expression              {;}
    | expression GE expression              {;}
    | expression LT expression              {;}
    | expression GT expression              {;}
    
    | PLUS expression                       {;}
    | MINUS expression                      {;}
    | NOT expression                        {;}

    | IDENTIFIER LPAR expression RPAR       {;}
    | IDENTIFIER LPAR RPAR                  {;}

    | IDENTIFIER                            {;}
    | NATURAL                               {;}
    | CHRLIT                                {;}
    | DECIMAL                               {;}
    | LPAR expression RPAR                  {;}

    | IDENTIFIER LPAR error RPAR            {;}
    | LPAR error RPAR                       {;}
    ;



%%

