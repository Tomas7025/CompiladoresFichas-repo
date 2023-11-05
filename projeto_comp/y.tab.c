/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "uccompiler.y"


#include "ast.h"
#include <stdio.h>
extern int yylex(void);
void yyerror(char *);
extern char *yytext;

struct node *program;
extern char *category_m[];


#line 84 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CHAR = 258,                    /* CHAR  */
    ELSE = 259,                    /* ELSE  */
    WHILE = 260,                   /* WHILE  */
    IF = 261,                      /* IF  */
    INT = 262,                     /* INT  */
    SHORT = 263,                   /* SHORT  */
    DOUBLE = 264,                  /* DOUBLE  */
    RETURN = 265,                  /* RETURN  */
    VOID = 266,                    /* VOID  */
    BITWISEAND = 267,              /* BITWISEAND  */
    BITWISEOR = 268,               /* BITWISEOR  */
    BITWISEXOR = 269,              /* BITWISEXOR  */
    AND = 270,                     /* AND  */
    ASSIGN = 271,                  /* ASSIGN  */
    MUL = 272,                     /* MUL  */
    COMMA = 273,                   /* COMMA  */
    DIV = 274,                     /* DIV  */
    EQ = 275,                      /* EQ  */
    GE = 276,                      /* GE  */
    GT = 277,                      /* GT  */
    LBRACE = 278,                  /* LBRACE  */
    LE = 279,                      /* LE  */
    LPAR = 280,                    /* LPAR  */
    LT = 281,                      /* LT  */
    MINUS = 282,                   /* MINUS  */
    MOD = 283,                     /* MOD  */
    NE = 284,                      /* NE  */
    NOT = 285,                     /* NOT  */
    OR = 286,                      /* OR  */
    PLUS = 287,                    /* PLUS  */
    RBRACE = 288,                  /* RBRACE  */
    RPAR = 289,                    /* RPAR  */
    SEMI = 290,                    /* SEMI  */
    RESERVED = 291,                /* RESERVED  */
    IDENTIFIER = 292,              /* IDENTIFIER  */
    NATURAL = 293,                 /* NATURAL  */
    DECIMAL = 294,                 /* DECIMAL  */
    CHRLIT = 295,                  /* CHRLIT  */
    LOGIC = 296,                   /* LOGIC  */
    POLARITY = 297                 /* POLARITY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define CHAR 258
#define ELSE 259
#define WHILE 260
#define IF 261
#define INT 262
#define SHORT 263
#define DOUBLE 264
#define RETURN 265
#define VOID 266
#define BITWISEAND 267
#define BITWISEOR 268
#define BITWISEXOR 269
#define AND 270
#define ASSIGN 271
#define MUL 272
#define COMMA 273
#define DIV 274
#define EQ 275
#define GE 276
#define GT 277
#define LBRACE 278
#define LE 279
#define LPAR 280
#define LT 281
#define MINUS 282
#define MOD 283
#define NE 284
#define NOT 285
#define OR 286
#define PLUS 287
#define RBRACE 288
#define RPAR 289
#define SEMI 290
#define RESERVED 291
#define IDENTIFIER 292
#define NATURAL 293
#define DECIMAL 294
#define CHRLIT 295
#define LOGIC 296
#define POLARITY 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "uccompiler.y"

    char *token;
    struct node *node;

#line 226 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CHAR = 3,                       /* CHAR  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_SHORT = 8,                      /* SHORT  */
  YYSYMBOL_DOUBLE = 9,                     /* DOUBLE  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_VOID = 11,                      /* VOID  */
  YYSYMBOL_BITWISEAND = 12,                /* BITWISEAND  */
  YYSYMBOL_BITWISEOR = 13,                 /* BITWISEOR  */
  YYSYMBOL_BITWISEXOR = 14,                /* BITWISEXOR  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_MUL = 17,                       /* MUL  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_DIV = 19,                       /* DIV  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_GE = 21,                        /* GE  */
  YYSYMBOL_GT = 22,                        /* GT  */
  YYSYMBOL_LBRACE = 23,                    /* LBRACE  */
  YYSYMBOL_LE = 24,                        /* LE  */
  YYSYMBOL_LPAR = 25,                      /* LPAR  */
  YYSYMBOL_LT = 26,                        /* LT  */
  YYSYMBOL_MINUS = 27,                     /* MINUS  */
  YYSYMBOL_MOD = 28,                       /* MOD  */
  YYSYMBOL_NE = 29,                        /* NE  */
  YYSYMBOL_NOT = 30,                       /* NOT  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_PLUS = 32,                      /* PLUS  */
  YYSYMBOL_RBRACE = 33,                    /* RBRACE  */
  YYSYMBOL_RPAR = 34,                      /* RPAR  */
  YYSYMBOL_SEMI = 35,                      /* SEMI  */
  YYSYMBOL_RESERVED = 36,                  /* RESERVED  */
  YYSYMBOL_IDENTIFIER = 37,                /* IDENTIFIER  */
  YYSYMBOL_NATURAL = 38,                   /* NATURAL  */
  YYSYMBOL_DECIMAL = 39,                   /* DECIMAL  */
  YYSYMBOL_CHRLIT = 40,                    /* CHRLIT  */
  YYSYMBOL_LOGIC = 41,                     /* LOGIC  */
  YYSYMBOL_POLARITY = 42,                  /* POLARITY  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_functions_and_declarations = 44, /* functions_and_declarations  */
  YYSYMBOL_function_defenition = 45,       /* function_defenition  */
  YYSYMBOL_function_body = 46,             /* function_body  */
  YYSYMBOL_declarations_and_statements = 47, /* declarations_and_statements  */
  YYSYMBOL_function_declaration = 48,      /* function_declaration  */
  YYSYMBOL_function_declarator = 49,       /* function_declarator  */
  YYSYMBOL_parameter_list = 50,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 51,     /* parameter_declaration  */
  YYSYMBOL_declaration = 52,               /* declaration  */
  YYSYMBOL_declarator_repetition = 53,     /* declarator_repetition  */
  YYSYMBOL_typespec = 54,                  /* typespec  */
  YYSYMBOL_declarator = 55,                /* declarator  */
  YYSYMBOL_statement = 56,                 /* statement  */
  YYSYMBOL_statement_repetition = 57,      /* statement_repetition  */
  YYSYMBOL_expression = 58                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   620

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    49,    49,    52,    55,    58,    61,    64,    70,    83,
      84,    88,    89,    92,   100,   106,   117,   124,   127,   132,
     136,   141,   154,   157,   161,   166,   167,   168,   169,   170,
     173,   177,   183,   184,   185,   186,   187,   192,   197,   201,
     204,   207,   210,   211,   212,   213,   214,   217,   218,   228,
     229,   232,   236,   241,   245,   249,   253,   257,   262,   266,
     270,   274,   278,   283,   287,   291,   295,   299,   303,   308,
     311,   314,   318,   322,   326,   327,   328,   329,   330,   332,
     333
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CHAR", "ELSE",
  "WHILE", "IF", "INT", "SHORT", "DOUBLE", "RETURN", "VOID", "BITWISEAND",
  "BITWISEOR", "BITWISEXOR", "AND", "ASSIGN", "MUL", "COMMA", "DIV", "EQ",
  "GE", "GT", "LBRACE", "LE", "LPAR", "LT", "MINUS", "MOD", "NE", "NOT",
  "OR", "PLUS", "RBRACE", "RPAR", "SEMI", "RESERVED", "IDENTIFIER",
  "NATURAL", "DECIMAL", "CHRLIT", "LOGIC", "POLARITY", "$accept",
  "functions_and_declarations", "function_defenition", "function_body",
  "declarations_and_statements", "function_declaration",
  "function_declarator", "parameter_list", "parameter_declaration",
  "declaration", "declarator_repetition", "typespec", "declarator",
  "statement", "statement_repetition", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-44)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     602,   -30,   -44,   -44,   -44,   -44,   -44,   124,   -44,   -44,
     -44,   -31,   -44,   -44,   -44,   -44,   -44,    48,   -22,   -11,
     -44,   562,   609,    71,   -44,   -44,    -1,   -44,   128,   562,
     562,   562,     7,   -44,   -44,   -44,   469,    -9,   -44,     0,
      17,    41,   208,   151,   -44,   -44,   111,   -44,    -1,   -44,
     329,    54,   -44,    51,   377,   -44,   -44,   -44,     1,   562,
     562,   562,   562,   562,   562,   562,   562,   562,   562,   562,
     562,   562,   562,   562,   562,   562,   562,   609,   -44,   -44,
     562,   562,   -44,   353,    36,   -44,   -44,   191,   -44,   -44,
     -44,   -44,   -44,   -44,    52,   -44,   400,   544,   530,   183,
     511,   469,   -44,   469,   -44,   558,    -5,    -5,    -5,    -5,
       2,   -44,   558,   490,     2,   -44,   423,   446,   -44,   -44,
     -44,    40,   -44,   -44,   -44,   -44,   231,   254,   -44,    53,
     -44,    55,    83,   -44,    85,   277,   300,    56,   -44,    60,
     -44,   -44,   -44
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    25,    26,    28,    29,    27,     0,     2,     3,
       4,     0,    22,     1,     5,     6,     7,    31,     0,     0,
      23,     0,     0,     0,    15,     8,     0,    21,     0,     0,
       0,     0,    74,    75,    77,    76,    30,     0,    17,    20,
       0,     0,     0,     0,    10,    33,     0,    11,     0,    12,
       0,    31,    24,     0,     0,    70,    71,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    19,
       0,     0,    40,     0,     0,    35,    47,     0,     9,    13,
      14,    32,    80,    78,     0,    73,     0,    60,    61,    62,
      59,    51,    55,    52,    56,    63,    66,    68,    65,    67,
      54,    57,    64,    58,    53,    18,     0,     0,    39,    41,
      50,     0,    34,    48,    79,    72,     0,     0,    49,     0,
      38,     0,    36,    46,    42,     0,     0,     0,    37,     0,
      43,    44,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -44,   -44,    90,   -44,   -44,    92,   -44,   -44,    23,    -3,
     -44,   -12,    76,   -43,   -44,   -13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,    25,    46,     9,    18,    37,    38,    10,
      19,    11,    20,    49,    87,    50
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      86,    23,    94,    90,    16,    12,    17,    26,    36,    77,
      39,    48,    64,    24,    66,    54,    55,    56,    57,    64,
      47,    66,    72,    73,    27,    78,    28,    76,    29,    83,
      73,    30,    58,    31,    48,    95,    51,    79,    32,    33,
      34,    35,    80,    89,   123,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    21,    39,    81,   116,   117,   119,
      21,   120,     1,    22,     2,   128,    40,    41,     3,     4,
       5,    42,     6,   130,   132,    92,   124,   135,   133,   136,
     134,   141,   138,   140,    43,   142,    28,    14,    29,    15,
     115,    30,    52,    31,    44,     0,    45,     0,    32,    33,
      34,    35,     1,     0,     2,     0,    40,    41,     3,     4,
       5,    42,     6,     0,    13,     1,     0,     2,     0,    53,
       0,     3,     4,     5,    43,     6,    28,     0,    29,     0,
       0,    30,     0,    31,    88,     0,    45,     0,    32,    33,
      34,    35,    84,    28,     0,    29,    40,    41,    30,     0,
      31,    42,     0,     0,     0,    32,    33,    34,    35,     0,
       0,     0,     0,     0,    43,     0,    28,     0,    29,     0,
       0,    30,     0,    31,    85,     0,    45,     0,    32,    33,
      34,    35,   121,     0,     0,    59,    40,    41,     0,     0,
      64,    42,    66,    67,    68,    69,     0,    70,     0,    71,
      72,    73,    74,     0,    43,    76,    28,     0,    29,     0,
       0,    30,     0,    31,   122,     0,    45,     0,    32,    33,
      34,    35,   129,    28,     0,    29,    40,    41,    30,     0,
      31,    42,     0,    82,     0,    32,    33,    34,    35,     0,
       0,     0,     0,     0,    43,   131,    28,     0,    29,    40,
      41,    30,     0,    31,    42,     0,    45,     0,    32,    33,
      34,    35,     0,     0,     0,     0,     0,    43,   137,    28,
       0,    29,    40,    41,    30,     0,    31,    42,     0,    45,
       0,    32,    33,    34,    35,     0,     0,     0,     0,     0,
      43,   139,    28,     0,    29,    40,    41,    30,     0,    31,
      42,     0,    45,     0,    32,    33,    34,    35,     0,     0,
       0,     0,     0,    43,     0,    28,     0,    29,     0,     0,
      30,     0,    31,     0,     0,    45,     0,    32,    33,    34,
      35,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    70,     0,    71,    72,    73,    74,     0,
      75,    76,     0,     0,    91,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,    70,     0,    71,
      72,    73,    74,     0,    75,    76,     0,     0,   118,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,    70,     0,    71,    72,    73,    74,     0,    75,    76,
       0,    93,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,    70,     0,    71,    72,    73,    74,
       0,    75,    76,     0,   125,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,    70,     0,    71,
      72,    73,    74,     0,    75,    76,     0,   126,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
      70,     0,    71,    72,    73,    74,     0,    75,    76,     0,
     127,    59,    60,    61,    62,    63,    64,     0,    66,    67,
      68,    69,     0,    70,     0,    71,    72,    73,    74,     0,
      75,    76,    59,    60,    61,    62,     0,    64,     0,    66,
      67,    68,    69,     0,    70,     0,    71,    72,    73,    74,
       0,     0,    76,    59,    60,    61,     0,     0,    64,     0,
      66,    67,    68,    69,     0,    70,     0,    71,    72,    73,
      74,     0,    59,    76,    61,     0,     0,    64,     0,    66,
      67,    68,    69,     0,    70,     0,    71,    72,    73,    74,
       0,    64,    76,    66,    67,    68,    69,     0,    70,     0,
      71,    72,    73,    74,     0,    64,    76,    66,     0,    68,
      69,     0,    70,     0,    71,    72,    73,    28,     0,    29,
      76,     0,    30,     0,    31,     0,     0,     0,     0,    32,
      33,    34,    35,     1,     0,     2,     0,     0,     0,     3,
       4,     5,     2,     6,     0,     0,     3,     4,     5,     0,
       6
};

