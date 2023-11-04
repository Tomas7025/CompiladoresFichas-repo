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


//? #include "ast.h"

int yylex(void);
void yyerror(char *);

struct node *program;

char l_category[][20] = { "Program", "Function", "Parameters", "Parameter", "Arguments", "Integer", "Double", "Identifier", "Natural", "Decimal", "Call", "If", "Add", "Sub", "Mul", "Div" };


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
# define YYDEBUG 1
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
    LOGIC = 296                    /* LOGIC  */
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "uccompiler.y"

    char *token;
    struct node *node;

#line 224 "y.tab.c"

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
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_functions_and_declarations = 43, /* functions_and_declarations  */
  YYSYMBOL_function_defenition = 44,       /* function_defenition  */
  YYSYMBOL_function_body = 45,             /* function_body  */
  YYSYMBOL_declarations_and_statements = 46, /* declarations_and_statements  */
  YYSYMBOL_function_declaration = 47,      /* function_declaration  */
  YYSYMBOL_function_declarator = 48,       /* function_declarator  */
  YYSYMBOL_parameter_list = 49,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 50,     /* parameter_declaration  */
  YYSYMBOL_declaration = 51,               /* declaration  */
  YYSYMBOL_declarator_repetition = 52,     /* declarator_repetition  */
  YYSYMBOL_typespec = 53,                  /* typespec  */
  YYSYMBOL_declarator = 54,                /* declarator  */
  YYSYMBOL_statement = 55,                 /* statement  */
  YYSYMBOL_statement_repetition = 56,      /* statement_repetition  */
  YYSYMBOL_expression = 57                 /* expression  */
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
#define YYLAST   623

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    50,    50,    51,    52,    53,    54,    55,    56,    57,
      61,    65,    66,    70,    71,    72,    73,    74,    75,    79,
      83,    87,    88,    91,    92,    95,    98,    99,   102,   103,
     104,   105,   106,   109,   110,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   125,   126,   129,   130,   132,
     133,   134,   135,   136,   138,   139,   140,   141,   142,   144,
     145,   146,   147,   148,   149,   151,   152,   153,   155,   156,
     158,   159,   160,   161,   162,   164,   165
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
  "NATURAL", "DECIMAL", "CHRLIT", "LOGIC", "$accept",
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

