#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"
#include "codegen.h"

int temporary;   // sequence of temporary registers in a function

extern struct symbol_list *global_scope;

int codegen_global_vars(struct symbol_list *global_scope) {
    struct symbol_list *global_cur = global_scope;

    while ((global_cur = global_scope->next) != NULL) {
        if (global_cur->node->category == Declaration) {
            // global_cur->node getchild(node, 2)->token
        }
    }
    return 0;
}