static const yytype_int16 yycheck[] =
{
      43,    23,     1,    46,     7,    35,    37,    18,    21,    18,
      22,    23,    17,    35,    19,    28,    29,    30,    31,    17,
      23,    19,    27,    28,    35,    34,    25,    32,    27,    42,
      28,    30,    25,    32,    46,    34,    37,    37,    37,    38,
      39,    40,    25,    46,    87,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    16,    77,    25,    80,    81,    33,
      16,    35,     1,    25,     3,    35,     5,     6,     7,     8,
       9,    10,    11,   126,   127,    34,    34,     4,    35,     4,
      35,    35,   135,   136,    23,    35,    25,     7,    27,     7,
      77,    30,    26,    32,    33,    -1,    35,    -1,    37,    38,
      39,    40,     1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    11,    -1,     0,     1,    -1,     3,    -1,     1,
      -1,     7,     8,     9,    23,    11,    25,    -1,    27,    -1,
      -1,    30,    -1,    32,    33,    -1,    35,    -1,    37,    38,
      39,    40,     1,    25,    -1,    27,     5,     6,    30,    -1,
      32,    10,    -1,    -1,    -1,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    25,    -1,    27,    -1,
      -1,    30,    -1,    32,    33,    -1,    35,    -1,    37,    38,
      39,    40,     1,    -1,    -1,    12,     5,     6,    -1,    -1,
      17,    10,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    29,    -1,    23,    32,    25,    -1,    27,    -1,
      -1,    30,    -1,    32,    33,    -1,    35,    -1,    37,    38,
      39,    40,     1,    25,    -1,    27,     5,     6,    30,    -1,
      32,    10,    -1,    35,    -1,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    23,     1,    25,    -1,    27,     5,
       6,    30,    -1,    32,    10,    -1,    35,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    23,     1,    25,
      -1,    27,     5,     6,    30,    -1,    32,    10,    -1,    35,
      -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      23,     1,    25,    -1,    27,     5,     6,    30,    -1,    32,
      10,    -1,    35,    -1,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    25,    -1,    27,    -1,    -1,
      30,    -1,    32,    -1,    -1,    35,    -1,    37,    38,    39,
      40,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    28,    29,    -1,
      31,    32,    -1,    -1,    35,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    29,    -1,    31,    32,    -1,    -1,    35,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    -1,    31,    32,
      -1,    34,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      -1,    31,    32,    -1,    34,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    29,    -1,    31,    32,    -1,    34,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    -1,    31,    32,    -1,
      34,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    28,    29,    -1,
      31,    32,    12,    13,    14,    15,    -1,    17,    -1,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      -1,    -1,    32,    12,    13,    14,    -1,    -1,    17,    -1,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    -1,    12,    32,    14,    -1,    -1,    17,    -1,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      -1,    17,    32,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    -1,    17,    32,    19,    -1,    21,
      22,    -1,    24,    -1,    26,    27,    28,    25,    -1,    27,
      32,    -1,    30,    -1,    32,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,     1,    -1,     3,    -1,    -1,    -1,     7,
       8,     9,     3,    11,    -1,    -1,     7,     8,     9,    -1,
      11
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     7,     8,     9,    11,    44,    45,    48,
      52,    54,    35,     0,    45,    48,    52,    37,    49,    53,
      55,    16,    25,    23,    35,    46,    18,    35,    25,    27,
      30,    32,    37,    38,    39,    40,    58,    50,    51,    54,
       5,     6,    10,    23,    33,    35,    47,    52,    54,    56,
      58,    37,    55,     1,    58,    58,    58,    58,    25,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      24,    26,    27,    28,    29,    31,    32,    18,    34,    37,
      25,    25,    35,    58,     1,    33,    56,    57,    33,    52,
      56,    35,    34,    34,     1,    34,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    51,    58,    58,    35,    33,
      35,     1,    33,    56,    34,    34,    34,    34,    35,     1,
      56,     1,    56,    35,    35,     4,     4,     1,    56,     1,
      56,    35,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    44,    44,    44,    44,    44,    45,    46,
      46,    47,    47,    47,    47,    48,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    54,    54,    54,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    57,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     2,     3,     3,
       2,     1,     1,     2,     2,     3,     4,     1,     3,     2,
       1,     3,     2,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     2,     1,     3,     2,     5,     7,     5,     3,
       2,     3,     6,     8,     8,     9,     6,     1,     2,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     4,     3,     1,     1,     1,     1,     3,     4,
       3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* functions_and_declarations: function_defenition  */
#line 49 "uccompiler.y"
                                                                    { (yyval.node) = program = newnode(Program, NULL); 
                                                                      addchild((yyval.node), (yyvsp[0].node));
                                                                    }
#line 1456 "y.tab.c"
    break;

  case 3: /* functions_and_declarations: function_declaration  */
#line 52 "uccompiler.y"
                                                                    { (yyval.node) = program = newnode(Program, NULL); 
                                                                      addchild((yyval.node), (yyvsp[0].node));
                                                                    }
#line 1464 "y.tab.c"
    break;

  case 4: /* functions_and_declarations: declaration  */
#line 55 "uccompiler.y"
                                                                    { (yyval.node) = program = newnode(Program, NULL); 
                                                                      addchild((yyval.node), (yyvsp[0].node));
                                                                    }
#line 1472 "y.tab.c"
    break;

  case 5: /* functions_and_declarations: functions_and_declarations function_defenition  */
#line 58 "uccompiler.y"
                                                                    { addchild((yyvsp[-1].node), (yyvsp[0].node));
                                                                      (yyval.node) = (yyvsp[-1].node);
                                                                    }
#line 1480 "y.tab.c"
    break;

  case 6: /* functions_and_declarations: functions_and_declarations function_declaration  */
#line 61 "uccompiler.y"
                                                                    { addchild((yyvsp[-1].node), (yyvsp[0].node));
                                                                      (yyval.node) = (yyvsp[-1].node);
                                                                    }
#line 1488 "y.tab.c"
    break;

  case 7: /* functions_and_declarations: functions_and_declarations declaration  */
#line 64 "uccompiler.y"
                                                                    { addchild((yyvsp[-1].node), (yyvsp[0].node));
                                                                      (yyval.node) = (yyvsp[-1].node);
                                                                    }
#line 1496 "y.tab.c"
    break;

  case 8: /* function_defenition: typespec function_declarator function_body  */
#line 70 "uccompiler.y"
                                                                    { (yyval.node) = (yyvsp[-1].node); 
                                                                      (yyval.node)->category = FuncDefinition;
                                                                      // Insere typespec no inicio
                                                                      struct node_list *temp = (struct node_list *)malloc(sizeof(struct node_list));
                                                                      temp->node = (yyvsp[-2].node);
                                                                      temp->next = (yyval.node)->children->next;
                                                                      (yyval.node)->children->next = temp;
                                                                      
                                                                      addchild((yyval.node), (yyvsp[0].node));
                                                                    }
#line 1511 "y.tab.c"
    break;

  case 9: /* function_body: LBRACE declarations_and_statements RBRACE  */
#line 83 "uccompiler.y"
                                                             { (yyval.node) = (yyvsp[-1].node);}
#line 1517 "y.tab.c"
    break;

  case 10: /* function_body: LBRACE RBRACE  */
#line 84 "uccompiler.y"
                                                             { (yyval.node) = newnode(FuncBody, NULL); }
#line 1523 "y.tab.c"
    break;

  case 11: /* declarations_and_statements: declaration  */
#line 88 "uccompiler.y"
                                                             { (yyval.node) = (yyvsp[0].node); }
#line 1529 "y.tab.c"
    break;

  case 12: /* declarations_and_statements: statement  */
#line 89 "uccompiler.y"
                                                             { (yyval.node) = newnode(FuncBody, NULL);
                                                               addchild((yyval.node), (yyvsp[0].node));
                                                             }
#line 1537 "y.tab.c"
    break;

  case 13: /* declarations_and_statements: declarations_and_statements declaration  */
#line 92 "uccompiler.y"
                                                             { struct node_list *aux = (yyval.node)->children; 
                                                               while (aux->next != NULL) {
                                                                aux = aux->next;
                                                               }
                                                               aux->next = (yyvsp[0].node)->children->next;
                                                               free((yyvsp[0].node)->children);
                                                               free((yyvsp[0].node));
                                                             }
#line 1550 "y.tab.c"
    break;

  case 14: /* declarations_and_statements: declarations_and_statements statement  */
#line 100 "uccompiler.y"
                                                             { (yyval.node) = (yyvsp[-1].node);
                                                               addchild((yyval.node), (yyvsp[0].node));
                                                             }
#line 1558 "y.tab.c"
    break;

  case 15: /* function_declaration: typespec function_declarator SEMI  */
#line 106 "uccompiler.y"
                                                             { (yyval.node) = (yyvsp[-1].node);
                                                               (yyval.node)->category = FuncDeclaration;
                                                               // Insere typespec no inicio
                                                               struct node_list *temp = (struct node_list *)malloc(sizeof(struct node_list));
                                                               temp->node = (yyvsp[-2].node);
                                                               temp->next = (yyval.node)->children->next;
                                                               (yyval.node)->children->next = temp;
                                                             }
#line 1571 "y.tab.c"
    break;

  case 16: /* function_declarator: IDENTIFIER LPAR parameter_list RPAR  */
#line 117 "uccompiler.y"
                                                             { (yyval.node) = newnode(Null, NULL);
                                                               addchild((yyval.node), newnode(Identifier, (yyvsp[-3].token)));
                                                               addchild((yyval.node), (yyvsp[-1].node));
                                                             }
#line 1580 "y.tab.c"
    break;

  case 17: /* parameter_list: parameter_declaration  */
#line 124 "uccompiler.y"
                                                             { (yyval.node) = newnode(ParamList, NULL); 
                                                               addchild((yyval.node), (yyvsp[0].node));
                                                             }
#line 1588 "y.tab.c"
    break;

  case 18: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 127 "uccompiler.y"
                                                             { addchild((yyvsp[-2].node), (yyvsp[0].node)); 
                                                               (yyval.node) = (yyvsp[-2].node);
                                                             }
#line 1596 "y.tab.c"
    break;

  case 19: /* parameter_declaration: typespec IDENTIFIER  */
#line 132 "uccompiler.y"
                                                             { (yyval.node) = newnode(ParamDeclaration, NULL); 
                                                               addchild((yyval.node), (yyvsp[-1].node));
                                                               addchild((yyval.node), newnode(Identifier, (yyvsp[0].token)));
                                                             }
#line 1605 "y.tab.c"
    break;

  case 20: /* parameter_declaration: typespec  */
#line 136 "uccompiler.y"
                                                             { (yyval.node) = newnode(ParamDeclaration, NULL); 
                                                               addchild((yyval.node), (yyvsp[0].node));
                                                             }
#line 1613 "y.tab.c"
    break;

  case 21: /* declaration: typespec declarator_repetition SEMI  */
#line 141 "uccompiler.y"
                                                             {
                                                                struct node_list *aux = (yyvsp[-1].node)->children->next;                                         // Aponta para o primeiro filho do node FuncBody

                                                                while(aux != NULL){                                                                 // Percorre os filhos dele
                                                                    struct node_list* temp = (struct node_list*)malloc(sizeof(struct node_list));   // Cria um novo node_list
                                                                    temp->node = (yyvsp[-2].node);                                                                // Que guarda o TypeSpec
                                                                    temp->next = aux->node->children->next;                                         // E que aponta para o antigo 1o node
                                                                    aux->node->children->next = temp;                                               // O 1o node passa a ser o temp (TypeSpec)
                                                                    
                                                                    aux = aux->next;                                                                // Avança para o proximo filho FuncBody
                                                                }
                                                                (yyval.node) = (yyvsp[-1].node);                                                                            // Passa para $$ o FuncBody
                                                             }
#line 1631 "y.tab.c"
    break;

  case 22: /* declaration: error SEMI  */
#line 154 "uccompiler.y"
                                                             {;}
#line 1637 "y.tab.c"
    break;

  case 23: /* declarator_repetition: declarator  */
#line 157 "uccompiler.y"
                                                             {             
                                                               (yyval.node) = newnode(FuncBody, NULL);
                                                               addchild((yyval.node), (yyvsp[0].node));            
                                                             }
#line 1646 "y.tab.c"
    break;

  case 24: /* declarator_repetition: declarator_repetition COMMA declarator  */
#line 161 "uccompiler.y"
                                                             { addchild((yyvsp[-2].node), (yyvsp[0].node)); 
                                                               (yyval.node) = (yyvsp[-2].node);
                                                             }
#line 1654 "y.tab.c"
    break;

  case 25: /* typespec: CHAR  */
#line 166 "uccompiler.y"
                                                             { (yyval.node) = newnode(Char, NULL); }
#line 1660 "y.tab.c"
    break;

  case 26: /* typespec: INT  */
#line 167 "uccompiler.y"
                                                             { (yyval.node) = newnode(Int, NULL); }
#line 1666 "y.tab.c"
    break;

  case 27: /* typespec: VOID  */
#line 168 "uccompiler.y"
                                                             { (yyval.node) = newnode(Void, NULL); }
#line 1672 "y.tab.c"
    break;

  case 28: /* typespec: SHORT  */
#line 169 "uccompiler.y"
                                                             { (yyval.node) = newnode(Short, NULL); }
#line 1678 "y.tab.c"
    break;

  case 29: /* typespec: DOUBLE  */
#line 170 "uccompiler.y"
                                                             { (yyval.node) = newnode(Double, NULL); }
#line 1684 "y.tab.c"
    break;

  case 30: /* declarator: IDENTIFIER ASSIGN expression  */
#line 173 "uccompiler.y"
                                                             {  (yyval.node) = newnode(Declaration, NULL);      
                                                                addchild((yyval.node), newnode(Identifier, (yyvsp[-2].token)));
                                                                addchild((yyval.node), (yyvsp[0].node));
                                                             }
#line 1693 "y.tab.c"
    break;

  case 31: /* declarator: IDENTIFIER  */
#line 177 "uccompiler.y"
                                                             { 
                                                               (yyval.node) = newnode(Declaration, NULL);             // Declaration
                                                               addchild((yyval.node), newnode(Identifier, (yyvsp[0].token)));       //   | ID               
                                                             }
#line 1702 "y.tab.c"
    break;

  case 32: /* statement: expression SEMI  */
#line 183 "uccompiler.y"
                                                             { (yyval.node) = (yyvsp[-1].node); }
#line 1708 "y.tab.c"
    break;

  case 33: /* statement: SEMI  */
#line 184 "uccompiler.y"
                                                             { (yyval.node) = newnode(Null, NULL); }
#line 1714 "y.tab.c"
    break;

  case 34: /* statement: LBRACE statement_repetition RBRACE  */
#line 185 "uccompiler.y"
                                                             { (yyval.node) = (yyvsp[-1].node); }
#line 1720 "y.tab.c"
    break;

  case 35: /* statement: LBRACE RBRACE  */
#line 186 "uccompiler.y"
                                                             { (yyval.node) = newnode(Null, NULL); }
#line 1726 "y.tab.c"
    break;

  case 36: /* statement: IF LPAR expression RPAR statement  */
#line 187 "uccompiler.y"
                                                             { (yyval.node) = newnode(If, NULL);
                                                               addchild((yyval.node), (yyvsp[-2].node));
                                                               addchild((yyval.node), (yyvsp[0].node));
                                                               addchild((yyval.node), newnode(Null, NULL));
                                                             }
#line 1736 "y.tab.c"
    break;

  case 37: /* statement: IF LPAR expression RPAR statement ELSE statement  */
#line 192 "uccompiler.y"
                                                             { (yyval.node) = newnode(If, NULL);
                                                               addchild((yyval.node), (yyvsp[-4].node));
                                                               addchild((yyval.node), (yyvsp[-2].node));
                                                               addchild((yyval.node), (yyvsp[0].node));
                                                             }
#line 1746 "y.tab.c"
    break;

  case 38: /* statement: WHILE LPAR expression RPAR statement  */
#line 197 "uccompiler.y"
                                                             { (yyval.node) = newnode(While, NULL);
                                                               addchild((yyval.node), (yyvsp[-2].node));
                                                               addchild((yyval.node), (yyvsp[0].node));
                                                             }
#line 1755 "y.tab.c"
    break;

  case 39: /* statement: RETURN expression SEMI  */
#line 201 "uccompiler.y"
                                                             { (yyval.node) = newnode(Return, NULL);
                                                               addchild((yyval.node), (yyvsp[-1].node));
                                                             }
#line 1763 "y.tab.c"
    break;

  case 40: /* statement: RETURN SEMI  */
#line 204 "uccompiler.y"
                                                             { (yyval.node) = newnode(Return, NULL);
                                                               addchild((yyval.node), newnode(Null, NULL));
                                                             }
#line 1771 "y.tab.c"
    break;

  case 41: /* statement: LBRACE error RBRACE  */
#line 207 "uccompiler.y"
                                                             {;}
#line 1777 "y.tab.c"
    break;

  case 42: /* statement: IF LPAR expression RPAR error SEMI  */
#line 210 "uccompiler.y"
                                                              {;}
#line 1783 "y.tab.c"
    break;

  case 43: /* statement: IF LPAR expression RPAR error SEMI ELSE statement  */
#line 211 "uccompiler.y"
                                                              {;}
#line 1789 "y.tab.c"
    break;

  case 44: /* statement: IF LPAR expression RPAR statement ELSE error SEMI  */
#line 212 "uccompiler.y"
                                                              {;}
#line 1795 "y.tab.c"
    break;

  case 45: /* statement: IF LPAR expression RPAR error SEMI ELSE error SEMI  */
#line 213 "uccompiler.y"
                                                              {;}
#line 1801 "y.tab.c"
    break;

  case 46: /* statement: WHILE LPAR expression RPAR error SEMI  */
#line 214 "uccompiler.y"
                                                              {;}
#line 1807 "y.tab.c"
    break;

  case 47: /* statement_repetition: statement  */
#line 217 "uccompiler.y"
                                            { (yyval.node) = (yyvsp[0].node); }
#line 1813 "y.tab.c"
    break;

  case 48: /* statement_repetition: statement_repetition statement  */
#line 218 "uccompiler.y"
                                            { if ((yyvsp[-1].node)->category == StatList)  {
                                                addchild((yyvsp[-1].node), (yyvsp[0].node));
                                                (yyval.node) = (yyvsp[-1].node);
                                              } else {
                                                (yyval.node) = newnode(StatList, NULL);
                                                addchild((yyval.node), (yyvsp[-1].node));
                                                addchild((yyval.node), (yyvsp[0].node));
                                              }
                                            }
#line 1827 "y.tab.c"
    break;

  case 49: /* statement_repetition: statement_repetition error SEMI  */
#line 228 "uccompiler.y"
                                            {;}
#line 1833 "y.tab.c"
    break;

  case 50: /* statement_repetition: error SEMI  */
#line 229 "uccompiler.y"
                                            {;}
#line 1839 "y.tab.c"
    break;

  case 51: /* expression: expression ASSIGN expression  */
#line 232 "uccompiler.y"
                                            { (yyval.node) = newnode(Store, NULL);
                                              addchild((yyval.node), (yyvsp[-2].node)); 
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 1848 "y.tab.c"
    break;

  case 52: /* expression: expression COMMA expression  */
#line 236 "uccompiler.y"
                                            { (yyval.node) = newnode(Comma, NULL);
                                              addchild((yyval.node), (yyvsp[-2].node)); 
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 1857 "y.tab.c"
    break;

  case 53: /* expression: expression PLUS expression  */
#line 241 "uccompiler.y"
                                            { (yyval.node) = newnode(Add, NULL);
                                              addchild((yyval.node), (yyvsp[-2].node)); 
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 1866 "y.tab.c"
    break;

  case 54: /* expression: expression MINUS expression  */
#line 245 "uccompiler.y"
                                            { (yyval.node) = newnode(Sub, NULL);
                                              addchild((yyval.node), (yyvsp[-2].node)); 
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 1875 "y.tab.c"
    break;

  case 55: /* expression: expression MUL expression  */
#line 249 "uccompiler.y"
                                            { (yyval.node) = newnode(Mul, NULL);
                                              addchild((yyval.node), (yyvsp[-2].node)); 
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 1884 "y.tab.c"
    break;

  case 56: /* expression: expression DIV expression  */
#line 253 "uccompiler.y"
                                            { (yyval.node) = newnode(Div, NULL);
                                              addchild((yyval.node), (yyvsp[-2].node)); 
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 1893 "y.tab.c"
    break;

  case 57: /* expression: expression MOD expression  */
#line 257 "uccompiler.y"
                                            { (yyval.node) = newnode(Mod, NULL);
                                              addchild((yyval.node), (yyvsp[-2].node)); 
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 1902 "y.tab.c"
    break;

  case 58: /* expression: expression OR expression  */
#line 262 "uccompiler.y"
                                            { (yyval.node) = newnode(Or, NULL);
                                              addchild((yyval.node), (yyvsp[-2].node)); 
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 1911 "y.tab.c"
    break;

  case 59: /* expression: expression AND expression  */
#line 266 "uccompiler.y"
                                            { (yyval.node) = newnode(And, NULL);
                                              addchild((yyval.node), (yyvsp[-2].node)); 
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 1920 "y.tab.c"
    break;

  case 60: /* expression: expression BITWISEAND expression  */
#line 270 "uccompiler.y"
                                            { (yyval.node) = newnode(BitWiseAnd, NULL);
                                              addchild((yyval.node), (yyvsp[-2].node)); 
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 1929 "y.tab.c"
    break;

  case 61: /* expression: expression BITWISEOR expression  */
#line 274 "uccompiler.y"
                                            { (yyval.node) = newnode(BitWiseOr, NULL);
                                              addchild((yyval.node), (yyvsp[-2].node)); 
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 1938 "y.tab.c"
    break;

  case 62: /* expression: expression BITWISEXOR expression  */
#line 278 "uccompiler.y"
                                            { (yyval.node) = newnode(BitWiseXor, NULL);
                                              addchild((yyval.node), (yyvsp[-2].node)); 
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 1947 "y.tab.c"
    break;

  case 63: /* expression: expression EQ expression  */
#line 283 "uccompiler.y"
                                            { (yyval.node) = newnode(Eq, NULL);
                                              addchild((yyval.node), (yyvsp[-2].node)); 
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 1956 "y.tab.c"
    break;

  case 64: /* expression: expression NE expression  */
#line 287 "uccompiler.y"
                                            { (yyval.node) = newnode(Ne, NULL);
                                              addchild((yyval.node), (yyvsp[-2].node)); 
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 1965 "y.tab.c"
    break;

  case 65: /* expression: expression LE expression  */
#line 291 "uccompiler.y"
                                            { (yyval.node) = newnode(Le, NULL);
                                              addchild((yyval.node), (yyvsp[-2].node)); 
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 1974 "y.tab.c"
    break;

  case 66: /* expression: expression GE expression  */
#line 295 "uccompiler.y"
                                            { (yyval.node) = newnode(Ge, NULL);
                                              addchild((yyval.node), (yyvsp[-2].node)); 
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 1983 "y.tab.c"
    break;

  case 67: /* expression: expression LT expression  */
#line 299 "uccompiler.y"
                                            { (yyval.node) = newnode(Lt, NULL);
                                              addchild((yyval.node), (yyvsp[-2].node)); 
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 1992 "y.tab.c"
    break;

  case 68: /* expression: expression GT expression  */
#line 303 "uccompiler.y"
                                            { (yyval.node) = newnode(Gt, NULL);
                                              addchild((yyval.node), (yyvsp[-2].node)); 
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 2001 "y.tab.c"
    break;

  case 69: /* expression: PLUS expression  */
#line 308 "uccompiler.y"
                                            { (yyval.node) = newnode(Plus, NULL);
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 2009 "y.tab.c"
    break;

  case 70: /* expression: MINUS expression  */
#line 311 "uccompiler.y"
                                            { (yyval.node) = newnode(Minus, NULL);
                                              addchild((yyval.node), (yyvsp[0].node)); 
                                            }
#line 2017 "y.tab.c"
    break;

  case 71: /* expression: NOT expression  */
#line 314 "uccompiler.y"
                                            { (yyval.node) = newnode(Not, NULL);
                                              addchild((yyval.node), (yyvsp[0].node));  
                                            }
#line 2025 "y.tab.c"
    break;

  case 72: /* expression: IDENTIFIER LPAR expression RPAR  */
#line 318 "uccompiler.y"
                                            { (yyval.node) = newnode(Call, NULL); 
                                              addchild((yyval.node), newnode(Identifier, (yyvsp[-3].token)));
                                              addchild((yyval.node), (yyvsp[-1].node)); 
                                            }
#line 2034 "y.tab.c"
    break;

  case 73: /* expression: IDENTIFIER LPAR RPAR  */
#line 322 "uccompiler.y"
                                            { (yyval.node) = newnode(Call, NULL); 
                                              addchild((yyval.node), newnode(Identifier, (yyvsp[-2].token)));
                                            }
#line 2042 "y.tab.c"
    break;

  case 74: /* expression: IDENTIFIER  */
#line 326 "uccompiler.y"
                                            { (yyval.node) = newnode(Identifier, (yyvsp[0].token)); }
#line 2048 "y.tab.c"
    break;

  case 75: /* expression: NATURAL  */
#line 327 "uccompiler.y"
                                            { (yyval.node) = newnode(Natural, (yyvsp[0].token)); }
#line 2054 "y.tab.c"
    break;

  case 76: /* expression: CHRLIT  */
#line 328 "uccompiler.y"
                                            { (yyval.node) = newnode(ChrLit, (yyvsp[0].token)); }
#line 2060 "y.tab.c"
    break;

  case 77: /* expression: DECIMAL  */
#line 329 "uccompiler.y"
                                            { (yyval.node) = newnode(Decimal, (yyvsp[0].token)); }
#line 2066 "y.tab.c"
    break;

  case 78: /* expression: LPAR expression RPAR  */
#line 330 "uccompiler.y"
                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2072 "y.tab.c"
    break;

  case 79: /* expression: IDENTIFIER LPAR error RPAR  */
#line 332 "uccompiler.y"
                                            { (yyval.node) = newnode(Error, NULL); }
#line 2078 "y.tab.c"
    break;

  case 80: /* expression: LPAR error RPAR  */
#line 333 "uccompiler.y"
                                            { (yyval.node) = newnode(Error, NULL); }
#line 2084 "y.tab.c"
    break;


#line 2088 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 337 "uccompiler.y"




/* 
Declaration −→ error SEMI
Statement −→ error SEMI
Statement −→ LBRACE error RBRACE
Expression −→ IDENTIFIER LPAR error RPAR
Expression −→ LPAR error RPAR
*/