#define YYPACT_NINF (-49)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-18)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      65,   -24,   -49,   -49,   -49,   -49,   -49,    98,   -49,   -49,
     -49,    -4,   -49,   -49,    -5,   -49,   -49,   -49,   -10,    -9,
     -13,   -49,   -49,   583,   134,    85,   -49,   -49,     0,   -49,
     222,   583,   583,   583,    -1,   -49,   -49,   -49,   486,   -11,
     -49,     6,     3,    19,    21,   299,   245,   -49,   -49,    42,
     125,     0,   165,   346,    12,   -49,    45,   394,    -7,   -49,
      -7,     2,   583,   583,   583,   583,   583,   583,   583,   583,
     583,   583,   583,   583,   583,   583,   583,   583,   583,   583,
     134,   -49,   -49,   205,   583,   583,   -49,   370,    47,   -49,
     -49,   281,   -49,   -49,   -49,   -49,   -49,   -49,    51,   -49,
     417,   273,   547,   565,   528,   486,   -49,   486,   -49,   579,
      50,    50,    50,    50,    -7,   -49,   579,   507,    -7,   -49,
     -49,   440,   463,   -49,   -49,   -49,   -49,   -49,   -49,   317,
     317,   -49,    93,   317,   -49
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    28,    29,    31,    32,    30,     0,     2,     3,
       4,     0,     8,     1,     0,     5,     6,     7,    34,     0,
       0,    26,     9,     0,     0,     0,    19,    10,     0,    25,
       0,     0,     0,     0,    70,    71,    73,    72,    33,     0,
      21,    24,     0,     0,     0,     0,     0,    12,    36,     0,
       0,     0,     0,     0,    34,    27,     0,     0,    66,    67,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    23,     0,     0,     0,    43,     0,     0,    38,
      45,     0,    11,    15,    16,    35,    76,    74,     0,    69,
       0,    56,    57,    58,    55,    47,    51,    48,    52,    59,
      62,    64,    61,    63,    50,    53,    60,    54,    49,    22,
      18,     0,     0,    42,    44,    37,    46,    75,    68,     0,
       0,    41,    39,     0,    40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -49,   -49,    82,   -49,   -48,    95,   -49,   -49,    20,    13,
     -49,     1,    75,   -46,   -49,   -14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,    27,    49,     9,    19,    39,    40,    50,
      20,    51,    21,    52,    91,    53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      90,    11,    93,    98,    94,    28,    23,    80,    11,    38,
      67,    12,    69,    10,    25,    24,    57,    58,    59,    60,
      17,    76,    29,    81,    61,    41,    26,    30,    23,    31,
      22,    87,    32,    18,    33,   120,    99,    54,    83,    34,
      35,    36,    37,    82,    84,   126,    85,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,     1,    67,     2,    69,
     121,   122,     3,     4,     5,    92,     6,    75,    76,    96,
     124,    41,    79,   131,   132,   127,    42,   134,     2,    15,
      43,    44,     3,     4,     5,    45,     6,   133,    13,    14,
     119,     2,    16,    55,     0,     3,     4,     5,    46,     6,
      30,     0,    31,     0,     0,    32,     0,    33,    47,     0,
      48,     0,    34,    35,    36,    37,    42,     0,     2,     0,
      43,    44,     3,     4,     5,    45,     6,     2,     0,     0,
       0,     3,     4,     5,     0,     6,     0,     0,    46,     0,
      30,     0,    31,     0,     0,    32,     0,    33,   -13,     0,
      48,     0,    34,    35,    36,    37,    42,     0,     2,     0,
      43,    44,     3,     4,     5,    45,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
      30,     0,    31,     0,     0,    32,     0,    33,   -14,     0,
      48,     0,    34,    35,    36,    37,    42,     0,     2,     0,
      43,    44,     3,     4,     5,    45,     6,     0,     0,     0,
       0,     0,     0,    56,     0,     0,     0,     0,    46,     0,
      30,     0,    31,     0,     0,    32,     0,    33,   -17,     0,
      48,     0,    34,    35,    36,    37,    88,    30,     0,    31,
      43,    44,    32,     0,    33,    45,     0,     0,     0,    34,
      35,    36,    37,     0,     0,     0,     0,     0,    46,     0,
      30,     0,    31,     0,     0,    32,     0,    33,    89,     0,
      48,     0,    34,    35,    36,    37,    43,    44,     0,     0,
      67,    45,    69,    70,    71,    72,     0,    73,     0,    74,
      75,    76,    77,     0,    46,    79,    30,     0,    31,     0,
       0,    32,     0,    33,   125,     0,    48,     0,    34,    35,
      36,    37,    43,    44,    30,     0,    31,    45,     0,    32,
       0,    33,     0,     0,    86,     0,    34,    35,    36,    37,
      46,     0,    30,     0,    31,     0,     0,    32,     0,    33,
       0,     0,    48,     0,    34,    35,    36,    37,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
      73,     0,    74,    75,    76,    77,     0,    78,    79,     0,
       0,    95,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,     0,    73,     0,    74,    75,    76,    77,
       0,    78,    79,     0,     0,   123,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,     0,    73,     0,
      74,    75,    76,    77,     0,    78,    79,     0,    97,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
       0,    73,     0,    74,    75,    76,    77,     0,    78,    79,
       0,   128,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,     0,    73,     0,    74,    75,    76,    77,
       0,    78,    79,     0,   129,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,    73,     0,    74,
      75,    76,    77,     0,    78,    79,     0,   130,    62,    63,
      64,    65,    66,    67,     0,    69,    70,    71,    72,     0,
      73,     0,    74,    75,    76,    77,     0,    78,    79,    62,
      63,    64,    65,     0,    67,     0,    69,    70,    71,    72,
       0,    73,     0,    74,    75,    76,    77,     0,     0,    79,
      62,    63,    64,     0,     0,    67,     0,    69,    70,    71,
      72,     0,    73,     0,    74,    75,    76,    77,     0,    62,
      79,    64,     0,     0,    67,     0,    69,    70,    71,    72,
       0,    73,     0,    74,    75,    76,    77,    62,     0,    79,
       0,     0,    67,     0,    69,    70,    71,    72,     0,    73,
       0,    74,    75,    76,    77,     0,    67,    79,    69,     0,
      71,    72,     0,    73,     0,    74,    75,    76,    30,     0,
      31,    79,     0,    32,     0,    33,     0,     0,     0,     0,
      34,    35,    36,    37
};

