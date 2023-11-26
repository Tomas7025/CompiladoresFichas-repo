#ifndef _AST_H
#define _AST_H


#define category_map { "Program", "Declaration", "FuncDeclaration", "FuncDefinition", "ParamList", "FuncBody", "ParamDeclaration", "StatList", "If", "While", "Return", "Or", "And", "Eq", "Ne", "Lt", "Gt", "Le", "Ge", "Add", "Sub", "Mul", "Div", "Mod", "Not", "Minus", "Plus", "Store", "Comma", "Call", "BitWiseAnd", "BitWiseXor", "BitWiseOr", "Char", "ChrLit", "Identifier", "Int", "Short", "Natural", "Double", "Decimal", "Void", "Null", "Error" }
enum category { Program, Declaration, FuncDeclaration, FuncDefinition, ParamList, FuncBody, ParamDeclaration, StatList, If, While, Return, Or, And, Eq, Ne, Lt, Gt, Le, Ge, Add, Sub, Mul, Div, Mod, Not, Minus, Plus, Store, Comma, Call, BitWiseAnd, BitWiseXor, BitWiseOr, Char, ChrLit, Identifier, Int, Short, Natural, Double, Decimal, Void, Null, Error };
enum type { void_type, char_type, short_type, integer_type, double_type, no_type, undefined_type };
#define type_name(x) (x == integer_type ? "int" : (x == short_type ? "short" : (x == void_type ? "void" : (x == double_type ? "double" : (x == char_type ? "char" : "undef")))))

struct node {
    enum category category;
    char *token;
    struct node_list *children;
    enum type type;
    int token_line, token_column;
};

struct node_list {
    struct node *node;
    struct node_list *next;
};

struct node *newnode(enum category category, char *token);
void addchild(struct node *parent, struct node *child);
void show(struct node *node, int depth, int anotations);
void clear();
void add_gc(struct node *node);
struct node *getchild(struct node *parent, int position);

int countchildren(struct node *node);



#endif