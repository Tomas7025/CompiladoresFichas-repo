// macros.h

#ifndef MACROS_H
#define MACROS_H

#define YY_USER_ACTION \
    { \
        if (yyleng != 1) \
            colum_number += yyleng; \
        else if (yytext[0] == '\n') { \
            printf("BREAK_LINE\n"); \
            colum_number = 0; \
            line_number++; \
        } else \
            colum_number++; \
    } 

#define UPPER_CASE(str) \
    { \
        for(int i = 0; str[i] != 0; i++) { \
            if (str[i] >= 'a' && str[i] <= 'z') { \
                str[i] = str[i] - 'a' + 'A'; \
            } \
        } \
    }

#define UNRECOGNIZED_CHAR printf("Unrecognized character '%c' (line %d, column %d)\n", yytext[0], line_number, colum_number);

#endif