static const yytype_int16 yycheck[] =
{
      46,     0,    50,     1,    52,    18,    16,    18,     7,    23,
      17,    35,    19,     0,    23,    25,    30,    31,    32,    33,
       7,    28,    35,    34,    25,    24,    35,    25,    16,    27,
      35,    45,    30,    37,    32,    83,    34,    37,    35,    37,
      38,    39,    40,    37,    25,    91,    25,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     1,    17,     3,    19,
      84,    85,     7,     8,     9,    33,    11,    27,    28,    34,
      33,    80,    32,   129,   130,    34,     1,   133,     3,     7,
       5,     6,     7,     8,     9,    10,    11,     4,     0,     1,
      80,     3,     7,    28,    -1,     7,     8,     9,    23,    11,
      25,    -1,    27,    -1,    -1,    30,    -1,    32,    33,    -1,
      35,    -1,    37,    38,    39,    40,     1,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    11,     3,    -1,    -1,
      -1,     7,     8,     9,    -1,    11,    -1,    -1,    23,    -1,
      25,    -1,    27,    -1,    -1,    30,    -1,    32,    33,    -1,
      35,    -1,    37,    38,    39,    40,     1,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      25,    -1,    27,    -1,    -1,    30,    -1,    32,    33,    -1,
      35,    -1,    37,    38,    39,    40,     1,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    23,    -1,
      25,    -1,    27,    -1,    -1,    30,    -1,    32,    33,    -1,
      35,    -1,    37,    38,    39,    40,     1,    25,    -1,    27,
       5,     6,    30,    -1,    32,    10,    -1,    -1,    -1,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      25,    -1,    27,    -1,    -1,    30,    -1,    32,    33,    -1,
      35,    -1,    37,    38,    39,    40,     5,     6,    -1,    -1,
      17,    10,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    29,    -1,    23,    32,    25,    -1,    27,    -1,
      -1,    30,    -1,    32,    33,    -1,    35,    -1,    37,    38,
      39,    40,     5,     6,    25,    -1,    27,    10,    -1,    30,
      -1,    32,    -1,    -1,    35,    -1,    37,    38,    39,    40,
      23,    -1,    25,    -1,    27,    -1,    -1,    30,    -1,    32,
      -1,    -1,    35,    -1,    37,    38,    39,    40,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    -1,    31,    32,    -1,
      -1,    35,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      -1,    31,    32,    -1,    -1,    35,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    -1,    31,    32,    -1,    34,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    -1,    31,    32,
      -1,    34,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      -1,    31,    32,    -1,    34,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    29,    -1,    31,    32,    -1,    34,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    -1,    31,    32,    12,
      13,    14,    15,    -1,    17,    -1,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    -1,    -1,    32,
      12,    13,    14,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    28,    29,    -1,    12,
      32,    14,    -1,    -1,    17,    -1,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    12,    -1,    32,
      -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    28,    29,    -1,    17,    32,    19,    -1,
      21,    22,    -1,    24,    -1,    26,    27,    28,    25,    -1,
      27,    32,    -1,    30,    -1,    32,    -1,    -1,    -1,    -1,
      37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     7,     8,     9,    11,    43,    44,    47,
      51,    53,    35,     0,     1,    44,    47,    51,    37,    48,
      52,    54,    35,    16,    25,    23,    35,    45,    18,    35,
      25,    27,    30,    32,    37,    38,    39,    40,    57,    49,
      50,    53,     1,     5,     6,    10,    23,    33,    35,    46,
      51,    53,    55,    57,    37,    54,     1,    57,    57,    57,
      57,    25,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    24,    26,    27,    28,    29,    31,    32,
      18,    34,    37,    35,    25,    25,    35,    57,     1,    33,
      55,    56,    33,    46,    46,    35,    34,    34,     1,    34,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    50,
      46,    57,    57,    35,    33,    33,    55,    34,    34,    34,
      34,    55,    55,     4,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    43,    43,    43,    43,    43,    43,
      44,    45,    45,    46,    46,    46,    46,    46,    46,    47,
      48,    49,    49,    50,    50,    51,    52,    52,    53,    53,
      53,    53,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     2,     2,     3,
       3,     3,     2,     1,     1,     2,     2,     2,     3,     3,
       4,     1,     3,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     3,     1,     2,     1,     3,     2,     5,
       7,     5,     3,     2,     3,     1,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     4,     3,
       1,     1,     1,     1,     3,     4,     3
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
#line 50 "uccompiler.y"
                                                                    { ; }
#line 1445 "y.tab.c"
    break;

  case 3: /* functions_and_declarations: function_declaration  */
#line 51 "uccompiler.y"
                                                                    {;}
#line 1451 "y.tab.c"
    break;

  case 4: /* functions_and_declarations: declaration  */
#line 52 "uccompiler.y"
                                                                    { ; }
#line 1457 "y.tab.c"
    break;

  case 5: /* functions_and_declarations: functions_and_declarations function_defenition  */
#line 53 "uccompiler.y"
                                                                    {;}
#line 1463 "y.tab.c"
    break;

  case 6: /* functions_and_declarations: functions_and_declarations function_declaration  */
#line 54 "uccompiler.y"
                                                                    {;}
#line 1469 "y.tab.c"
    break;

  case 7: /* functions_and_declarations: functions_and_declarations declaration  */
#line 55 "uccompiler.y"
                                                                    {;}
#line 1475 "y.tab.c"
    break;

  case 8: /* functions_and_declarations: error SEMI  */
#line 56 "uccompiler.y"
                                                                    {;}
#line 1481 "y.tab.c"
    break;

  case 9: /* functions_and_declarations: functions_and_declarations error SEMI  */
#line 57 "uccompiler.y"
                                                                    {;}
#line 1487 "y.tab.c"
    break;

  case 10: /* function_defenition: typespec function_declarator function_body  */
#line 61 "uccompiler.y"
                                                                    {;}
#line 1493 "y.tab.c"
    break;

  case 11: /* function_body: LBRACE declarations_and_statements RBRACE  */
#line 65 "uccompiler.y"
                                                             {;}
#line 1499 "y.tab.c"
    break;

  case 12: /* function_body: LBRACE RBRACE  */
#line 66 "uccompiler.y"
                                                             {;}
#line 1505 "y.tab.c"
    break;

  case 13: /* declarations_and_statements: declaration  */
#line 70 "uccompiler.y"
                                                             {;}
#line 1511 "y.tab.c"
    break;

  case 14: /* declarations_and_statements: statement  */
#line 71 "uccompiler.y"
                                                             {;}
#line 1517 "y.tab.c"
    break;

  case 15: /* declarations_and_statements: declaration declarations_and_statements  */
#line 72 "uccompiler.y"
                                                             {;}
#line 1523 "y.tab.c"
    break;

  case 16: /* declarations_and_statements: statement declarations_and_statements  */
#line 73 "uccompiler.y"
                                                             {;}
#line 1529 "y.tab.c"
    break;

  case 17: /* declarations_and_statements: error SEMI  */
#line 74 "uccompiler.y"
                                                             {;}
#line 1535 "y.tab.c"
    break;

  case 18: /* declarations_and_statements: error SEMI declarations_and_statements  */
#line 75 "uccompiler.y"
                                                             {;}
#line 1541 "y.tab.c"
    break;

  case 19: /* function_declaration: typespec function_declarator SEMI  */
#line 79 "uccompiler.y"
                                                             {;}
#line 1547 "y.tab.c"
    break;

  case 20: /* function_declarator: IDENTIFIER LPAR parameter_list RPAR  */
#line 83 "uccompiler.y"
                                                             {;}
#line 1553 "y.tab.c"
    break;

  case 21: /* parameter_list: parameter_declaration  */
#line 87 "uccompiler.y"
                                                             {;}
#line 1559 "y.tab.c"
    break;

  case 22: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 88 "uccompiler.y"
                                                             {;}
#line 1565 "y.tab.c"
    break;

  case 23: /* parameter_declaration: typespec IDENTIFIER  */
#line 91 "uccompiler.y"
                                                             {;}
#line 1571 "y.tab.c"
    break;

  case 24: /* parameter_declaration: typespec  */
#line 92 "uccompiler.y"
                                                             {;}
#line 1577 "y.tab.c"
    break;

  case 25: /* declaration: typespec declarator_repetition SEMI  */
#line 95 "uccompiler.y"
                                                             { ; }
#line 1583 "y.tab.c"
    break;

  case 26: /* declarator_repetition: declarator  */
#line 98 "uccompiler.y"
                                                             { ; }
#line 1589 "y.tab.c"
    break;

  case 27: /* declarator_repetition: declarator_repetition COMMA declarator  */
#line 99 "uccompiler.y"
                                                             {;}
#line 1595 "y.tab.c"
    break;

  case 28: /* typespec: CHAR  */
#line 102 "uccompiler.y"
                                                             { ; }
#line 1601 "y.tab.c"
    break;

  case 29: /* typespec: INT  */
#line 103 "uccompiler.y"
                                                             {;}
#line 1607 "y.tab.c"
    break;

  case 30: /* typespec: VOID  */
#line 104 "uccompiler.y"
                                                             {;}
#line 1613 "y.tab.c"
    break;

  case 31: /* typespec: SHORT  */
#line 105 "uccompiler.y"
                                                             {;}
#line 1619 "y.tab.c"
    break;

  case 32: /* typespec: DOUBLE  */
#line 106 "uccompiler.y"
                                                             {;}
#line 1625 "y.tab.c"
    break;

  case 33: /* declarator: IDENTIFIER ASSIGN expression  */
#line 109 "uccompiler.y"
                                                             {;}
#line 1631 "y.tab.c"
    break;

  case 34: /* declarator: IDENTIFIER  */
#line 110 "uccompiler.y"
                                                             {;}
#line 1637 "y.tab.c"
    break;

  case 35: /* statement: expression SEMI  */
#line 113 "uccompiler.y"
                                                             {;}
#line 1643 "y.tab.c"
    break;

  case 36: /* statement: SEMI  */
#line 114 "uccompiler.y"
                                                             {;}
#line 1649 "y.tab.c"
    break;

  case 37: /* statement: LBRACE statement_repetition RBRACE  */
#line 115 "uccompiler.y"
                                                             {;}
#line 1655 "y.tab.c"
    break;

  case 38: /* statement: LBRACE RBRACE  */
#line 116 "uccompiler.y"
                                                             {;}
#line 1661 "y.tab.c"
    break;

  case 39: /* statement: IF LPAR expression RPAR statement  */
#line 117 "uccompiler.y"
                                                             {;}
#line 1667 "y.tab.c"
    break;

  case 40: /* statement: IF LPAR expression RPAR statement ELSE statement  */
#line 118 "uccompiler.y"
                                                             {;}
#line 1673 "y.tab.c"
    break;

  case 41: /* statement: WHILE LPAR expression RPAR statement  */
#line 119 "uccompiler.y"
                                                             {;}
#line 1679 "y.tab.c"
    break;

  case 42: /* statement: RETURN expression SEMI  */
#line 120 "uccompiler.y"
                                                             {;}
#line 1685 "y.tab.c"
    break;

  case 43: /* statement: RETURN SEMI  */
#line 121 "uccompiler.y"
                                                             {;}
#line 1691 "y.tab.c"
    break;

  case 44: /* statement: LBRACE error RBRACE  */
#line 122 "uccompiler.y"
                                            {;}
#line 1697 "y.tab.c"
    break;

  case 45: /* statement_repetition: statement  */
#line 125 "uccompiler.y"
                                            {;}
#line 1703 "y.tab.c"
    break;

  case 46: /* statement_repetition: statement_repetition statement  */
#line 126 "uccompiler.y"
                                            {;}
#line 1709 "y.tab.c"
    break;

  case 47: /* expression: expression ASSIGN expression  */
#line 129 "uccompiler.y"
                                            {;}
#line 1715 "y.tab.c"
    break;

  case 48: /* expression: expression COMMA expression  */
#line 130 "uccompiler.y"
                                            {;}
#line 1721 "y.tab.c"
    break;

  case 49: /* expression: expression PLUS expression  */
#line 132 "uccompiler.y"
                                            {;}
#line 1727 "y.tab.c"
    break;

  case 50: /* expression: expression MINUS expression  */
#line 133 "uccompiler.y"
                                            {;}
#line 1733 "y.tab.c"
    break;

  case 51: /* expression: expression MUL expression  */
#line 134 "uccompiler.y"
                                            {;}
#line 1739 "y.tab.c"
    break;

  case 52: /* expression: expression DIV expression  */
#line 135 "uccompiler.y"
                                            {;}
#line 1745 "y.tab.c"
    break;

  case 53: /* expression: expression MOD expression  */
#line 136 "uccompiler.y"
                                            {;}
#line 1751 "y.tab.c"
    break;

  case 54: /* expression: expression OR expression  */
#line 138 "uccompiler.y"
                                            {;}
#line 1757 "y.tab.c"
    break;

  case 55: /* expression: expression AND expression  */
#line 139 "uccompiler.y"
                                            {;}
#line 1763 "y.tab.c"
    break;

  case 56: /* expression: expression BITWISEAND expression  */
#line 140 "uccompiler.y"
                                            {;}
#line 1769 "y.tab.c"
    break;

  case 57: /* expression: expression BITWISEOR expression  */
#line 141 "uccompiler.y"
                                            {;}
#line 1775 "y.tab.c"
    break;

  case 58: /* expression: expression BITWISEXOR expression  */
#line 142 "uccompiler.y"
                                            {;}
#line 1781 "y.tab.c"
    break;

  case 59: /* expression: expression EQ expression  */
#line 144 "uccompiler.y"
                                            {;}
#line 1787 "y.tab.c"
    break;

  case 60: /* expression: expression NE expression  */
#line 145 "uccompiler.y"
                                            {;}
#line 1793 "y.tab.c"
    break;

  case 61: /* expression: expression LE expression  */
#line 146 "uccompiler.y"
                                            {;}
#line 1799 "y.tab.c"
    break;

  case 62: /* expression: expression GE expression  */
#line 147 "uccompiler.y"
                                            {;}
#line 1805 "y.tab.c"
    break;

  case 63: /* expression: expression LT expression  */
#line 148 "uccompiler.y"
                                            {;}
#line 1811 "y.tab.c"
    break;

  case 64: /* expression: expression GT expression  */
#line 149 "uccompiler.y"
                                            {;}
#line 1817 "y.tab.c"
    break;

  case 65: /* expression: PLUS expression  */
#line 151 "uccompiler.y"
                                            {;}
#line 1823 "y.tab.c"
    break;

  case 66: /* expression: MINUS expression  */
#line 152 "uccompiler.y"
                                            {;}
#line 1829 "y.tab.c"
    break;

  case 67: /* expression: NOT expression  */
#line 153 "uccompiler.y"
                                            {;}
#line 1835 "y.tab.c"
    break;

  case 68: /* expression: IDENTIFIER LPAR expression RPAR  */
#line 155 "uccompiler.y"
                                            {;}
#line 1841 "y.tab.c"
    break;

  case 69: /* expression: IDENTIFIER LPAR RPAR  */
#line 156 "uccompiler.y"
                                            {;}
#line 1847 "y.tab.c"
    break;

  case 70: /* expression: IDENTIFIER  */
#line 158 "uccompiler.y"
                                            {;}
#line 1853 "y.tab.c"
    break;

  case 71: /* expression: NATURAL  */
#line 159 "uccompiler.y"
                                            {;}
#line 1859 "y.tab.c"
    break;

  case 72: /* expression: CHRLIT  */
#line 160 "uccompiler.y"
                                            {;}
#line 1865 "y.tab.c"
    break;

  case 73: /* expression: DECIMAL  */
#line 161 "uccompiler.y"
                                            {;}
#line 1871 "y.tab.c"
    break;

  case 74: /* expression: LPAR expression RPAR  */
#line 162 "uccompiler.y"
                                            {;}
#line 1877 "y.tab.c"
    break;

  case 75: /* expression: IDENTIFIER LPAR error RPAR  */
#line 164 "uccompiler.y"
                                            {;}
#line 1883 "y.tab.c"
    break;

  case 76: /* expression: LPAR error RPAR  */
#line 165 "uccompiler.y"
                                            {;}
#line 1889 "y.tab.c"
    break;


#line 1893 "y.tab.c"

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

#line 177 "uccompiler.y"


