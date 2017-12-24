/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 30 "core/cfg.y" /* yacc.c:339  */


#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include "route_struct.h"
#include "globals.h"
#ifdef SHM_MEM
#include "shm_init.h"
#endif /* SHM_MEM */
#include "route.h"
#include "switch.h"
#include "dprint.h"
#include "sr_module.h"
#include "modparam.h"
#include "ip_addr.h"
#include "resolve.h"
#include "socket_info.h"
#include "name_alias.h"
#include "ut.h"
#include "dset.h"
#include "select.h"
#include "flags.h"
#include "tcp_init.h"
#include "tcp_options.h"
#include "sctp_core.h"
#include "pvar.h"
#include "lvalue.h"
#include "rvalue.h"
#include "sr_compat.h"
#include "msg_translator.h"
#include "async_task.h"

#include "kemi.h"
#include "ppcfg.h"
#include "pvapi.h"
#include "config.h"
#include "cfg_core.h"
#include "cfg/cfg.h"
#ifdef CORE_TLS
#include "tls/tls_config.h"
#endif
#include "timer_ticks.h"

#ifdef DEBUG_DMALLOC
#include <dmalloc.h>
#endif

/* hack to avoid alloca usage in the generated C file (needed for compiler
 with no built in alloca, like icc*/
#undef _ALLOCA_H

#define onsend_check(s) \
	do{\
		if (rt!=ONSEND_ROUTE) yyerror( s " allowed only in onsend_routes");\
	}while(0)

	#define IF_AUTO_BIND_IPV6(x) x

#ifdef USE_DNS_CACHE
	#define IF_DNS_CACHE(x) x
#else
	#define IF_DNS_CACHE(x) warn("dns cache support not compiled in")
#endif

#ifdef USE_DNS_FAILOVER
	#define IF_DNS_FAILOVER(x) x
#else
	#define IF_DNS_FAILOVER(x) warn("dns failover support not compiled in")
#endif

#ifdef USE_NAPTR
	#define IF_NAPTR(x) x
#else
	#define IF_NAPTR(x) warn("dns naptr support not compiled in")
#endif

#ifdef USE_DST_BLACKLIST
	#define IF_DST_BLACKLIST(x) x
#else
	#define IF_DST_BLACKLIST(x) warn("dst blacklist support not compiled in")
#endif

#ifdef USE_SCTP
	#define IF_SCTP(x) x
#else
	#define IF_SCTP(x) warn("sctp support not compiled in")
#endif

#ifdef USE_RAW_SOCKS
	#define IF_RAW_SOCKS(x) x
#else
	#define IF_RAW_SOCKS(x) warn("raw socket support not compiled in")
#endif


extern int yylex();
/* safer then using yytext which can be array or pointer */
extern char* yy_number_str;

static void yyerror(char* s, ...);
static void yyerror_at(struct cfg_pos* pos, char* s, ...);
static char* tmp;
static int i_tmp;
static unsigned u_tmp;
static struct socket_id* lst_tmp;
static struct name_lst*  nl_tmp;
static int rt;  /* Type of route block for find_export */
static str* str_tmp;
static str s_tmp;
static struct ip_addr* ip_tmp;
static struct avp_spec* s_attr;
static select_t sel;
static select_t* sel_ptr;
static pv_spec_t* pv_spec;
static struct action *mod_func_action;
static struct lvalue* lval_tmp;
static struct rvalue* rval_tmp;

static void warn(char* s, ...);
static void warn_at(struct cfg_pos* pos, char* s, ...);
static void get_cpos(struct cfg_pos* pos);
static struct rval_expr* mk_rve_rval(enum rval_type, void* v);
static struct rval_expr* mk_rve1(enum rval_expr_op op, struct rval_expr* rve1);
static struct rval_expr* mk_rve2(enum rval_expr_op op, struct rval_expr* rve1,
									struct rval_expr* rve2);
static int rval_expr_int_check(struct rval_expr *rve);
static int warn_ct_rve(struct rval_expr *rve, char* name);
static struct socket_id* mk_listen_id(char*, int, int);
static struct name_lst* mk_name_lst(char* name, int flags);
static struct socket_id* mk_listen_id2(struct name_lst*, int, int);
static void free_name_lst(struct name_lst* lst);
static void free_socket_id_lst(struct socket_id* i);

static struct case_stms* mk_case_stm(struct rval_expr* ct, int is_re, 
									struct action* a, int* err);
static int case_check_type(struct case_stms* stms);
static int case_check_default(struct case_stms* stms);
static int mod_f_params_pre_fixup(struct action* a);
static void free_mod_func_action(struct action* a);


extern int line;
extern int column;
extern int startcolumn;
extern int startline;
extern char *finame;
extern char *routename;
extern char *default_routename;

#define set_cfg_pos(x) \
	do{\
		if(x) {\
		(x)->cline = line;\
		(x)->cfile = (finame!=0)?finame:((cfg_file!=0)?cfg_file:"default");\
		(x)->rname = (routename!=0)?routename:((default_routename!=0)?default_routename:"DEFAULT");\
		}\
	}while(0)



#line 235 "core/cfg.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "cfg.tab.h".  */
#ifndef YY_YY_CORE_CFG_TAB_H_INCLUDED
# define YY_YY_CORE_CFG_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FORWARD = 258,
    FORWARD_TCP = 259,
    FORWARD_TLS = 260,
    FORWARD_SCTP = 261,
    FORWARD_UDP = 262,
    EXIT = 263,
    DROP = 264,
    RETURN = 265,
    BREAK = 266,
    LOG_TOK = 267,
    ERROR = 268,
    ROUTE = 269,
    ROUTE_REQUEST = 270,
    ROUTE_FAILURE = 271,
    ROUTE_ONREPLY = 272,
    ROUTE_REPLY = 273,
    ROUTE_BRANCH = 274,
    ROUTE_SEND = 275,
    ROUTE_EVENT = 276,
    EXEC = 277,
    SET_HOST = 278,
    SET_HOSTPORT = 279,
    SET_HOSTPORTTRANS = 280,
    PREFIX = 281,
    STRIP = 282,
    STRIP_TAIL = 283,
    SET_USERPHONE = 284,
    APPEND_BRANCH = 285,
    REMOVE_BRANCH = 286,
    CLEAR_BRANCHES = 287,
    SET_USER = 288,
    SET_USERPASS = 289,
    SET_PORT = 290,
    SET_URI = 291,
    REVERT_URI = 292,
    FORCE_RPORT = 293,
    ADD_LOCAL_RPORT = 294,
    FORCE_TCP_ALIAS = 295,
    UDP_MTU = 296,
    UDP_MTU_TRY_PROTO = 297,
    UDP4_RAW = 298,
    UDP4_RAW_MTU = 299,
    UDP4_RAW_TTL = 300,
    IF = 301,
    ELSE = 302,
    SET_ADV_ADDRESS = 303,
    SET_ADV_PORT = 304,
    FORCE_SEND_SOCKET = 305,
    SET_FWD_NO_CONNECT = 306,
    SET_RPL_NO_CONNECT = 307,
    SET_FWD_CLOSE = 308,
    SET_RPL_CLOSE = 309,
    SWITCH = 310,
    CASE = 311,
    DEFAULT = 312,
    WHILE = 313,
    CFG_SELECT = 314,
    CFG_RESET = 315,
    URIHOST = 316,
    URIPORT = 317,
    MAX_LEN = 318,
    SETFLAG = 319,
    RESETFLAG = 320,
    ISFLAGSET = 321,
    SETAVPFLAG = 322,
    RESETAVPFLAG = 323,
    ISAVPFLAGSET = 324,
    METHOD = 325,
    URI = 326,
    FROM_URI = 327,
    TO_URI = 328,
    SRCIP = 329,
    SRCPORT = 330,
    DSTIP = 331,
    DSTPORT = 332,
    TOIP = 333,
    TOPORT = 334,
    SNDIP = 335,
    SNDPORT = 336,
    SNDPROTO = 337,
    SNDAF = 338,
    PROTO = 339,
    AF = 340,
    MYSELF = 341,
    MSGLEN = 342,
    UDP = 343,
    TCP = 344,
    TLS = 345,
    SCTP = 346,
    WS = 347,
    WSS = 348,
    DEBUG_V = 349,
    FORK = 350,
    FORK_DELAY = 351,
    MODINIT_DELAY = 352,
    LOGSTDERROR = 353,
    LOGFACILITY = 354,
    LOGNAME = 355,
    LOGCOLOR = 356,
    LOGPREFIX = 357,
    LOGPREFIXMODE = 358,
    LOGENGINETYPE = 359,
    LOGENGINEDATA = 360,
    LISTEN = 361,
    ADVERTISE = 362,
    ALIAS = 363,
    SR_AUTO_ALIASES = 364,
    DNS = 365,
    REV_DNS = 366,
    DNS_TRY_IPV6 = 367,
    DNS_TRY_NAPTR = 368,
    DNS_SRV_LB = 369,
    DNS_UDP_PREF = 370,
    DNS_TCP_PREF = 371,
    DNS_TLS_PREF = 372,
    DNS_SCTP_PREF = 373,
    DNS_RETR_TIME = 374,
    DNS_RETR_NO = 375,
    DNS_SERVERS_NO = 376,
    DNS_USE_SEARCH = 377,
    DNS_SEARCH_FMATCH = 378,
    DNS_NAPTR_IGNORE_RFC = 379,
    DNS_CACHE_INIT = 380,
    DNS_USE_CACHE = 381,
    DNS_USE_FAILOVER = 382,
    DNS_CACHE_FLAGS = 383,
    DNS_CACHE_NEG_TTL = 384,
    DNS_CACHE_MIN_TTL = 385,
    DNS_CACHE_MAX_TTL = 386,
    DNS_CACHE_MEM = 387,
    DNS_CACHE_GC_INT = 388,
    DNS_CACHE_DEL_NONEXP = 389,
    DNS_CACHE_REC_PREF = 390,
    AUTO_BIND_IPV6 = 391,
    DST_BLST_INIT = 392,
    USE_DST_BLST = 393,
    DST_BLST_MEM = 394,
    DST_BLST_TTL = 395,
    DST_BLST_GC_INT = 396,
    DST_BLST_UDP_IMASK = 397,
    DST_BLST_TCP_IMASK = 398,
    DST_BLST_TLS_IMASK = 399,
    DST_BLST_SCTP_IMASK = 400,
    IP_FREE_BIND = 401,
    PORT = 402,
    STAT = 403,
    CHILDREN = 404,
    SOCKET_WORKERS = 405,
    ASYNC_WORKERS = 406,
    ASYNC_USLEEP = 407,
    CHECK_VIA = 408,
    PHONE2TEL = 409,
    MEMLOG = 410,
    MEMDBG = 411,
    MEMSUM = 412,
    MEMSAFETY = 413,
    MEMJOIN = 414,
    MEMSTATUSMODE = 415,
    CORELOG = 416,
    SIP_WARNING = 417,
    SERVER_SIGNATURE = 418,
    SERVER_HEADER = 419,
    USER_AGENT_HEADER = 420,
    REPLY_TO_VIA = 421,
    LOADMODULE = 422,
    LOADPATH = 423,
    MODPARAM = 424,
    CFGENGINE = 425,
    MAXBUFFER = 426,
    SQL_BUFFER_SIZE = 427,
    USER = 428,
    GROUP = 429,
    CHROOT = 430,
    WDIR = 431,
    RUNDIR = 432,
    MHOMED = 433,
    DISABLE_TCP = 434,
    TCP_ACCEPT_ALIASES = 435,
    TCP_CHILDREN = 436,
    TCP_CONNECT_TIMEOUT = 437,
    TCP_SEND_TIMEOUT = 438,
    TCP_CON_LIFETIME = 439,
    TCP_POLL_METHOD = 440,
    TCP_MAX_CONNECTIONS = 441,
    TLS_MAX_CONNECTIONS = 442,
    TCP_NO_CONNECT = 443,
    TCP_SOURCE_IPV4 = 444,
    TCP_SOURCE_IPV6 = 445,
    TCP_OPT_FD_CACHE = 446,
    TCP_OPT_BUF_WRITE = 447,
    TCP_OPT_CONN_WQ_MAX = 448,
    TCP_OPT_WQ_MAX = 449,
    TCP_OPT_RD_BUF = 450,
    TCP_OPT_WQ_BLK = 451,
    TCP_OPT_DEFER_ACCEPT = 452,
    TCP_OPT_DELAYED_ACK = 453,
    TCP_OPT_SYNCNT = 454,
    TCP_OPT_LINGER2 = 455,
    TCP_OPT_KEEPALIVE = 456,
    TCP_OPT_KEEPIDLE = 457,
    TCP_OPT_KEEPINTVL = 458,
    TCP_OPT_KEEPCNT = 459,
    TCP_OPT_CRLF_PING = 460,
    TCP_OPT_ACCEPT_NO_CL = 461,
    TCP_OPT_ACCEPT_HEP3 = 462,
    TCP_CLONE_RCVBUF = 463,
    TCP_REUSE_PORT = 464,
    DISABLE_TLS = 465,
    ENABLE_TLS = 466,
    TLSLOG = 467,
    TLS_PORT_NO = 468,
    TLS_METHOD = 469,
    TLS_HANDSHAKE_TIMEOUT = 470,
    TLS_SEND_TIMEOUT = 471,
    SSLv23 = 472,
    SSLv2 = 473,
    SSLv3 = 474,
    TLSv1 = 475,
    TLS_VERIFY = 476,
    TLS_REQUIRE_CERTIFICATE = 477,
    TLS_CERTIFICATE = 478,
    TLS_PRIVATE_KEY = 479,
    TLS_CA_LIST = 480,
    DISABLE_SCTP = 481,
    ENABLE_SCTP = 482,
    SCTP_CHILDREN = 483,
    ADVERTISED_ADDRESS = 484,
    ADVERTISED_PORT = 485,
    DISABLE_CORE = 486,
    OPEN_FD_LIMIT = 487,
    SHM_MEM_SZ = 488,
    SHM_FORCE_ALLOC = 489,
    MLOCK_PAGES = 490,
    REAL_TIME = 491,
    RT_PRIO = 492,
    RT_POLICY = 493,
    RT_TIMER1_PRIO = 494,
    RT_TIMER1_POLICY = 495,
    RT_TIMER2_PRIO = 496,
    RT_TIMER2_POLICY = 497,
    MCAST_LOOPBACK = 498,
    MCAST_TTL = 499,
    MCAST = 500,
    TOS = 501,
    PMTU_DISCOVERY = 502,
    KILL_TIMEOUT = 503,
    MAX_WLOOPS = 504,
    PVBUFSIZE = 505,
    PVBUFSLOTS = 506,
    PVCACHELIMIT = 507,
    PVCACHEACTION = 508,
    HTTP_REPLY_PARSE = 509,
    VERSION_TABLE_CFG = 510,
    VERBOSE_STARTUP = 511,
    CFG_DESCRIPTION = 512,
    SERVER_ID = 513,
    MAX_RECURSIVE_LEVEL = 514,
    MAX_BRANCHES_PARAM = 515,
    LATENCY_CFG_LOG = 516,
    LATENCY_LOG = 517,
    LATENCY_LIMIT_DB = 518,
    LATENCY_LIMIT_ACTION = 519,
    MSG_TIME = 520,
    ONSEND_RT_REPLY = 521,
    FLAGS_DECL = 522,
    AVPFLAGS_DECL = 523,
    ATTR_MARK = 524,
    SELECT_MARK = 525,
    ATTR_FROM = 526,
    ATTR_TO = 527,
    ATTR_FROMURI = 528,
    ATTR_TOURI = 529,
    ATTR_FROMUSER = 530,
    ATTR_TOUSER = 531,
    ATTR_FROMDOMAIN = 532,
    ATTR_TODOMAIN = 533,
    ATTR_GLOBAL = 534,
    ADDEQ = 535,
    SUBST = 536,
    SUBSTDEF = 537,
    SUBSTDEFS = 538,
    EQUAL = 539,
    LOG_OR = 540,
    LOG_AND = 541,
    BIN_OR = 542,
    BIN_AND = 543,
    BIN_XOR = 544,
    BIN_LSHIFT = 545,
    BIN_RSHIFT = 546,
    EQUAL_T = 547,
    DIFF = 548,
    MATCH = 549,
    INTEQ = 550,
    INTDIFF = 551,
    STREQ = 552,
    STRDIFF = 553,
    GT = 554,
    LT = 555,
    GTE = 556,
    LTE = 557,
    PLUS = 558,
    MINUS = 559,
    STAR = 560,
    SLASH = 561,
    MODULO = 562,
    NOT = 563,
    UNARY = 564,
    BIN_NOT = 565,
    DEFINED = 566,
    INTCAST = 567,
    STRCAST = 568,
    DOT = 569,
    STRLEN = 570,
    STREMPTY = 571,
    NUMBER = 572,
    ID = 573,
    NUM_ID = 574,
    STRING = 575,
    IPV6ADDR = 576,
    PVAR = 577,
    AVP_OR_PVAR = 578,
    EVENT_RT_NAME = 579,
    COMMA = 580,
    SEMICOLON = 581,
    RPAREN = 582,
    LPAREN = 583,
    LBRACE = 584,
    RBRACE = 585,
    LBRACK = 586,
    RBRACK = 587,
    CR = 588,
    COLON = 589
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 199 "core/cfg.y" /* yacc.c:355  */

	long intval;
	unsigned long uval;
	char* strval;
	struct expr* expr;
	struct action* action;
	struct case_stms* case_stms;
	struct net* ipnet;
	struct ip_addr* ipaddr;
	struct socket_id* sockid;
	struct name_lst* name_l;
	struct avp_spec* attr;
	struct _pv_spec* pvar;
	struct lvalue* lval;
	struct rvalue* rval;
	struct rval_expr* rv_expr;
	select_t* select;

#line 629 "core/cfg.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CORE_CFG_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 644 "core/cfg.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  441
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   11591

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  335
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  871
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1626

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   589

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint16 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   612,   612,   615,   616,   617,   620,   621,   622,   623,
     624,   625,   625,   626,   626,   627,   628,   628,   629,   629,
     630,   630,   631,   632,   635,   651,   659,   673,   674,   680,
     681,   685,   686,   687,   688,   689,   692,   693,   694,   695,
     696,   697,   698,   701,   702,   705,   706,   707,   708,   709,
     713,   714,   715,   716,   717,   721,   722,   725,   726,   729,
     730,   732,   733,   736,   739,   745,   746,   750,   751,   754,
     755,   758,   764,   765,   766,   767,   768,   769,   770,   771,
     772,   775,   776,   782,   783,   784,   785,   786,   787,   788,
     789,   790,   791,   792,   793,   794,   795,   796,   797,   798,
     799,   800,   801,   802,   803,   804,   805,   806,   807,   808,
     809,   810,   811,   813,   814,   815,   816,   817,   818,   819,
     820,   821,   822,   823,   824,   825,   826,   827,   828,   829,
     830,   831,   832,   833,   834,   835,   836,   837,   838,   839,
     840,   841,   842,   843,   844,   845,   846,   847,   848,   849,
     850,   851,   852,   855,   856,   859,   860,   863,   864,   865,
     866,   869,   870,   873,   874,   877,   878,   881,   882,   883,
     884,   885,   890,   891,   892,   893,   894,   895,   896,   897,
     898,   899,   900,   901,   902,   903,   904,   905,   906,   907,
     908,   909,   910,   911,   912,   913,   914,   915,   916,   917,
     918,   919,   920,   921,   922,   923,   926,   927,   934,   941,
     942,   943,   944,   945,   946,   947,   948,   949,   950,   951,
     952,   953,   954,   955,   956,   963,   964,   971,   972,   979,
     980,   987,   988,   995,   996,  1006,  1007,  1021,  1035,  1036,
    1043,  1044,  1051,  1052,  1059,  1060,  1069,  1070,  1079,  1080,
    1087,  1088,  1095,  1096,  1103,  1104,  1111,  1112,  1119,  1120,
    1127,  1128,  1135,  1136,  1143,  1144,  1151,  1152,  1159,  1160,
    1167,  1168,  1175,  1176,  1183,  1184,  1191,  1192,  1199,  1200,
    1207,  1208,  1215,  1217,  1224,  1225,  1236,  1237,  1244,  1245,
    1252,  1253,  1260,  1261,  1268,  1269,  1276,  1283,  1290,  1297,
    1304,  1311,  1312,  1319,  1320,  1327,  1328,  1335,  1336,  1343,
    1344,  1351,  1352,  1359,  1360,  1367,  1368,  1375,  1376,  1383,
    1384,  1385,  1386,  1389,  1390,  1393,  1394,  1395,  1396,  1408,
    1421,  1423,  1434,  1435,  1436,  1437,  1443,  1444,  1454,  1455,
    1456,  1457,  1458,  1459,  1466,  1467,  1474,  1475,  1476,  1477,
    1478,  1479,  1480,  1481,  1482,  1483,  1484,  1485,  1486,  1487,
    1488,  1489,  1490,  1491,  1498,  1499,  1506,  1507,  1514,  1521,
    1522,  1523,  1550,  1551,  1552,  1553,  1554,  1555,  1556,  1557,
    1558,  1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,  1567,
    1568,  1569,  1570,  1571,  1572,  1573,  1574,  1575,  1576,  1577,
    1578,  1579,  1580,  1581,  1582,  1583,  1584,  1585,  1586,  1587,
    1589,  1590,  1592,  1594,  1595,  1596,  1599,  1600,  1603,  1604,
    1605,  1608,  1609,  1612,  1613,  1614,  1622,  1627,  1632,  1637,
    1642,  1645,  1650,  1658,  1664,  1665,  1675,  1676,  1686,  1687,
    1698,  1709,  1710,  1716,  1717,  1723,  1727,  1728,  1731,  1760,
    1775,  1776,  1780,  1791,  1792,  1796,  1797,  1801,  1810,  1828,
    1829,  1832,  1841,  1859,  1863,  1864,  1869,  1869,  1878,  1879,
    1881,  1880,  1905,  1910,  1919,  1937,  1939,  1948,  1966,  1968,
    1987,  1990,  1991,  1992,  1993,  1994,  1995,  2017,  2018,  2019,
    2020,  2023,  2024,  2025,  2026,  2029,  2030,  2036,  2037,  2038,
    2039,  2040,  2041,  2042,  2045,  2046,  2047,  2048,  2055,  2056,
    2057,  2064,  2065,  2066,  2070,  2071,  2072,  2073,  2074,  2079,
    2080,  2083,  2084,  2085,  2091,  2093,  2095,  2096,  2098,  2100,
    2102,  2104,  2106,  2107,  2109,  2110,  2111,  2112,  2114,  2116,
    2118,  2120,  2122,  2124,  2125,  2161,  2163,  2165,  2167,  2170,
    2172,  2174,  2176,  2180,  2181,  2192,  2193,  2197,  2198,  2214,
    2230,  2231,  2234,  2235,  2236,  2245,  2246,  2262,  2278,  2280,
    2287,  2329,  2330,  2333,  2334,  2335,  2338,  2339,  2340,  2341,
    2342,  2343,  2344,  2345,  2348,  2356,  2366,  2383,  2390,  2397,
    2404,  2411,  2416,  2421,  2422,  2423,  2424,  2425,  2428,  2437,
    2444,  2469,  2485,  2486,  2491,  2510,  2519,  2531,  2546,  2547,
    2550,  2550,  2560,  2561,  2562,  2563,  2564,  2565,  2566,  2567,
    2568,  2571,  2574,  2575,  2578,  2585,  2588,  2595,  2601,  2602,
    2611,  2612,  2613,  2616,  2617,  2629,  2653,  2664,  2695,  2699,
    2709,  2723,  2735,  2736,  2738,  2739,  2740,  2754,  2755,  2756,
    2757,  2758,  2759,  2760,  2764,  2765,  2766,  2779,  2785,  2786,
    2787,  2788,  2789,  2790,  2791,  2792,  2793,  2794,  2795,  2796,
    2797,  2798,  2799,  2817,  2818,  2819,  2820,  2821,  2822,  2823,
    2824,  2825,  2826,  2827,  2828,  2829,  2830,  2831,  2832,  2833,
    2835,  2837,  2838,  2839,  2840,  2841,  2844,  2862,  2863,  2864,
    2867,  2868,  2869,  2870,  2871,  2872,  2873,  2874,  2875,  2876,
    2877,  2878,  2879,  2880,  2881,  2882,  2883,  2884,  2885,  2886,
    2887,  2888,  2889,  2890,  2891,  2892,  2893,  2894,  2895,  2896,
    2897,  2898,  2899,  2900,  2901,  2909,  2917,  2925,  2933,  2941,
    2949,  2957,  2965,  2973,  2974,  2976,  2984,  2992,  3000,  3009,
    3018,  3027,  3035,  3044,  3052,  3053,  3055,  3058,  3059,  3060,
    3061,  3068,  3075,  3076,  3082,  3089,  3090,  3096,  3103,  3104,
    3110,  3113,  3116,  3117,  3118,  3121,  3122,  3123,  3132,  3141,
    3142,  3143,  3144,  3145,  3146,  3147,  3148,  3149,  3150,  3151,
    3152,  3153,  3154,  3155,  3156,  3157,  3158,  3162,  3166,  3167,
    3168,  3169,  3170,  3171,  3172,  3173,  3174,  3175,  3176,  3177,
    3178,  3179,  3180,  3181,  3182,  3183,  3184,  3185,  3186,  3187,
    3188,  3189,  3190,  3191,  3192,  3193,  3201,  3209,  3217,  3218,
    3220,  3222,  3233,  3234,  3235,  3251,  3252,  3253,  3257,  3260,
    3261,  3264,  3267,  3270,  3273,  3276,  3279,  3282,  3285,  3288,
    3291,  3292,  3293,  3296,  3297,  3298,  3298,  3326,  3328,  3330,
    3331,  3334,  3351,  3355,  3359,  3363,  3368,  3372,  3377,  3381,
    3385,  3389
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FORWARD", "FORWARD_TCP", "FORWARD_TLS",
  "FORWARD_SCTP", "FORWARD_UDP", "EXIT", "DROP", "RETURN", "BREAK",
  "LOG_TOK", "ERROR", "ROUTE", "ROUTE_REQUEST", "ROUTE_FAILURE",
  "ROUTE_ONREPLY", "ROUTE_REPLY", "ROUTE_BRANCH", "ROUTE_SEND",
  "ROUTE_EVENT", "EXEC", "SET_HOST", "SET_HOSTPORT", "SET_HOSTPORTTRANS",
  "PREFIX", "STRIP", "STRIP_TAIL", "SET_USERPHONE", "APPEND_BRANCH",
  "REMOVE_BRANCH", "CLEAR_BRANCHES", "SET_USER", "SET_USERPASS",
  "SET_PORT", "SET_URI", "REVERT_URI", "FORCE_RPORT", "ADD_LOCAL_RPORT",
  "FORCE_TCP_ALIAS", "UDP_MTU", "UDP_MTU_TRY_PROTO", "UDP4_RAW",
  "UDP4_RAW_MTU", "UDP4_RAW_TTL", "IF", "ELSE", "SET_ADV_ADDRESS",
  "SET_ADV_PORT", "FORCE_SEND_SOCKET", "SET_FWD_NO_CONNECT",
  "SET_RPL_NO_CONNECT", "SET_FWD_CLOSE", "SET_RPL_CLOSE", "SWITCH", "CASE",
  "DEFAULT", "WHILE", "CFG_SELECT", "CFG_RESET", "URIHOST", "URIPORT",
  "MAX_LEN", "SETFLAG", "RESETFLAG", "ISFLAGSET", "SETAVPFLAG",
  "RESETAVPFLAG", "ISAVPFLAGSET", "METHOD", "URI", "FROM_URI", "TO_URI",
  "SRCIP", "SRCPORT", "DSTIP", "DSTPORT", "TOIP", "TOPORT", "SNDIP",
  "SNDPORT", "SNDPROTO", "SNDAF", "PROTO", "AF", "MYSELF", "MSGLEN", "UDP",
  "TCP", "TLS", "SCTP", "WS", "WSS", "DEBUG_V", "FORK", "FORK_DELAY",
  "MODINIT_DELAY", "LOGSTDERROR", "LOGFACILITY", "LOGNAME", "LOGCOLOR",
  "LOGPREFIX", "LOGPREFIXMODE", "LOGENGINETYPE", "LOGENGINEDATA", "LISTEN",
  "ADVERTISE", "ALIAS", "SR_AUTO_ALIASES", "DNS", "REV_DNS",
  "DNS_TRY_IPV6", "DNS_TRY_NAPTR", "DNS_SRV_LB", "DNS_UDP_PREF",
  "DNS_TCP_PREF", "DNS_TLS_PREF", "DNS_SCTP_PREF", "DNS_RETR_TIME",
  "DNS_RETR_NO", "DNS_SERVERS_NO", "DNS_USE_SEARCH", "DNS_SEARCH_FMATCH",
  "DNS_NAPTR_IGNORE_RFC", "DNS_CACHE_INIT", "DNS_USE_CACHE",
  "DNS_USE_FAILOVER", "DNS_CACHE_FLAGS", "DNS_CACHE_NEG_TTL",
  "DNS_CACHE_MIN_TTL", "DNS_CACHE_MAX_TTL", "DNS_CACHE_MEM",
  "DNS_CACHE_GC_INT", "DNS_CACHE_DEL_NONEXP", "DNS_CACHE_REC_PREF",
  "AUTO_BIND_IPV6", "DST_BLST_INIT", "USE_DST_BLST", "DST_BLST_MEM",
  "DST_BLST_TTL", "DST_BLST_GC_INT", "DST_BLST_UDP_IMASK",
  "DST_BLST_TCP_IMASK", "DST_BLST_TLS_IMASK", "DST_BLST_SCTP_IMASK",
  "IP_FREE_BIND", "PORT", "STAT", "CHILDREN", "SOCKET_WORKERS",
  "ASYNC_WORKERS", "ASYNC_USLEEP", "CHECK_VIA", "PHONE2TEL", "MEMLOG",
  "MEMDBG", "MEMSUM", "MEMSAFETY", "MEMJOIN", "MEMSTATUSMODE", "CORELOG",
  "SIP_WARNING", "SERVER_SIGNATURE", "SERVER_HEADER", "USER_AGENT_HEADER",
  "REPLY_TO_VIA", "LOADMODULE", "LOADPATH", "MODPARAM", "CFGENGINE",
  "MAXBUFFER", "SQL_BUFFER_SIZE", "USER", "GROUP", "CHROOT", "WDIR",
  "RUNDIR", "MHOMED", "DISABLE_TCP", "TCP_ACCEPT_ALIASES", "TCP_CHILDREN",
  "TCP_CONNECT_TIMEOUT", "TCP_SEND_TIMEOUT", "TCP_CON_LIFETIME",
  "TCP_POLL_METHOD", "TCP_MAX_CONNECTIONS", "TLS_MAX_CONNECTIONS",
  "TCP_NO_CONNECT", "TCP_SOURCE_IPV4", "TCP_SOURCE_IPV6",
  "TCP_OPT_FD_CACHE", "TCP_OPT_BUF_WRITE", "TCP_OPT_CONN_WQ_MAX",
  "TCP_OPT_WQ_MAX", "TCP_OPT_RD_BUF", "TCP_OPT_WQ_BLK",
  "TCP_OPT_DEFER_ACCEPT", "TCP_OPT_DELAYED_ACK", "TCP_OPT_SYNCNT",
  "TCP_OPT_LINGER2", "TCP_OPT_KEEPALIVE", "TCP_OPT_KEEPIDLE",
  "TCP_OPT_KEEPINTVL", "TCP_OPT_KEEPCNT", "TCP_OPT_CRLF_PING",
  "TCP_OPT_ACCEPT_NO_CL", "TCP_OPT_ACCEPT_HEP3", "TCP_CLONE_RCVBUF",
  "TCP_REUSE_PORT", "DISABLE_TLS", "ENABLE_TLS", "TLSLOG", "TLS_PORT_NO",
  "TLS_METHOD", "TLS_HANDSHAKE_TIMEOUT", "TLS_SEND_TIMEOUT", "SSLv23",
  "SSLv2", "SSLv3", "TLSv1", "TLS_VERIFY", "TLS_REQUIRE_CERTIFICATE",
  "TLS_CERTIFICATE", "TLS_PRIVATE_KEY", "TLS_CA_LIST", "DISABLE_SCTP",
  "ENABLE_SCTP", "SCTP_CHILDREN", "ADVERTISED_ADDRESS", "ADVERTISED_PORT",
  "DISABLE_CORE", "OPEN_FD_LIMIT", "SHM_MEM_SZ", "SHM_FORCE_ALLOC",
  "MLOCK_PAGES", "REAL_TIME", "RT_PRIO", "RT_POLICY", "RT_TIMER1_PRIO",
  "RT_TIMER1_POLICY", "RT_TIMER2_PRIO", "RT_TIMER2_POLICY",
  "MCAST_LOOPBACK", "MCAST_TTL", "MCAST", "TOS", "PMTU_DISCOVERY",
  "KILL_TIMEOUT", "MAX_WLOOPS", "PVBUFSIZE", "PVBUFSLOTS", "PVCACHELIMIT",
  "PVCACHEACTION", "HTTP_REPLY_PARSE", "VERSION_TABLE_CFG",
  "VERBOSE_STARTUP", "CFG_DESCRIPTION", "SERVER_ID", "MAX_RECURSIVE_LEVEL",
  "MAX_BRANCHES_PARAM", "LATENCY_CFG_LOG", "LATENCY_LOG",
  "LATENCY_LIMIT_DB", "LATENCY_LIMIT_ACTION", "MSG_TIME",
  "ONSEND_RT_REPLY", "FLAGS_DECL", "AVPFLAGS_DECL", "ATTR_MARK",
  "SELECT_MARK", "ATTR_FROM", "ATTR_TO", "ATTR_FROMURI", "ATTR_TOURI",
  "ATTR_FROMUSER", "ATTR_TOUSER", "ATTR_FROMDOMAIN", "ATTR_TODOMAIN",
  "ATTR_GLOBAL", "ADDEQ", "SUBST", "SUBSTDEF", "SUBSTDEFS", "EQUAL",
  "LOG_OR", "LOG_AND", "BIN_OR", "BIN_AND", "BIN_XOR", "BIN_LSHIFT",
  "BIN_RSHIFT", "EQUAL_T", "DIFF", "MATCH", "INTEQ", "INTDIFF", "STREQ",
  "STRDIFF", "GT", "LT", "GTE", "LTE", "PLUS", "MINUS", "STAR", "SLASH",
  "MODULO", "NOT", "UNARY", "BIN_NOT", "DEFINED", "INTCAST", "STRCAST",
  "DOT", "STRLEN", "STREMPTY", "NUMBER", "ID", "NUM_ID", "STRING",
  "IPV6ADDR", "PVAR", "AVP_OR_PVAR", "EVENT_RT_NAME", "COMMA", "SEMICOLON",
  "RPAREN", "LPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "CR",
  "COLON", "$accept", "cfg", "statements", "statement", "$@1", "$@2",
  "$@3", "$@4", "$@5", "listen_id", "listen_id_lst", "listen_id2", "proto",
  "eqproto", "port", "phostport", "listen_phostport", "id_lst", "intno",
  "flags_decl", "flag_list", "flag_spec", "flag_name", "avpflags_decl",
  "avpflag_list", "avpflag_spec", "assign_stm", "cfg_var_id",
  "cfg_var_idn", "cfg_var", "module_stm", "ip", "ipv4", "ipv6addr", "ipv6",
  "route_name", "route_main", "route_stm", "failure_route_stm",
  "route_reply_main", "onreply_route_stm", "$@6", "$@7",
  "branch_route_stm", "send_route_stm", "event_route_stm",
  "preprocess_stm", "equalop", "cmpop", "strop", "rve_equalop",
  "rve_cmpop", "uri_type", "eint_op_onsend", "eint_op", "eip_op_onsend",
  "eip_op", "exp_elem", "ipnet", "host", "host_if_id", "host_or_if",
  "fcmd", "stm", "actions", "action", "if_cmd", "ct_rval", "single_case",
  "case_stms", "switch_cmd", "while_cmd", "select_param", "select_params",
  "select_id", "$@8", "attr_class_spec", "attr_name_spec", "attr_spec",
  "attr_mark", "attr_id", "attr_id_num_idx", "attr_id_no_idx",
  "attr_id_ass", "attr_id_any", "attr_id_any_str", "pvar", "avp_pvar",
  "assign_op", "lval", "rval", "rve_un_op", "rval_expr", "assign_action",
  "avpflag_oper", "cmd", "$@9", "func_params", "func_param", "ret_cmd", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589
};
# endif

#define YYPACT_NINF -1102

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1102)))

#define YYTABLE_NINF -856

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2346,  -231,    57,    24,  -208,  -172,  -167,  -131,  -127,  -118,
   -1102,  -113,   -98,   -95,   -94,   -62,   -55,   -51,   -45,   -21,
     -10,     9,    32,    62,   418,   450,   482,   494,    40,   275,
     587,   649,   669,   671,   677,   678,   730,   781,   786,   801,
     802,   844,   854,   855,   861,   869,   877,   885,   888,   889,
     890,   907,   910,   911,   914,   916,   917,   918,   948,   949,
     953,   955,   514,   566,   575,   598,   609,   626,   629,   630,
     640,   641,   655,   656,   691,   694,   696,   712,   755,   761,
     762,   768,   769,    72,   201,    36,   203,   770,   782,   795,
     807,   822,   828,   836,   841,   842,   846,   847,   848,   852,
     856,   860,   865,   867,   868,   875,   876,   879,   880,   956,
     957,   962,   971,   887,   927,   928,   936,   951,   954,   958,
     960,   973,   985,   986,   988,   991,   994,  1007,  1008,  1009,
    1010,  1014,  1016,  1017,  1018,  1019,  1022,  1024,  1027,  1030,
    1031,  1037,  1040,  1041,  1042,  1044,  1045,  1070,  1076,  1077,
    1078,  1079,  1081,  1092,  1093,  1097,  1185,  1187,  1188,   972,
    1195,  1196,  1197,  1198,  1199,  1200,  1205,  1206,  1207,  1208,
    1211,  1212,  1213,  1214,  1240,  1241,  1256,  1257,   179,   180,
     172,   173,   182, -1102, -1102, -1102,   176,  1485, -1102,    78,
     297,   301,   540,   905, -1102, -1102, -1102,  -288, -1102, -1102,
     381, -1102, -1102, -1102, -1102,   577, -1102,   210,   289,   853,
     303,   291,   294,   306,   298,   305,   329,   330,   161,   186,
     351,   196,   439,   213,   230,   309,   314,   588,   599,   611,
   -1102,   654, -1102,   662, -1102,   667, -1102,  -226, -1102,  -226,
   -1102,  -226, -1102,  -226, -1102,   685, -1102,   708, -1102,   713,
   -1102,   783, -1102,   784, -1102,   862, -1102,  1005, -1102,  1176,
   -1102,  1249, -1102,  1250, -1102,  1251, -1102,  1252, -1102,  1254,
   -1102,  1255, -1102,  1259, -1102,  1260, -1102,  1275, -1102,  1385,
   -1102,  1386, -1102,  1387, -1102,  1388, -1102,  1425, -1102,  1437,
   -1102,  1438, -1102,  1439, -1102,  1440, -1102,  1441,   321,   612,
     804,   615,   617,   620,   642,   643,   647,   332,   335,   360,
     412,   415,   426,   437,   652,   653,   241,   242,   657, -1102,
   -1102, -1102,   243, -1102, -1102,  1253, -1102,   244, -1102,   659,
     660,   187,   191,   211,   214,   219,   664,   665,   666,   668,
     453,   493,   495,   233,   673,   675,   680,   681,    27,   683,
     686, -1102,  1442, -1102,  1443, -1102,  1444, -1102,  1445,   687,
     688,   689,   699,   700,   702,   703,   704,   705,   706,   707,
     710,   711,   714,   716,   717,   723,   790,   726,   727,   739,
     741,   246,   249,   251,   743,   746,   752,    23,   754,   757,
     758,   759,   760,   766,   767,   778,   787,   788,   791,   792,
     793,   794,   799,   236,   279, -1102,  1446,   805,   810,   812,
     816,   820,   824,   825,   252,   826,   829,  1447,  1448,   511,
     525,   830,   831,   833,   837, -1102, -1102, -1102, -1102,   946,
    1435, -1102, -1102, -1102,  1469, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102,  -231, -1102,    64,    39,  1245, -1102,    83, -1102,
      88, -1102,    89, -1102,    14, -1102,   817,  1453, -1102, -1102,
   -1102, -1102,  1243, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102,  1478, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102,  1482, -1102, -1102,
   -1102, -1102,  1156,   670, -1102,  1463,  1464,   999,  1692, -1102,
   -1102, -1102, -1102, -1102,  -188, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
    1475, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102,  1482, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
    -153,  1484,  -153, -1102,   577, -1102, 11265, -1102, 11265,   577,
   -1102, 11265,   577, -1102, 11265,   577, -1102,  1480, -1102, -1102,
   -1102,  1518,  1473, 11265,    43, -1102,  1489,  1483,  1487,  1477,
     300,  1038, -1102,  1156,   276,   284,  1490, -1102, -1102, -1102,
    1499,    47,    48,    54,    55,    73, 10216, 10543, 10628, -1102,
      79,    81,    93,  1479,    95,   103,   104,   105,   106,   107,
     109,   118,  1488,   121,   122,   128,   134,  1504,  1505,  1506,
    1507,  1508, 10713,   135,   136,   137,  1509,  1529,  1531,  1532,
    6040, 10713,   142,   144,   149,   150,   153, -1102, -1102, -1102,
   -1102,   154, -1102, -1102, -1102,    31,  3394, -1102, -1102, -1102,
   -1102,   987, -1102, -1102, -1102, -1102, -1102,  1528,  1520,   155,
   -1102,  1535,  3467,  1540,  3547,  1541,  3795,  1545,  1546,   193,
    1501,  3875, -1102,  1534,  1565,  1156, -1102, -1102, -1102, -1102,
   -1102, -1102,  1553,  1566, -1102, -1102, -1102, -1102, -1102,  1576,
    1573, -1102,     8, -1102,    53, -1102,    60, -1102,   108, -1102,
     124,   744, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102,  -134, -1102,  -134, -1102,   775, -1102, -1102,
    1478, -1102, -1102,  6127,  6214,  6543,  1575,  1577, -1102,  5208,
   11194, -1102,   895, -1102,   883, -1102,   921, -1102, -1102, -1102,
     987, -1102, -1102, -1102, -1102, -1102, -1102, -1102,  6630,  1258,
    5537,  1258,  5624,  1258, -1102,   205, -1102,   254, -1102,  6717,
    1584, -1102,   256, -1102,   258, -1102,   259, -1102,   260, -1102,
     838, -1102,   839, -1102,  1579, -1102,    10,  1588, -1102,   265,
   -1102,   266, -1102,   267, -1102,   270,  1599,  1601,  1602,   159,
     857,  7046, 10149, -1102,   140, -1102,   840, -1102,   378,  1603,
    1605,  1614,  1615, -1102,  1046, 10149, -1102,   271, -1102,   272,
   -1102,   603, -1102,   618, -1102,   695, -1102,  1618, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102,  1633, -1102,  1617, -1102, 10713, -1102, -1102,
     215, -1102, -1102,  1627, -1102,  1640, -1102,  1641,  1642, -1102,
    1715,  1716,   817, -1102, 11265,  1657, -1102,  -234,  1658,   -99,
   11265,  1668,  -129, -1102,  -108, -1102,  -100,  -101,  1670,   -79,
     -63,   408,   -39,  1671,   519,   582,   674,   963,  1672,   732,
     737,   796,   970,  1674,   843,   903,   904,   982, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102,  7133,  5001,  5094, -1102,  1209,
    1666, -1102, -1102, -1102, -1102, -1102, -1102,  7220,  7549,  1683,
   -1102,  1727,  1731,  1732,  1733,  1100,  1698,  1708,  3944, -1102,
    7636, -1102, -1102, -1102, -1102, -1102,  7723,  8052, -1102,  2662,
    1709, -1102, -1102,  8139,  8226,  8555,  8642, 10713, 10713, 10713,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102,  8729,  9058,  9145,  9232,  9561,  9648,  9735, -1102, -1102,
    1712,  1717,  1714,  1726,  1718,  1737,    22,  1143,  1739,  1740,
    1741,  1743,  1752,  1753,  1757,  1759,  1766,  1767,  1768,  1769,
    1770, -1102,  1771, -1102,  1772, -1102,  1773,  1797,  1798,  1799,
    1800,  1801,  1802,  1804, -1102, -1102, -1102,  1805,  1806, -1102,
    1808,  1809, 11265,  1997, -1102,  1810,  1813,  1819,  1820,  1821,
    1815,  1817,  1825, -1102, -1102, -1102, -1102,    29, -1102,  1826,
    1830,  1829,  1831,  1832,  1833,  1834,  1835,  1836,  1837, 10713,
    1839,  1861,  1258,   909, -1102,   987, -1102,  1840, -1102, 11265,
   11265, 11265, 11265,  1846,  1847,  1884,  4017,  1855, -1102, -1102,
    1867,  1868,  4123, -1102,    -5, -1102,  1879, -1102,  1880, -1102,
     250,   281,  1881, -1102, -1102,     6, -1102,  1882, -1102,  1883,
   -1102,  1887, -1102, -1102,   589, -1102,  1888, -1102,  1889, -1102,
    1892, -1102, -1102,   715, -1102,  1898, -1102,  1899, -1102,  1900,
   -1102, -1102,   718, -1102,  1901, -1102,  1903, -1102,  1904, -1102,
   -1102,  1885,  1232, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102,  1232, -1102, -1102,  1232, -1102, -1102, -1102,  1870,
   -1102,  1908,  1875,  1486,  1897,  2126, -1102, -1102, -1102, -1102,
   -1102, -1102,  1954,  1232, -1102,  1232, -1102,  1067, -1102,  2023,
    1482,  1816,  1919, -1102,  -186,  1232,  -245, -1102,  2802, -1102,
    2823, -1102,  2869, -1102,  1119,  1161,  2886,  1215, -1102,  -159,
   -1102,  -159, -1102, -1102, -1102, -1102, -1102, -1102, -1102,  1232,
   -1102,  1067, -1102,  1906, -1102, -1102,  1907, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102,  4345, 11125, -1102,
   -1102, -1102, -1102, -1102,   421,  1156, -1102,  1902,  5711,  1894,
   -1102, -1102,   -11, -1102, 11040, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102,  1258,   923, -1102, -1102, -1102,  -153, -1102,
   -1102,   237,  4451,  4520,  4593,  4673, -1102, -1102,  -270, -1102,
    1912, -1102, -1102, -1102,  1909,  1910,  1911,  1935, -1102, -1102,
   -1102, -1102,  1936,  1937,  1938,  1939,  1940,  1941,  1942,  1943,
    1944,  1946,  1947,  1948,  1951,  1955,  1957,  1958,  1959,  1960,
    1962,  1963,  1964,   -26,  1666, -1102, -1102, -1102, -1102,    34,
    1961,  1967,  1968, -1102, -1102, -1102, -1102,  1896, -1102,  1965,
   10064,  1966,  1258, 11265, -1102, -1102,  1969,  2350, 10713, -1102,
    1970,  1971,  1974, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102,  1972,  1973, -1102, -1102,  1482,
   -1102, -1102, -1102, -1102,  -234, 11265,  1998,  1999,  2749,  2818,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102, -1102,  2887,
   11265, 11265, -1102,  2997,  3219,  3325
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     422,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   421,    22,    23,     0,     0,     4,     0,
       0,     0,     0,     0,     8,     9,     6,     0,   419,    10,
       0,    15,     7,   420,   468,     0,   469,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     101,     0,   103,     0,   105,     0,   107,     0,   109,     0,
     111,     0,   113,     0,   115,     0,   117,     0,   119,     0,
     121,     0,   123,     0,   125,     0,   127,     0,   129,     0,
     131,     0,   133,     0,   135,     0,   139,     0,   137,     0,
     141,     0,   143,     0,   145,     0,   147,     0,   149,     0,
     151,     0,   153,     0,   155,     0,   157,     0,   159,     0,
     161,     0,   163,     0,   165,     0,   167,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   434,
     433,   436,     0,   435,   441,     0,   443,     0,   442,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   254,     0,   256,     0,   258,     0,   260,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   374,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    66,    65,    59,    61,
      63,    68,    71,    67,    69,   482,   481,   484,   483,   486,
     485,     1,     5,     3,     0,     0,     0,    12,     0,    14,
       0,    17,     0,    19,     0,    21,     0,     0,   466,   452,
     453,   454,     0,   410,   409,   408,   407,   412,    31,    32,
      33,    34,    35,   411,   414,     0,    57,   413,   416,   415,
     418,   417,    73,    72,    75,    74,    77,    76,    79,    78,
      81,    80,    83,    82,    85,    84,    87,    86,    89,    88,
      91,    90,    93,    92,    95,    94,   330,   564,   562,   563,
      25,   449,     0,     0,    30,    50,     0,    55,   328,    24,
     446,   450,   447,   565,    26,   332,   331,   334,   333,    97,
      96,    99,    98,   100,   102,   104,   106,   108,   110,   112,
     114,   116,   118,   120,   122,   124,   126,   128,   130,   132,
     134,   138,   136,   140,   142,   144,   146,   148,   150,   152,
     154,   156,   158,   160,   162,   164,   166,   169,   168,   176,
     170,   171,   178,   177,   180,   179,   182,   181,   184,   183,
     186,   185,   188,   187,   190,   189,   192,   191,   194,   193,
     196,   195,   198,   197,   200,   199,   202,   201,   204,   203,
     321,   320,   323,   322,   325,   324,   327,   326,   438,   437,
       0,   445,   444,   173,   172,   175,   174,   209,   208,   207,
     212,   211,   210,   215,   214,   213,   218,   217,   216,   221,
     220,   219,   223,   222,   225,   224,   227,   226,   229,   228,
     231,   230,   233,   232,   235,   234,   238,   236,   237,   240,
     239,   242,   241,   244,   243,   246,     0,   245,   248,   247,
     250,   249,   252,   251,   253,   255,   257,   259,   262,   261,
     264,   263,   266,   265,   268,   267,   270,   269,   272,   271,
     274,   273,   276,   275,   278,   277,   280,   279,   282,   281,
     284,   283,   286,   285,   288,   287,   290,   289,   292,   291,
     294,   293,   299,   295,   296,   297,   298,   311,   310,   313,
     312,   301,   300,   303,   302,   305,   304,   307,   306,   309,
     308,   315,   314,   317,   316,   319,   318,   336,   335,   338,
     337,   340,   339,   342,   341,   344,   343,   346,   345,   348,
     347,   350,   349,   352,   351,   354,   353,   356,   355,   358,
     357,   360,   359,   362,   361,   364,   363,   366,   365,   369,
     367,   368,   372,   370,   371,   373,   376,   375,   378,   377,
     380,   379,   382,   381,   384,   383,   386,   385,   388,   387,
     206,   205,   390,   389,   392,   391,   393,   394,   398,   397,
     396,   395,   400,   399,   402,   401,   404,   403,   406,   405,
       0,     0,     0,   459,     0,   460,     0,   463,     0,     0,
     475,     0,     0,   478,     0,     0,   480,     0,   424,   425,
     423,     0,     0,     0,     0,    58,     0,    27,     0,     0,
       0,     0,    56,     0,     0,     0,     0,    62,    64,    70,
       0,     0,     0,     0,     0,     0,   867,   864,   868,   871,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   820,   822,   824,
     827,     0,     0,     0,     0,     0,   841,   843,   845,   847,
       0,     0,     0,     0,     0,     0,     0,   697,   698,   699,
     624,     0,   636,   637,   582,     0,     0,   574,   577,   578,
     579,     0,   628,   629,   639,   640,   641,     0,     0,     0,
     570,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   472,     0,     0,     0,    29,   451,    54,    44,
      43,    51,    52,     0,   569,   564,   567,   568,   566,     0,
       0,   710,     0,   732,     0,   743,     0,   754,     0,   721,
       0,     0,   508,   509,   510,   521,   514,   522,   515,   520,
     512,   519,   511,     0,   513,     0,   516,     0,   517,   610,
     656,   654,   655,     0,     0,     0,     0,     0,   643,     0,
       0,   642,     0,   518,     0,   523,     0,   649,   648,   647,
       0,   630,   632,   631,   644,   645,   646,   657,     0,   866,
       0,   863,     0,   870,   758,     0,   775,     0,   779,     0,
       0,   783,     0,   802,     0,   805,     0,   786,     0,   792,
       0,   789,     0,   795,     0,   798,     0,     0,   811,     0,
     814,     0,   808,     0,   817,     0,     0,     0,     0,     0,
       0,     0,     0,   833,     0,   836,     0,   839,     0,     0,
       0,     0,     0,   602,     0,     0,   850,     0,   853,     0,
     762,     0,   765,     0,   768,     0,   857,     0,   583,   576,
     575,   457,   573,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,     0,   622,   625,   638,     0,   581,   773,
       0,   580,   461,     0,   473,     0,   476,     0,     0,   430,
     426,   427,     0,   467,     0,     0,    28,     0,     0,     0,
       0,     0,     0,   557,     0,   700,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   527,   487,
     488,   496,   489,   490,   495,     0,     0,     0,   552,     0,
       0,   695,   678,   680,   659,   681,   660,     0,     0,     0,
     865,   630,   631,   645,   646,     0,     0,     0,     0,   531,
       0,   536,   491,   492,   493,   494,     0,     0,   548,     0,
     625,   679,   658,     0,     0,     0,     0,     0,     0,     0,
     497,   498,   503,   499,   500,   501,   502,   504,   505,   506,
     507,     0,     0,     0,     0,     0,     0,     0,   862,   869,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   794,     0,   797,     0,   800,     0,     0,     0,     0,
       0,     0,     0,     0,   819,   821,   823,     0,     0,   826,
       0,     0,     0,   584,   571,     0,     0,     0,     0,     0,
      45,     0,     0,   840,   842,   844,   846,     0,   604,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   858,
       0,     0,   696,     0,   635,     0,   633,     0,   634,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,   329,
       0,     0,     0,   711,     0,   709,     0,   702,     0,   703,
       0,     0,     0,   701,   733,     0,   731,     0,   724,     0,
     725,     0,   723,   744,     0,   742,     0,   735,     0,   736,
       0,   734,   755,     0,   753,     0,   746,     0,   747,     0,
     745,   722,     0,   720,     0,   713,     0,   714,     0,   712,
     526,     0,   524,   542,    36,    37,    38,    39,    40,    41,
      42,   540,   541,   539,   537,   538,   551,   549,   550,   605,
     609,   611,     0,     0,     0,     0,   653,   675,   652,   651,
     650,   530,     0,   528,   535,   533,   534,   532,   547,     0,
      57,     0,   555,   543,   545,   544,     0,   692,   674,   691,
     673,   687,   666,   688,   667,   668,   669,   670,   682,   661,
     683,   662,   684,   663,   685,   664,   686,   665,   690,   672,
     689,   671,   759,     0,   756,   776,     0,   780,   778,   777,
     781,   784,   782,   803,   801,   806,   804,   787,   785,   793,
     791,   790,   788,   799,   796,   812,   810,   815,   813,   809,
     807,   818,   816,   828,   825,   830,   829,     0,     0,   832,
     831,   835,   834,   838,     0,     0,   837,     0,     0,     0,
     601,   599,     0,   851,     0,   854,   852,   760,   761,   763,
     764,   766,   767,   861,     0,   860,   623,   627,     0,   772,
     625,     0,     0,     0,     0,     0,   428,   429,     0,   471,
       0,   439,   440,   458,     0,     0,     0,     0,   561,   559,
     560,   558,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   693,   676,   694,   677,     0,
       0,     0,     0,   572,   585,    49,    46,    47,   603,     0,
       0,     0,   586,   592,   600,   598,    57,     0,     0,   856,
       0,     0,     0,   462,   474,   477,   479,   431,   432,   448,
     707,   708,   705,   706,   704,   729,   730,   727,   728,   726,
     740,   741,   738,   739,   737,   751,   752,   749,   750,   748,
     718,   719,   716,   717,   715,     0,     0,   608,   556,   554,
     553,   626,   757,   774,     0,   595,     0,     0,     0,     0,
     848,   849,   859,   771,   770,   769,   607,   606,    48,     0,
     596,   590,   597,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1102, -1102, -1102,  2044, -1102, -1102, -1102, -1102, -1102,  -385,
    1308,  1403,  -205,  1088, -1101, -1102, -1102,   -87,  -210, -1102,
    1502, -1102,  -178, -1102,  1533, -1102, -1102, -1102,  1201, -1102,
   -1102,  -930,  1984,  1793,  1986,   464, -1102, -1102, -1102, -1102,
   -1102, -1102, -1102, -1102, -1102, -1102, -1102,  -946, -1102,  -905,
   -1102, -1102,  1158, -1102, -1102, -1102,  1189, -1102, -1102,   299,
    -701, -1102,  -241, -1047,  -748,  -721, -1102,   789,   864, -1102,
   -1102, -1102,   803, -1102, -1102, -1102, -1102,  1060,  -938,  -506,
    -801, -1102,  -744, -1102, -1102, -1102,  -527,  -772, -1102, -1102,
   -1102, -1102,    20,  -818, -1102, -1102, -1102, -1102,   785, -1102
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   514,
     828,   515,   516,  1361,   931,  1262,   517,   518,   981,   194,
     428,   429,   430,   195,   433,   434,   196,   197,   821,   198,
     199,   519,   520,   521,   522,   462,   446,   447,   449,   200,
     201,   823,   923,   451,   453,   455,   202,  1144,  1177,  1145,
    1206,  1207,   982,   983,   984,   985,   986,   987,  1393,  1117,
     523,   524,   988,  1253,   896,   897,   898,  1551,  1471,  1472,
     899,   900,  1370,  1371,   989,  1150,  1083,  1084,  1085,   990,
     991,   992,   993,   904,   994,  1287,   995,   996,  1087,   907,
     997,   998,  1165,   908,   909,   910,  1067,  1484,  1485,   911
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     477,   432,   728,   483,   473,   902,  1298,   902,  1268,  1111,
     902,  1232,  1116,   902,  1121,   816,  1126,  1146,  1131,  1147,
    1136,  1149,   902,  1066,   727,   206,   456,   536,   658,   537,
    1467,   538,  1068,   539,   906,  1598,   906,   324,  1176,   906,
     805,   230,   906,   457,   922,  1468,  1469,  1567,   941,   943,
    1568,   906,  1180,   203,  1118,   945,   947,  1504,   204,   475,
     912,  1123,   903,   914,   903,   803,   916,   903,  1513,  1112,
     903,   929,   476,   319,   949,   921,   207,  1170,   475,   903,
    1004,  1179,  1006,   930,   807,  1468,  1469,  1487,   568,   810,
     813,   476,   444,   445,  1008,   902,  1011,   585,   587,   589,
     591,   593,   595,   597,  1013,  1015,  1017,  1019,  1021,  1128,
    1023,   902,   208,   902,  1119,   902,   834,   209,  1310,  1025,
     902,  1124,  1028,  1030,   906,  1133,   835,   827,  1311,  1032,
     641,   643,   645,   936,   938,  1034,  1043,  1045,  1047,   526,
     906,  1255,   906,  1056,   906,  1058,  1203,  1204,  1205,   906,
    1060,  1062,   903,   210,  1064,  1066,  1089,   211,  1139,  1140,
    1247,  1166,   492,  1142,  1143,   426,   212,   427,   903,  1129,
     903,   213,   903,   435,   437,  1072,   441,   903,  1161,   902,
     425,   431,  1166,   439,  1166,  1134,   214,   494,   617,   215,
     216,  1072,   620,  1072,  1099,  1072,  1304,   498,  1305,  1161,
    1072,  1161,   321,  1310,   326,   475,  1210,  1164,   906,   789,
     791,   463,   623,  1311,   502,   626,  1283,  1306,   476,  1307,
     629,  1300,   217,  1166,  1312,  1308,  1313,  1309,  1164,   218,
    1164,   504,  1168,   219,   646,  1162,   903,   759,  1561,   220,
    1161,   902,   602,   604,   608,   611,  1315,   715,  1316,  1392,
     717,  1508,   719,   780,   902,  1213,  1162,  1219,  1162,  1221,
    1223,  1225,  1317,   221,  1318,  1310,  1236,  1238,  1240,  1164,
     906,  1242,  1269,  1271,   222,  1311,   232,   934,   475,   905,
     762,   905,  1510,   906,   905,   937,  1321,   905,  1322,  1286,
     465,   476,   478,   223,  1595,   480,   905,  1162,   903,   484,
     901,   928,   901,   902,   474,   901,   486,   482,   901,   902,
     506,   903,  1505,   448,   475,   525,   224,   901,  1288,  1554,
     450,  1254,   567,  1514,   231,   656,  1113,   476,  1114,   511,
     488,   490,   906,   584,  1254,  1115,   586,  1233,   906,   513,
     507,   508,   509,   510,   511,   817,   225,  1490,   511,  1428,
    -855,  1599,   496,  -465,   513,   511,  1296,  1069,   513,  1470,
     903,   588,  1302,  1546,   325,   513,   903,   902,  -456,   905,
     656,  1113,  -470,  1120,   511,   942,   944,   656,  1113,  1259,
    1125,   511,   946,   948,   513,   905,  -464,   905,   205,   905,
     901,   513,   320,  -455,   905,   804,   906,   468,   469,   470,
     471,   950,   468,   469,   470,   471,   901,  1005,   901,  1007,
     901,  1544,   808,   590,   809,   901,   592,   811,   814,   812,
     815,  1009,  1545,  1012,   903,   656,  1113,   594,  1130,   511,
     832,  1014,  1016,  1018,  1020,  1022,  1149,  1024,   596,   513,
     500,   656,  1113,  1149,  1135,   511,  1026,  1072,   933,  1029,
    1031,   902,  1163,   905,   640,   513,  1033,   507,   508,   509,
     510,   511,  1035,  1044,  1046,  1048,   468,   469,   470,   471,
    1057,   513,  1059,  1163,   901,  1163,  1248,  1061,  1063,   493,
     906,  1065,  -855,  1090,   890,   322,  1249,   327,   902,   902,
     902,   902,   436,   438,   642,   902,   644,   426,   426,   427,
     427,   902,   440,  1618,  1457,   618,   495,   619,   903,   621,
    1100,   622,   788,  1101,  1163,   905,   499,   906,   906,   906,
     906,   323,  1211,   328,   906,  1212,   790,   464,   905,   624,
     906,   625,   627,   503,   628,  1284,   901,   630,   893,   631,
     827,  1492,  1493,  1494,  1495,   903,   903,   903,   903,   901,
     505,   647,   903,   648,   760,   426,   761,   427,   903,   233,
     452,   603,   605,   609,   612,   895,   716,   895,  1509,   718,
     895,   720,   781,   895,  1214,  1072,  1220,   905,  1222,  1224,
    1226,  1072,   895,   905,  1285,  1237,  1239,  1241,   234,   527,
    1243,  1270,  1272,   935,   508,   509,   763,   764,   901,  1511,
     529,   935,   508,   509,   901,   929,   466,   475,   479,  1600,
     475,   481,   531,   569,   472,   485,   572,   930,   574,   472,
     476,   576,   487,   476,   432,   475,   507,   508,   509,   510,
     511,   507,   508,   509,   510,   511,   475,   512,   476,   475,
     513,   905,   512,   578,   580,   513,   489,   491,   582,   476,
     236,  1518,   476,   598,   600,   895,   902,   902,   606,  1256,
     613,   615,   901,  1260,   475,   632,   634,   636,   497,   638,
     238,   895,   240,   895,   649,   895,   651,   476,   242,   244,
     895,   653,   655,   472,   660,   906,   906,   662,   668,   670,
     672,   902,   902,   902,   902,   507,   508,   509,   510,   511,
     674,   676,   226,   678,   680,   682,   684,   686,   688,   513,
     458,   690,   692,   903,   903,   694,   475,   696,   698,   475,
     906,   906,   906,   906,   700,   905,   929,   707,   709,   476,
     475,   246,   476,  1319,   227,  1320,  1072,  1254,   930,   895,
     711,   475,   713,   476,   721,  1138,   901,   723,   903,   903,
     903,   903,   902,   725,   476,   729,   501,   475,   731,   733,
     735,   737,   905,   905,   905,   905,   228,   739,   741,   905,
     476,  1072,  1072,  1072,  1072,   905,  1148,  1523,   229,   743,
    1528,   906,   248,   901,   901,   901,   901,   250,   745,   747,
     901,   702,   749,   751,   753,   755,   901,   475,   298,   475,
     757,   895,   252,   254,   902,  1609,   766,   902,   902,   903,
     476,   768,   476,   770,   895,   475,  1234,   772,   902,   902,
     902,   774,   902,   902,   902,   776,   778,   782,   476,   475,
     784,   792,   794,   906,   796,  1251,   906,   906,   798,  1227,
    1229,  1257,   476,  1261,  1324,   256,  1325,   906,   906,   906,
     299,   906,   906,   906,   467,   258,   260,  1619,  1250,   300,
    1623,   903,   262,   895,   903,   903,   999,  1001,  1003,   895,
     264,   235,  1624,  1625,   818,   903,   903,   903,   266,   903,
     903,   903,   301,  1274,  1171,  1276,   268,  1278,  1072,   270,
     272,   274,  1042,   302,   459,   460,  1169,   461,  1072,  1301,
    1054,  1055,  1072,  1072,  1072,   528,  1519,  1326,   276,  1327,
     303,   278,   280,   304,   305,   282,   530,   284,   286,   288,
    1273,   426,  1178,   427,   306,   307,   454,   895,   532,   570,
     905,   905,   573,   237,   575,  1275,   426,   577,   427,   308,
     309,   468,   469,   470,   471,   468,   469,   470,   471,   290,
     292,   901,   901,   239,   294,   241,   296,   351,   353,   579,
     581,   243,   245,   355,   583,   905,   905,   905,   905,   599,
     601,   533,   357,   405,   607,   310,   614,   616,   311,   534,
     312,   633,   635,   637,   535,   639,   901,   901,   901,   901,
     650,   511,   652,  1152,  1154,  1156,   313,   654,   656,  1328,
     661,  1329,   540,   663,   669,   671,   673,   703,   704,   705,
     706,   895,  1277,   426,   247,   427,   675,   677,  1182,   679,
     681,   683,   685,   687,   689,   541,   905,   691,   693,  1217,
     542,   695,  1524,   697,   699,  1529,  1139,  1140,  1141,   314,
     701,  1142,  1143,   708,   710,   315,   316,   901,   895,   895,
     895,   895,   317,   318,   329,   895,   712,  1333,   714,  1334,
     722,   895,  1335,   724,  1336,   249,   330,  1139,  1140,   726,
     251,   730,  1142,  1143,   732,   734,   736,   738,   905,   331,
    1547,   905,   905,   740,   742,   253,   255,   468,   469,   470,
     471,   332,   905,   905,   905,   744,   905,   905,   905,   901,
     543,   544,   901,   901,   746,   748,   333,  1282,   750,   752,
     754,   756,   334,   901,   901,   901,   758,   901,   901,   901,
     335,  1337,   767,  1338,   571,   336,   337,   769,   257,   771,
     338,   339,   340,   773,   819,   820,   341,   775,   259,   261,
     342,   777,   779,   783,   343,   263,   785,   793,   795,   344,
     797,   345,   346,   265,   799,  1228,  1230,  1258,   472,   347,
     348,   267,   472,   349,   350,  1352,  1362,  1365,  1342,   269,
    1343,   359,   271,   273,   275,  1139,  1140,  1373,  1375,   545,
    1142,  1143,  1172,  1173,  1174,  1175,  1540,  1139,  1140,  1141,
    1383,   277,  1142,  1143,   279,   281,  1385,  1387,   283,  1395,
     285,   287,   289,  1398,  1400,  1402,  1404,  1405,  1406,  1407,
    1366,   360,   361,  1139,  1140,  1141,   895,   895,  1142,  1143,
     362,  1409,  1411,  1413,  1415,  1417,  1419,  1421,  1344,  1346,
    1345,  1347,   291,   293,  1488,   363,  1489,   295,   364,   297,
     352,   354,   365,  1122,   366,  1127,   356,  1132,  1558,  1137,
    1559,   895,   895,   895,   895,   358,   406,   367,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1310,   840,   368,
     369,   800,   370,   913,  1310,   371,   915,  1311,   372,   917,
     952,   953,   954,   955,  1311,   957,  1310,   959,  1330,   961,
    1331,   373,   374,   375,   376,  1339,  1311,  1340,   377,  1483,
     378,   379,   380,   381,   472,  1082,   382,  1348,   383,  1349,
    1560,   384,   895,  1562,   385,   386,   507,   508,   509,   510,
     511,   387,   546,  1596,   388,   389,   390,   512,   391,   392,
     513,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,
    1192,  1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,
    1202,  1203,  1204,  1205,   393,   507,   508,   509,   510,   511,
     394,   395,   396,   397,   895,   398,   512,   895,   895,   513,
    1201,  1202,  1203,  1204,  1205,  1267,   399,   400,   895,   895,
     895,   401,   895,   895,   895,  1183,  1184,  1185,  1186,  1187,
    1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,  1196,  1197,
    1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,  1187,  1188,
    1189,  1190,  1191,  1192,  1193,  1194,  1195,  1196,  1197,  1198,
    1199,  1200,  1201,  1202,  1203,  1204,  1205,  1377,  1183,  1184,
    1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,
    1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,
    1205,  1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,  1196,
    1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,   402,
    1429,   403,   404,   507,   508,   509,   510,   511,  1394,   407,
     408,   409,   410,   411,   412,    -2,   442,   513,  1552,   413,
     414,   415,   416,   547,  1557,   417,   418,   419,   420,   -11,
     -11,   -13,     2,     3,   -16,   -18,   -20,  1190,  1191,  1192,
    1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,
    1203,  1204,  1205,     4,   421,   422,     5,     6,     7,     8,
       9,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,
     423,   424,    10,  1183,  1184,  1185,  1186,  1187,  1188,  1189,
    1190,  1191,  1192,  1193,  1194,  1195,  1196,  1197,  1198,  1199,
    1200,  1201,  1202,  1203,  1204,  1205,   548,   549,   550,   551,
    1552,   552,   553,   610,   806,   824,   554,   555,  1483,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   556,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   557,   558,   559,   560,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   561,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   562,   563,   564,   565,   566,   664,
     665,   666,   667,   765,   786,   787,   180,   181,   182,   801,
     822,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,
    1192,  1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,
    1202,  1203,  1204,  1205,   802,   825,   826,   830,   831,   833,
     836,   838,   919,   183,   918,   920,   924,  1010,   925,   927,
     939,   184,  1086,  1536,   926,  1102,  1027,  1066,   185,  -557,
    -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,
    -557,   940,  1036,  1037,  1038,  1039,  1040,  1049,  -557,  -557,
    -557,  -557,  -557,  -557,  -557,  -557,  1088,  -557,  -557,  -557,
    -557,  -557,  -557,  -557,  -557,  -557,  -557,  1050,  -557,  1051,
    1052,  1091,  -557,  1104,  -557,  -557,  -557,  -557,  -557,  -557,
    -557,  -557,  1093,  1095,  -557,  -557,  -557,  1097,  1098,  1105,
    -557,  -557,  -557,  -557,  -557,  -557,  1066,  1107,  -525,  -525,
    -525,  -525,  -525,  -525,  -525,  -525,  -525,  -525,  -525,  -525,
    1108,  1109,  1110,  1157,  1218,  1158,  1231,  -525,  -525,  -525,
    -525,  -525,  -525,  -525,  -525,  1235,  -525,  -525,  -525,  -525,
    -525,  -525,  -525,  -525,  -525,  -525,  1244,  -525,  1245,  1246,
    1263,  -525,  1264,  -525,  -525,  -525,  -525,  -525,  -525,  -525,
    -525,  1265,  1266,  -525,  -525,  -525,  1279,  1280,  1281,  -525,
    -525,  -525,  -525,  -525,  -525,  1148,  1289,  -529,  -529,  -529,
    -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  1290,
    1291,  1292,  1293,  1294,  1297,  1299,  -529,  -529,  -529,  -529,
    -529,  -529,  -529,  -529,  1369,  -529,  -529,  -529,  -529,  -529,
    -529,  -529,  -529,  -529,  -529,  1303,  -529,  1314,  1323,  1332,
    -529,  1341,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,
    1376,  -628,  -529,  -529,  -529,  -629,  -640,  -641,  -529,  -529,
    -529,  -529,  -529,  -529,  1148,  1378,  -546,  -546,  -546,  -546,
    -546,  -546,  -546,  -546,  -546,  -546,  -546,  -546,  1379,  1422,
    1396,  1424,  1423,  1426,  1458,  -546,  -546,  -546,  -546,  -546,
    -546,  -546,  -546,  1425,  -546,  -546,  -546,  -546,  -546,  -546,
    -546,  -546,  -546,  -546,  1427,  -546,  1430,  1431,  1432,  -546,
    1433,  -546,  -546,  -546,  -546,  -546,  -546,  -546,  -546,  1434,
    1435,  -546,  -546,  -546,  1436,  -557,  1437,  -546,  -546,  -546,
    -546,  -546,  -546,  1438,  1439,  1440,  1441,  1442,  1443,  1444,
    1445,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,
    -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,
    -557,  -557,  -557,  -557,  1446,  1447,  1448,  1449,  1450,  1451,
    -557,  1452,  1453,  1454,  -557,  1455,  1456,  1459,  -557,  -557,
    1460,  -557,  -557,  -557,  -855,  -557,  1461,  1462,  1463,  1464,
    -557,  1465,  1466,  1473,  -525,  1474,  1475,  1082,  1476,  1477,
    1478,  1479,  1480,  1481,  1482,  1491,  1496,  1497,  1498,  1500,
    -525,  -525,  -525,  -525,  -525,  -525,  -525,  -525,  -525,  -525,
    -525,  -525,  -525,  -525,  -525,  -525,  -525,  -525,  -525,  -525,
    -525,  -525,  -525,  1487,  1501,  1502,  1506,  1507,  1512,  1515,
    1516,  1533,  1535,  -525,  1517,  1520,  1521,  -525,  -525,  1522,
    -525,  -525,  -525,  -855,  -525,  1525,  1526,  1527,  1530,  -525,
    1531,  1532,  1534,  -529,  1537,  1539,  1541,  1542,  1553,  1569,
    1604,   443,  1548,  1106,   932,  1364,  1570,  1571,  1572,  -529,
    -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,
    -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,
    -529,  -529,  1573,  1574,  1575,  1576,  1577,  1578,  1579,  1580,
    1581,  1582,  -529,  1583,  1584,  1585,  -529,  -529,  1586,  -529,
    -529,  -529,  1587,  -529,  1588,  1589,  1590,  1591,  -529,  1592,
    1593,  1594,  -546,  1601,  1602,  1603,  1610,  1613,  1614,  1605,
    1608,  1615,   837,  1295,  1616,  1617,   829,  1367,  -546,  -546,
    -546,  -546,  -546,  -546,  -546,  -546,  -546,  -546,  -546,  -546,
    -546,  -546,  -546,  -546,  -546,  -546,  -546,  -546,  -546,  -546,
    -546,   657,  1620,  1621,   659,   839,  1555,  1597,  1368,  1607,
    1486,  -546,     0,  1612,     0,  -546,  -546,     1,  -546,  -546,
    -546,     0,  -546,     0,     0,     0,     0,  -546,     0,     0,
     -11,   -11,   -13,     2,     3,   -16,   -18,   -20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     0,     0,     5,     6,     7,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,
    1192,  1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,
    1202,  1203,  1204,  1205,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,  1538,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,     0,     0,     0,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,     0,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   180,   181,   182,
       0,     0,     0,     0,     0,  1183,  1184,  1185,  1186,  1187,
    1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,  1196,  1197,
    1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,     0,     0,
       0,     0,     0,  1388,   183,   841,   842,   843,   844,   845,
       0,     0,   184,     0,   850,   851,   852,  1611,     0,   185,
       0,     0,     0,     0,   853,   854,   855,   856,   857,   858,
     859,   860,     0,   861,   862,   863,   864,   865,   866,   867,
     868,   869,   870,     0,   871,     0,     0,     0,     0,     0,
     873,   874,   875,   876,   877,   878,   879,     0,     0,     0,
       0,   882,   883,     0,     0,     0,   884,   885,   886,   887,
     888,   889,   951,   952,   953,   954,   955,   956,   957,   958,
     959,   960,   961,   962,   963,   964,   965,   966,  1389,   968,
    1622,     0,   841,   842,   843,   844,   845,   846,   847,   848,
     849,   850,   851,   852,     0,     0,     0,     0,     0,     0,
       0,   853,   854,   855,   856,   857,   858,   859,   860,     0,
     861,   862,   863,   864,   865,   866,   867,   868,   869,   870,
       0,   871,     0,     0,     0,   872,     0,   873,   874,   875,
     876,   877,   878,   879,   880,  -589,  -589,   881,   882,   883,
       0,     0,     0,   884,   885,   886,   887,   888,   889,  1070,
       0,   841,   842,   843,   844,   845,   846,   847,   848,   849,
     850,   851,   852,     0,     0,     0,     0,     0,     0,     0,
     853,   854,   855,   856,   857,   858,   859,   860,     0,   861,
     862,   863,   864,   865,   866,   867,   868,   869,   870,     0,
     871,     0,     0,     0,   872,     0,   873,   874,   875,   876,
     877,   878,   879,   880,  -591,  -591,   881,   882,   883,     0,
       0,     0,   884,   885,   886,   887,   888,   889,  1070,     0,
     841,   842,   843,   844,   845,   846,   847,   848,   849,   850,
     851,   852,     0,     0,     0,     0,     0,     0,     0,   853,
     854,   855,   856,   857,   858,   859,   860,     0,   861,   862,
     863,   864,   865,   866,   867,   868,   869,   870,     0,   871,
       0,   890,   969,   872,     0,   873,   874,   875,   876,   877,
     878,   879,   880,  -593,  -593,   881,   882,   883,     0,     0,
       0,   884,   885,   886,   887,   888,   889,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   970,     0,     0,     0,
     971,     0,   972,   973,   974,   975,     0,   976,   977,  1390,
    1391,     0,   978,   511,   892,   893,     0,     0,     0,     0,
    1041,   980,     0,   513,     0,     0,     0,     0,  1070,     0,
     841,   842,   843,   844,   845,   846,   847,   848,   849,   850,
     851,   852,     0,     0,     0,     0,     0,     0,   890,   853,
     854,   855,   856,   857,   858,   859,   860,     0,   861,   862,
     863,   864,   865,   866,   867,   868,   869,   870,     0,   871,
       0,     0,     0,   872,     0,   873,   874,   875,   876,   877,
     878,   879,   880,  -587,  -587,   881,   882,   883,     0,     0,
       0,   884,   885,   886,   887,   888,   889,   891,     0,     0,
       0,   892,   893,     0,     0,   894,     0,     0,     0,  -589,
       0,     0,     0,     0,     0,     0,     0,   890,  1184,  1185,
    1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,
    1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,
    1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,
    1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,
    1205,     0,     0,     0,     0,     0,   891,     0,     0,     0,
     892,   893,     0,     0,   894,     0,     0,     0,  -591,     0,
       0,     0,     0,     0,     0,     0,   890,  1186,  1187,  1188,
    1189,  1190,  1191,  1192,  1193,  1194,  1195,  1196,  1197,  1198,
    1199,  1200,  1201,  1202,  1203,  1204,  1205,  1189,  1190,  1191,
    1192,  1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,
    1202,  1203,  1204,  1205,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   891,     0,     0,     0,   892,
     893,     0,     0,   894,     0,     0,     0,  -593,     0,     0,
    1070,     0,   841,   842,   843,   844,   845,   846,   847,   848,
     849,   850,   851,   852,     0,     0,     0,     0,     0,     0,
       0,   853,   854,   855,   856,   857,   858,   859,   860,     0,
     861,   862,   863,   864,   865,   866,   867,   868,   869,   870,
       0,   871,     0,     0,     0,   872,   890,   873,   874,   875,
     876,   877,   878,   879,   880,  -594,  -594,   881,   882,   883,
       0,     0,     0,   884,   885,   886,   887,   888,   889,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   891,     0,     0,     0,   892,
     893,     0,     0,   894,     0,     0,  1070,  -587,   841,   842,
     843,   844,   845,   846,   847,   848,   849,   850,   851,   852,
       0,     0,     0,     0,     0,     0,     0,   853,   854,   855,
     856,   857,   858,   859,   860,     0,   861,   862,   863,   864,
     865,   866,   867,   868,   869,   870,     0,   871,     0,     0,
       0,   872,     0,   873,   874,   875,   876,   877,   878,   879,
     880,  -588,  -588,   881,   882,   883,     0,     0,     0,   884,
     885,   886,   887,   888,   889,  1070,     0,   841,   842,   843,
     844,   845,   846,   847,   848,   849,   850,   851,   852,     0,
       0,     0,     0,     0,     0,     0,   853,   854,   855,   856,
     857,   858,   859,   860,     0,   861,   862,   863,   864,   865,
     866,   867,   868,   869,   870,     0,   871,     0,     0,     0,
     872,     0,   873,   874,   875,   876,   877,   878,   879,   880,
       0,     0,   881,   882,   883,     0,     0,     0,   884,   885,
     886,   887,   888,   889,     0,     0,     0,     0,  1070,     0,
     841,   842,   843,   844,   845,   846,   847,   848,   849,   850,
     851,   852,     0,     0,     0,     0,     0,     0,   890,   853,
     854,   855,   856,   857,   858,   859,   860,     0,   861,   862,
     863,   864,   865,   866,   867,   868,   869,   870,     0,   871,
       0,     0,     0,   872,     0,   873,   874,   875,   876,   877,
     878,   879,   880,     0,     0,   881,   882,   883,     0,     0,
       0,   884,   885,   886,   887,   888,   889,   891,     0,     0,
       0,   892,   893,     0,     0,   894,     0,     0,  1070,  -594,
     841,   842,   843,   844,   845,   846,   847,   848,   849,   850,
     851,   852,     0,     0,     0,     0,     0,     0,     0,   853,
     854,   855,   856,   857,   858,   859,   860,     0,   861,   862,
     863,   864,   865,   866,   867,   868,   869,   870,     0,   871,
       0,     0,     0,   872,   890,   873,   874,   875,   876,   877,
     878,   879,   880,     0,     0,   881,   882,   883,     0,     0,
       0,   884,   885,   886,   887,   888,   889,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   891,     0,     0,     0,   892,   893,     0,
       0,   894,     0,     0,     0,  -588,     0,     0,     0,     0,
       0,     0,     0,   890,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   891,     0,     0,     0,   892,   893,     0,     0,
     894,     0,     0,     0,  1071,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   890,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   891,     0,     0,     0,   892,
     893,     0,     0,   894,     0,     0,  1070,  1092,   841,   842,
     843,   844,   845,   846,   847,   848,   849,   850,   851,   852,
       0,     0,     0,     0,     0,     0,   890,   853,   854,   855,
     856,   857,   858,   859,   860,     0,   861,   862,   863,   864,
     865,   866,   867,   868,   869,   870,     0,   871,     0,     0,
       0,   872,     0,   873,   874,   875,   876,   877,   878,   879,
     880,     0,     0,   881,   882,   883,     0,     0,     0,   884,
     885,   886,   887,   888,   889,   891,     0,     0,     0,   892,
     893,     0,     0,   894,     0,     0,  1070,  1094,   841,   842,
     843,   844,   845,   846,   847,   848,   849,   850,   851,   852,
       0,     0,     0,     0,     0,     0,     0,   853,   854,   855,
     856,   857,   858,   859,   860,     0,   861,   862,   863,   864,
     865,   866,   867,   868,   869,   870,     0,   871,     0,     0,
       0,   872,     0,   873,   874,   875,   876,   877,   878,   879,
     880,     0,     0,   881,   882,   883,     0,     0,     0,   884,
     885,   886,   887,   888,   889,  1070,     0,   841,   842,   843,
     844,   845,   846,   847,   848,   849,   850,   851,   852,     0,
       0,     0,     0,     0,     0,     0,   853,   854,   855,   856,
     857,   858,   859,   860,     0,   861,   862,   863,   864,   865,
     866,   867,   868,   869,   870,     0,   871,     0,     0,     0,
     872,     0,   873,   874,   875,   876,   877,   878,   879,   880,
       0,     0,   881,   882,   883,     0,     0,     0,   884,   885,
     886,   887,   888,   889,     0,     0,     0,     0,  1070,     0,
     841,   842,   843,   844,   845,   846,   847,   848,   849,   850,
     851,   852,     0,     0,     0,     0,     0,     0,     0,   853,
     854,   855,   856,   857,   858,   859,   860,     0,   861,   862,
     863,   864,   865,   866,   867,   868,   869,   870,     0,   871,
       0,     0,     0,   872,   890,   873,   874,   875,   876,   877,
     878,   879,   880,     0,     0,   881,   882,   883,     0,     0,
       0,   884,   885,   886,   887,   888,   889,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   891,     0,     0,     0,   892,   893,     0,
       0,   894,     0,     0,  1070,  1096,   841,   842,   843,   844,
     845,   846,   847,   848,   849,   850,   851,   852,     0,     0,
       0,     0,     0,     0,   890,   853,   854,   855,   856,   857,
     858,   859,   860,     0,   861,   862,   863,   864,   865,   866,
     867,   868,   869,   870,     0,   871,     0,     0,     0,   872,
       0,   873,   874,   875,   876,   877,   878,   879,   880,     0,
       0,   881,   882,   883,     0,     0,     0,   884,   885,   886,
     887,   888,   889,   891,     0,     0,     0,   892,   893,     0,
       0,   894,     0,     0,     0,  1103,     0,     0,     0,     0,
       0,     0,     0,   890,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   891,     0,     0,     0,   892,   893,     0,     0,
     894,     0,     0,     0,  1380,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   890,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   891,     0,     0,     0,   892,
     893,     0,     0,   894,     0,     0,  1070,  1499,   841,   842,
     843,   844,   845,   846,   847,   848,   849,   850,   851,   852,
       0,     0,     0,     0,     0,     0,     0,   853,   854,   855,
     856,   857,   858,   859,   860,     0,   861,   862,   863,   864,
     865,   866,   867,   868,   869,   870,     0,   871,     0,     0,
       0,   872,   890,   873,   874,   875,   876,   877,   878,   879,
     880,     0,     0,   881,   882,   883,     0,     0,     0,   884,
     885,   886,   887,   888,   889,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   891,     0,     0,     0,   892,   893,     0,     0,   894,
       0,     0,  1070,  1503,   841,   842,   843,   844,   845,   846,
     847,   848,   849,   850,   851,   852,     0,     0,     0,     0,
       0,     0,     0,   853,   854,   855,   856,   857,   858,   859,
     860,     0,   861,   862,   863,   864,   865,   866,   867,   868,
     869,   870,     0,   871,     0,     0,     0,   872,     0,   873,
     874,   875,   876,   877,   878,   879,   880,     0,     0,   881,
     882,   883,     0,     0,     0,   884,   885,   886,   887,   888,
     889,  1070,     0,   841,   842,   843,   844,   845,   846,   847,
     848,   849,   850,   851,   852,     0,     0,     0,     0,     0,
       0,     0,   853,   854,   855,   856,   857,   858,   859,   860,
       0,   861,   862,   863,   864,   865,   866,   867,   868,   869,
     870,     0,   871,     0,     0,     0,   872,     0,   873,   874,
     875,   876,   877,   878,   879,   880,     0,     0,   881,   882,
     883,     0,     0,     0,   884,   885,   886,   887,   888,   889,
       0,     0,     0,     0,  1070,     0,   841,   842,   843,   844,
     845,   846,   847,   848,   849,   850,   851,   852,     0,     0,
       0,     0,     0,     0,   890,   853,   854,   855,   856,   857,
     858,   859,   860,     0,   861,   862,   863,   864,   865,   866,
     867,   868,   869,   870,     0,   871,     0,     0,     0,   872,
       0,   873,   874,   875,   876,   877,   878,   879,   880,     0,
       0,   881,   882,   883,     0,     0,     0,   884,   885,   886,
     887,   888,   889,   891,     0,     0,     0,   892,   893,     0,
       0,   894,     0,     0,  1070,  1543,   841,   842,   843,   844,
     845,   846,   847,   848,   849,   850,   851,   852,     0,     0,
       0,     0,     0,     0,     0,   853,   854,   855,   856,   857,
     858,   859,   860,     0,   861,   862,   863,   864,   865,   866,
     867,   868,   869,   870,     0,   871,     0,     0,     0,   872,
     890,   873,   874,   875,   876,   877,   878,   879,   880,     0,
       0,   881,   882,   883,     0,     0,     0,   884,   885,   886,
     887,   888,   889,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   891,
       0,     0,     0,   892,   893,     0,     0,   894,     0,     0,
       0,  1563,     0,     0,     0,     0,     0,     0,     0,   890,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   891,     0,
       0,     0,   892,   893,     0,     0,   894,     0,     0,     0,
    1564,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   890,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   891,     0,     0,     0,   892,   893,     0,     0,   894,
       0,     0,     0,  1565,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   890,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   891,     0,     0,     0,   892,   893,     0,     0,   894,
       0,     0,  1353,  1566,   841,   842,   843,   844,   845,     0,
       0,     0,     0,   850,   851,   852,     0,     0,     0,     0,
       0,     0,     0,   853,   854,   855,   856,   857,   858,   859,
     860,     0,   861,   862,   863,   864,   865,   866,   867,   868,
     869,   870,     0,   871,     0,     0,     0,     0,     0,   873,
     874,   875,   876,   877,   878,   879,     0,     0,     0,     0,
     882,   883,     0,     0,     0,   884,   885,   886,   887,   888,
     889,   951,   952,   953,   954,   955,   956,   957,   958,   959,
     960,   961,   962,   963,   964,   965,   966,   967,   968,  1354,
    1355,  1356,  1357,  1358,  1359,  1363,     0,   841,   842,   843,
     844,   845,     0,     0,     0,     0,   850,   851,   852,     0,
       0,     0,     0,     0,     0,     0,   853,   854,   855,   856,
     857,   858,   859,   860,     0,   861,   862,   863,   864,   865,
     866,   867,   868,   869,   870,     0,   871,     0,     0,     0,
       0,     0,   873,   874,   875,   876,   877,   878,   879,     0,
       0,     0,     0,   882,   883,     0,     0,     0,   884,   885,
     886,   887,   888,   889,   951,   952,   953,   954,   955,   956,
     957,   958,   959,   960,   961,   962,   963,   964,   965,   966,
     967,   968,  1354,  1355,  1356,  1357,  1358,  1359,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1159,
       0,   841,   842,   843,   844,   845,     0,     0,     0,     0,
     850,   851,   852,     0,     0,     0,     0,     0,     0,     0,
     853,   854,   855,   856,   857,   858,   859,   860,     0,   861,
     862,   863,   864,   865,   866,   867,   868,   869,   870,     0,
     871,     0,     0,     0,     0,     0,   873,   874,   875,   876,
     877,   878,   879,     0,     0,     0,     0,   882,   883,     0,
     890,   969,   884,   885,   886,   887,   888,   889,   951,   952,
     953,   954,   955,   956,   957,   958,   959,   960,   961,   962,
     963,   964,   965,   966,   967,   968,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   970,  1360,     0,     0,   971,
       0,   972,   973,   974,   975,     0,   976,   977,   476,   891,
       0,   978,     0,   892,   893,     0,     0,     0,     0,  1041,
     980,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   890,   969,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   970,  1360,
       0,     0,   971,     0,   972,   973,   974,   975,     0,   976,
     977,   476,   891,     0,   978,     0,   892,   893,     0,     0,
       0,     0,  1041,   980,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   890,   969,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   970,     0,     0,     0,   971,     0,   972,   973,
     974,   975,     0,   976,   977,   476,   891,     0,   978,     0,
     892,   893,     0,     0,     0,  1160,  1041,   980,  1159,     0,
     841,   842,   843,   844,   845,     0,     0,     0,     0,   850,
     851,   852,     0,     0,     0,     0,     0,     0,     0,   853,
     854,   855,   856,   857,   858,   859,   860,     0,   861,   862,
     863,   864,   865,   866,   867,   868,   869,   870,     0,   871,
       0,     0,     0,     0,     0,   873,   874,   875,   876,   877,
     878,   879,     0,     0,     0,     0,   882,   883,     0,     0,
       0,   884,   885,   886,   887,   888,   889,   951,   952,   953,
     954,   955,   956,   957,   958,   959,   960,   961,   962,   963,
     964,   965,   966,   967,   968,  1159,     0,   841,   842,   843,
     844,   845,     0,     0,     0,     0,   850,   851,   852,     0,
       0,     0,     0,     0,     0,     0,   853,   854,   855,   856,
     857,   858,   859,   860,     0,   861,   862,   863,   864,   865,
     866,   867,   868,   869,   870,     0,   871,     0,     0,     0,
       0,     0,   873,   874,   875,   876,   877,   878,   879,     0,
       0,     0,     0,   882,   883,     0,     0,     0,   884,   885,
     886,   887,   888,   889,   951,   952,   953,   954,   955,   956,
     957,   958,   959,   960,   961,   962,   963,   964,   965,   966,
     967,   968,  1549,     0,   841,   842,   843,   844,   845,     0,
       0,     0,     0,   850,   851,   852,     0,     0,     0,     0,
       0,     0,     0,   853,   854,   855,   856,   857,   858,   859,
     860,     0,   861,   862,   863,   864,   865,   866,   867,   868,
     869,   870,     0,   871,     0,     0,     0,     0,     0,   873,
     874,   875,   876,   877,   878,   879,     0,     0,     0,     0,
     882,   883,     0,     0,     0,   884,   885,   886,   887,   888,
     889,   951,   952,   953,   954,   955,   956,   957,   958,   959,
     960,   961,   962,   963,   964,   965,   966,   967,   968,     0,
       0,     0,     0,     0,     0,     0,   890,   969,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   970,     0,     0,     0,   971,     0,   972,   973,   974,
     975,     0,   976,   977,   476,   891,     0,   978,     0,   892,
     893,     0,     0,     0,  1208,  1041,   980,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   890,   969,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   970,     0,
       0,     0,   971,     0,   972,   973,   974,   975,     0,   976,
     977,   476,   891,     0,   978,     0,   892,   893,     0,     0,
       0,  1209,  1041,   980,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     890,   969,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   970,     0,  1550,     0,   971,
       0,   972,   973,   974,   975,     0,   976,   977,   476,   891,
       0,   978,     0,   892,   893,     0,     0,     0,     0,  1041,
     980,  1053,     0,   841,   842,   843,   844,   845,     0,     0,
       0,     0,   850,   851,   852,     0,     0,     0,     0,     0,
       0,     0,   853,   854,   855,   856,   857,   858,   859,   860,
       0,   861,   862,   863,   864,   865,   866,   867,   868,   869,
     870,     0,   871,     0,     0,     0,     0,     0,   873,   874,
     875,   876,   877,   878,   879,     0,     0,     0,     0,   882,
     883,     0,     0,     0,   884,   885,   886,   887,   888,   889,
     951,   952,   953,   954,   955,   956,   957,   958,   959,   960,
     961,   962,   963,   964,   965,   966,   967,   968,  1151,     0,
     841,   842,   843,   844,   845,     0,     0,     0,     0,   850,
     851,   852,     0,     0,     0,     0,     0,     0,     0,   853,
     854,   855,   856,   857,   858,   859,   860,     0,   861,   862,
     863,   864,   865,   866,   867,   868,   869,   870,     0,   871,
       0,     0,     0,     0,     0,   873,   874,   875,   876,   877,
     878,   879,     0,     0,     0,     0,   882,   883,     0,     0,
       0,   884,   885,   886,   887,   888,   889,   951,   952,   953,
     954,   955,   956,   957,   958,   959,   960,   961,   962,   963,
     964,   965,   966,   967,   968,  1153,     0,   841,   842,   843,
     844,   845,     0,     0,     0,     0,   850,   851,   852,     0,
       0,     0,     0,     0,     0,     0,   853,   854,   855,   856,
     857,   858,   859,   860,     0,   861,   862,   863,   864,   865,
     866,   867,   868,   869,   870,     0,   871,     0,     0,     0,
       0,     0,   873,   874,   875,   876,   877,   878,   879,     0,
       0,     0,     0,   882,   883,     0,     0,     0,   884,   885,
     886,   887,   888,   889,   951,   952,   953,   954,   955,   956,
     957,   958,   959,   960,   961,   962,   963,   964,   965,   966,
     967,   968,     0,     0,     0,     0,     0,     0,     0,   890,
     969,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   970,     0,     0,     0,   971,     0,
     972,   973,   974,   975,     0,   976,   977,   476,   891,     0,
     978,     0,   892,   893,     0,     0,     0,     0,  1041,   980,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   890,   969,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   970,     0,     0,     0,   971,     0,   972,   973,   974,
     975,     0,   976,   977,   476,   891,     0,   978,     0,   892,
     893,     0,     0,     0,     0,  1041,   980,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   890,   969,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   970,     0,
       0,     0,   971,     0,   972,   973,   974,   975,     0,   976,
     977,   476,   891,     0,   978,     0,   892,   893,     0,     0,
       0,     0,  1041,   980,  1155,     0,   841,   842,   843,   844,
     845,     0,     0,     0,     0,   850,   851,   852,     0,     0,
       0,     0,     0,     0,     0,   853,   854,   855,   856,   857,
     858,   859,   860,     0,   861,   862,   863,   864,   865,   866,
     867,   868,   869,   870,     0,   871,     0,     0,     0,     0,
       0,   873,   874,   875,   876,   877,   878,   879,     0,     0,
       0,     0,   882,   883,     0,     0,     0,   884,   885,   886,
     887,   888,   889,   951,   952,   953,   954,   955,   956,   957,
     958,   959,   960,   961,   962,   963,   964,   965,   966,   967,
     968,  1181,     0,   841,   842,   843,   844,   845,     0,     0,
       0,     0,   850,   851,   852,     0,     0,     0,     0,     0,
       0,     0,   853,   854,   855,   856,   857,   858,   859,   860,
       0,   861,   862,   863,   864,   865,   866,   867,   868,   869,
     870,     0,   871,     0,     0,     0,     0,     0,   873,   874,
     875,   876,   877,   878,   879,     0,     0,     0,     0,   882,
     883,     0,     0,     0,   884,   885,   886,   887,   888,   889,
     951,   952,   953,   954,   955,   956,   957,   958,   959,   960,
     961,   962,   963,   964,   965,   966,   967,   968,  1215,     0,
     841,   842,   843,   844,   845,     0,     0,     0,     0,   850,
     851,   852,     0,     0,     0,     0,     0,     0,     0,   853,
     854,   855,   856,   857,   858,   859,   860,     0,   861,   862,
     863,   864,   865,   866,   867,   868,   869,   870,     0,   871,
       0,     0,     0,     0,     0,   873,   874,   875,   876,   877,
     878,   879,     0,     0,     0,     0,   882,   883,     0,     0,
       0,   884,   885,   886,   887,   888,   889,   951,   952,   953,
     954,   955,   956,   957,   958,   959,   960,   961,   962,   963,
     964,   965,   966,   967,   968,     0,     0,     0,     0,     0,
       0,     0,   890,   969,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   970,     0,     0,
       0,   971,     0,   972,   973,   974,   975,     0,   976,   977,
     476,   891,     0,   978,     0,   892,   893,     0,     0,     0,
       0,  1041,   980,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   890,
     969,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   970,     0,     0,     0,   971,     0,
     972,   973,   974,   975,     0,   976,   977,   476,   891,     0,
     978,     0,   892,   893,     0,     0,     0,     0,  1041,   980,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   890,   969,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   970,     0,     0,     0,   971,     0,   972,   973,   974,
     975,     0,   976,   977,   476,  1216,     0,   978,     0,   892,
     893,     0,     0,     0,     0,  1041,   980,  1159,     0,   841,
     842,   843,   844,   845,     0,     0,     0,     0,   850,   851,
     852,     0,     0,     0,     0,     0,     0,     0,   853,   854,
     855,   856,   857,   858,   859,   860,     0,   861,   862,   863,
     864,   865,   866,   867,   868,   869,   870,     0,   871,     0,
       0,     0,     0,     0,   873,   874,   875,   876,   877,   878,
     879,     0,     0,     0,     0,   882,   883,     0,     0,     0,
     884,   885,   886,   887,   888,   889,   951,   952,   953,   954,
     955,   956,   957,   958,   959,   960,   961,   962,   963,   964,
     965,   966,   967,   968,  1350,     0,   841,   842,   843,   844,
     845,     0,     0,     0,     0,   850,   851,   852,     0,     0,
       0,     0,     0,     0,     0,   853,   854,   855,   856,   857,
     858,   859,   860,     0,   861,   862,   863,   864,   865,   866,
     867,   868,   869,   870,     0,   871,     0,     0,     0,     0,
       0,   873,   874,   875,   876,   877,   878,   879,     0,     0,
       0,     0,   882,   883,     0,     0,     0,   884,   885,   886,
     887,   888,   889,   951,   952,   953,   954,   955,   956,   957,
     958,   959,   960,   961,   962,   963,   964,   965,   966,   967,
     968,  1372,     0,   841,   842,   843,   844,   845,     0,     0,
       0,     0,   850,   851,   852,     0,     0,     0,     0,     0,
       0,     0,   853,   854,   855,   856,   857,   858,   859,   860,
       0,   861,   862,   863,   864,   865,   866,   867,   868,   869,
     870,     0,   871,     0,     0,     0,     0,     0,   873,   874,
     875,   876,   877,   878,   879,     0,     0,     0,     0,   882,
     883,     0,     0,     0,   884,   885,   886,   887,   888,   889,
     951,   952,   953,   954,   955,   956,   957,   958,   959,   960,
     961,   962,   963,   964,   965,   966,   967,   968,     0,     0,
       0,     0,     0,     0,     0,   890,   969,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     970,     0,     0,     0,   971,     0,   972,   973,   974,   975,
       0,   976,   977,   476,   891,     0,   978,     0,   892,   893,
       0,     0,     0,     0,  1041,   980,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   890,   969,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   970,     0,     0,
       0,   971,     0,   972,   973,   974,   975,     0,   976,   977,
     476,  1351,     0,   978,     0,   892,   893,     0,     0,     0,
       0,  1041,   980,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   890,
     969,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   970,     0,     0,     0,   971,     0,
     972,   973,   974,   975,     0,   976,   977,   476,   891,     0,
     978,     0,   892,   893,     0,     0,     0,     0,  1041,   980,
    1374,     0,   841,   842,   843,   844,   845,     0,     0,     0,
       0,   850,   851,   852,     0,     0,     0,     0,     0,     0,
       0,   853,   854,   855,   856,   857,   858,   859,   860,     0,
     861,   862,   863,   864,   865,   866,   867,   868,   869,   870,
       0,   871,     0,     0,     0,     0,     0,   873,   874,   875,
     876,   877,   878,   879,     0,     0,     0,     0,   882,   883,
       0,     0,     0,   884,   885,   886,   887,   888,   889,   951,
     952,   953,   954,   955,   956,   957,   958,   959,   960,   961,
     962,   963,   964,   965,   966,   967,   968,  1381,     0,   841,
     842,   843,   844,   845,     0,     0,     0,     0,   850,   851,
     852,     0,     0,     0,     0,     0,     0,     0,   853,   854,
     855,   856,   857,   858,   859,   860,     0,   861,   862,   863,
     864,   865,   866,   867,   868,   869,   870,     0,   871,     0,
       0,     0,     0,     0,   873,   874,   875,   876,   877,   878,
     879,     0,     0,     0,     0,   882,   883,     0,     0,     0,
     884,   885,   886,   887,   888,   889,   951,   952,   953,   954,
     955,   956,   957,   958,   959,   960,   961,   962,   963,   964,
     965,   966,  1382,   968,  1384,     0,   841,   842,   843,   844,
     845,     0,     0,     0,     0,   850,   851,   852,     0,     0,
       0,     0,     0,     0,     0,   853,   854,   855,   856,   857,
     858,   859,   860,     0,   861,   862,   863,   864,   865,   866,
     867,   868,   869,   870,     0,   871,     0,     0,     0,     0,
       0,   873,   874,   875,   876,   877,   878,   879,     0,     0,
       0,     0,   882,   883,     0,     0,     0,   884,   885,   886,
     887,   888,   889,   951,   952,   953,   954,   955,   956,   957,
     958,   959,   960,   961,   962,   963,   964,   965,   966,   967,
     968,     0,     0,     0,     0,     0,     0,     0,   890,   969,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   970,     0,     0,     0,   971,     0,   972,
     973,   974,   975,     0,   976,   977,   476,   891,     0,   978,
       0,   892,   893,     0,     0,     0,     0,  1041,   980,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   890,   969,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     970,     0,     0,     0,   971,     0,   972,   973,   974,   975,
       0,   976,   977,   476,   891,     0,   978,     0,   892,   893,
       0,     0,     0,     0,  1041,   980,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   890,   969,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   970,     0,     0,
       0,   971,     0,   972,   973,   974,   975,     0,   976,   977,
     476,   891,     0,   978,     0,   892,   893,     0,     0,     0,
       0,  1041,   980,  1386,     0,   841,   842,   843,   844,   845,
       0,     0,     0,     0,   850,   851,   852,     0,     0,     0,
       0,     0,     0,     0,   853,   854,   855,   856,   857,   858,
     859,   860,     0,   861,   862,   863,   864,   865,   866,   867,
     868,   869,   870,     0,   871,     0,     0,     0,     0,     0,
     873,   874,   875,   876,   877,   878,   879,     0,     0,     0,
       0,   882,   883,     0,     0,     0,   884,   885,   886,   887,
     888,   889,   951,   952,   953,   954,   955,   956,   957,   958,
     959,   960,   961,   962,   963,   964,   965,   966,   967,   968,
    1397,     0,   841,   842,   843,   844,   845,     0,     0,     0,
       0,   850,   851,   852,     0,     0,     0,     0,     0,     0,
       0,   853,   854,   855,   856,   857,   858,   859,   860,     0,
     861,   862,   863,   864,   865,   866,   867,   868,   869,   870,
       0,   871,     0,     0,     0,     0,     0,   873,   874,   875,
     876,   877,   878,   879,     0,     0,     0,     0,   882,   883,
       0,     0,     0,   884,   885,   886,   887,   888,   889,   951,
     952,   953,   954,   955,   956,   957,   958,   959,   960,   961,
     962,   963,   964,   965,   966,   967,   968,  1399,     0,   841,
     842,   843,   844,   845,     0,     0,     0,     0,   850,   851,
     852,     0,     0,     0,     0,     0,     0,     0,   853,   854,
     855,   856,   857,   858,   859,   860,     0,   861,   862,   863,
     864,   865,   866,   867,   868,   869,   870,     0,   871,     0,
       0,     0,     0,     0,   873,   874,   875,   876,   877,   878,
     879,     0,     0,     0,     0,   882,   883,     0,     0,     0,
     884,   885,   886,   887,   888,   889,   951,   952,   953,   954,
     955,   956,   957,   958,   959,   960,   961,   962,   963,   964,
     965,   966,   967,   968,     0,     0,     0,     0,     0,     0,
       0,   890,   969,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   970,     0,     0,     0,
     971,     0,   972,   973,   974,   975,     0,   976,   977,   476,
     891,     0,   978,     0,   892,   893,     0,     0,     0,     0,
    1041,   980,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   890,   969,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   970,     0,     0,     0,   971,     0,   972,
     973,   974,   975,     0,   976,   977,   476,   891,     0,   978,
       0,   892,   893,     0,     0,     0,     0,  1041,   980,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   890,   969,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     970,     0,     0,     0,   971,     0,   972,   973,   974,   975,
       0,   976,   977,   476,   891,     0,   978,     0,   892,   893,
       0,     0,     0,     0,  1041,   980,  1401,     0,   841,   842,
     843,   844,   845,     0,     0,     0,     0,   850,   851,   852,
       0,     0,     0,     0,     0,     0,     0,   853,   854,   855,
     856,   857,   858,   859,   860,     0,   861,   862,   863,   864,
     865,   866,   867,   868,   869,   870,     0,   871,     0,     0,
       0,     0,     0,   873,   874,   875,   876,   877,   878,   879,
       0,     0,     0,     0,   882,   883,     0,     0,     0,   884,
     885,   886,   887,   888,   889,   951,   952,   953,   954,   955,
     956,   957,   958,   959,   960,   961,   962,   963,   964,   965,
     966,   967,   968,  1403,     0,   841,   842,   843,   844,   845,
       0,     0,     0,     0,   850,   851,   852,     0,     0,     0,
       0,     0,     0,     0,   853,   854,   855,   856,   857,   858,
     859,   860,     0,   861,   862,   863,   864,   865,   866,   867,
     868,   869,   870,     0,   871,     0,     0,     0,     0,     0,
     873,   874,   875,   876,   877,   878,   879,     0,     0,     0,
       0,   882,   883,     0,     0,     0,   884,   885,   886,   887,
     888,   889,   951,   952,   953,   954,   955,   956,   957,   958,
     959,   960,   961,   962,   963,   964,   965,   966,   967,   968,
    1408,     0,   841,   842,   843,   844,   845,     0,     0,     0,
       0,   850,   851,   852,     0,     0,     0,     0,     0,     0,
       0,   853,   854,   855,   856,   857,   858,   859,   860,     0,
     861,   862,   863,   864,   865,   866,   867,   868,   869,   870,
       0,   871,     0,     0,     0,     0,     0,   873,   874,   875,
     876,   877,   878,   879,     0,     0,     0,     0,   882,   883,
       0,     0,     0,   884,   885,   886,   887,   888,   889,   951,
     952,   953,   954,   955,   956,   957,   958,   959,   960,   961,
     962,   963,   964,   965,   966,   967,   968,     0,     0,     0,
       0,     0,     0,     0,   890,   969,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   970,
       0,     0,     0,   971,     0,   972,   973,   974,   975,     0,
     976,   977,   476,   891,     0,   978,     0,   892,   893,     0,
       0,     0,     0,  1041,   980,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   890,   969,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   970,     0,     0,     0,
     971,     0,   972,   973,   974,   975,     0,   976,   977,   476,
     891,     0,   978,     0,   892,   893,     0,     0,     0,     0,
    1041,   980,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   890,   969,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   970,     0,     0,     0,   971,     0,   972,
     973,   974,   975,     0,   976,   977,   476,   891,     0,   978,
       0,   892,   893,     0,     0,     0,     0,  1041,   980,  1410,
       0,   841,   842,   843,   844,   845,     0,     0,     0,     0,
     850,   851,   852,     0,     0,     0,     0,     0,     0,     0,
     853,   854,   855,   856,   857,   858,   859,   860,     0,   861,
     862,   863,   864,   865,   866,   867,   868,   869,   870,     0,
     871,     0,     0,     0,     0,     0,   873,   874,   875,   876,
     877,   878,   879,     0,     0,     0,     0,   882,   883,     0,
       0,     0,   884,   885,   886,   887,   888,   889,   951,   952,
     953,   954,   955,   956,   957,   958,   959,   960,   961,   962,
     963,   964,   965,   966,   967,   968,  1412,     0,   841,   842,
     843,   844,   845,     0,     0,     0,     0,   850,   851,   852,
       0,     0,     0,     0,     0,     0,     0,   853,   854,   855,
     856,   857,   858,   859,   860,     0,   861,   862,   863,   864,
     865,   866,   867,   868,   869,   870,     0,   871,     0,     0,
       0,     0,     0,   873,   874,   875,   876,   877,   878,   879,
       0,     0,     0,     0,   882,   883,     0,     0,     0,   884,
     885,   886,   887,   888,   889,   951,   952,   953,   954,   955,
     956,   957,   958,   959,   960,   961,   962,   963,   964,   965,
     966,   967,   968,  1414,     0,   841,   842,   843,   844,   845,
       0,     0,     0,     0,   850,   851,   852,     0,     0,     0,
       0,     0,     0,     0,   853,   854,   855,   856,   857,   858,
     859,   860,     0,   861,   862,   863,   864,   865,   866,   867,
     868,   869,   870,     0,   871,     0,     0,     0,     0,     0,
     873,   874,   875,   876,   877,   878,   879,     0,     0,     0,
       0,   882,   883,     0,     0,     0,   884,   885,   886,   887,
     888,   889,   951,   952,   953,   954,   955,   956,   957,   958,
     959,   960,   961,   962,   963,   964,   965,   966,   967,   968,
       0,     0,     0,     0,     0,     0,     0,   890,   969,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   970,     0,     0,     0,   971,     0,   972,   973,
     974,   975,     0,   976,   977,   476,   891,     0,   978,     0,
     892,   893,     0,     0,     0,     0,  1041,   980,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   890,   969,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   970,
       0,     0,     0,   971,     0,   972,   973,   974,   975,     0,
     976,   977,   476,   891,     0,   978,     0,   892,   893,     0,
       0,     0,     0,  1041,   980,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   890,   969,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   970,     0,     0,     0,
     971,     0,   972,   973,   974,   975,     0,   976,   977,   476,
     891,     0,   978,     0,   892,   893,     0,     0,     0,     0,
    1041,   980,  1416,     0,   841,   842,   843,   844,   845,     0,
       0,     0,     0,   850,   851,   852,     0,     0,     0,     0,
       0,     0,     0,   853,   854,   855,   856,   857,   858,   859,
     860,     0,   861,   862,   863,   864,   865,   866,   867,   868,
     869,   870,     0,   871,     0,     0,     0,     0,     0,   873,
     874,   875,   876,   877,   878,   879,     0,     0,     0,     0,
     882,   883,     0,     0,     0,   884,   885,   886,   887,   888,
     889,   951,   952,   953,   954,   955,   956,   957,   958,   959,
     960,   961,   962,   963,   964,   965,   966,   967,   968,  1418,
       0,   841,   842,   843,   844,   845,     0,     0,     0,     0,
     850,   851,   852,     0,     0,     0,     0,     0,     0,     0,
     853,   854,   855,   856,   857,   858,   859,   860,     0,   861,
     862,   863,   864,   865,   866,   867,   868,   869,   870,     0,
     871,     0,     0,     0,     0,     0,   873,   874,   875,   876,
     877,   878,   879,     0,     0,     0,     0,   882,   883,     0,
       0,     0,   884,   885,   886,   887,   888,   889,   951,   952,
     953,   954,   955,   956,   957,   958,   959,   960,   961,   962,
     963,   964,   965,   966,   967,   968,  1420,     0,   841,   842,
     843,   844,   845,     0,     0,     0,     0,   850,   851,   852,
       0,     0,     0,     0,     0,     0,     0,   853,   854,   855,
     856,   857,   858,   859,   860,     0,   861,   862,   863,   864,
     865,   866,   867,   868,   869,   870,     0,   871,     0,     0,
       0,     0,     0,   873,   874,   875,   876,   877,   878,   879,
       0,     0,     0,     0,   882,   883,     0,     0,     0,   884,
     885,   886,   887,   888,   889,   951,   952,   953,   954,   955,
     956,   957,   958,   959,   960,   961,   962,   963,   964,   965,
     966,   967,   968,     0,     0,     0,     0,     0,     0,     0,
     890,   969,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   970,     0,     0,     0,   971,
       0,   972,   973,   974,   975,     0,   976,   977,   476,   891,
       0,   978,     0,   892,   893,     0,     0,     0,     0,  1041,
     980,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   890,   969,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   970,     0,     0,     0,   971,     0,   972,   973,
     974,   975,     0,   976,   977,   476,   891,     0,   978,     0,
     892,   893,     0,     0,     0,     0,  1041,   980,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   890,   969,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   970,
       0,     0,     0,   971,     0,   972,   973,   974,   975,     0,
     976,   977,   476,   891,     0,   978,     0,   892,   893,     0,
       0,     0,     0,  1041,   980,  1606,     0,   841,   842,   843,
     844,   845,     0,     0,     0,     0,   850,   851,   852,     0,
       0,     0,     0,     0,     0,     0,   853,   854,   855,   856,
     857,   858,   859,   860,     0,   861,   862,   863,   864,   865,
     866,   867,   868,   869,   870,     0,   871,     0,     0,     0,
       0,     0,   873,   874,   875,   876,   877,   878,   879,     0,
       0,     0,     0,   882,   883,     0,     0,     0,   884,   885,
     886,   887,   888,   889,   951,   952,   953,   954,   955,   956,
     957,   958,   959,   960,   961,   962,   963,   964,   965,   966,
     967,   968,   841,   842,   843,   844,   845,   846,   847,   848,
     849,   850,   851,   852,     0,     0,     0,     0,     0,     0,
       0,   853,   854,   855,   856,   857,   858,   859,   860,     0,
     861,   862,   863,   864,   865,   866,   867,   868,   869,   870,
       0,   871,     0,     0,     0,   872,     0,   873,   874,   875,
     876,   877,   878,   879,   880,     0,     0,   881,   882,   883,
       0,     0,     0,   884,   885,   886,   887,   888,   889,   841,
     842,   843,   844,   845,     0,     0,     0,     0,   850,   851,
     852,     0,     0,     0,     0,     0,     0,     0,   853,   854,
     855,   856,   857,   858,   859,   860,     0,   861,   862,   863,
     864,   865,   866,   867,   868,   869,   870,     0,   871,     0,
       0,     0,     0,     0,   873,   874,   875,   876,   877,   878,
     879,     0,     0,     0,     0,   882,   883,     0,     0,     0,
     884,   885,   886,   887,   888,   889,   951,   952,   953,   954,
     955,   956,   957,   958,   959,   960,   961,   962,   963,   964,
     965,   966,   967,   968,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   890,   969,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   970,     0,
       0,     0,   971,     0,   972,   973,   974,   975,     0,   976,
     977,   476,   891,     0,   978,     0,   892,   893,     0,     0,
       0,     0,  1041,   980,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   890,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1183,  1184,  1185,  1186,  1187,  1188,
    1189,  1190,  1191,  1192,  1193,  1194,  1195,  1196,  1197,  1198,
    1199,  1200,  1201,  1202,  1203,  1204,  1205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   891,     0,     0,
       0,   892,   893,     0,     0,   894,     0,     0,  1252,     0,
       0,     0,     0,     0,     0,   890,   969,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     970,     0,     0,     0,   971,     0,   972,   973,   974,   975,
       0,   976,   977,   476,   891,     0,   978,     0,   892,   893,
       0,     0,     0,     0,   979,   980,   841,   842,   843,   844,
     845,     0,     0,     0,     0,   850,   851,   852,     0,     0,
       0,     0,     0,     0,     0,   853,   854,   855,   856,   857,
     858,   859,   860,     0,   861,   862,   863,   864,   865,   866,
     867,   868,   869,   870,     0,   871,     0,     0,     0,     0,
       0,   873,   874,   875,   876,   877,   878,   879,     0,     0,
       0,     0,   882,   883,     0,     0,     0,   884,   885,   886,
     887,   888,   889,   951,   952,   953,   954,   955,   956,   957,
     958,   959,   960,   961,   962,   963,   964,   965,   966,   967,
     968,   841,   842,   843,   844,   845,     0,     0,     0,     0,
     850,   851,   852,     0,     0,     0,     0,     0,     0,     0,
     853,   854,   855,   856,   857,   858,   859,   860,     0,   861,
     862,   863,   864,   865,   866,   867,   868,   869,   870,     0,
     871,     0,     0,     0,     0,     0,   873,   874,   875,   876,
     877,   878,   879,     0,     0,     0,     0,   882,   883,     0,
       0,     0,   884,   885,   886,   887,   888,   889,   951,   952,
     953,   954,   955,   956,   957,   958,   959,   960,   961,   962,
     963,   964,   965,   966,   967,   968,   841,   842,   843,   844,
     845,     0,     0,     0,     0,   850,   851,   852,     0,     0,
       0,     0,     0,     0,     0,   853,   854,   855,   856,   857,
     858,   859,   860,     0,   861,   862,   863,   864,   865,   866,
     867,   868,   869,   870,     0,   871,     0,     0,     0,     0,
       0,   873,   874,   875,   876,   877,   878,   879,     0,     0,
       0,     0,   882,   883,     0,     0,     0,   884,   885,   886,
     887,   888,   889,   951,   952,   953,   954,   955,   956,   957,
     958,   959,   960,   961,   962,   963,   964,   965,   966,   967,
     968,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   890,   969,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   970,     0,     0,
       0,   971,     0,   972,   973,   974,   975,     0,   976,   977,
     476,   891,     0,   978,     0,   892,   893,     0,     0,     0,
       0,  1000,   980,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   890,   969,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   970,     0,     0,     0,   971,     0,   972,   973,
     974,   975,     0,   976,   977,   476,   891,     0,   978,     0,
     892,   893,     0,     0,     0,     0,  1002,   980,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   890,   969,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   970,     0,     0,
       0,   971,     0,   972,   973,   974,   975,     0,   976,   977,
     476,   891,     0,   978,     0,   892,   893,     0,     0,     0,
       0,  1041,   980,   841,   842,   843,   844,   845,     0,     0,
       0,     0,   850,   851,   852,     0,     0,     0,     0,     0,
       0,     0,   853,   854,   855,   856,   857,   858,   859,   860,
       0,   861,   862,   863,   864,   865,   866,   867,   868,   869,
     870,     0,   871,     0,     0,     0,     0,     0,   873,   874,
     875,   876,   877,   878,   879,     0,     0,     0,     0,   882,
     883,     0,     0,     0,   884,   885,   886,   887,   888,   889,
     951,   952,   953,   954,   955,   956,   957,   958,   959,   960,
     961,   962,   963,   964,   965,   966,   967,   968,   841,   842,
     843,   844,   845,   846,   847,   848,   849,   850,   851,   852,
       0,     0,     0,     0,     0,     0,     0,   853,   854,   855,
     856,   857,   858,   859,   860,     0,   861,   862,   863,   864,
     865,   866,   867,   868,   869,   870,     0,   871,     0,     0,
       0,   872,     0,   873,   874,   875,   876,   877,   878,   879,
     880,     0,     0,   881,   882,   883,     0,     0,     0,   884,
     885,   886,   887,   888,   889,  1167,     0,   841,   842,   843,
     844,   845,   846,   847,   848,   849,   850,   851,   852,     0,
       0,     0,     0,     0,     0,     0,   853,   854,   855,   856,
     857,   858,   859,   860,     0,   861,   862,   863,   864,   865,
     866,   867,   868,   869,   870,     0,   871,     0,     0,     0,
     872,     0,   873,   874,   875,   876,   877,   878,   879,   880,
       0,     0,   881,   882,   883,     0,     0,     0,   884,   885,
     886,   887,   888,   889,     0,     0,     0,     0,   841,   842,
     843,   844,   845,   846,   847,   848,   849,   850,   851,   852,
       0,     0,     0,     0,     0,     0,     0,   853,   854,   855,
     856,   857,   858,   859,   860,     0,   861,   862,   863,   864,
     865,   866,   867,   868,   869,   870,     0,   871,     0,   890,
     969,   872,     0,   873,   874,   875,   876,   877,   878,   879,
     880,     0,     0,   881,   882,   883,     0,     0,     0,   884,
     885,   886,   887,   888,   889,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   970,     0,     0,     0,   971,     0,
     972,   973,   974,   975,     0,   976,   977,  1556,   891,     0,
     978,     0,   892,   893,     0,     0,     0,     0,  1041,   980,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   890,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   891,     0,     0,     0,   892,   893,     0,
       0,   894,     0,     0,  1252,     0,     0,     0,     0,     0,
       0,     0,     0,   890,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   891,     0,     0,     0,   892,   893,     0,     0,
     894,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   890,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   891,     0,     0,     0,   892,   893,     0,
       0,   894
};

static const yytype_int16 yycheck[] =
{
     210,   179,   387,   213,   209,   806,  1107,   808,  1055,     1,
     811,     1,   942,   814,   944,     1,   946,   963,   948,   965,
     950,   967,   823,     1,     1,     1,   314,   237,     1,   239,
       1,   241,     1,   243,   806,     1,   808,     1,   984,   811,
       1,     1,   814,   331,     1,    56,    57,   317,     1,     1,
     320,   823,   990,   284,     1,     1,     1,    62,     1,   304,
     808,     1,   806,   811,   808,     1,   814,   811,    62,    61,
     814,   305,   317,     1,     1,   823,   284,   982,   304,   823,
       1,   986,     1,   317,     1,    56,    57,   332,   298,     1,
       1,   317,    14,    15,     1,   896,     1,   307,   308,   309,
     310,   311,   312,   313,     1,     1,     1,     1,     1,     1,
       1,   912,   284,   914,    61,   916,   304,   284,   304,     1,
     921,    61,     1,     1,   896,     1,   314,   512,   314,     1,
     340,   341,   342,   834,   835,     1,     1,     1,     1,   226,
     912,     1,   914,     1,   916,     1,   305,   306,   307,   921,
       1,     1,   896,   284,     1,     1,     1,   284,   292,   293,
       1,   979,     1,   297,   298,   318,   284,   320,   912,    61,
     914,   284,   916,     1,     1,   896,     0,   921,   979,   980,
       1,     1,  1000,     1,  1002,    61,   284,     1,     1,   284,
     284,   912,     1,   914,     1,   916,   325,     1,   327,  1000,
     921,  1002,     1,   304,     1,   304,     1,   979,   980,   419,
     420,     1,     1,   314,     1,     1,     1,   325,   317,   327,
       1,   320,   284,  1041,   325,   325,   327,   327,  1000,   284,
    1002,     1,   980,   284,     1,   979,   980,     1,     1,   284,
    1041,  1042,     1,     1,     1,     1,   325,     1,   327,  1179,
       1,     1,     1,     1,  1055,     1,  1000,     1,  1002,     1,
       1,     1,   325,   284,   327,   304,     1,     1,     1,  1041,
    1042,     1,     1,     1,   284,   314,     1,     1,   304,   806,
       1,   808,     1,  1055,   811,     1,   325,   814,   327,  1090,
       1,   317,     1,   284,   320,     1,   823,  1041,  1042,     1,
     806,     1,   808,  1104,     1,   811,     1,     1,   814,  1110,
       1,  1055,   317,    16,   304,     1,   284,   823,  1090,   330,
      19,  1042,     1,   317,   284,   317,   318,   317,   320,   321,
       1,     1,  1104,     1,  1055,   327,     1,   327,  1110,   331,
     317,   318,   319,   320,   321,   331,   284,  1285,   321,   327,
     328,   317,     1,   329,   331,   321,  1104,   326,   331,   330,
    1104,     1,  1110,  1464,   328,   331,  1110,  1168,   329,   896,
     317,   318,   329,   320,   321,   328,   328,   317,   318,     1,
     320,   321,   328,   328,   331,   912,   329,   914,   331,   916,
     896,   331,   320,   329,   921,   331,  1168,    88,    89,    90,
      91,   328,    88,    89,    90,    91,   912,   328,   914,   328,
     916,  1458,   329,     1,   331,   921,     1,   329,   329,   331,
     331,   328,     1,   328,  1168,   317,   318,     1,   320,   321,
     517,   328,   328,   328,   328,   328,  1382,   328,     1,   331,
       1,   317,   318,  1389,   320,   321,   328,  1168,   833,   328,
     328,  1252,   979,   980,     1,   331,   328,   317,   318,   319,
     320,   321,   328,   328,   328,   328,    88,    89,    90,    91,
     328,   331,   328,  1000,   980,  1002,   317,   328,   328,   318,
    1252,   328,   328,   328,   269,   284,   327,   284,  1289,  1290,
    1291,  1292,   320,   320,     1,  1296,     1,   318,   318,   320,
     320,  1302,   320,  1604,  1252,   318,   320,   320,  1252,   318,
     317,   320,     1,   320,  1041,  1042,   320,  1289,  1290,  1291,
    1292,   320,   317,   320,  1296,   320,     1,   317,  1055,   318,
    1302,   320,   318,   320,   320,   320,  1042,   318,   323,   320,
     925,  1289,  1290,  1291,  1292,  1289,  1290,  1291,  1292,  1055,
     320,   318,  1296,   320,   318,   318,   320,   320,  1302,   284,
      20,   320,   320,   320,   320,   806,   320,   808,   318,   320,
     811,   320,   320,   814,   320,  1296,   320,  1104,   320,   320,
     320,  1302,   823,  1110,  1090,   320,   320,   320,     1,     1,
     320,   320,   320,   317,   318,   319,   317,   318,  1104,   318,
       1,   317,   318,   319,  1110,   305,   317,   304,   317,  1539,
     304,   317,     1,     1,   305,   317,     1,   317,     1,   305,
     317,     1,   317,   317,   802,   304,   317,   318,   319,   320,
     321,   317,   318,   319,   320,   321,   304,   328,   317,   304,
     331,  1168,   328,     1,     1,   331,   317,   317,     1,   317,
       1,    62,   317,     1,     1,   896,  1457,  1458,     1,  1044,
       1,     1,  1168,  1048,   304,     1,     1,     1,   317,     1,
       1,   912,     1,   914,     1,   916,     1,   317,     1,     1,
     921,     1,     1,   305,     1,  1457,  1458,     1,     1,     1,
       1,  1492,  1493,  1494,  1495,   317,   318,   319,   320,   321,
       1,     1,   284,     1,     1,     1,     1,     1,     1,   331,
     329,     1,     1,  1457,  1458,     1,   304,     1,     1,   304,
    1492,  1493,  1494,  1495,     1,  1252,   305,     1,     1,   317,
     304,     1,   317,   325,   284,   327,  1457,  1458,   317,   980,
       1,   304,     1,   317,     1,     1,  1252,     1,  1492,  1493,
    1494,  1495,  1553,     1,   317,     1,   317,   304,     1,     1,
       1,     1,  1289,  1290,  1291,  1292,   284,     1,     1,  1296,
     317,  1492,  1493,  1494,  1495,  1302,     1,    62,   284,     1,
      62,  1553,     1,  1289,  1290,  1291,  1292,     1,     1,     1,
    1296,     1,     1,     1,     1,     1,  1302,   304,   284,   304,
       1,  1042,     1,     1,  1605,  1553,     1,  1608,  1609,  1553,
     317,     1,   317,     1,  1055,   304,  1026,     1,  1619,  1620,
    1621,     1,  1623,  1624,  1625,     1,     1,     1,   317,   304,
       1,     1,     1,  1605,     1,  1040,  1608,  1609,     1,     1,
       1,     1,   317,  1048,   325,     1,   327,  1619,  1620,  1621,
     284,  1623,  1624,  1625,     1,     1,     1,  1605,     1,   284,
    1608,  1605,     1,  1104,  1608,  1609,   846,   847,   848,  1110,
       1,   284,  1620,  1621,    57,  1619,  1620,  1621,     1,  1623,
    1624,  1625,   284,  1061,     1,  1063,     1,  1065,  1609,     1,
       1,     1,   872,   284,   317,   318,     1,   320,  1619,  1109,
     880,   881,  1623,  1624,  1625,   317,   317,   325,     1,   327,
     284,     1,     1,   284,   284,     1,   317,     1,     1,     1,
     317,   318,     1,   320,   284,   284,    21,  1168,   317,   317,
    1457,  1458,   317,   284,   317,   317,   318,   317,   320,   284,
     284,    88,    89,    90,    91,    88,    89,    90,    91,     1,
       1,  1457,  1458,   284,     1,   284,     1,     1,     1,   317,
     317,   284,   284,     1,   317,  1492,  1493,  1494,  1495,   317,
     317,   317,     1,     1,   317,   284,   317,   317,   284,   317,
     284,   317,   317,   317,   317,   317,  1492,  1493,  1494,  1495,
     317,   321,   317,   973,   974,   975,   284,   317,   317,   325,
     317,   327,   317,   317,   317,   317,   317,   217,   218,   219,
     220,  1252,   317,   318,   284,   320,   317,   317,   998,   317,
     317,   317,   317,   317,   317,   317,  1553,   317,   317,  1009,
     317,   317,   317,   317,   317,   317,   292,   293,   294,   284,
     317,   297,   298,   317,   317,   284,   284,  1553,  1289,  1290,
    1291,  1292,   284,   284,   284,  1296,   317,   325,   317,   327,
     317,  1302,   325,   317,   327,   284,   284,   292,   293,   317,
     284,   317,   297,   298,   317,   317,   317,   317,  1605,   284,
    1465,  1608,  1609,   317,   317,   284,   284,    88,    89,    90,
      91,   284,  1619,  1620,  1621,   317,  1623,  1624,  1625,  1605,
     317,   317,  1608,  1609,   317,   317,   284,  1087,   317,   317,
     317,   317,   284,  1619,  1620,  1621,   317,  1623,  1624,  1625,
     284,   325,   317,   327,   320,   284,   284,   317,   284,   317,
     284,   284,   284,   317,   317,   318,   284,   317,   284,   284,
     284,   317,   317,   317,   284,   284,   317,   317,   317,   284,
     317,   284,   284,   284,   317,   317,   317,   317,   305,   284,
     284,   284,   305,   284,   284,  1145,  1146,  1147,   325,   284,
     327,   284,   284,   284,   284,   292,   293,  1157,  1158,   317,
     297,   298,   299,   300,   301,   302,  1396,   292,   293,   294,
    1170,   284,   297,   298,   284,   284,  1176,  1177,   284,  1179,
     284,   284,   284,  1183,  1184,  1185,  1186,  1187,  1188,  1189,
       1,   284,   284,   292,   293,   294,  1457,  1458,   297,   298,
     284,  1201,  1202,  1203,  1204,  1205,  1206,  1207,   325,   325,
     327,   327,   284,   284,   325,   284,   327,   284,   284,   284,
     284,   284,   284,   944,   284,   946,   284,   948,   325,   950,
     327,  1492,  1493,  1494,  1495,   284,   284,   284,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   304,   804,   284,
     284,   325,   284,   809,   304,   284,   812,   314,   284,   815,
      71,    72,    73,    74,   314,    76,   304,    78,   325,    80,
     327,   284,   284,   284,   284,   325,   314,   327,   284,  1279,
     284,   284,   284,   284,   305,   318,   284,   325,   284,   327,
    1488,   284,  1553,  1491,   284,   284,   317,   318,   319,   320,
     321,   284,   317,  1533,   284,   284,   284,   328,   284,   284,
     331,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   284,   317,   318,   319,   320,   321,
     284,   284,   284,   284,  1605,   284,   328,  1608,  1609,   331,
     303,   304,   305,   306,   307,   329,   284,   284,  1619,  1620,
    1621,   284,  1623,  1624,  1625,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   327,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   284,
     327,   284,   284,   317,   318,   319,   320,   321,  1179,   284,
     284,   284,   284,   284,   284,     0,     1,   331,  1468,   284,
     284,   284,   284,   317,  1474,   284,   284,   284,   284,    14,
      15,    16,    17,    18,    19,    20,    21,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    38,   284,   284,    41,    42,    43,    44,
      45,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     284,   284,    57,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   317,   317,   317,   317,
    1550,   317,   317,   320,   329,   332,   317,   317,  1558,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   317,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   317,   317,   317,   317,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   317,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   281,   282,   283,   334,
     317,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   325,   317,   314,   334,   334,   107,
     325,   317,   284,   318,   324,   332,   317,   328,   325,   332,
     320,   326,   284,   327,   327,   314,   328,     1,   333,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,   332,   328,   328,   328,   328,   328,   328,    22,    23,
      24,    25,    26,    27,    28,    29,   326,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,   328,    42,   328,
     328,   326,    46,   329,    48,    49,    50,    51,    52,    53,
      54,    55,   332,   332,    58,    59,    60,   332,   332,   314,
      64,    65,    66,    67,    68,    69,     1,   334,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
     334,   325,   329,   328,   320,   328,   327,    22,    23,    24,
      25,    26,    27,    28,    29,   327,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,   327,    42,   327,   327,
     327,    46,   327,    48,    49,    50,    51,    52,    53,    54,
      55,   327,   327,    58,    59,    60,   328,   314,   331,    64,
      65,    66,    67,    68,    69,     1,   329,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,   329,
     329,   329,   257,   257,   317,   317,    22,    23,    24,    25,
      26,    27,    28,    29,   318,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,   327,    42,   327,   327,   327,
      46,   327,    48,    49,    50,    51,    52,    53,    54,    55,
     327,   284,    58,    59,    60,   284,   284,   284,    64,    65,
      66,    67,    68,    69,     1,   327,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,   330,   327,
     331,   327,   325,   325,    47,    22,    23,    24,    25,    26,
      27,    28,    29,   327,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,   327,    42,   327,   327,   327,    46,
     327,    48,    49,    50,    51,    52,    53,    54,    55,   327,
     327,    58,    59,    60,   327,   269,   327,    64,    65,    66,
      67,    68,    69,   327,   327,   327,   327,   327,   327,   327,
     327,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   327,   327,   327,   327,   327,   327,
     314,   327,   327,   327,   318,   327,   327,   327,   322,   323,
     327,   325,   326,   327,   328,   329,   327,   327,   327,   334,
     334,   334,   327,   327,   269,   325,   327,   318,   327,   327,
     327,   327,   327,   327,   327,   325,   320,   320,   284,   314,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   332,   327,   327,   317,   317,   317,   317,
     317,   331,   327,   318,   317,   317,   317,   322,   323,   317,
     325,   326,   327,   328,   329,   317,   317,   317,   317,   334,
     317,   317,   314,   269,   327,   306,   320,   320,   334,   317,
     334,   187,   330,   925,   831,  1147,   327,   327,   327,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   318,   327,   327,   327,   322,   323,   327,   325,
     326,   327,   327,   329,   327,   327,   327,   327,   334,   327,
     327,   327,   269,   332,   327,   327,   327,   327,   327,   334,
     334,   327,   800,  1102,   332,   332,   513,  1149,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   347,   334,   334,   348,   802,  1472,  1534,  1149,  1550,
    1280,   318,    -1,  1558,    -1,   322,   323,     1,   325,   326,
     327,    -1,   329,    -1,    -1,    -1,    -1,   334,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   327,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,    -1,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   281,   282,   283,
      -1,    -1,    -1,    -1,    -1,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    -1,    -1,
      -1,    -1,    -1,     1,   318,     3,     4,     5,     6,     7,
      -1,    -1,   326,    -1,    12,    13,    14,   327,    -1,   333,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    64,    65,    66,    67,    68,    69,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,   269,   270,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   304,    -1,    -1,    -1,
     308,    -1,   310,   311,   312,   313,    -1,   315,   316,   317,
     318,    -1,   320,   321,   322,   323,    -1,    -1,    -1,    -1,
     328,   329,    -1,   331,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,   269,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,   318,    -1,    -1,
      -1,   322,   323,    -1,    -1,   326,    -1,    -1,    -1,   330,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,    -1,    -1,    -1,    -1,    -1,   318,    -1,    -1,    -1,
     322,   323,    -1,    -1,   326,    -1,    -1,    -1,   330,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   269,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   318,    -1,    -1,    -1,   322,
     323,    -1,    -1,   326,    -1,    -1,    -1,   330,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    46,   269,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   318,    -1,    -1,    -1,   322,
     323,    -1,    -1,   326,    -1,    -1,     1,   330,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,   269,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,   318,    -1,    -1,
      -1,   322,   323,    -1,    -1,   326,    -1,    -1,     1,   330,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    46,   269,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   318,    -1,    -1,    -1,   322,   323,    -1,
      -1,   326,    -1,    -1,    -1,   330,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   318,    -1,    -1,    -1,   322,   323,    -1,    -1,
     326,    -1,    -1,    -1,   330,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   318,    -1,    -1,    -1,   322,
     323,    -1,    -1,   326,    -1,    -1,     1,   330,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,   269,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,   318,    -1,    -1,    -1,   322,
     323,    -1,    -1,   326,    -1,    -1,     1,   330,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    46,   269,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   318,    -1,    -1,    -1,   322,   323,    -1,
      -1,   326,    -1,    -1,     1,   330,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,   269,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,   318,    -1,    -1,    -1,   322,   323,    -1,
      -1,   326,    -1,    -1,    -1,   330,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   318,    -1,    -1,    -1,   322,   323,    -1,    -1,
     326,    -1,    -1,    -1,   330,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   318,    -1,    -1,    -1,   322,
     323,    -1,    -1,   326,    -1,    -1,     1,   330,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    46,   269,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   318,    -1,    -1,    -1,   322,   323,    -1,    -1,   326,
      -1,    -1,     1,   330,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,   269,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,   318,    -1,    -1,    -1,   322,   323,    -1,
      -1,   326,    -1,    -1,     1,   330,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,
     269,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   318,
      -1,    -1,    -1,   322,   323,    -1,    -1,   326,    -1,    -1,
      -1,   330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   318,    -1,
      -1,    -1,   322,   323,    -1,    -1,   326,    -1,    -1,    -1,
     330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   318,    -1,    -1,    -1,   322,   323,    -1,    -1,   326,
      -1,    -1,    -1,   330,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   318,    -1,    -1,    -1,   322,   323,    -1,    -1,   326,
      -1,    -1,     1,   330,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,
     269,   270,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   304,   305,    -1,    -1,   308,
      -1,   310,   311,   312,   313,    -1,   315,   316,   317,   318,
      -1,   320,    -1,   322,   323,    -1,    -1,    -1,    -1,   328,
     329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,   270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,   305,
      -1,    -1,   308,    -1,   310,   311,   312,   313,    -1,   315,
     316,   317,   318,    -1,   320,    -1,   322,   323,    -1,    -1,
      -1,    -1,   328,   329,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,   270,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   304,    -1,    -1,    -1,   308,    -1,   310,   311,
     312,   313,    -1,   315,   316,   317,   318,    -1,   320,    -1,
     322,   323,    -1,    -1,    -1,   327,   328,   329,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   269,   270,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   304,    -1,    -1,    -1,   308,    -1,   310,   311,   312,
     313,    -1,   315,   316,   317,   318,    -1,   320,    -1,   322,
     323,    -1,    -1,    -1,   327,   328,   329,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,   270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,    -1,
      -1,    -1,   308,    -1,   310,   311,   312,   313,    -1,   315,
     316,   317,   318,    -1,   320,    -1,   322,   323,    -1,    -1,
      -1,   327,   328,   329,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     269,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   304,    -1,   306,    -1,   308,
      -1,   310,   311,   312,   313,    -1,   315,   316,   317,   318,
      -1,   320,    -1,   322,   323,    -1,    -1,    -1,    -1,   328,
     329,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   304,    -1,    -1,    -1,   308,    -1,
     310,   311,   312,   313,    -1,   315,   316,   317,   318,    -1,
     320,    -1,   322,   323,    -1,    -1,    -1,    -1,   328,   329,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   269,   270,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   304,    -1,    -1,    -1,   308,    -1,   310,   311,   312,
     313,    -1,   315,   316,   317,   318,    -1,   320,    -1,   322,
     323,    -1,    -1,    -1,    -1,   328,   329,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,   270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,    -1,
      -1,    -1,   308,    -1,   310,   311,   312,   313,    -1,   315,
     316,   317,   318,    -1,   320,    -1,   322,   323,    -1,    -1,
      -1,    -1,   328,   329,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   269,   270,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,    -1,    -1,
      -1,   308,    -1,   310,   311,   312,   313,    -1,   315,   316,
     317,   318,    -1,   320,    -1,   322,   323,    -1,    -1,    -1,
      -1,   328,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   304,    -1,    -1,    -1,   308,    -1,
     310,   311,   312,   313,    -1,   315,   316,   317,   318,    -1,
     320,    -1,   322,   323,    -1,    -1,    -1,    -1,   328,   329,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   269,   270,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   304,    -1,    -1,    -1,   308,    -1,   310,   311,   312,
     313,    -1,   315,   316,   317,   318,    -1,   320,    -1,   322,
     323,    -1,    -1,    -1,    -1,   328,   329,     1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   269,   270,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     304,    -1,    -1,    -1,   308,    -1,   310,   311,   312,   313,
      -1,   315,   316,   317,   318,    -1,   320,    -1,   322,   323,
      -1,    -1,    -1,    -1,   328,   329,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   269,   270,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,    -1,    -1,
      -1,   308,    -1,   310,   311,   312,   313,    -1,   315,   316,
     317,   318,    -1,   320,    -1,   322,   323,    -1,    -1,    -1,
      -1,   328,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   304,    -1,    -1,    -1,   308,    -1,
     310,   311,   312,   313,    -1,   315,   316,   317,   318,    -1,
     320,    -1,   322,   323,    -1,    -1,    -1,    -1,   328,   329,
       1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,   270,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   304,    -1,    -1,    -1,   308,    -1,   310,
     311,   312,   313,    -1,   315,   316,   317,   318,    -1,   320,
      -1,   322,   323,    -1,    -1,    -1,    -1,   328,   329,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   269,   270,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     304,    -1,    -1,    -1,   308,    -1,   310,   311,   312,   313,
      -1,   315,   316,   317,   318,    -1,   320,    -1,   322,   323,
      -1,    -1,    -1,    -1,   328,   329,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   269,   270,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,    -1,    -1,
      -1,   308,    -1,   310,   311,   312,   313,    -1,   315,   316,
     317,   318,    -1,   320,    -1,   322,   323,    -1,    -1,    -1,
      -1,   328,   329,     1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   269,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   304,    -1,    -1,    -1,
     308,    -1,   310,   311,   312,   313,    -1,   315,   316,   317,
     318,    -1,   320,    -1,   322,   323,    -1,    -1,    -1,    -1,
     328,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,   270,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   304,    -1,    -1,    -1,   308,    -1,   310,
     311,   312,   313,    -1,   315,   316,   317,   318,    -1,   320,
      -1,   322,   323,    -1,    -1,    -1,    -1,   328,   329,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   269,   270,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     304,    -1,    -1,    -1,   308,    -1,   310,   311,   312,   313,
      -1,   315,   316,   317,   318,    -1,   320,    -1,   322,   323,
      -1,    -1,    -1,    -1,   328,   329,     1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   269,   270,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,
      -1,    -1,    -1,   308,    -1,   310,   311,   312,   313,    -1,
     315,   316,   317,   318,    -1,   320,    -1,   322,   323,    -1,
      -1,    -1,    -1,   328,   329,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   269,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   304,    -1,    -1,    -1,
     308,    -1,   310,   311,   312,   313,    -1,   315,   316,   317,
     318,    -1,   320,    -1,   322,   323,    -1,    -1,    -1,    -1,
     328,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,   270,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   304,    -1,    -1,    -1,   308,    -1,   310,
     311,   312,   313,    -1,   315,   316,   317,   318,    -1,   320,
      -1,   322,   323,    -1,    -1,    -1,    -1,   328,   329,     1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,   270,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   304,    -1,    -1,    -1,   308,    -1,   310,   311,
     312,   313,    -1,   315,   316,   317,   318,    -1,   320,    -1,
     322,   323,    -1,    -1,    -1,    -1,   328,   329,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   269,   270,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,
      -1,    -1,    -1,   308,    -1,   310,   311,   312,   313,    -1,
     315,   316,   317,   318,    -1,   320,    -1,   322,   323,    -1,
      -1,    -1,    -1,   328,   329,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   269,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   304,    -1,    -1,    -1,
     308,    -1,   310,   311,   312,   313,    -1,   315,   316,   317,
     318,    -1,   320,    -1,   322,   323,    -1,    -1,    -1,    -1,
     328,   329,     1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     269,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   304,    -1,    -1,    -1,   308,
      -1,   310,   311,   312,   313,    -1,   315,   316,   317,   318,
      -1,   320,    -1,   322,   323,    -1,    -1,    -1,    -1,   328,
     329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,   270,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   304,    -1,    -1,    -1,   308,    -1,   310,   311,
     312,   313,    -1,   315,   316,   317,   318,    -1,   320,    -1,
     322,   323,    -1,    -1,    -1,    -1,   328,   329,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   269,   270,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,
      -1,    -1,    -1,   308,    -1,   310,   311,   312,   313,    -1,
     315,   316,   317,   318,    -1,   320,    -1,   322,   323,    -1,
      -1,    -1,    -1,   328,   329,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,   270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,    -1,
      -1,    -1,   308,    -1,   310,   311,   312,   313,    -1,   315,
     316,   317,   318,    -1,   320,    -1,   322,   323,    -1,    -1,
      -1,    -1,   328,   329,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   318,    -1,    -1,
      -1,   322,   323,    -1,    -1,   326,    -1,    -1,   329,    -1,
      -1,    -1,    -1,    -1,    -1,   269,   270,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     304,    -1,    -1,    -1,   308,    -1,   310,   311,   312,   313,
      -1,   315,   316,   317,   318,    -1,   320,    -1,   322,   323,
      -1,    -1,    -1,    -1,   328,   329,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   269,   270,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,    -1,    -1,
      -1,   308,    -1,   310,   311,   312,   313,    -1,   315,   316,
     317,   318,    -1,   320,    -1,   322,   323,    -1,    -1,    -1,
      -1,   328,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,   270,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   304,    -1,    -1,    -1,   308,    -1,   310,   311,
     312,   313,    -1,   315,   316,   317,   318,    -1,   320,    -1,
     322,   323,    -1,    -1,    -1,    -1,   328,   329,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   269,   270,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,    -1,    -1,
      -1,   308,    -1,   310,   311,   312,   313,    -1,   315,   316,
     317,   318,    -1,   320,    -1,   322,   323,    -1,    -1,    -1,
      -1,   328,   329,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,   269,
     270,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   304,    -1,    -1,    -1,   308,    -1,
     310,   311,   312,   313,    -1,   315,   316,   317,   318,    -1,
     320,    -1,   322,   323,    -1,    -1,    -1,    -1,   328,   329,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   318,    -1,    -1,    -1,   322,   323,    -1,
      -1,   326,    -1,    -1,   329,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   318,    -1,    -1,    -1,   322,   323,    -1,    -1,
     326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   318,    -1,    -1,    -1,   322,   323,    -1,
      -1,   326
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    17,    18,    38,    41,    42,    43,    44,    45,
      57,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     281,   282,   283,   318,   326,   333,   336,   337,   338,   339,
     340,   341,   342,   343,   354,   358,   361,   362,   364,   365,
     374,   375,   381,   284,     1,   331,     1,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
       1,   284,     1,   284,     1,   284,     1,   284,     1,   284,
       1,   284,     1,   284,     1,   284,     1,   284,     1,   284,
       1,   284,     1,   284,     1,   284,     1,   284,     1,   284,
       1,   284,     1,   284,     1,   284,     1,   284,     1,   284,
       1,   284,     1,   284,     1,   284,     1,   284,     1,   284,
       1,   284,     1,   284,     1,   284,     1,   284,     1,   284,
       1,   284,     1,   284,     1,   284,     1,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,     1,
     320,     1,   284,   320,     1,   328,     1,   284,   320,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,     1,   284,     1,   284,     1,   284,     1,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,     1,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,     1,   318,   320,   355,   356,
     357,     1,   357,   359,   360,     1,   320,     1,   320,     1,
     320,     0,     1,   338,    14,    15,   371,   372,    16,   373,
      19,   378,    20,   379,    21,   380,   314,   331,   329,   317,
     318,   320,   370,     1,   317,     1,   317,     1,    88,    89,
      90,    91,   305,   347,     1,   304,   317,   353,     1,   317,
       1,   317,     1,   353,     1,   317,     1,   317,     1,   317,
       1,   317,     1,   318,     1,   320,     1,   317,     1,   320,
       1,   317,     1,   320,     1,   320,     1,   317,   318,   319,
     320,   321,   328,   331,   344,   346,   347,   351,   352,   366,
     367,   368,   369,   395,   396,     1,   352,     1,   317,     1,
     317,     1,   317,   317,   317,   317,   353,   353,   353,   353,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,     1,   353,     1,
     317,   320,     1,   317,     1,   317,     1,   317,     1,   317,
       1,   317,     1,   317,     1,   353,     1,   353,     1,   353,
       1,   353,     1,   353,     1,   353,     1,   353,     1,   317,
       1,   317,     1,   320,     1,   320,     1,   317,     1,   320,
     320,     1,   320,     1,   317,     1,   317,     1,   318,   320,
       1,   318,   320,     1,   318,   320,     1,   318,   320,     1,
     318,   320,     1,   317,     1,   317,     1,   317,     1,   317,
       1,   353,     1,   353,     1,   353,     1,   318,   320,     1,
     317,     1,   317,     1,   317,     1,   317,   367,     1,   369,
       1,   317,     1,   317,   317,   317,   317,   317,     1,   317,
       1,   317,     1,   317,     1,   317,     1,   317,     1,   317,
       1,   317,     1,   317,     1,   317,     1,   317,     1,   317,
       1,   317,     1,   317,     1,   317,     1,   317,     1,   317,
       1,   317,     1,   217,   218,   219,   220,     1,   317,     1,
     317,     1,   317,     1,   317,     1,   320,     1,   320,     1,
     320,     1,   317,     1,   317,     1,   317,     1,   344,     1,
     317,     1,   317,     1,   317,     1,   317,     1,   317,     1,
     317,     1,   317,     1,   317,     1,   317,     1,   317,     1,
     317,     1,   317,     1,   317,     1,   317,     1,   317,     1,
     318,   320,     1,   317,   318,   317,     1,   317,     1,   317,
       1,   317,     1,   317,     1,   317,     1,   317,     1,   317,
       1,   320,     1,   317,     1,   317,   317,   317,     1,   353,
       1,   353,     1,   317,     1,   317,     1,   317,     1,   317,
     325,   334,   325,     1,   331,     1,   329,     1,   329,   331,
       1,   329,   331,     1,   329,   331,     1,   331,    57,   317,
     318,   363,   317,   376,   332,   317,   314,   344,   345,   368,
     334,   334,   352,   107,   304,   314,   325,   355,   317,   359,
     370,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    22,    23,    24,    25,    26,    27,    28,
      29,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    42,    46,    48,    49,    50,    51,    52,    53,    54,
      55,    58,    59,    60,    64,    65,    66,    67,    68,    69,
     269,   318,   322,   323,   326,   397,   399,   400,   401,   405,
     406,   414,   415,   417,   418,   421,   422,   424,   428,   429,
     430,   434,   399,   370,   399,   370,   399,   370,   324,   284,
     332,   399,     1,   377,   317,   325,   327,   332,     1,   305,
     317,   349,   346,   344,     1,   317,   395,     1,   395,   320,
     332,     1,   328,     1,   328,     1,   328,     1,   328,     1,
     328,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,   270,
     304,   308,   310,   311,   312,   313,   315,   316,   320,   328,
     329,   353,   387,   388,   389,   390,   391,   392,   397,   409,
     414,   415,   416,   417,   419,   421,   422,   425,   426,   427,
     328,   427,   328,   427,     1,   328,     1,   328,     1,   328,
     328,     1,   328,     1,   328,     1,   328,     1,   328,     1,
     328,     1,   328,     1,   328,     1,   328,   328,     1,   328,
       1,   328,     1,   328,     1,   328,   328,   328,   328,   328,
     328,   328,   427,     1,   328,     1,   328,     1,   328,   328,
     328,   328,   328,     1,   427,   427,     1,   328,     1,   328,
       1,   328,     1,   328,     1,   328,     1,   431,     1,   326,
       1,   330,   400,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   318,   411,   412,   413,   284,   423,   326,     1,
     328,   326,   330,   332,   330,   332,   330,   332,   332,     1,
     317,   320,   314,   330,   329,   314,   345,   334,   334,   325,
     329,     1,    61,   318,   320,   327,   366,   394,     1,    61,
     320,   366,   394,     1,    61,   320,   366,   394,     1,    61,
     320,   366,   394,     1,    61,   320,   366,   394,     1,   292,
     293,   294,   297,   298,   382,   384,   382,   382,     1,   382,
     410,     1,   427,     1,   427,     1,   427,   328,   328,     1,
     327,   415,   417,   421,   422,   427,   428,     1,   399,     1,
     384,     1,   299,   300,   301,   302,   382,   383,     1,   384,
     413,     1,   427,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   385,   386,   327,   327,
       1,   317,   320,     1,   320,     1,   318,   427,   320,     1,
     320,     1,   320,     1,   320,     1,   320,     1,   317,     1,
     317,   327,     1,   327,   353,   327,     1,   320,     1,   320,
       1,   320,     1,   320,   327,   327,   327,     1,   317,   327,
       1,   347,   329,   398,   400,     1,   344,     1,   317,     1,
     344,   347,   350,   327,   327,   327,   327,   329,   398,     1,
     320,     1,   320,   317,   357,   317,   357,   317,   357,   328,
     314,   331,   427,     1,   320,   414,   415,   420,   422,   329,
     329,   329,   329,   257,   257,   363,   399,   317,   349,   317,
     320,   353,   399,   327,   325,   327,   325,   327,   325,   327,
     304,   314,   325,   327,   327,   325,   327,   325,   327,   325,
     327,   325,   327,   327,   325,   327,   325,   327,   325,   327,
     325,   327,   327,   325,   327,   325,   327,   325,   327,   325,
     327,   327,   325,   327,   325,   327,   325,   327,   325,   327,
       1,   318,   427,     1,    88,    89,    90,    91,    92,    93,
     305,   348,   427,     1,   348,   427,     1,   387,   391,   318,
     407,   408,     1,   427,     1,   427,   327,   327,   327,   330,
     330,     1,    86,   427,     1,   427,     1,   427,     1,    86,
     317,   318,   366,   393,   394,   427,   331,     1,   427,     1,
     427,     1,   427,     1,   427,   427,   427,   427,     1,   427,
       1,   427,     1,   427,     1,   427,     1,   427,     1,   427,
       1,   427,   327,   325,   327,   327,   325,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   399,    47,   327,
     327,   327,   327,   327,   334,   334,   327,     1,    56,    57,
     330,   403,   404,   327,   325,   327,   327,   327,   327,   327,
     327,   327,   327,   427,   432,   433,   412,   332,   325,   327,
     413,   325,   399,   399,   399,   399,   320,   320,   284,   330,
     314,   327,   327,   330,    62,   317,   317,   317,     1,   318,
       1,   318,   317,    62,   317,   317,   317,   317,    62,   317,
     317,   317,   317,    62,   317,   317,   317,   317,    62,   317,
     317,   317,   317,   331,   314,   327,   327,   327,   327,   306,
     353,   320,   320,   330,   398,     1,   349,   344,   330,     1,
     306,   402,   427,   334,   330,   403,   317,   427,   325,   327,
     357,     1,   357,   330,   330,   330,   330,   317,   320,   317,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   320,   353,   407,     1,   317,
     366,   332,   327,   327,   334,   334,     1,   402,   334,   399,
     327,   327,   433,   327,   327,   327,   332,   332,   349,   399,
     334,   334,     1,   399,   399,   399
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   335,   336,   337,   337,   337,   338,   338,   338,   338,
     338,   339,   338,   340,   338,   338,   341,   338,   342,   338,
     343,   338,   338,   338,   344,   344,   344,   345,   345,   346,
     346,   347,   347,   347,   347,   347,   348,   348,   348,   348,
     348,   348,   348,   349,   349,   350,   350,   350,   350,   350,
     351,   351,   351,   351,   351,   352,   352,   353,   353,   354,
     354,   355,   355,   356,   356,   357,   357,   358,   358,   359,
     359,   360,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   362,   362,   363,   363,   363,   364,   364,   364,   364,
     364,   364,   364,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   366,   366,   367,   368,
     369,   369,   370,   370,   370,   371,   371,   372,   372,   372,
     372,   373,   373,   373,   374,   374,   376,   375,   375,   375,
     377,   375,   375,   378,   378,   378,   379,   379,   379,   380,
     380,   381,   381,   381,   381,   381,   381,   382,   382,   382,
     382,   383,   383,   383,   383,   384,   384,   385,   385,   385,
     385,   385,   385,   385,   386,   386,   386,   386,   387,   387,
     387,   388,   388,   388,   389,   389,   389,   389,   389,   390,
     390,   391,   391,   391,   392,   392,   392,   392,   392,   392,
     392,   392,   392,   392,   392,   392,   392,   392,   392,   392,
     392,   392,   392,   392,   392,   392,   392,   392,   392,   392,
     392,   392,   392,   393,   393,   393,   393,   394,   394,   394,
     394,   394,   395,   395,   395,   396,   396,   396,   396,   396,
     397,   398,   398,   399,   399,   399,   400,   400,   400,   400,
     400,   400,   400,   400,   401,   401,   402,   403,   403,   403,
     403,   403,   403,   403,   403,   403,   403,   403,   404,   404,
     405,   405,   405,   405,   406,   407,   407,   407,   408,   408,
     410,   409,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   412,   413,   413,   414,   415,   416,   417,   418,   418,
     419,   419,   419,   420,   420,   420,   421,   422,   423,   424,
     424,   424,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   426,   426,   426,   427,   427,   427,
     427,   427,   427,   427,   427,   427,   427,   427,   427,   427,
     427,   427,   427,   427,   427,   427,   427,   427,   427,   427,
     427,   427,   427,   427,   427,   427,   427,   427,   427,   427,
     427,   427,   427,   427,   427,   427,   428,   429,   429,   429,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   431,   430,   430,   432,   432,
     432,   433,   434,   434,   434,   434,   434,   434,   434,   434,
     434,   434
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     0,     2,     0,     2,     1,     0,     2,     0,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     5,     3,
       1,     3,     3,     5,     3,     1,     2,     1,     2,     2,
       2,     1,     3,     1,     3,     1,     1,     2,     2,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     2,     3,     2,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     7,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       2,     1,     1,     1,     1,     1,     5,     5,     7,     7,
       5,     8,     8,     2,     2,     2,     2,     3,     3,     8,
       8,     2,     2,     2,     3,     3,     1,     1,     7,     1,
       1,     3,     1,     1,     1,     1,     1,     4,     7,     2,
       2,     4,     7,     2,     1,     1,     0,     5,     2,     2,
       0,     8,     5,     4,     7,     2,     4,     7,     2,     7,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     2,     3,     3,
       3,     2,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     2,     3,     3,     1,     3,     1,     3,     3,
       3,     3,     1,     1,     1,     1,     3,     3,     3,     3,
       1,     1,     3,     2,     1,     2,     2,     1,     1,     1,
       2,     2,     1,     2,     3,     5,     1,     4,     5,     3,
       4,     3,     2,     4,     5,     3,     4,     4,     2,     1,
       5,     4,     2,     5,     3,     1,     4,     4,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     5,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     1,     1,     1,     1,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     4,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     4,     2,     3,     1,     1,     1,
       3,     4,     4,     4,     6,     6,     6,     6,     6,     4,
       2,     4,     4,     4,     4,     6,     6,     6,     6,     6,
       4,     2,     4,     4,     4,     4,     6,     6,     6,     6,
       6,     4,     2,     4,     4,     4,     4,     6,     6,     6,
       6,     6,     4,     2,     4,     4,     4,     4,     6,     6,
       6,     6,     6,     4,     2,     4,     4,     6,     2,     4,
       4,     4,     2,     4,     4,     2,     4,     4,     2,     6,
       6,     6,     4,     2,     6,     2,     4,     4,     4,     2,
       4,     4,     4,     2,     4,     4,     2,     4,     4,     2,
       4,     4,     2,     4,     3,     2,     4,     3,     2,     4,
       3,     4,     2,     4,     4,     2,     4,     4,     2,     4,
       4,     2,     4,     4,     2,     4,     4,     2,     4,     3,
       1,     3,     1,     3,     1,     4,     3,     1,     4,     4,
       4,     4,     4,     2,     4,     4,     2,     4,     4,     2,
       3,     1,     3,     1,     3,     1,     3,     1,     6,     6,
       2,     4,     4,     2,     4,     0,     5,     2,     0,     3,
       1,     1,     3,     2,     1,     3,     2,     1,     1,     3,
       2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 3:
#line 615 "core/cfg.y" /* yacc.c:1646  */
    {}
#line 4947 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 616 "core/cfg.y" /* yacc.c:1646  */
    {}
#line 4953 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 617 "core/cfg.y" /* yacc.c:1646  */
    { yyerror(""); YYABORT;}
#line 4959 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 625 "core/cfg.y" /* yacc.c:1646  */
    {rt=REQUEST_ROUTE;}
#line 4965 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 626 "core/cfg.y" /* yacc.c:1646  */
    {rt=FAILURE_ROUTE;}
#line 4971 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 628 "core/cfg.y" /* yacc.c:1646  */
    {rt=BRANCH_ROUTE;}
#line 4977 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 629 "core/cfg.y" /* yacc.c:1646  */
    {rt=ONSEND_ROUTE;}
#line 4983 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 630 "core/cfg.y" /* yacc.c:1646  */
    {rt=EVENT_ROUTE;}
#line 4989 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 635 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[0].ipaddr)){
			tmp=ip_addr2a((yyvsp[0].ipaddr));
			if (tmp==0) {
				LM_CRIT("cfg. parser: bad ip address.\n");
				(yyval.strval)=0;
			} else {
				(yyval.strval)=pkg_malloc(strlen(tmp)+1);
				if ((yyval.strval)==0) {
					LM_CRIT("cfg. parser: out of memory.\n");
				} else {
					strncpy((yyval.strval), tmp, strlen(tmp)+1);
				}
			}
		}
	}
#line 5010 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 651 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.strval)=pkg_malloc(strlen((yyvsp[0].strval))+1);
		if ((yyval.strval)==0) {
				LM_CRIT("cfg. parser: out of memory.\n");
		} else {
				strncpy((yyval.strval), (yyvsp[0].strval), strlen((yyvsp[0].strval))+1);
		}
	}
#line 5023 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 659 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[0].strval)){
			(yyval.strval)=pkg_malloc(strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
					LM_CRIT("cfg. parser: out of memory.\n");
			} else {
					strncpy((yyval.strval), (yyvsp[0].strval), strlen((yyvsp[0].strval))+1);
			}
		}
	}
#line 5038 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 673 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.name_l)=mk_name_lst((yyvsp[0].strval), SI_IS_MHOMED); }
#line 5044 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 674 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.name_l)=mk_name_lst((yyvsp[-2].strval), SI_IS_MHOMED);
										if ((yyval.name_l)) (yyval.name_l)->next=(yyvsp[0].name_l);
									}
#line 5052 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 680 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.name_l)=(yyvsp[-1].name_l); }
#line 5058 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 681 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.name_l)=mk_name_lst((yyvsp[0].strval), 0); }
#line 5064 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 685 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_UDP; }
#line 5070 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 686 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_TCP; }
#line 5076 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 687 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_TLS; }
#line 5082 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 688 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_SCTP; }
#line 5088 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 689 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=0; }
#line 5094 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 692 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_UDP; }
#line 5100 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 693 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_TCP; }
#line 5106 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 694 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_TLS; }
#line 5112 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 695 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_SCTP; }
#line 5118 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 696 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_WS; }
#line 5124 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 697 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_WSS; }
#line 5130 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 698 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=0; }
#line 5136 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 701 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=(yyvsp[0].intval); }
#line 5142 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 702 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=0; }
#line 5148 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 705 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=mk_listen_id((yyvsp[0].strval), 0, 0); }
#line 5154 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 706 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=mk_listen_id((yyvsp[-2].strval), 0, (yyvsp[0].intval)); }
#line 5160 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 707 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=mk_listen_id((yyvsp[0].strval), (yyvsp[-2].intval), 0); }
#line 5166 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 708 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=mk_listen_id((yyvsp[-2].strval), (yyvsp[-4].intval), (yyvsp[0].intval));}
#line 5172 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 709 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=0; yyerror("port number expected"); }
#line 5178 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 713 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=mk_listen_id2((yyvsp[0].name_l), 0, 0); }
#line 5184 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 714 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=mk_listen_id2((yyvsp[-2].name_l), 0, (yyvsp[0].intval)); }
#line 5190 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 715 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=mk_listen_id2((yyvsp[0].name_l), (yyvsp[-2].intval), 0); }
#line 5196 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 716 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=mk_listen_id2((yyvsp[-2].name_l), (yyvsp[-4].intval), (yyvsp[0].intval));}
#line 5202 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 717 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=0; yyerror("port number expected"); }
#line 5208 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 721 "core/cfg.y" /* yacc.c:1646  */
    {  (yyval.sockid)=(yyvsp[0].sockid) ; }
#line 5214 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 722 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=(yyvsp[-1].sockid);  if ((yyval.sockid)) (yyval.sockid)->next=(yyvsp[0].sockid); }
#line 5220 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 726 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=-(yyvsp[0].intval); }
#line 5226 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 730 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("flag list expected\n"); }
#line 5232 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 736 "core/cfg.y" /* yacc.c:1646  */
    { if (register_flag((yyvsp[0].strval),-1)<0)
								yyerror("register flag failed");
						}
#line 5240 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 739 "core/cfg.y" /* yacc.c:1646  */
    {
						if (register_flag((yyvsp[-2].strval), (yyvsp[0].intval))<0)
								yyerror("register flag failed");
										}
#line 5249 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 745 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)=(yyvsp[0].strval); }
#line 5255 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 746 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)=(yyvsp[0].strval); }
#line 5261 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 751 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("avpflag list expected\n"); }
#line 5267 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 758 "core/cfg.y" /* yacc.c:1646  */
    {
		if (register_avpflag((yyvsp[0].strval))==0)
			yyerror("cannot declare avpflag");
	}
#line 5276 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 764 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.debug=(yyvsp[0].intval); }
#line 5282 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 765 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number  expected"); }
#line 5288 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 766 "core/cfg.y" /* yacc.c:1646  */
    { dont_fork= ! (yyvsp[0].intval); }
#line 5294 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 767 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5300 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 768 "core/cfg.y" /* yacc.c:1646  */
    { set_fork_delay((yyvsp[0].intval)); }
#line 5306 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 769 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5312 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 770 "core/cfg.y" /* yacc.c:1646  */
    { set_modinit_delay((yyvsp[0].intval)); }
#line 5318 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 771 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5324 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 772 "core/cfg.y" /* yacc.c:1646  */
    { if (!config_check)  /* if set from cmd line, don't overwrite from yyparse()*/
					if(log_stderr == 0) log_stderr=(yyvsp[0].intval);
				   }
#line 5332 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 775 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5338 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 776 "core/cfg.y" /* yacc.c:1646  */
    {
		if ( (i_tmp=str2facility((yyvsp[0].strval)))==-1)
			yyerror("bad facility (see syslog(3) man page)");
		if (!config_check)
			default_core_cfg.log_facility=i_tmp;
	}
#line 5349 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 782 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("ID expected"); }
#line 5355 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 783 "core/cfg.y" /* yacc.c:1646  */
    { log_name=(yyvsp[0].strval); }
#line 5361 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 784 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 5367 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 785 "core/cfg.y" /* yacc.c:1646  */
    { log_color=(yyvsp[0].intval); }
#line 5373 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 786 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5379 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 787 "core/cfg.y" /* yacc.c:1646  */
    { log_prefix_fmt=(yyvsp[0].strval); }
#line 5385 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 788 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 5391 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 789 "core/cfg.y" /* yacc.c:1646  */
    { log_prefix_mode=(yyvsp[0].intval); }
#line 5397 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 790 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5403 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 791 "core/cfg.y" /* yacc.c:1646  */
    { _km_log_engine_type=(yyvsp[0].strval); }
#line 5409 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 792 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 5415 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 793 "core/cfg.y" /* yacc.c:1646  */
    { _km_log_engine_data=(yyvsp[0].strval); }
#line 5421 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 794 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 5427 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 795 "core/cfg.y" /* yacc.c:1646  */
    { received_dns|= ((yyvsp[0].intval))?DO_DNS:0; }
#line 5433 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 796 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5439 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 797 "core/cfg.y" /* yacc.c:1646  */
    { received_dns|= ((yyvsp[0].intval))?DO_REV_DNS:0; }
#line 5445 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 798 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5451 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 799 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.dns_try_ipv6=(yyvsp[0].intval); }
#line 5457 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 800 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5463 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 801 "core/cfg.y" /* yacc.c:1646  */
    { IF_NAPTR(default_core_cfg.dns_try_naptr=(yyvsp[0].intval)); }
#line 5469 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 802 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5475 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 803 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_FAILOVER(default_core_cfg.dns_srv_lb=(yyvsp[0].intval)); }
#line 5481 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 804 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5487 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 805 "core/cfg.y" /* yacc.c:1646  */
    { IF_NAPTR(default_core_cfg.dns_udp_pref=(yyvsp[0].intval));}
#line 5493 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 806 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5499 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 807 "core/cfg.y" /* yacc.c:1646  */
    { IF_NAPTR(default_core_cfg.dns_tcp_pref=(yyvsp[0].intval));}
#line 5505 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 808 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5511 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 809 "core/cfg.y" /* yacc.c:1646  */
    { IF_NAPTR(default_core_cfg.dns_tls_pref=(yyvsp[0].intval));}
#line 5517 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 810 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5523 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 811 "core/cfg.y" /* yacc.c:1646  */
    {
								IF_NAPTR(default_core_cfg.dns_sctp_pref=(yyvsp[0].intval)); }
#line 5530 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 813 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5536 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 814 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.dns_retr_time=(yyvsp[0].intval); }
#line 5542 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 815 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5548 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 816 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.dns_retr_no=(yyvsp[0].intval); }
#line 5554 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 817 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5560 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 818 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.dns_servers_no=(yyvsp[0].intval); }
#line 5566 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 819 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5572 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 820 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.dns_search_list=(yyvsp[0].intval); }
#line 5578 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 821 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5584 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 822 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.dns_search_fmatch=(yyvsp[0].intval); }
#line 5590 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 823 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5596 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 824 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.dns_naptr_ignore_rfc=(yyvsp[0].intval); }
#line 5602 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 825 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5608 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 826 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(dns_cache_init=(yyvsp[0].intval)); }
#line 5614 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 827 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5620 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 828 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(default_core_cfg.use_dns_cache=(yyvsp[0].intval)); }
#line 5626 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 829 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5632 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 830 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_FAILOVER(default_core_cfg.use_dns_failover=(yyvsp[0].intval));}
#line 5638 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 831 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5644 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 832 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(default_core_cfg.dns_cache_flags=(yyvsp[0].intval)); }
#line 5650 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 833 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5656 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 834 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(default_core_cfg.dns_neg_cache_ttl=(yyvsp[0].intval)); }
#line 5662 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 835 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5668 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 836 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(default_core_cfg.dns_cache_max_ttl=(yyvsp[0].intval)); }
#line 5674 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 837 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5680 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 838 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(default_core_cfg.dns_cache_min_ttl=(yyvsp[0].intval)); }
#line 5686 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 839 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5692 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 840 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(default_core_cfg.dns_cache_max_mem=(yyvsp[0].intval)); }
#line 5698 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 841 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5704 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 842 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(dns_timer_interval=(yyvsp[0].intval)); }
#line 5710 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 843 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5716 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 844 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(default_core_cfg.dns_cache_del_nonexp=(yyvsp[0].intval)); }
#line 5722 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 845 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5728 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 846 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(default_core_cfg.dns_cache_rec_pref=(yyvsp[0].intval)); }
#line 5734 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 847 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5740 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 848 "core/cfg.y" /* yacc.c:1646  */
    {IF_AUTO_BIND_IPV6(auto_bind_ipv6 = (yyvsp[0].intval));}
#line 5746 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 849 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5752 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 850 "core/cfg.y" /* yacc.c:1646  */
    { IF_DST_BLACKLIST(dst_blacklist_init=(yyvsp[0].intval)); }
#line 5758 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 851 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5764 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 852 "core/cfg.y" /* yacc.c:1646  */
    {
		IF_DST_BLACKLIST(default_core_cfg.use_dst_blacklist=(yyvsp[0].intval));
	}
#line 5772 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 855 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5778 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 856 "core/cfg.y" /* yacc.c:1646  */
    {
		IF_DST_BLACKLIST(default_core_cfg.blst_max_mem=(yyvsp[0].intval));
	}
#line 5786 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 859 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5792 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 860 "core/cfg.y" /* yacc.c:1646  */
    {
		IF_DST_BLACKLIST(default_core_cfg.blst_timeout=(yyvsp[0].intval));
	}
#line 5800 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 863 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5806 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 864 "core/cfg.y" /* yacc.c:1646  */
    { IF_DST_BLACKLIST(blst_timer_interval=(yyvsp[0].intval));}
#line 5812 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 865 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5818 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 866 "core/cfg.y" /* yacc.c:1646  */
    {
		IF_DST_BLACKLIST(default_core_cfg.blst_udp_imask=(yyvsp[0].intval));
	}
#line 5826 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 869 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number(flags) expected"); }
#line 5832 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 870 "core/cfg.y" /* yacc.c:1646  */
    {
		IF_DST_BLACKLIST(default_core_cfg.blst_tcp_imask=(yyvsp[0].intval));
	}
#line 5840 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 873 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number(flags) expected"); }
#line 5846 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 874 "core/cfg.y" /* yacc.c:1646  */
    {
		IF_DST_BLACKLIST(default_core_cfg.blst_tls_imask=(yyvsp[0].intval));
	}
#line 5854 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 877 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number(flags) expected"); }
#line 5860 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 878 "core/cfg.y" /* yacc.c:1646  */
    {
		IF_DST_BLACKLIST(default_core_cfg.blst_sctp_imask=(yyvsp[0].intval));
	}
#line 5868 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 881 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number(flags) expected"); }
#line 5874 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 882 "core/cfg.y" /* yacc.c:1646  */
    { _sr_ip_free_bind=(yyvsp[0].intval); }
#line 5880 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 883 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 5886 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 884 "core/cfg.y" /* yacc.c:1646  */
    { port_no=(yyvsp[0].intval); }
#line 5892 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 885 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef STATS
				stat_file=(yyvsp[0].strval);
		#endif
	}
#line 5902 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 890 "core/cfg.y" /* yacc.c:1646  */
    { maxbuffer=(yyvsp[0].intval); }
#line 5908 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 891 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5914 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 892 "core/cfg.y" /* yacc.c:1646  */
    { sql_buffer_size=(yyvsp[0].intval); }
#line 5920 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 893 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5926 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 894 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5932 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 895 "core/cfg.y" /* yacc.c:1646  */
    { children_no=(yyvsp[0].intval); }
#line 5938 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 896 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5944 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 897 "core/cfg.y" /* yacc.c:1646  */
    { socket_workers=(yyvsp[0].intval); }
#line 5950 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 898 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5956 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 899 "core/cfg.y" /* yacc.c:1646  */
    { async_task_set_workers((yyvsp[0].intval)); }
#line 5962 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 900 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5968 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 901 "core/cfg.y" /* yacc.c:1646  */
    { async_task_set_usleep((yyvsp[0].intval)); }
#line 5974 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 902 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5980 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 903 "core/cfg.y" /* yacc.c:1646  */
    { check_via=(yyvsp[0].intval); }
#line 5986 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 904 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5992 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 905 "core/cfg.y" /* yacc.c:1646  */
    { phone2tel=(yyvsp[0].intval); }
#line 5998 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 906 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6004 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 907 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.memlog=(yyvsp[0].intval); }
#line 6010 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 908 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 6016 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 909 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.memdbg=(yyvsp[0].intval); }
#line 6022 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 910 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 6028 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 911 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.mem_summary=(yyvsp[0].intval); }
#line 6034 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 912 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 6040 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 913 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.mem_safety=(yyvsp[0].intval); }
#line 6046 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 914 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 6052 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 915 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.mem_join=(yyvsp[0].intval); }
#line 6058 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 916 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 6064 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 917 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.mem_status_mode=(yyvsp[0].intval); }
#line 6070 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 918 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 6076 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 919 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.corelog=(yyvsp[0].intval); }
#line 6082 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 920 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 6088 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 921 "core/cfg.y" /* yacc.c:1646  */
    { sip_warning=(yyvsp[0].intval); }
#line 6094 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 922 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6100 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 923 "core/cfg.y" /* yacc.c:1646  */
    { version_table.s=(yyvsp[0].strval);
			version_table.len=strlen(version_table.s);
	}
#line 6108 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 926 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 6114 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 927 "core/cfg.y" /* yacc.c:1646  */
    {
		if (shm_initialized())
			yyerror("user must be before any modparam or the"
					" route blocks");
		else if (user==0)
			user=(yyvsp[0].strval);
	}
#line 6126 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 934 "core/cfg.y" /* yacc.c:1646  */
    {
		if (shm_initialized())
			yyerror("user must be before any modparam or the"
					" route blocks");
		else if (user==0)
			user=(yyvsp[0].strval);
	}
#line 6138 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 941 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 6144 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 942 "core/cfg.y" /* yacc.c:1646  */
    { group=(yyvsp[0].strval); }
#line 6150 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 943 "core/cfg.y" /* yacc.c:1646  */
    { group=(yyvsp[0].strval); }
#line 6156 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 944 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 6162 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 945 "core/cfg.y" /* yacc.c:1646  */
    { chroot_dir=(yyvsp[0].strval); }
#line 6168 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 946 "core/cfg.y" /* yacc.c:1646  */
    { chroot_dir=(yyvsp[0].strval); }
#line 6174 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 947 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 6180 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 948 "core/cfg.y" /* yacc.c:1646  */
    { working_dir=(yyvsp[0].strval); }
#line 6186 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 949 "core/cfg.y" /* yacc.c:1646  */
    { working_dir=(yyvsp[0].strval); }
#line 6192 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 950 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 6198 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 951 "core/cfg.y" /* yacc.c:1646  */
    { runtime_dir=(yyvsp[0].strval); }
#line 6204 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 952 "core/cfg.y" /* yacc.c:1646  */
    { runtime_dir=(yyvsp[0].strval); }
#line 6210 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 953 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 6216 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 954 "core/cfg.y" /* yacc.c:1646  */
    { mhomed=(yyvsp[0].intval); }
#line 6222 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 955 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6228 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 956 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_disable=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6240 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 963 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6246 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 964 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.accept_aliases=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6258 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 971 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6264 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 972 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_cfg_children_no=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6276 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 979 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6282 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 980 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.connect_timeout_s=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6294 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 987 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6300 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 988 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.send_timeout=S_TO_TICKS((yyvsp[0].intval));
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6312 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 995 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6318 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 996 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			if ((yyvsp[0].intval)<0)
				tcp_default_cfg.con_lifetime=-1;
			else
				tcp_default_cfg.con_lifetime=S_TO_TICKS((yyvsp[0].intval));
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6333 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1006 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6339 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1007 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_poll_method=get_poll_type((yyvsp[0].strval));
			if (tcp_poll_method==POLL_NONE) {
				LOG(L_CRIT, "bad poll method name:"
						" %s\n, try one of %s.\n",
						(yyvsp[0].strval), poll_support);
				yyerror("bad tcp_poll_method "
						"value");
			}
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6358 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1021 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_poll_method=get_poll_type((yyvsp[0].strval));
			if (tcp_poll_method==POLL_NONE) {
				LOG(L_CRIT, "bad poll method name:"
						" %s\n, try one of %s.\n",
						(yyvsp[0].strval), poll_support);
				yyerror("bad tcp_poll_method "
						"value");
			}
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6377 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1035 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("poll method name expected"); }
#line 6383 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1036 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_max_connections=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6395 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1043 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6401 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1044 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			tls_max_connections=(yyvsp[0].intval);
		#else
			warn("tls support not compiled in");
		#endif
	}
#line 6413 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1051 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6419 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1052 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.no_connect=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6431 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1059 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6437 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1060 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			if (tcp_set_src_addr((yyvsp[0].ipaddr))<0)
				warn("tcp_source_ipv4 failed");
		#else
			warn("tcp support not compiled in");
		#endif
		pkg_free((yyvsp[0].ipaddr));
	}
#line 6451 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1069 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("IPv4 address expected"); }
#line 6457 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1070 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
				if (tcp_set_src_addr((yyvsp[0].ipaddr))<0)
					warn("tcp_source_ipv6 failed");
		#else
			warn("tcp support not compiled in");
		#endif
		pkg_free((yyvsp[0].ipaddr));
	}
#line 6471 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1079 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("IPv6 address expected"); }
#line 6477 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1080 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.fd_cache=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6489 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1087 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6495 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1088 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.async=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6507 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1095 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6513 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1096 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.tcpconn_wq_max=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6525 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1103 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6531 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1104 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.tcp_wq_max=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6543 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1111 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6549 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1112 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.rd_buf_size=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6561 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1119 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6567 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1120 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.wq_blk_size=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6579 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1127 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6585 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1128 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.defer_accept=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6597 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1135 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6603 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1136 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.delayed_ack=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6615 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1143 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6621 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1144 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.syncnt=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6633 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1151 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6639 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1152 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.linger2=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6651 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1159 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6657 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1160 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.keepalive=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6669 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1167 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected");}
#line 6675 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1168 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.keepidle=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6687 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1175 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6693 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1176 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.keepintvl=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6705 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1183 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6711 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1184 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.keepcnt=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6723 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1191 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6729 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1192 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.crlf_ping=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6741 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1199 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6747 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1200 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.accept_no_cl=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6759 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1207 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6765 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1208 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			ksr_tcp_accept_hep3=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6777 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1215 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6783 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1217 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_set_clone_rcvbuf((yyvsp[0].intval));
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6795 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1224 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6801 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1225 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
		#ifdef SO_REUSEPORT
			tcp_default_cfg.reuse_port=(yyvsp[0].intval);
		#else
			warn("support for SO_REUSEPORT not compiled in");
		#endif
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6817 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1236 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6823 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1237 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			tls_disable=(yyvsp[0].intval);
		#else
			warn("tls support not compiled in");
		#endif
	}
#line 6835 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1244 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6841 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1245 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			tls_disable=!((yyvsp[0].intval));
		#else
			warn("tls support not compiled in");
		#endif
	}
#line 6853 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1252 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6859 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1253 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_log=(yyvsp[0].intval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 6871 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1260 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 6877 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1261 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			tls_port_no=(yyvsp[0].intval);
		#else
			warn("tls support not compiled in");
		#endif
	}
#line 6889 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1268 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6895 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1269 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_method=TLS_USE_SSLv23;
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 6907 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1276 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_method=TLS_USE_SSLv2;
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 6919 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1283 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_method=TLS_USE_SSLv3;
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 6931 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1290 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_method=TLS_USE_TLSv1;
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 6943 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1297 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			yyerror("SSLv23, SSLv2, SSLv3 or TLSv1 expected");
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 6955 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1304 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_verify_cert=(yyvsp[0].intval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 6967 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1311 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6973 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1312 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_require_cert=(yyvsp[0].intval);
		#else
			warn( "tls-in-core support not compiled in");
		#endif
	}
#line 6985 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1319 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6991 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1320 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_cert_file=(yyvsp[0].strval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7003 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1327 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 7009 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1328 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_pkey_file=(yyvsp[0].strval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7021 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1335 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 7027 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1336 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_ca_file=(yyvsp[0].strval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7039 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1343 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 7045 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1344 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_handshake_timeout=(yyvsp[0].intval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7057 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1351 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7063 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1352 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_send_timeout=(yyvsp[0].intval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7075 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1359 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7081 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1360 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			sctp_disable=(yyvsp[0].intval);
		#else
			warn("sctp support not compiled in");
		#endif
	}
#line 7093 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1367 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7099 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1368 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			sctp_disable=((yyvsp[0].intval)<=1)?!(yyvsp[0].intval):(yyvsp[0].intval);
		#else
			warn("sctp support not compiled in");
		#endif
	}
#line 7111 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1375 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean or number expected"); }
#line 7117 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1376 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			sctp_children_no=(yyvsp[0].intval);
		#else
			warn("sctp support not compiled in");
		#endif
	}
#line 7129 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1383 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7135 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1384 "core/cfg.y" /* yacc.c:1646  */
    { server_signature=(yyvsp[0].intval); }
#line 7141 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1385 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7147 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1386 "core/cfg.y" /* yacc.c:1646  */
    { server_hdr.s=(yyvsp[0].strval);
			server_hdr.len=strlen(server_hdr.s);
	}
#line 7155 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1389 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 7161 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1390 "core/cfg.y" /* yacc.c:1646  */
    { user_agent_hdr.s=(yyvsp[0].strval);
			user_agent_hdr.len=strlen(user_agent_hdr.s);
	}
#line 7169 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1393 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 7175 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1394 "core/cfg.y" /* yacc.c:1646  */
    { reply_to_via=(yyvsp[0].intval); }
#line 7181 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1395 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7187 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1396 "core/cfg.y" /* yacc.c:1646  */
    {
		for(lst_tmp=(yyvsp[0].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			if (add_listen_iface(	lst_tmp->addr_lst->name,
									lst_tmp->addr_lst->next,
									lst_tmp->port, lst_tmp->proto,
									lst_tmp->flags)!=0) {
				LM_CRIT("cfg. parser: failed to add listen address\n");
				break;
			}
		}
		free_socket_id_lst((yyvsp[0].sockid));
	}
#line 7204 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1408 "core/cfg.y" /* yacc.c:1646  */
    {
		for(lst_tmp=(yyvsp[-4].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			if (add_listen_advertise_iface(	lst_tmp->addr_lst->name,
									lst_tmp->addr_lst->next,
									lst_tmp->port, lst_tmp->proto,
									(yyvsp[-2].strval), (yyvsp[0].intval),
									lst_tmp->flags)!=0) {
				LM_CRIT("cfg. parser: failed to add listen address\n");
				break;
			}
		}
		free_socket_id_lst((yyvsp[-4].sockid));
	}
#line 7222 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1421 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("ip address, interface name or"
									" hostname expected"); }
#line 7229 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1423 "core/cfg.y" /* yacc.c:1646  */
    {
		for(lst_tmp=(yyvsp[0].sockid); lst_tmp; lst_tmp=lst_tmp->next){
			add_alias(	lst_tmp->addr_lst->name,
						strlen(lst_tmp->addr_lst->name),
						lst_tmp->port, lst_tmp->proto);
			for (nl_tmp=lst_tmp->addr_lst->next; nl_tmp; nl_tmp=nl_tmp->next)
				add_alias(nl_tmp->name, strlen(nl_tmp->name),
							lst_tmp->port, lst_tmp->proto);
		}
		free_socket_id_lst((yyvsp[0].sockid));
	}
#line 7245 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1434 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("hostname expected"); }
#line 7251 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1435 "core/cfg.y" /* yacc.c:1646  */
    { sr_auto_aliases=(yyvsp[0].intval); }
#line 7257 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1436 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7263 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1437 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[0].strval)){
			default_global_address.s=(yyvsp[0].strval);
			default_global_address.len=strlen((yyvsp[0].strval));
		}
	}
#line 7274 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1443 "core/cfg.y" /* yacc.c:1646  */
    {yyerror("ip address or hostname expected"); }
#line 7280 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1444 "core/cfg.y" /* yacc.c:1646  */
    {
		tmp=int2str((yyvsp[0].intval), &i_tmp);
		if ((default_global_port.s=pkg_malloc(i_tmp))==0) {
			LM_CRIT("cfg. parser: out of memory.\n");
			default_global_port.len=0;
		} else {
			default_global_port.len=i_tmp;
			memcpy(default_global_port.s, tmp, default_global_port.len);
		};
	}
#line 7295 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1454 "core/cfg.y" /* yacc.c:1646  */
    {yyerror("ip address or hostname expected"); }
#line 7301 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1455 "core/cfg.y" /* yacc.c:1646  */
    { disable_core_dump=(yyvsp[0].intval); }
#line 7307 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1456 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7313 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1457 "core/cfg.y" /* yacc.c:1646  */
    { open_files_limit=(yyvsp[0].intval); }
#line 7319 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1458 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7325 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1459 "core/cfg.y" /* yacc.c:1646  */
    {
		if (shm_initialized())
			yyerror("shm/shm_mem_size must be before any modparam or the"
					" route blocks");
		else if (shm_mem_size == 0 || shm_mem_size == SHM_MEM_POOL_SIZE)
			shm_mem_size=(yyvsp[0].intval) * 1024 * 1024;
	}
#line 7337 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1466 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7343 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1467 "core/cfg.y" /* yacc.c:1646  */
    {
		if (shm_initialized())
			yyerror("shm_force_alloc must be before any modparam or the"
					" route blocks");
		else
			shm_force_alloc=(yyvsp[0].intval);
	}
#line 7355 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1474 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7361 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1475 "core/cfg.y" /* yacc.c:1646  */
    { mlock_pages=(yyvsp[0].intval); }
#line 7367 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1476 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7373 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1477 "core/cfg.y" /* yacc.c:1646  */
    { real_time=(yyvsp[0].intval); }
#line 7379 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1478 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7385 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1479 "core/cfg.y" /* yacc.c:1646  */
    { rt_prio=(yyvsp[0].intval); }
#line 7391 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1480 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7397 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1481 "core/cfg.y" /* yacc.c:1646  */
    { rt_policy=(yyvsp[0].intval); }
#line 7403 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1482 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7409 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1483 "core/cfg.y" /* yacc.c:1646  */
    { rt_timer1_prio=(yyvsp[0].intval); }
#line 7415 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1484 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7421 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1485 "core/cfg.y" /* yacc.c:1646  */
    { rt_timer1_policy=(yyvsp[0].intval); }
#line 7427 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1486 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7433 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1487 "core/cfg.y" /* yacc.c:1646  */
    { rt_timer2_prio=(yyvsp[0].intval); }
#line 7439 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1488 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7445 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1489 "core/cfg.y" /* yacc.c:1646  */
    { rt_timer2_policy=(yyvsp[0].intval); }
#line 7451 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1490 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7457 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1491 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_MCAST
			mcast_loopback=(yyvsp[0].intval);
		#else
			warn("no multicast support compiled in");
		#endif
	}
#line 7469 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1498 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7475 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1499 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_MCAST
			mcast_ttl=(yyvsp[0].intval);
		#else
			warn("no multicast support compiled in");
		#endif
	}
#line 7487 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1506 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7493 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1507 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_MCAST
			mcast=(yyvsp[0].strval);
		#else
			warn("no multicast support compiled in");
		#endif
	}
#line 7505 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1514 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_MCAST
			mcast=(yyvsp[0].strval);
		#else
			warn("no multicast support compiled in");
		#endif
	}
#line 7517 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 369:
#line 1521 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string expected"); }
#line 7523 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1522 "core/cfg.y" /* yacc.c:1646  */
    { tos=(yyvsp[0].intval); }
#line 7529 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 371:
#line 1523 "core/cfg.y" /* yacc.c:1646  */
    { if (strcasecmp((yyvsp[0].strval),"IPTOS_LOWDELAY")) {
			tos=IPTOS_LOWDELAY;
		} else if (strcasecmp((yyvsp[0].strval),"IPTOS_THROUGHPUT")) {
			tos=IPTOS_THROUGHPUT;
		} else if (strcasecmp((yyvsp[0].strval),"IPTOS_RELIABILITY")) {
			tos=IPTOS_RELIABILITY;
#if defined(IPTOS_MINCOST)
		} else if (strcasecmp((yyvsp[0].strval),"IPTOS_MINCOST")) {
			tos=IPTOS_MINCOST;
#endif
#if defined(IPTOS_LOWCOST)
		} else if (strcasecmp((yyvsp[0].strval),"IPTOS_LOWCOST")) {
			tos=IPTOS_LOWCOST;
#endif
		} else {
			yyerror("invalid tos value - allowed: "
				"IPTOS_LOWDELAY,IPTOS_THROUGHPUT,"
				"IPTOS_RELIABILITY"
#if defined(IPTOS_LOWCOST)
				",IPTOS_LOWCOST"
#endif
#if !defined(IPTOS_MINCOST)
				",IPTOS_MINCOST"
#endif
				"\n");
		}
	}
#line 7561 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1550 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7567 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1551 "core/cfg.y" /* yacc.c:1646  */
    { pmtu_discovery=(yyvsp[0].intval); }
#line 7573 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1552 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7579 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1553 "core/cfg.y" /* yacc.c:1646  */
    { ser_kill_timeout=(yyvsp[0].intval); }
#line 7585 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1554 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7591 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 377:
#line 1555 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.max_while_loops=(yyvsp[0].intval); }
#line 7597 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1556 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7603 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1557 "core/cfg.y" /* yacc.c:1646  */
    { pv_set_buffer_size((yyvsp[0].intval)); }
#line 7609 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1558 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7615 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1559 "core/cfg.y" /* yacc.c:1646  */
    { pv_set_buffer_slots((yyvsp[0].intval)); }
#line 7621 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1560 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7627 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1561 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.pv_cache_limit=(yyvsp[0].intval); }
#line 7633 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1562 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7639 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1563 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.pv_cache_action=(yyvsp[0].intval); }
#line 7645 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1564 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7651 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1565 "core/cfg.y" /* yacc.c:1646  */
    { http_reply_parse=(yyvsp[0].intval); }
#line 7657 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1566 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7663 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 389:
#line 1567 "core/cfg.y" /* yacc.c:1646  */
    { ksr_verbose_startup=(yyvsp[0].intval); }
#line 7669 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 390:
#line 1568 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7675 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 391:
#line 1569 "core/cfg.y" /* yacc.c:1646  */
    { server_id=(yyvsp[0].intval); }
#line 7681 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 392:
#line 1570 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number  expected"); }
#line 7687 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 393:
#line 1571 "core/cfg.y" /* yacc.c:1646  */
    { set_max_recursive_level((yyvsp[0].intval)); }
#line 7693 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 394:
#line 1572 "core/cfg.y" /* yacc.c:1646  */
    { sr_dst_max_branches = (yyvsp[0].intval); }
#line 7699 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 395:
#line 1573 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.latency_log=(yyvsp[0].intval); }
#line 7705 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 396:
#line 1574 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number  expected"); }
#line 7711 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 397:
#line 1575 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.latency_cfg_log=(yyvsp[0].intval); }
#line 7717 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 398:
#line 1576 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number  expected"); }
#line 7723 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 399:
#line 1577 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.latency_limit_db=(yyvsp[0].intval); }
#line 7729 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 400:
#line 1578 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number  expected"); }
#line 7735 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 401:
#line 1579 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.latency_limit_action=(yyvsp[0].intval); }
#line 7741 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 402:
#line 1580 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number  expected"); }
#line 7747 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 403:
#line 1581 "core/cfg.y" /* yacc.c:1646  */
    { sr_msg_time=(yyvsp[0].intval); }
#line 7753 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 404:
#line 1582 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number  expected"); }
#line 7759 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 405:
#line 1583 "core/cfg.y" /* yacc.c:1646  */
    { onsend_route_reply=(yyvsp[0].intval); }
#line 7765 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 406:
#line 1584 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 7771 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 407:
#line 1585 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.udp_mtu=(yyvsp[0].intval); }
#line 7777 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 408:
#line 1586 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7783 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 409:
#line 1588 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.force_rport=(yyvsp[0].intval); fix_global_req_flags(0, 0); }
#line 7789 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 410:
#line 1589 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7795 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 411:
#line 1591 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.udp_mtu_try_proto=(yyvsp[0].intval); fix_global_req_flags(0, 0); }
#line 7801 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 412:
#line 1593 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("TCP, TLS, SCTP or UDP expected"); }
#line 7807 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 413:
#line 1594 "core/cfg.y" /* yacc.c:1646  */
    { IF_RAW_SOCKS(default_core_cfg.udp4_raw=(yyvsp[0].intval)); }
#line 7813 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 414:
#line 1595 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7819 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 415:
#line 1596 "core/cfg.y" /* yacc.c:1646  */
    {
		IF_RAW_SOCKS(default_core_cfg.udp4_raw_mtu=(yyvsp[0].intval));
	}
#line 7827 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 416:
#line 1599 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7833 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 417:
#line 1600 "core/cfg.y" /* yacc.c:1646  */
    {
		IF_RAW_SOCKS(default_core_cfg.udp4_raw_ttl=(yyvsp[0].intval));
	}
#line 7841 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 418:
#line 1603 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7847 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 420:
#line 1605 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("unknown config variable"); }
#line 7853 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 422:
#line 1609 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)="default" ; }
#line 7859 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 424:
#line 1613 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)="default" ; }
#line 7865 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 425:
#line 1614 "core/cfg.y" /* yacc.c:1646  */
    {
		yyerror("cfg var field name - use of number or reserved token not allowed: %s",
				yy_number_str);
		YYERROR;
	}
#line 7875 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 426:
#line 1622 "core/cfg.y" /* yacc.c:1646  */
    {
		if (cfg_declare_int((yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[0].intval), 0, 0, NULL)) {
			yyerror("variable cannot be declared");
		}
	}
#line 7885 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 427:
#line 1627 "core/cfg.y" /* yacc.c:1646  */
    {
		if (cfg_declare_str((yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[0].strval), NULL)) {
			yyerror("variable cannot be declared");
		}
	}
#line 7895 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 428:
#line 1632 "core/cfg.y" /* yacc.c:1646  */
    {
		if (cfg_declare_int((yyvsp[-6].strval), (yyvsp[-4].strval), (yyvsp[-2].intval), 0, 0, (yyvsp[0].strval))) {
			yyerror("variable cannot be declared");
		}
	}
#line 7905 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 429:
#line 1637 "core/cfg.y" /* yacc.c:1646  */
    {
		if (cfg_declare_str((yyvsp[-6].strval), (yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[0].strval))) {
			yyerror("variable cannot be declared");
		}
	}
#line 7915 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 430:
#line 1642 "core/cfg.y" /* yacc.c:1646  */
    {
		yyerror("number or string expected");
	}
#line 7923 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 431:
#line 1645 "core/cfg.y" /* yacc.c:1646  */
    {
		if (cfg_ginst_var_int((yyvsp[-7].strval), (yyvsp[-5].intval), (yyvsp[-2].strval), (yyvsp[0].intval))) {
			yyerror("variable cannot be added to the group instance");
		}
	}
#line 7933 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 432:
#line 1650 "core/cfg.y" /* yacc.c:1646  */
    {
		if (cfg_ginst_var_string((yyvsp[-7].strval), (yyvsp[-5].intval), (yyvsp[-2].strval), (yyvsp[0].strval))) {
			yyerror("variable cannot be added to the group instance");
		}
	}
#line 7943 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 433:
#line 1658 "core/cfg.y" /* yacc.c:1646  */
    {
		LM_DBG("loading module %s\n", (yyvsp[0].strval));
			if (load_module((yyvsp[0].strval))!=0) {
				yyerror("failed to load module");
			}
	}
#line 7954 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 434:
#line 1664 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string expected"); }
#line 7960 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 435:
#line 1665 "core/cfg.y" /* yacc.c:1646  */
    {
		if(mods_dir_cmd==0) {
			LM_DBG("loading modules under %s\n", (yyvsp[0].strval));
			printf("loading modules under config path: %s\n", (yyvsp[0].strval));
			mods_dir = (yyvsp[0].strval);
		} else {
			LM_DBG("ignoring mod path given in config: %s\n", (yyvsp[0].strval));
			printf("loading modules under command line path: %s\n", mods_dir);
		}
	}
#line 7975 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 436:
#line 1675 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string expected"); }
#line 7981 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 437:
#line 1676 "core/cfg.y" /* yacc.c:1646  */
    {
		if(mods_dir_cmd==0) {
			LM_DBG("loading modules under %s\n", (yyvsp[0].strval));
			printf("loading modules under config path: %s\n", (yyvsp[0].strval));
			mods_dir = (yyvsp[0].strval);
		} else {
			LM_DBG("ignoring mod path given in config: %s\n", (yyvsp[0].strval));
			printf("loading modules under command line path: %s\n", mods_dir);
		}
	}
#line 7996 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 438:
#line 1686 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string expected"); }
#line 8002 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 439:
#line 1687 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		if (set_mod_param_regex((yyvsp[-5].strval), (yyvsp[-3].strval), PARAM_STRING, (yyvsp[-1].strval)) != 0) {
			 yyerror("Can't set module parameter");
		}
	}
#line 8018 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 440:
#line 1698 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		if (set_mod_param_regex((yyvsp[-5].strval), (yyvsp[-3].strval), PARAM_INT, (void*)(yyvsp[-1].intval)) != 0) {
			 yyerror("Can't set module parameter");
		}
	}
#line 8034 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 441:
#line 1709 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("Invalid arguments"); }
#line 8040 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 442:
#line 1710 "core/cfg.y" /* yacc.c:1646  */
    {
		if(sr_kemi_eng_setz((yyvsp[0].strval), NULL)) {
			yyerror("Can't set config routing engine");
			YYABORT;
		}
	}
#line 8051 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 443:
#line 1716 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string expected"); }
#line 8057 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 444:
#line 1717 "core/cfg.y" /* yacc.c:1646  */
    {
		if(sr_kemi_eng_setz((yyvsp[0].strval), NULL)) {
			yyerror("Can't set config routing engine");
			YYABORT;
		}
	}
#line 8068 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 445:
#line 1723 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string expected"); }
#line 8074 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 446:
#line 1727 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.ipaddr)=(yyvsp[0].ipaddr); }
#line 8080 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 447:
#line 1728 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.ipaddr)=(yyvsp[0].ipaddr); }
#line 8086 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 448:
#line 1731 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.ipaddr)=pkg_malloc(sizeof(struct ip_addr));
		if ((yyval.ipaddr)==0) {
			LM_CRIT("cfg. parser: out of memory.\n");
		} else {
			memset((yyval.ipaddr), 0, sizeof(struct ip_addr));
			(yyval.ipaddr)->af=AF_INET;
			(yyval.ipaddr)->len=4;
			if (((yyvsp[-6].intval)>255) || ((yyvsp[-6].intval)<0) ||
				((yyvsp[-4].intval)>255) || ((yyvsp[-4].intval)<0) ||
				((yyvsp[-2].intval)>255) || ((yyvsp[-2].intval)<0) ||
				((yyvsp[0].intval)>255) || ((yyvsp[0].intval)<0)) {
				yyerror("invalid ipv4 address");
				(yyval.ipaddr)->u.addr32[0]=0;
				/* $$=0; */
			} else {
				(yyval.ipaddr)->u.addr[0]=(yyvsp[-6].intval);
				(yyval.ipaddr)->u.addr[1]=(yyvsp[-4].intval);
				(yyval.ipaddr)->u.addr[2]=(yyvsp[-2].intval);
				(yyval.ipaddr)->u.addr[3]=(yyvsp[0].intval);
				/*
				$$=htonl( ($1<<24)|
				($3<<16)| ($5<<8)|$7 );
				*/
			}
		}
	}
#line 8118 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 449:
#line 1760 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.ipaddr)=pkg_malloc(sizeof(struct ip_addr));
		if ((yyval.ipaddr)==0) {
			LM_CRIT("cfg. parser: out of memory.\n");
		} else {
			memset((yyval.ipaddr), 0, sizeof(struct ip_addr));
			(yyval.ipaddr)->af=AF_INET6;
			(yyval.ipaddr)->len=16;
			if (inet_pton(AF_INET6, (yyvsp[0].strval), (yyval.ipaddr)->u.addr)<=0) {
				yyerror("bad ipv6 address");
			}
		}
	}
#line 8136 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 450:
#line 1775 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.ipaddr)=(yyvsp[0].ipaddr); }
#line 8142 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 451:
#line 1776 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.ipaddr)=(yyvsp[-1].ipaddr); }
#line 8148 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 452:
#line 1780 "core/cfg.y" /* yacc.c:1646  */
    {
					tmp=int2str((yyvsp[0].intval), &i_tmp);
					if (((yyval.strval)=pkg_malloc(i_tmp+1))==0) {
						yyerror("out of  memory");
						YYABORT;
					} else {
						memcpy((yyval.strval), tmp, i_tmp);
						(yyval.strval)[i_tmp]=0;
					}
					routename = tmp;
						}
#line 8164 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 453:
#line 1791 "core/cfg.y" /* yacc.c:1646  */
    { routename = (yyvsp[0].strval); (yyval.strval)=(yyvsp[0].strval); }
#line 8170 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 454:
#line 1792 "core/cfg.y" /* yacc.c:1646  */
    { routename = (yyvsp[0].strval); (yyval.strval)=(yyvsp[0].strval); }
#line 8176 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 455:
#line 1796 "core/cfg.y" /* yacc.c:1646  */
    { routename=NULL; }
#line 8182 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 456:
#line 1797 "core/cfg.y" /* yacc.c:1646  */
    { routename=NULL; }
#line 8188 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 457:
#line 1801 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		push((yyvsp[-1].action), &main_rt.rlist[DEFAULT_RT]);
	}
#line 8202 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 458:
#line 1810 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		i_tmp=route_get(&main_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (main_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &main_rt.rlist[i_tmp]);
	}
#line 8225 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 459:
#line 1828 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid  route  statement"); }
#line 8231 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 460:
#line 1829 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid  request_route  statement"); }
#line 8237 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 461:
#line 1832 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		push((yyvsp[-1].action), &failure_rt.rlist[DEFAULT_RT]);
	}
#line 8251 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 462:
#line 1841 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		i_tmp=route_get(&failure_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (failure_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &failure_rt.rlist[i_tmp]);
	}
#line 8274 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 463:
#line 1859 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid failure_route statement"); }
#line 8280 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 464:
#line 1863 "core/cfg.y" /* yacc.c:1646  */
    { routename=NULL; }
#line 8286 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 465:
#line 1864 "core/cfg.y" /* yacc.c:1646  */
    { routename=NULL; }
#line 8292 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 466:
#line 1869 "core/cfg.y" /* yacc.c:1646  */
    {rt=CORE_ONREPLY_ROUTE;}
#line 8298 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 467:
#line 1869 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		push((yyvsp[-1].action), &onreply_rt.rlist[DEFAULT_RT]);
	}
#line 8312 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 468:
#line 1878 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid onreply_route statement"); }
#line 8318 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 469:
#line 1879 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid onreply_route statement"); }
#line 8324 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 470:
#line 1881 "core/cfg.y" /* yacc.c:1646  */
    {rt=(*(yyvsp[-1].strval)=='0' && (yyvsp[-1].strval)[1]==0)?CORE_ONREPLY_ROUTE:TM_ONREPLY_ROUTE;}
#line 8330 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 471:
#line 1882 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		if (*(yyvsp[-5].strval)=='0' && (yyvsp[-5].strval)[1]==0){
			/* onreply_route[0] {} is equivalent with onreply_route {}*/
			push((yyvsp[-1].action), &onreply_rt.rlist[DEFAULT_RT]);
		}else{
			i_tmp=route_get(&onreply_rt, (yyvsp[-5].strval));
			if (i_tmp==-1){
				yyerror("internal error");
				YYABORT;
			}
			if (onreply_rt.rlist[i_tmp]){
				yyerror("duplicate route");
				YYABORT;
			}
			push((yyvsp[-1].action), &onreply_rt.rlist[i_tmp]);
		}
	}
#line 8358 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 472:
#line 1905 "core/cfg.y" /* yacc.c:1646  */
    {
		yyerror("invalid onreply_route statement");
	}
#line 8366 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 473:
#line 1910 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		push((yyvsp[-1].action), &branch_rt.rlist[DEFAULT_RT]);
	}
#line 8380 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 474:
#line 1919 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		i_tmp=route_get(&branch_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (branch_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &branch_rt.rlist[i_tmp]);
	}
#line 8403 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 475:
#line 1937 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid branch_route statement"); }
#line 8409 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 476:
#line 1939 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		push((yyvsp[-1].action), &onsend_rt.rlist[DEFAULT_RT]);
	}
#line 8423 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 477:
#line 1948 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		i_tmp=route_get(&onsend_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (onsend_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &onsend_rt.rlist[i_tmp]);
	}
#line 8446 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 478:
#line 1966 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid onsend_route statement"); }
#line 8452 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 479:
#line 1968 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		i_tmp=route_get(&event_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (event_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &event_rt.rlist[i_tmp]);
	}
#line 8475 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 480:
#line 1987 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid event_route statement"); }
#line 8481 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 481:
#line 1990 "core/cfg.y" /* yacc.c:1646  */
    { if(pp_subst_add((yyvsp[0].strval))<0) YYERROR; }
#line 8487 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 482:
#line 1991 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid subst preprocess statement"); }
#line 8493 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 483:
#line 1992 "core/cfg.y" /* yacc.c:1646  */
    { if(pp_substdef_add((yyvsp[0].strval), 0)<0) YYERROR; }
#line 8499 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 484:
#line 1993 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid substdef preprocess statement"); }
#line 8505 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 485:
#line 1994 "core/cfg.y" /* yacc.c:1646  */
    { if(pp_substdef_add((yyvsp[0].strval), 1)<0) YYERROR; }
#line 8511 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 486:
#line 1995 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid substdefs preprocess statement"); }
#line 8517 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 487:
#line 2017 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=EQUAL_OP; }
#line 8523 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 488:
#line 2018 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=DIFF_OP; }
#line 8529 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 489:
#line 2019 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=EQUAL_OP; }
#line 8535 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 490:
#line 2020 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=DIFF_OP; }
#line 8541 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 491:
#line 2023 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=GT_OP; }
#line 8547 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 492:
#line 2024 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=LT_OP; }
#line 8553 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 493:
#line 2025 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=GTE_OP; }
#line 8559 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 494:
#line 2026 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=LTE_OP; }
#line 8565 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 495:
#line 2029 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=(yyvsp[0].intval); }
#line 8571 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 496:
#line 2030 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=MATCH_OP; }
#line 8577 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 497:
#line 2036 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_EQ_OP; }
#line 8583 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 498:
#line 2037 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_DIFF_OP; }
#line 8589 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 499:
#line 2038 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_IEQ_OP; }
#line 8595 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 500:
#line 2039 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_IDIFF_OP; }
#line 8601 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 501:
#line 2040 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_STREQ_OP; }
#line 8607 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 502:
#line 2041 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_STRDIFF_OP; }
#line 8613 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 503:
#line 2042 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_MATCH_OP; }
#line 8619 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 504:
#line 2045 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_GT_OP; }
#line 8625 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 505:
#line 2046 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_LT_OP; }
#line 8631 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 506:
#line 2047 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_GTE_OP; }
#line 8637 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 507:
#line 2048 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_LTE_OP; }
#line 8643 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 508:
#line 2055 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=URI_O;}
#line 8649 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 509:
#line 2056 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=FROM_URI_O;}
#line 8655 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 510:
#line 2057 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=TO_URI_O;}
#line 8661 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 511:
#line 2064 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=SNDPORT_O; }
#line 8667 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 512:
#line 2065 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=TOPORT_O; }
#line 8673 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 513:
#line 2066 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=SNDAF_O; }
#line 8679 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 514:
#line 2070 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=SRCPORT_O; }
#line 8685 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 515:
#line 2071 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=DSTPORT_O; }
#line 8691 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 516:
#line 2072 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=AF_O; }
#line 8697 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2073 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=MSGLEN_O; }
#line 8703 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2079 "core/cfg.y" /* yacc.c:1646  */
    { onsend_check("snd_ip"); (yyval.intval)=SNDIP_O; }
#line 8709 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2080 "core/cfg.y" /* yacc.c:1646  */
    { onsend_check("to_ip");  (yyval.intval)=TOIP_O; }
#line 8715 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2083 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=SRCIP_O; }
#line 8721 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2084 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=DSTIP_O; }
#line 8727 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2092 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.expr)= mk_elem((yyvsp[-1].intval), METHOD_O, 0, RVE_ST, (yyvsp[0].rv_expr));}
#line 8733 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2094 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.expr) = mk_elem((yyvsp[-1].intval), METHOD_O, 0, STRING_ST,(yyvsp[0].strval)); }
#line 8739 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2095 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("string expected"); }
#line 8745 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2097 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("invalid operator,== , !=, or =~ expected"); }
#line 8751 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2099 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.expr) = mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr)); }
#line 8757 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2101 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, MYSELF_ST, 0); }
#line 8763 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2103 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("string or MYSELF expected"); }
#line 8769 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2105 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("invalid operator, == , != or =~ expected"); }
#line 8775 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2106 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr) ); }
#line 8781 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2108 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr) ); }
#line 8787 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2109 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("number expected"); }
#line 8793 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2110 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("number expected"); }
#line 8799 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2111 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("==, !=, <,>, >= or <=  expected"); }
#line 8805 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2113 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), PROTO_O, 0, NUMBER_ST, (void*)(yyvsp[0].intval) ); }
#line 8811 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2115 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), PROTO_O, 0, RVE_ST, (yyvsp[0].rv_expr) ); }
#line 8817 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2117 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("protocol expected (udp, tcp, tls, sctp, ws, or wss)"); }
#line 8823 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2119 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), SNDPROTO_O, 0, NUMBER_ST, (void*)(yyvsp[0].intval) ); }
#line 8829 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2121 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), SNDPROTO_O, 0, RVE_ST, (yyvsp[0].rv_expr) ); }
#line 8835 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2123 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("protocol expected (udp, tcp, tls, sctp, ws, or wss)"); }
#line 8841 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2124 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, NET_ST, (yyvsp[0].ipnet)); }
#line 8847 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2125 "core/cfg.y" /* yacc.c:1646  */
    {
			s_tmp.s=0;
			(yyval.expr)=0;
			if (rve_is_constant((yyvsp[0].rv_expr))){
				i_tmp=rve_guess_type((yyvsp[0].rv_expr));
				if (i_tmp==RV_INT)
					yyerror("string expected");
				else if (i_tmp==RV_STR){
					if (((rval_tmp=rval_expr_eval(0, 0, (yyvsp[0].rv_expr)))==0) ||
								(rval_get_str(0, 0, &s_tmp, rval_tmp, 0)<0)){
						rval_destroy(rval_tmp);
						yyerror("bad rvalue expression");
					}else{
						rval_destroy(rval_tmp);
					}
				}else{
					yyerror("BUG: unexpected dynamic type");
				}
			}else{
					/* warn("non constant rvalue in ip comparison") */;
			}
			if (s_tmp.s){
				ip_tmp=str2ip(&s_tmp);
				if (ip_tmp==0)
					ip_tmp=str2ip6(&s_tmp);
				pkg_free(s_tmp.s);
				if (ip_tmp) {
					(yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, NET_ST,
								mk_new_net_bitlen(ip_tmp, ip_tmp->len*8) );
				} else {
					(yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr));
				}
			}else{
				(yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr));
			}
		}
#line 8888 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2162 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, STRING_ST, (yyvsp[0].strval)); }
#line 8894 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2164 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, MYSELF_ST, 0); }
#line 8900 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2166 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror( "ip address or hostname expected" ); }
#line 8906 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2168 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("invalid operator, ==, != or =~ expected");}
#line 8912 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2171 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[0].intval), 0, MYSELF_ST, 0); }
#line 8918 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2173 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[0].intval), 0, MYSELF_ST, 0); }
#line 8924 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2175 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("URI, SRCIP or DSTIP expected"); }
#line 8930 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2176 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror ("invalid operator, == or != expected"); }
#line 8936 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2180 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.ipnet)=mk_new_net((yyvsp[-2].ipaddr), (yyvsp[0].ipaddr)); }
#line 8942 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2181 "core/cfg.y" /* yacc.c:1646  */
    {
		if (((yyvsp[0].intval)<0) || ((yyvsp[0].intval)>(yyvsp[-2].ipaddr)->len*8)) {
			yyerror("invalid bit number in netmask");
			(yyval.ipnet)=0;
		} else {
			(yyval.ipnet)=mk_new_net_bitlen((yyvsp[-2].ipaddr), (yyvsp[0].intval));
		/*
			$$=mk_new_net($1, htonl( ($3)?~( (1<<(32-$3))-1 ):0 ) );
		*/
		}
	}
#line 8958 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2192 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.ipnet)=mk_new_net_bitlen((yyvsp[0].ipaddr), (yyvsp[0].ipaddr)->len*8); }
#line 8964 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2193 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.ipnet)=0; yyerror("netmask (eg:255.0.0.0 or 8) expected"); }
#line 8970 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2197 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)=(yyvsp[0].strval); }
#line 8976 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2198 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2].strval)){
			(yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
				LM_CRIT("cfg. parser: memory allocation"
							" failure while parsing host\n");
			} else {
				memcpy((yyval.strval), (yyvsp[-2].strval), strlen((yyvsp[-2].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))]='.';
				memcpy((yyval.strval)+strlen((yyvsp[-2].strval))+1, (yyvsp[0].strval), strlen((yyvsp[0].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))]=0;
			}
			pkg_free((yyvsp[-2].strval));
		}
		if ((yyvsp[0].strval)) pkg_free((yyvsp[0].strval));
	}
#line 8997 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2214 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2].strval)){
			(yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
				LM_CRIT("cfg. parser: memory allocation"
							" failure while parsing host\n");
			} else {
				memcpy((yyval.strval), (yyvsp[-2].strval), strlen((yyvsp[-2].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))]='-';
				memcpy((yyval.strval)+strlen((yyvsp[-2].strval))+1, (yyvsp[0].strval), strlen((yyvsp[0].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))]=0;
			}
			pkg_free((yyvsp[-2].strval));
		}
		if ((yyvsp[0].strval)) pkg_free((yyvsp[0].strval));
	}
#line 9018 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2230 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)=0; pkg_free((yyvsp[-2].strval)); yyerror("invalid hostname"); }
#line 9024 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2231 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)=0; pkg_free((yyvsp[-2].strval)); yyerror("invalid hostname"); }
#line 9030 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2236 "core/cfg.y" /* yacc.c:1646  */
    {
			/* get string version */
			(yyval.strval)=pkg_malloc(strlen(yy_number_str)+1);
			if ((yyval.strval))
				strcpy((yyval.strval), yy_number_str);
		}
#line 9041 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2245 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)=(yyvsp[0].strval); }
#line 9047 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2246 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2].strval)){
			(yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
				LM_CRIT("cfg. parser: memory allocation"
							" failure while parsing host/interface name\n");
			} else {
				memcpy((yyval.strval), (yyvsp[-2].strval), strlen((yyvsp[-2].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))]='.';
				memcpy((yyval.strval)+strlen((yyvsp[-2].strval))+1, (yyvsp[0].strval), strlen((yyvsp[0].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))]=0;
			}
			pkg_free((yyvsp[-2].strval));
		}
		if ((yyvsp[0].strval)) pkg_free((yyvsp[0].strval));
	}
#line 9068 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2262 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2].strval)){
			(yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
				LM_CRIT("cfg. parser: memory allocation"
							" failure while parsing host/interface name\n");
			} else {
				memcpy((yyval.strval), (yyvsp[-2].strval), strlen((yyvsp[-2].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))]='-';
				memcpy((yyval.strval)+strlen((yyvsp[-2].strval))+1, (yyvsp[0].strval), strlen((yyvsp[0].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))]=0;
			}
			pkg_free((yyvsp[-2].strval));
		}
		if ((yyvsp[0].strval)) pkg_free((yyvsp[0].strval));
	}
#line 9089 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2278 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)=0; pkg_free((yyvsp[-2].strval));
								yyerror("invalid host or interface name"); }
#line 9096 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2280 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)=0; pkg_free((yyvsp[-2].strval));
								yyerror("invalid host or interface name"); }
#line 9103 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2287 "core/cfg.y" /* yacc.c:1646  */
    {
		/* check if allowed */
		if ((yyvsp[0].action) && rt==ONSEND_ROUTE) {
			switch((yyvsp[0].action)->type) {
				case DROP_T:
				case LOG_T:
				case SETFLAG_T:
				case RESETFLAG_T:
				case ISFLAGSET_T:
				case IF_T:
				case MODULE0_T:
				case MODULE1_T:
				case MODULE2_T:
				case MODULE3_T:
				case MODULE4_T:
				case MODULE5_T:
				case MODULE6_T:
				case MODULEX_T:
				case SET_FWD_NO_CONNECT_T:
				case SET_RPL_NO_CONNECT_T:
				case SET_FWD_CLOSE_T:
				case SET_RPL_CLOSE_T:
					(yyval.action)=(yyvsp[0].action);
					break;
				default:
					(yyval.action)=0;
					yyerror("command not allowed in onsend_route\n");
			}
		} else {
			(yyval.action)=(yyvsp[0].action);
		}
	}
#line 9140 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2329 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=(yyvsp[0].action); }
#line 9146 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2330 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=(yyvsp[-1].action); }
#line 9152 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2333 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=append_action((yyvsp[-1].action), (yyvsp[0].action)); }
#line 9158 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2334 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=(yyvsp[0].action);}
#line 9164 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2335 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad command"); }
#line 9170 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2338 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=(yyvsp[-1].action);}
#line 9176 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2339 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=(yyvsp[0].action);}
#line 9182 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2340 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=(yyvsp[0].action);}
#line 9188 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2341 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=(yyvsp[0].action); }
#line 9194 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2342 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=(yyvsp[-1].action); }
#line 9200 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2343 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=(yyvsp[-1].action);}
#line 9206 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2344 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=0;}
#line 9212 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2345 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad command: missing ';'?"); }
#line 9218 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2348 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-1].rv_expr) && rval_expr_int_check((yyvsp[-1].rv_expr))>=0){
			warn_ct_rve((yyvsp[-1].rv_expr), "if");
			(yyval.action)=mk_action( IF_T, 3, RVE_ST, (yyvsp[-1].rv_expr), ACTIONS_ST, (yyvsp[0].action), NOSUBTYPE, 0);
			set_cfg_pos((yyval.action));
		}else
			YYERROR;
	}
#line 9231 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2356 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-3].rv_expr) && rval_expr_int_check((yyvsp[-3].rv_expr))>=0){
			warn_ct_rve((yyvsp[-3].rv_expr), "if");
			(yyval.action)=mk_action( IF_T, 3, RVE_ST, (yyvsp[-3].rv_expr), ACTIONS_ST, (yyvsp[-2].action), ACTIONS_ST, (yyvsp[0].action));
			set_cfg_pos((yyval.action));
		}else
			YYERROR;
	}
#line 9244 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2366 "core/cfg.y" /* yacc.c:1646  */
    {
			(yyval.rv_expr)=0;
			if ((yyvsp[0].rv_expr) && !rve_is_constant((yyvsp[0].rv_expr))){
				yyerror("constant expected");
				YYERROR;
			/*
			} else if ($1 &&
						!rve_check_type((enum rval_type*)&i_tmp, $1, 0, 0 ,0)){
				yyerror("invalid expression (bad type)");
			}else if ($1 && i_tmp!=RV_INT){
				yyerror("invalid expression type, int expected\n");
			*/
			}else
				(yyval.rv_expr)=(yyvsp[0].rv_expr);
		}
#line 9264 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2383 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.case_stms)=0;
		if ((yyvsp[-2].rv_expr)==0) { yyerror ("bad case label"); YYERROR; }
		else if ((((yyval.case_stms)=mk_case_stm((yyvsp[-2].rv_expr), 0, (yyvsp[0].action), &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 9276 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2390 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.case_stms)=0;
		if ((yyvsp[-2].rv_expr)==0) { yyerror ("bad case label"); YYERROR; }
		else if ((((yyval.case_stms)=mk_case_stm((yyvsp[-2].rv_expr), 1, (yyvsp[0].action), &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 9288 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2397 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.case_stms)=0;
		if ((yyvsp[-1].rv_expr)==0) { yyerror ("bad case label"); YYERROR; }
		else if ((((yyval.case_stms)=mk_case_stm((yyvsp[-1].rv_expr), 0, 0, &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 9300 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2404 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.case_stms)=0;
		if ((yyvsp[-1].rv_expr)==0) { yyerror ("bad regex case label"); YYERROR; }
		else if ((((yyval.case_stms)=mk_case_stm((yyvsp[-1].rv_expr), 1, 0, &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 9312 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2411 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((((yyval.case_stms)=mk_case_stm(0, 0, (yyvsp[0].action), &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 9322 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2416 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((((yyval.case_stms)=mk_case_stm(0, 0, 0, &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 9332 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2421 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.case_stms)=0; yyerror("bad case label"); }
#line 9338 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2422 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.case_stms)=0; yyerror("bad case regex label"); }
#line 9344 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2423 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.case_stms)=0; yyerror("bad case label"); }
#line 9350 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2424 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.case_stms)=0; yyerror("bad case regex label"); }
#line 9356 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2425 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.case_stms)=0; yyerror ("bad case body"); }
#line 9362 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2428 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.case_stms)=(yyvsp[-1].case_stms);
		if ((yyvsp[0].case_stms)==0) yyerror ("bad case");
		if ((yyval.case_stms)){
			*((yyval.case_stms)->append)=(yyvsp[0].case_stms);
			if (*((yyval.case_stms)->append)!=0)
				(yyval.case_stms)->append=&((*((yyval.case_stms)->append))->next);
		}
	}
#line 9376 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2437 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.case_stms)=(yyvsp[0].case_stms);
		if ((yyvsp[0].case_stms)==0) yyerror ("bad case");
		else (yyval.case_stms)->append=&((yyval.case_stms)->next);
	}
#line 9386 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2444 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=0;
		if ((yyvsp[-3].rv_expr)==0){
			yyerror("bad expression in switch(...)");
			YYERROR;
		}else if ((yyvsp[-1].case_stms)==0){
			yyerror ("bad switch body");
			YYERROR;
		}else if (case_check_default((yyvsp[-1].case_stms))!=0){
			yyerror_at(&(yyvsp[-3].rv_expr)->fpos, "bad switch(): too many "
							"\"default:\" labels\n");
			YYERROR;
		}else if (case_check_type((yyvsp[-1].case_stms))!=0){
			yyerror_at(&(yyvsp[-3].rv_expr)->fpos, "bad switch(): mixed integer and"
							" string/RE cases not allowed\n");
			YYERROR;
		}else{
			(yyval.action)=mk_action(SWITCH_T, 2, RVE_ST, (yyvsp[-3].rv_expr), CASE_ST, (yyvsp[-1].case_stms));
			if ((yyval.action)==0) {
				yyerror("internal error");
				YYABORT;
			}
			set_cfg_pos((yyval.action));
		}
	}
#line 9416 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2469 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=0;
		warn("empty switch()");
		if ((yyvsp[-2].rv_expr)==0){
			yyerror("bad expression in switch(...)");
			YYERROR;
		}else{
			/* it might have sideffects, so leave it for the optimizer */
			(yyval.action)=mk_action(SWITCH_T, 2, RVE_ST, (yyvsp[-2].rv_expr), CASE_ST, 0);
			if ((yyval.action)==0) {
				yyerror("internal error");
				YYABORT;
			}
			set_cfg_pos((yyval.action));
		}
	}
#line 9437 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2485 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror ("bad expression in switch(...)"); }
#line 9443 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2487 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=0; yyerror ("bad switch body"); }
#line 9449 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2491 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-1].rv_expr) && rval_expr_int_check((yyvsp[-1].rv_expr))>=0){
			warn_ct_rve((yyvsp[-1].rv_expr), "while");
			(yyval.action)=mk_action( WHILE_T, 2, RVE_ST, (yyvsp[-1].rv_expr), ACTIONS_ST, (yyvsp[0].action));
			set_cfg_pos((yyval.action));
		}else{
			yyerror_at(&(yyvsp[-1].rv_expr)->fpos, "bad while(...) expression");
			YYERROR;
		}
	}
#line 9464 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2510 "core/cfg.y" /* yacc.c:1646  */
    {
		if (sel.n >= MAX_SELECT_PARAMS-1) {
			yyerror("Select identifier too long\n");
		}
		sel.params[sel.n].type = SEL_PARAM_STR;
		sel.params[sel.n].v.s.s = (yyvsp[0].strval);
		sel.params[sel.n].v.s.len = strlen((yyvsp[0].strval));
		sel.n++;
	}
#line 9478 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2519 "core/cfg.y" /* yacc.c:1646  */
    {
		if (sel.n >= MAX_SELECT_PARAMS-2) {
			yyerror("Select identifier too long\n");
		}
		sel.params[sel.n].type = SEL_PARAM_STR;
		sel.params[sel.n].v.s.s = (yyvsp[-3].strval);
		sel.params[sel.n].v.s.len = strlen((yyvsp[-3].strval));
		sel.n++;
		sel.params[sel.n].type = SEL_PARAM_INT;
		sel.params[sel.n].v.i = (yyvsp[-1].intval);
		sel.n++;
	}
#line 9495 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2531 "core/cfg.y" /* yacc.c:1646  */
    {
		if (sel.n >= MAX_SELECT_PARAMS-2) {
			yyerror("Select identifier too long\n");
		}
		sel.params[sel.n].type = SEL_PARAM_STR;
		sel.params[sel.n].v.s.s = (yyvsp[-3].strval);
		sel.params[sel.n].v.s.len = strlen((yyvsp[-3].strval));
		sel.n++;
		sel.params[sel.n].type = SEL_PARAM_STR;
		sel.params[sel.n].v.s.s = (yyvsp[-1].strval);
		sel.params[sel.n].v.s.len = strlen((yyvsp[-1].strval));
		sel.n++;
	}
#line 9513 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2550 "core/cfg.y" /* yacc.c:1646  */
    { sel.n = 0; sel.f[0] = 0; }
#line 9519 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2550 "core/cfg.y" /* yacc.c:1646  */
    {
		sel_ptr = (select_t*)pkg_malloc(sizeof(select_t));
		if (!sel_ptr) {
			yyerror("No memory left to allocate select structure\n");
		}
		memcpy(sel_ptr, &sel, sizeof(select_t));
		(yyval.select) = sel_ptr;
	}
#line 9532 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2560 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_TRACK_FROM; }
#line 9538 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2561 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_TRACK_TO; }
#line 9544 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2562 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_TRACK_FROM | AVP_CLASS_URI; }
#line 9550 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2563 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_TRACK_TO | AVP_CLASS_URI; }
#line 9556 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 616:
#line 2564 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_TRACK_FROM | AVP_CLASS_USER; }
#line 9562 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 617:
#line 2565 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_TRACK_TO | AVP_CLASS_USER; }
#line 9568 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 618:
#line 2566 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_TRACK_FROM | AVP_CLASS_DOMAIN; }
#line 9574 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 619:
#line 2567 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_TRACK_TO | AVP_CLASS_DOMAIN; }
#line 9580 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 620:
#line 2568 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_TRACK_ALL | AVP_CLASS_GLOBAL; }
#line 9586 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 621:
#line 2571 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_NAME_STR; s_attr->name.s.s = (yyvsp[0].strval); s_attr->name.s.len = strlen ((yyvsp[0].strval)); }
#line 9592 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 624:
#line 2578 "core/cfg.y" /* yacc.c:1646  */
    {
		s_attr = (struct avp_spec*)pkg_malloc(sizeof(struct avp_spec));
		if (!s_attr) { yyerror("No memory left"); YYABORT; }
		else s_attr->type = 0;
	}
#line 9602 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 625:
#line 2585 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.attr) = s_attr; }
#line 9608 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 626:
#line 2588 "core/cfg.y" /* yacc.c:1646  */
    {
		s_attr->type|= (AVP_NAME_STR | ((yyvsp[-1].intval)<0?AVP_INDEX_BACKWARD:AVP_INDEX_FORWARD));
		s_attr->index = ((yyvsp[-1].intval)<0?-(yyvsp[-1].intval):(yyvsp[-1].intval));
		(yyval.attr) = s_attr;
	}
#line 9618 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2595 "core/cfg.y" /* yacc.c:1646  */
    {
		s_attr->type|= AVP_INDEX_ALL;
		(yyval.attr) = s_attr;
	}
#line 9627 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2617 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[0].lval)->type==LV_AVP){
			s_attr = pkg_malloc(sizeof(struct avp_spec));
			if (!s_attr) { yyerror("No memory left"); YYABORT; }
			else{
				*s_attr=(yyvsp[0].lval)->lv.avps;
			}
			(yyval.attr)=s_attr;
		}else
			(yyval.attr)=0; /* not an avp, a pvar */
		pkg_free((yyvsp[0].lval));
	}
#line 9644 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2629 "core/cfg.y" /* yacc.c:1646  */
    {
		avp_spec_t *avp_spec;
		str s;
		int type, idx;
		avp_spec = pkg_malloc(sizeof(*avp_spec));
		if (!avp_spec) {
			yyerror("Not enough memory");
			YYABORT;
		}
		s.s = (yyvsp[0].strval);
		if (s.s[0] == '$')
			s.s++;
		s.len = strlen(s.s);
		if (parse_avp_name(&s, &type, &avp_spec->name, &idx)) {
			yyerror("error when parsing AVP");
			pkg_free(avp_spec);
			YYABORT;
		}
		avp_spec->type = type;
		avp_spec->index = idx;
		(yyval.attr) = avp_spec;
	}
#line 9671 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2653 "core/cfg.y" /* yacc.c:1646  */
    {
			s_tmp.s=(yyvsp[0].strval); s_tmp.len=strlen((yyvsp[0].strval));
			pv_spec=pv_cache_get(&s_tmp);
			if (!pv_spec) {
				yyerror("Can't get from cache: %s", (yyvsp[0].strval));
				YYABORT;
			}
			(yyval.pvar)=pv_spec;
		}
#line 9685 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2664 "core/cfg.y" /* yacc.c:1646  */
    {
				lval_tmp=pkg_malloc(sizeof(*lval_tmp));
				if (!lval_tmp) {
					yyerror("Not enough memory");
					YYABORT;
				}
				memset(lval_tmp, 0, sizeof(*lval_tmp));
				s_tmp.s=(yyvsp[0].strval); s_tmp.len=strlen(s_tmp.s);
				lval_tmp->lv.pvs = pv_cache_get(&s_tmp);
				if (lval_tmp->lv.pvs==NULL){
					lval_tmp->lv.avps.type|= AVP_NAME_STR;
					lval_tmp->lv.avps.name.s.s = s_tmp.s+1;
					lval_tmp->lv.avps.name.s.len = s_tmp.len-1;
					lval_tmp->type=LV_AVP;
				}else{
					lval_tmp->type=LV_PVAR;
				}
				(yyval.lval) = lval_tmp;
				DBG("parsed ambiguous avp/pvar \"%.*s\" to %d\n",
							s_tmp.len, s_tmp.s, lval_tmp->type);
			}
#line 9711 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 638:
#line 2695 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval) = ASSIGN_T; }
#line 9717 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 639:
#line 2699 "core/cfg.y" /* yacc.c:1646  */
    {
					lval_tmp=pkg_malloc(sizeof(*lval_tmp));
					if (!lval_tmp) {
						yyerror("Not enough memory");
						YYABORT;
					}
					lval_tmp->type=LV_AVP; lval_tmp->lv.avps=*(yyvsp[0].attr);
					pkg_free((yyvsp[0].attr)); /* free the avp spec we just copied */
					(yyval.lval)=lval_tmp;
				}
#line 9732 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 640:
#line 2709 "core/cfg.y" /* yacc.c:1646  */
    {
					if (!pv_is_w((yyvsp[0].pvar)))
						yyerror("read only pvar in assignment left side");
					if ((yyvsp[0].pvar)->trans!=0)
						yyerror("pvar with transformations in assignment"
								" left side");
					lval_tmp=pkg_malloc(sizeof(*lval_tmp));
					if (!lval_tmp) {
						yyerror("Not enough memory");
						YYABORT;
					}
					lval_tmp->type=LV_PVAR; lval_tmp->lv.pvs=(yyvsp[0].pvar);
					(yyval.lval)=lval_tmp;
				}
#line 9751 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 641:
#line 2723 "core/cfg.y" /* yacc.c:1646  */
    {
					if (((yyvsp[0].lval))->type==LV_PVAR){
						if (!pv_is_w((yyvsp[0].lval)->lv.pvs))
							yyerror("read only pvar in assignment left side");
						if ((yyvsp[0].lval)->lv.pvs->trans!=0)
							yyerror("pvar with transformations in assignment"
									" left side");
					}
					(yyval.lval)=(yyvsp[0].lval);
				}
#line 9766 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 642:
#line 2735 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve_rval(RV_INT, (void*)(yyvsp[0].intval)); }
#line 9772 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 643:
#line 2736 "core/cfg.y" /* yacc.c:1646  */
    {	s_tmp.s=(yyvsp[0].strval); s_tmp.len=strlen((yyvsp[0].strval));
							(yyval.rv_expr)=mk_rve_rval(RV_STR, &s_tmp); }
#line 9779 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 644:
#line 2738 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve_rval(RV_AVP, (yyvsp[0].attr)); pkg_free((yyvsp[0].attr)); }
#line 9785 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 645:
#line 2739 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve_rval(RV_PVAR, (yyvsp[0].pvar)); }
#line 9791 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 646:
#line 2740 "core/cfg.y" /* yacc.c:1646  */
    {
							switch((yyvsp[0].lval)->type){
								case LV_AVP:
									(yyval.rv_expr)=mk_rve_rval(RV_AVP, &(yyvsp[0].lval)->lv.avps);
									break;
								case LV_PVAR:
									(yyval.rv_expr)=mk_rve_rval(RV_PVAR, (yyvsp[0].lval)->lv.pvs);
									break;
								default:
									yyerror("BUG: invalid lvalue type ");
									YYABORT;
							}
							pkg_free((yyvsp[0].lval)); /* not needed anymore */
						}
#line 9810 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 647:
#line 2754 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve_rval(RV_SEL, (yyvsp[0].select)); pkg_free((yyvsp[0].select)); }
#line 9816 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 648:
#line 2755 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve_rval(RV_ACTION_ST, (yyvsp[0].action)); }
#line 9822 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 649:
#line 2756 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=mk_rve_rval(RV_BEXPR, (yyvsp[0].expr)); }
#line 9828 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 650:
#line 2757 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve_rval(RV_ACTION_ST, (yyvsp[-1].action)); }
#line 9834 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 651:
#line 2758 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad command block"); }
#line 9840 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 652:
#line 2759 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve_rval(RV_ACTION_ST, (yyvsp[-1].action)); }
#line 9846 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 653:
#line 2760 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 9852 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 654:
#line 2764 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=RVE_LNOT_OP; }
#line 9858 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 655:
#line 2765 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=RVE_BNOT_OP; }
#line 9864 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 656:
#line 2766 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=RVE_UMINUS_OP; }
#line 9870 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 657:
#line 2779 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=(yyvsp[0].rv_expr);
										if ((yyval.rv_expr)==0){
											/*yyerror("out of memory\n");*/
											YYERROR;
										}
									}
#line 9881 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 658:
#line 2785 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve1((yyvsp[-1].intval), (yyvsp[0].rv_expr)); }
#line 9887 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 659:
#line 2786 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve1(RVE_INT_OP, (yyvsp[0].rv_expr)); }
#line 9893 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 660:
#line 2787 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve1(RVE_STR_OP, (yyvsp[0].rv_expr)); }
#line 9899 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 661:
#line 2788 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_PLUS_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 9905 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 662:
#line 2789 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_MINUS_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 9911 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 663:
#line 2790 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_MUL_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 9917 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 664:
#line 2791 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_DIV_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 9923 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 665:
#line 2792 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_MOD_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 9929 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 666:
#line 2793 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_BOR_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr)); }
#line 9935 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 667:
#line 2794 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_BAND_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr));}
#line 9941 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 668:
#line 2795 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_BXOR_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr));}
#line 9947 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 669:
#line 2796 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_BLSHIFT_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr));}
#line 9953 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 670:
#line 2797 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_BRSHIFT_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr));}
#line 9959 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 671:
#line 2798 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=mk_rve2( (yyvsp[-1].intval), (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr));}
#line 9965 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 672:
#line 2799 "core/cfg.y" /* yacc.c:1646  */
    {
			/* comparing with $null => treat as defined or !defined */
			if((yyvsp[0].rv_expr)->op==RVE_RVAL_OP && (yyvsp[0].rv_expr)->left.rval.type==RV_PVAR
					&& (yyvsp[0].rv_expr)->left.rval.v.pvs.type==PVT_NULL) {
				if((yyvsp[-1].intval)==RVE_DIFF_OP || (yyvsp[-1].intval)==RVE_IDIFF_OP
						|| (yyvsp[-1].intval)==RVE_STRDIFF_OP) {
					DBG("comparison with $null switched to notdefined operator\n");
					(yyval.rv_expr)=mk_rve1(RVE_DEFINED_OP, (yyvsp[-2].rv_expr));
				} else {
					DBG("comparison with $null switched to defined operator\n");
					(yyval.rv_expr)=mk_rve1(RVE_NOTDEFINED_OP, (yyvsp[-2].rv_expr));
				}
				/* free rve struct for $null */
				rve_destroy((yyvsp[0].rv_expr));
			} else {
				(yyval.rv_expr)=mk_rve2((yyvsp[-1].intval), (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr));
			}
		}
#line 9988 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 673:
#line 2817 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=mk_rve2(RVE_LAND_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr));}
#line 9994 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 674:
#line 2818 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=mk_rve2(RVE_LOR_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr));}
#line 10000 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 675:
#line 2819 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=(yyvsp[-1].rv_expr);}
#line 10006 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 676:
#line 2820 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=mk_rve1(RVE_STRLEN_OP, (yyvsp[-1].rv_expr));}
#line 10012 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 677:
#line 2821 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve1(RVE_STREMPTY_OP, (yyvsp[-1].rv_expr));}
#line 10018 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 678:
#line 2822 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=mk_rve1(RVE_DEFINED_OP, (yyvsp[0].rv_expr));}
#line 10024 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 679:
#line 2823 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10030 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 680:
#line 2824 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10036 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 681:
#line 2825 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10042 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 682:
#line 2826 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10048 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 683:
#line 2827 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10054 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 684:
#line 2828 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10060 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 685:
#line 2829 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10066 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 686:
#line 2830 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10072 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 687:
#line 2831 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10078 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 688:
#line 2832 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10084 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 689:
#line 2834 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10090 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 690:
#line 2836 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10096 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 691:
#line 2837 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10102 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 692:
#line 2838 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10108 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 693:
#line 2839 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10114 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 694:
#line 2840 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10120 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 695:
#line 2841 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10126 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 696:
#line 2844 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action((yyvsp[-1].intval), 2, LVAL_ST, (yyvsp[-2].lval),
														 	  RVE_ST, (yyvsp[0].rv_expr));
											set_cfg_pos((yyval.action));
										}
#line 10135 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 697:
#line 2862 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 10141 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 698:
#line 2863 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 10147 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 699:
#line 2864 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval) = -1; }
#line 10153 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 700:
#line 2867 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action)); }
#line 10159 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 701:
#line 2868 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(	FORWARD_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10165 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 702:
#line 2869 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(	FORWARD_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10171 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 703:
#line 2870 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(	FORWARD_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10177 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 704:
#line 2871 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10183 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 705:
#line 2872 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(FORWARD_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10189 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 706:
#line 2873 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10195 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 707:
#line 2874 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action)); }
#line 10201 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 708:
#line 2875 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(FORWARD_T, 2, URIHOST_ST, 0, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10207 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 709:
#line 2876 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10213 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 710:
#line 2877 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10219 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 711:
#line 2878 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad forward argument"); }
#line 10225 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 712:
#line 2879 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10231 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 713:
#line 2880 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10237 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 714:
#line 2881 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10243 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 715:
#line 2882 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10249 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 716:
#line 2883 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(FORWARD_UDP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10255 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 717:
#line 2884 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10261 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 718:
#line 2885 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(FORWARD_UDP_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action)); }
#line 10267 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 719:
#line 2886 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, URIHOST_ST, 0, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10273 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 720:
#line 2887 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10279 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 721:
#line 2888 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10285 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 722:
#line 2889 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad forward_udp argument"); }
#line 10291 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 723:
#line 2890 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10297 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 724:
#line 2891 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10303 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 725:
#line 2892 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10309 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 726:
#line 2893 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10315 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 727:
#line 2894 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(FORWARD_TCP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10321 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 728:
#line 2895 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10327 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 729:
#line 2896 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(FORWARD_TCP_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action)); }
#line 10333 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 730:
#line 2897 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, URIHOST_ST, 0, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10339 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 731:
#line 2898 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10345 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 732:
#line 2899 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10351 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 733:
#line 2900 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad forward_tcp argument"); }
#line 10357 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 734:
#line 2901 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10370 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 735:
#line 2909 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10383 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 736:
#line 2917 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10396 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 737:
#line 2925 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10409 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 738:
#line 2933 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10422 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 739:
#line 2941 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
					}
#line 10435 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 740:
#line 2949 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10448 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 741:
#line 2957 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, URIHOST_ST, 0, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10461 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 742:
#line 2965 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10474 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 743:
#line 2973 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10480 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 744:
#line 2974 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0;
									yyerror("bad forward_tls argument"); }
#line 10487 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 745:
#line 2976 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10500 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 746:
#line 2984 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10513 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 747:
#line 2992 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10526 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 748:
#line 3000 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST,
							(void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10540 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 749:
#line 3009 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST,
							(void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10554 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 750:
#line 3018 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST,
							(void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
					}
#line 10568 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 751:
#line 3027 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10581 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 752:
#line 3035 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, URIHOST_ST, 0, NUMBER_ST,
							(void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10595 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 753:
#line 3044 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10608 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 754:
#line 3052 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10614 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 755:
#line 3053 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0;
									yyerror("bad forward_sctp argument"); }
#line 10621 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 756:
#line 3055 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(LOG_T, 2, NUMBER_ST,
										(void*)(L_DBG+1), STRING_ST, (yyvsp[-1].strval));
									set_cfg_pos((yyval.action)); }
#line 10629 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 757:
#line 3058 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(LOG_T, 2, NUMBER_ST, (void*)(yyvsp[-3].intval), STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 10635 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 758:
#line 3059 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10641 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 759:
#line 3060 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad log argument"); }
#line 10647 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 760:
#line 3061 "core/cfg.y" /* yacc.c:1646  */
    {
							if (check_flag((yyvsp[-1].intval))==-1)
								yyerror("bad flag value");
							(yyval.action)=mk_action(SETFLAG_T, 1, NUMBER_ST,
													(void*)(yyvsp[-1].intval));
							set_cfg_pos((yyval.action));
									}
#line 10659 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 761:
#line 3068 "core/cfg.y" /* yacc.c:1646  */
    {
							i_tmp=get_flag_no((yyvsp[-1].strval), strlen((yyvsp[-1].strval)));
							if (i_tmp<0) yyerror("flag not declared");
							(yyval.action)=mk_action(SETFLAG_T, 1, NUMBER_ST,
										(void*)(long)i_tmp);
							set_cfg_pos((yyval.action));
									}
#line 10671 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 762:
#line 3075 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 10677 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 763:
#line 3076 "core/cfg.y" /* yacc.c:1646  */
    {
							if (check_flag((yyvsp[-1].intval))==-1)
								yyerror("bad flag value");
							(yyval.action)=mk_action(RESETFLAG_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval));
							set_cfg_pos((yyval.action));
									}
#line 10688 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 764:
#line 3082 "core/cfg.y" /* yacc.c:1646  */
    {
							i_tmp=get_flag_no((yyvsp[-1].strval), strlen((yyvsp[-1].strval)));
							if (i_tmp<0) yyerror("flag not declared");
							(yyval.action)=mk_action(RESETFLAG_T, 1, NUMBER_ST,
										(void*)(long)i_tmp);
							set_cfg_pos((yyval.action));
									}
#line 10700 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 765:
#line 3089 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 10706 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 766:
#line 3090 "core/cfg.y" /* yacc.c:1646  */
    {
							if (check_flag((yyvsp[-1].intval))==-1)
								yyerror("bad flag value");
							(yyval.action)=mk_action(ISFLAGSET_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval));
							set_cfg_pos((yyval.action));
									}
#line 10717 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 767:
#line 3096 "core/cfg.y" /* yacc.c:1646  */
    {
							i_tmp=get_flag_no((yyvsp[-1].strval), strlen((yyvsp[-1].strval)));
							if (i_tmp<0) yyerror("flag not declared");
							(yyval.action)=mk_action(ISFLAGSET_T, 1, NUMBER_ST,
										(void*)(long)i_tmp);
							set_cfg_pos((yyval.action));
									}
#line 10729 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 768:
#line 3103 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 10735 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 769:
#line 3104 "core/cfg.y" /* yacc.c:1646  */
    {
		i_tmp=get_avpflag_no((yyvsp[-1].strval));
		if (i_tmp==0) yyerror("avpflag not declared");
		(yyval.action)=mk_action(AVPFLAG_OPER_T, 3, AVP_ST, (yyvsp[-3].attr), NUMBER_ST, (void*)(long)i_tmp, NUMBER_ST, (void*)(yyvsp[-5].intval));
		set_cfg_pos((yyval.action));
	}
#line 10746 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 770:
#line 3110 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=0; yyerror("error parsing flag name");
	}
#line 10754 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 771:
#line 3113 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=0; yyerror("error parsing first parameter (avp or string)");
	}
#line 10762 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 772:
#line 3116 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad parameters"); }
#line 10768 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 773:
#line 3117 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 10774 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 774:
#line 3118 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(ERROR_T, 2, STRING_ST, (yyvsp[-3].strval), STRING_ST, (yyvsp[-1].strval));
			set_cfg_pos((yyval.action));
	}
#line 10782 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 775:
#line 3121 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10788 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 776:
#line 3122 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad error argument"); }
#line 10794 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 777:
#line 3123 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-1].rv_expr)) {
			(yyval.action) = mk_action(ROUTE_T, 1, RVE_ST, (void*)(yyvsp[-1].rv_expr));
			set_cfg_pos((yyval.action));
		} else {
			(yyval.action) = 0;
			YYERROR;
		}
	}
#line 10808 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 778:
#line 3132 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-1].strval)) {
			(yyval.action) = mk_action(ROUTE_T, 1, STRING_ST, (void*)(yyvsp[-1].strval));
			set_cfg_pos((yyval.action));
		} else {
			(yyval.action) = 0;
			YYERROR;
		}
	}
#line 10822 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 779:
#line 3141 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10828 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 780:
#line 3142 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad route argument"); }
#line 10834 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 781:
#line 3143 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(EXEC_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 10840 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 782:
#line 3144 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(SET_HOST_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 10846 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 783:
#line 3145 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10852 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 784:
#line 3146 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 10858 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 785:
#line 3147 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(PREFIX_T, 1, STRING_ST,  (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 10864 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 786:
#line 3148 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10870 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 787:
#line 3149 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 10876 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 788:
#line 3150 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(STRIP_TAIL_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10882 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 789:
#line 3151 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10888 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 790:
#line 3152 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, number expected"); }
#line 10894 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 791:
#line 3153 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(STRIP_T, 1, NUMBER_ST, (void*) (yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10900 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 792:
#line 3154 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10906 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 793:
#line 3155 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, number expected"); }
#line 10912 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 794:
#line 3156 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(SET_USERPHONE_T, 0); set_cfg_pos((yyval.action)); }
#line 10918 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 795:
#line 3157 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10924 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 796:
#line 3158 "core/cfg.y" /* yacc.c:1646  */
    {
			(yyval.action)=mk_action(REMOVE_BRANCH_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval));
			set_cfg_pos((yyval.action));
	}
#line 10933 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 797:
#line 3162 "core/cfg.y" /* yacc.c:1646  */
    {
			(yyval.action)=mk_action(REMOVE_BRANCH_T, 0);
			set_cfg_pos((yyval.action));
	}
#line 10942 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 798:
#line 3166 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10948 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 799:
#line 3167 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, number expected"); }
#line 10954 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 800:
#line 3168 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(CLEAR_BRANCHES_T, 0); set_cfg_pos((yyval.action)); }
#line 10960 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 801:
#line 3169 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(SET_HOSTPORT_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 10966 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 802:
#line 3170 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10972 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 803:
#line 3171 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 10978 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 804:
#line 3172 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(SET_HOSTPORTTRANS_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 10984 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 805:
#line 3173 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10990 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 806:
#line 3174 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 10996 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 807:
#line 3175 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(SET_PORT_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11002 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 808:
#line 3176 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11008 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 809:
#line 3177 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11014 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 810:
#line 3178 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(SET_USER_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11020 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 811:
#line 3179 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11026 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 812:
#line 3180 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11032 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 813:
#line 3181 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(SET_USERPASS_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11038 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 814:
#line 3182 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11044 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 815:
#line 3183 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11050 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 816:
#line 3184 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(SET_URI_T, 1, STRING_ST,(yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11056 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 817:
#line 3185 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11062 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 818:
#line 3186 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11068 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 819:
#line 3187 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(REVERT_URI_T, 0); set_cfg_pos((yyval.action)); }
#line 11074 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 820:
#line 3188 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(REVERT_URI_T, 0); set_cfg_pos((yyval.action)); }
#line 11080 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 821:
#line 3189 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORCE_RPORT_T, 0); set_cfg_pos((yyval.action)); }
#line 11086 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 822:
#line 3190 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(FORCE_RPORT_T, 0); set_cfg_pos((yyval.action)); }
#line 11092 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 823:
#line 3191 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(ADD_LOCAL_RPORT_T, 0); set_cfg_pos((yyval.action)); }
#line 11098 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 824:
#line 3192 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(ADD_LOCAL_RPORT_T, 0); set_cfg_pos((yyval.action)); }
#line 11104 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 825:
#line 3193 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			(yyval.action)=mk_action(FORCE_TCP_ALIAS_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval));
			set_cfg_pos((yyval.action));
		#else
			yyerror("tcp support not compiled in");
		#endif
	}
#line 11117 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 826:
#line 3201 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			(yyval.action)=mk_action(FORCE_TCP_ALIAS_T, 0);
			set_cfg_pos((yyval.action));
		#else
			yyerror("tcp support not compiled in");
		#endif
	}
#line 11130 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 827:
#line 3209 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			(yyval.action)=mk_action(FORCE_TCP_ALIAS_T, 0);
			set_cfg_pos((yyval.action));
		#else
			yyerror("tcp support not compiled in");
		#endif
	}
#line 11143 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 828:
#line 3217 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=0; yyerror("bad argument, number expected"); }
#line 11149 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 829:
#line 3219 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(UDP_MTU_TRY_PROTO_T, 1, NUMBER_ST, (yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11155 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 830:
#line 3221 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, UDP, TCP, TLS or SCTP expected"); }
#line 11161 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 831:
#line 3222 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=0;
		if ((str_tmp=pkg_malloc(sizeof(str)))==0) {
			LM_CRIT("cfg. parser: out of memory.\n");
		} else {
			str_tmp->s=(yyvsp[-1].strval);
			str_tmp->len=(yyvsp[-1].strval)?strlen((yyvsp[-1].strval)):0;
			(yyval.action)=mk_action(SET_ADV_ADDR_T, 1, STR_ST, str_tmp);
			set_cfg_pos((yyval.action));
		}
	}
#line 11177 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 832:
#line 3233 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11183 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 833:
#line 3234 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11189 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 834:
#line 3235 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=0;
		tmp=int2str((yyvsp[-1].intval), &i_tmp);
		if ((str_tmp=pkg_malloc(sizeof(str)))==0) {
			LM_CRIT("cfg. parser: out of memory.\n");
		} else {
			if ((str_tmp->s=pkg_malloc(i_tmp))==0) {
				LM_CRIT("cfg. parser: out of memory.\n");
			} else {
				memcpy(str_tmp->s, tmp, i_tmp);
				str_tmp->len=i_tmp;
				(yyval.action)=mk_action(SET_ADV_PORT_T, 1, STR_ST, str_tmp);
				set_cfg_pos((yyval.action));
			}
		}
	}
#line 11210 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 835:
#line 3251 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11216 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 836:
#line 3252 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11222 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 837:
#line 3253 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(FORCE_SEND_SOCKET_T, 1, SOCKID_ST, (yyvsp[-1].sockid));
		set_cfg_pos((yyval.action));
	}
#line 11231 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 838:
#line 3257 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=0; yyerror("bad argument, [proto:]host[:port] expected");
	}
#line 11239 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 839:
#line 3260 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11245 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 840:
#line 3261 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(SET_FWD_NO_CONNECT_T, 0); set_cfg_pos((yyval.action));
	}
#line 11253 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 841:
#line 3264 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(SET_FWD_NO_CONNECT_T, 0); set_cfg_pos((yyval.action));
	}
#line 11261 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 842:
#line 3267 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(SET_RPL_NO_CONNECT_T, 0); set_cfg_pos((yyval.action));
	}
#line 11269 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 843:
#line 3270 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(SET_RPL_NO_CONNECT_T, 0); set_cfg_pos((yyval.action));
	}
#line 11277 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 844:
#line 3273 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(SET_FWD_CLOSE_T, 0); set_cfg_pos((yyval.action));
	}
#line 11285 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 845:
#line 3276 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(SET_FWD_CLOSE_T, 0); set_cfg_pos((yyval.action));
	}
#line 11293 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 846:
#line 3279 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(SET_RPL_CLOSE_T, 0); set_cfg_pos((yyval.action));
	}
#line 11301 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 847:
#line 3282 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(SET_RPL_CLOSE_T, 0); set_cfg_pos((yyval.action));
	}
#line 11309 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 848:
#line 3285 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(CFG_SELECT_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
	}
#line 11317 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 849:
#line 3288 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(CFG_SELECT_T, 2, STRING_ST, (yyvsp[-3].strval), RVE_ST, (yyvsp[-1].rv_expr)); set_cfg_pos((yyval.action));
	}
#line 11325 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 850:
#line 3291 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11331 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 851:
#line 3292 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad arguments, string and number expected"); }
#line 11337 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 852:
#line 3293 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(CFG_RESET_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action));
	}
#line 11345 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 853:
#line 3296 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11351 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 854:
#line 3297 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad arguments, string expected"); }
#line 11357 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 855:
#line 3298 "core/cfg.y" /* yacc.c:1646  */
    {mod_func_action = mk_action(MODULE0_T, 2, MODEXP_ST, NULL, NUMBER_ST,
			0); }
#line 11364 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 856:
#line 3299 "core/cfg.y" /* yacc.c:1646  */
    {
		mod_func_action->val[0].u.data =
			find_export_record((yyvsp[-4].strval), mod_func_action->val[1].u.number, rt,
								&u_tmp);
		if (mod_func_action->val[0].u.data == 0) {
			if (find_export_record((yyvsp[-4].strval), mod_func_action->val[1].u.number, 0,
									&u_tmp) ) {
					LM_ERR("misused command %s\n", (yyvsp[-4].strval));
					yyerror("Command cannot be used in the block\n");
			} else {
				LM_ERR("cfg. parser: failed to find command %s (params %ld)\n",
						(yyvsp[-4].strval), mod_func_action->val[1].u.number);
				yyerror("unknown command, missing loadmodule?\n");
			}
			free_mod_func_action(mod_func_action);
			mod_func_action=0;
		}else{
			if (mod_func_action && mod_f_params_pre_fixup(mod_func_action)<0) {
				/* error messages are printed inside the function */
				free_mod_func_action(mod_func_action);
				mod_func_action = 0;
				YYERROR;
			}
		}
		(yyval.action) = mod_func_action;
		set_cfg_pos((yyval.action));
	}
#line 11396 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 857:
#line 3326 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("'('')' expected (function call)");}
#line 11402 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 859:
#line 3330 "core/cfg.y" /* yacc.c:1646  */
    { }
#line 11408 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 860:
#line 3331 "core/cfg.y" /* yacc.c:1646  */
    {}
#line 11414 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 861:
#line 3334 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[0].rv_expr) && mod_func_action->val[1].u.number < MAX_ACTIONS-2) {
			mod_func_action->val[mod_func_action->val[1].u.number+2].type =
				RVE_ST;
			mod_func_action->val[mod_func_action->val[1].u.number+2].u.data =
				(yyvsp[0].rv_expr);
			mod_func_action->val[1].u.number++;
		} else if ((yyvsp[0].rv_expr)) {
			yyerror("Too many arguments\n");
			YYERROR;
		} else {
			YYERROR;
		}
	}
#line 11433 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 862:
#line 3351 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, 0, NUMBER_ST,
						(void*)(DROP_R_F|EXIT_R_F)); set_cfg_pos((yyval.action));
	}
#line 11442 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 863:
#line 3355 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, RVE_ST, (yyvsp[0].rv_expr), NUMBER_ST,
						(void*)(DROP_R_F|EXIT_R_F)); set_cfg_pos((yyval.action));
	}
#line 11451 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 864:
#line 3359 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, 0, NUMBER_ST,
						(void*)(DROP_R_F|EXIT_R_F)); set_cfg_pos((yyval.action));
	}
#line 11460 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 865:
#line 3363 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, (void*)1, NUMBER_ST,
						(void*)EXIT_R_F);
		set_cfg_pos((yyval.action));
	}
#line 11470 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 866:
#line 3368 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, RVE_ST, (yyvsp[0].rv_expr), NUMBER_ST, (void*)EXIT_R_F);
		set_cfg_pos((yyval.action));
	}
#line 11479 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 867:
#line 3372 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, (void*)1, NUMBER_ST,
						(void*)EXIT_R_F);
		set_cfg_pos((yyval.action));
	}
#line 11489 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 868:
#line 3377 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, (void*)1, NUMBER_ST,
						(void*)RETURN_R_F); set_cfg_pos((yyval.action));
	}
#line 11498 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 869:
#line 3381 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, (void*)1, NUMBER_ST,
						(void*)RETURN_R_F); set_cfg_pos((yyval.action));
	}
#line 11507 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 870:
#line 3385 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, RVE_ST, (yyvsp[0].rv_expr), NUMBER_ST, (void*)RETURN_R_F);
		set_cfg_pos((yyval.action));
	}
#line 11516 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 871:
#line 3389 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, 0, NUMBER_ST, (void*)BREAK_R_F);
		set_cfg_pos((yyval.action));
	}
#line 11525 "core/cfg.tab.c" /* yacc.c:1646  */
    break;


#line 11529 "core/cfg.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 3395 "core/cfg.y" /* yacc.c:1906  */


static void get_cpos(struct cfg_pos* pos)
{
	pos->s_line=startline;
	pos->e_line=line;
	pos->s_col=startcolumn;
	pos->e_col=column-1;
	if(finame==0)
		finame = (cfg_file!=0)?cfg_file:"default";
	pos->fname=finame;
	pos->rname=(routename!=0)?routename:default_routename;
}


static void warn_at(struct cfg_pos* p, char* format, ...)
{
	va_list ap;
	char s[256];

	va_start(ap, format);
	vsnprintf(s, sizeof(s), format, ap);
	va_end(ap);
	if (p->e_line!=p->s_line)
		LM_WARN("warning in config file %s, from line %d, column %d to"
					" line %d, column %d: %s\n",
					p->fname, p->s_line, p->s_col, p->e_line, p->e_col, s);
	else if (p->s_col!=p->e_col)
		LM_WARN("warning in config file %s, line %d, column %d-%d: %s\n",
					p->fname, p->s_line, p->s_col, p->e_col, s);
	else
		LM_WARN("warning in config file %s, line %d, column %d: %s\n",
				p->fname, p->s_line, p->s_col, s);
	cfg_warnings++;
}



static void yyerror_at(struct cfg_pos* p, char* format, ...)
{
	va_list ap;
	char s[256];

	va_start(ap, format);
	vsnprintf(s, sizeof(s), format, ap);
	va_end(ap);
	if (p->e_line!=p->s_line)
		LM_CRIT("parse error in config file %s, from line %d, column %d"
					" to line %d, column %d: %s\n",
					p->fname, p->s_line, p->s_col, p->e_line, p->e_col, s);
	else if (p->s_col!=p->e_col)
		LM_CRIT("parse error in config file %s, line %d, column %d-%d: %s\n",
					p->fname, p->s_line, p->s_col, p->e_col, s);
	else
		LM_CRIT("parse error in config file %s, line %d, column %d: %s\n",
					p->fname, p->s_line, p->s_col, s);
	cfg_errors++;
}



static void warn(char* format, ...)
{
	va_list ap;
	char s[256];
	struct cfg_pos pos;

	get_cpos(&pos);
	va_start(ap, format);
	vsnprintf(s, sizeof(s), format, ap);
	va_end(ap);
	warn_at(&pos, s);
}



static void yyerror(char* format, ...)
{
	va_list ap;
	char s[256];
	struct cfg_pos pos;

	get_cpos(&pos);
	va_start(ap, format);
	vsnprintf(s, sizeof(s), format, ap);
	va_end(ap);
	yyerror_at(&pos, s);
}



/** mk_rval_expr_v wrapper.
 *  checks mk_rval_expr_v return value and sets the cfg. pos
 *  (line and column numbers)
 *  @return rval_expr* on success, 0 on error (@see mk_rval_expr_v)
 */
static struct rval_expr* mk_rve_rval(enum rval_type type, void* v)
{
	struct rval_expr* ret;
	struct cfg_pos pos;

	get_cpos(&pos);
	ret=mk_rval_expr_v(type, v, &pos);
	if (ret==0){
		yyerror("internal error: failed to create rval expr");
		/* YYABORT; */
	}
	return ret;
}


/** mk_rval_expr1 wrapper.
 *  checks mk_rval_expr1 return value (!=0 and type checking)
 *  @return rval_expr* on success, 0 on error (@see mk_rval_expr1)
 */
static struct rval_expr* mk_rve1(enum rval_expr_op op, struct rval_expr* rve1)
{
	struct rval_expr* ret;
	struct rval_expr* bad_rve;
	enum rval_type type, bad_t, exp_t;

	if (rve1==0)
		return 0;
	ret=mk_rval_expr1(op, rve1, &rve1->fpos);
	if (ret && (rve_check_type(&type, ret, &bad_rve, &bad_t, &exp_t)!=1)){
		yyerror_at(&rve1->fpos, "bad expression: type mismatch"
					" (%s instead of %s)", rval_type_name(bad_t),
					rval_type_name(exp_t));
		rve_destroy(ret);
		ret=0;
	}
	return ret;
}


/** mk_rval_expr2 wrapper.
 *  checks mk_rval_expr2 return value (!=0 and type checking)
 *  @return rval_expr* on success, 0 on error (@see mk_rval_expr2)
 */
static struct rval_expr* mk_rve2(enum rval_expr_op op, struct rval_expr* rve1,
									struct rval_expr* rve2)
{
	struct rval_expr* ret;
	struct rval_expr* bad_rve;
	enum rval_type type, bad_t, exp_t;
	struct cfg_pos pos;

	if ((rve1==0) || (rve2==0))
		return 0;
	bad_rve=0;
	bad_t=0;
	exp_t=0;
	cfg_pos_join(&pos, &rve1->fpos, &rve2->fpos);
	ret=mk_rval_expr2(op, rve1, rve2, &pos);
	if (ret && (rve_check_type(&type, ret, &bad_rve, &bad_t, &exp_t)!=1)){
		if (bad_rve)
			yyerror_at(&pos, "bad expression: type mismatch:"
						" %s instead of %s at (%d,%d)",
						rval_type_name(bad_t), rval_type_name(exp_t),
						bad_rve->fpos.s_line, bad_rve->fpos.s_col);
		else
			yyerror("BUG: unexpected null \"bad\" expression\n");
		rve_destroy(ret);
		ret=0;
	}
	return ret;
}


/** check if the expression is an int.
 * if the expression does not evaluate to an int return -1 and
 * log an error.
 * @return 0 success, no warnings; 1 success but warnings; -1 on error */
static int rval_expr_int_check(struct rval_expr *rve)
{
	struct rval_expr* bad_rve;
	enum rval_type type, bad_t, exp_t;

	if (rve==0){
		yyerror("invalid expression");
		return -1;
	}else if (!rve_check_type(&type, rve, &bad_rve, &bad_t ,&exp_t)){
		if (bad_rve)
			yyerror_at(&rve->fpos, "bad expression: type mismatch:"
						" %s instead of %s at (%d,%d)",
						rval_type_name(bad_t), rval_type_name(exp_t),
						bad_rve->fpos.s_line, bad_rve->fpos.s_col);
		else
			yyerror("BUG: unexpected null \"bad\" expression\n");
		return -1;
	}else if (type!=RV_INT && type!=RV_NONE){
		warn_at(&rve->fpos, "non-int expression (you might want to use"
				" casts)\n");
		return 1;
	}
	return 0;
}


/** warn if the expression is constant.
 * @return 0 on success (no warning), 1 when warning */
static int warn_ct_rve(struct rval_expr *rve, char* name)
{
	if (rve && rve_is_constant(rve)){
		warn_at(&rve->fpos, "constant value in %s%s",
				name?name:"expression", name?"(...)":"");
		return 1;
	}
	return 0;
}


static struct name_lst* mk_name_lst(char* host, int flags)
{
	struct name_lst* l;
	if (host==0) return 0;
	l=pkg_malloc(sizeof(struct name_lst));
	if (l==0) {
		LM_CRIT("cfg. parser: out of memory.\n");
	} else {
		l->name=host;
		l->flags=flags;
		l->next=0;
	}
	return l;
}


static struct socket_id* mk_listen_id(char* host, int proto, int port)
{
	struct socket_id* l;
	if (host==0) return 0;
	l=pkg_malloc(sizeof(struct socket_id));
	if (l==0) {
		LM_CRIT("cfg. parser: out of memory.\n");
	} else {
		l->addr_lst=mk_name_lst(host, 0);
		if (l->addr_lst==0){
			pkg_free(l);
			return 0;
		}
		l->flags=0;
		l->port=port;
		l->proto=proto;
		l->next=0;
	}
	return l;
}


static void free_name_lst(struct name_lst* lst)
{
	struct name_lst* tmp;

	while(lst){
		tmp=lst;
		lst=lst->next;
		pkg_free(tmp);
	}
}


static struct socket_id* mk_listen_id2(struct name_lst* addr_l, int proto,
										int port)
{
	struct socket_id* l;
	if (addr_l==0) return 0;
	l=pkg_malloc(sizeof(struct socket_id));
	if (l==0) {
		LM_CRIT("cfg. parser: out of memory.\n");
	} else {
		l->flags=addr_l->flags;
		l->port=port;
		l->proto=proto;
		l->addr_lst=addr_l;
		l->next=0;
	}
	return l;
}


static void free_socket_id(struct socket_id* i)
{
	free_name_lst(i->addr_lst);
	pkg_free(i);
}


static void free_socket_id_lst(struct socket_id* lst)
{
	struct socket_id* tmp;

	while(lst){
		tmp=lst;
		lst=lst->next;
		free_socket_id(tmp);
	}
}


/** create a temporary case statmenet structure.
 *  *err will be filled in case of error (return == 0):
 *   -1 - non constant expression
 *   -2 - expression error (bad type)
 *   -10 - memory allocation error
 */
static struct case_stms* mk_case_stm(struct rval_expr* ct, int is_re,
											struct action* a, int* err)
{
	struct case_stms* s;
	struct rval_expr* bad_rve;
	enum rval_type type, bad_t, exp_t;
	enum match_str_type t;

	t=MATCH_UNKNOWN;
	if (ct){
		/* if ct!=0 => case, else if ct==0 is a default */
		if (!rve_is_constant(ct)){
			yyerror_at(&ct->fpos, "non constant expression in case");
			*err=-1;
			return 0;
		}
		if (rve_check_type(&type, ct, &bad_rve, &bad_t, &exp_t)!=1){
			yyerror_at(&ct->fpos, "bad expression: type mismatch:"
							" %s instead of %s at (%d,%d)",
							rval_type_name(bad_t), rval_type_name(exp_t),
							bad_rve->fpos.s_line, bad_rve->fpos.s_col);
			*err=-2;
			return 0;
		}
		if (is_re)
			t=MATCH_RE;
		else if (type==RV_STR)
			t=MATCH_STR;
		else
			t=MATCH_INT;
	}

	s=pkg_malloc(sizeof(*s));
	if (s==0) {
		yyerror("internal error: memory allocation failure");
		*err=-10;
	} else {
		memset(s, 0, sizeof(*s));
		s->ct_rve=ct;
		s->type=t;
		s->actions=a;
		s->next=0;
		s->append=0;
	}
	return s;
}


/*
 * @return 0 on success, -1 on error.
 */
static int case_check_type(struct case_stms* stms)
{
	struct case_stms* c;
	struct case_stms* s;

	for(c=stms; c ; c=c->next){
		if (!c->ct_rve) continue;
		for (s=c->next; s; s=s->next){
			if (!s->ct_rve) continue;
			if ((s->type!=c->type) &&
				!(	(c->type==MATCH_STR || c->type==MATCH_RE) &&
					(s->type==MATCH_STR || s->type==MATCH_RE) ) ){
					yyerror_at(&s->ct_rve->fpos, "type mismatch in case");
					return -1;
			}
		}
	}
	return 0;
}


/*
 * @return 0 on success, -1 on error.
 */
static int case_check_default(struct case_stms* stms)
{
	struct case_stms* c;
	int default_no;

	default_no=0;
	for(c=stms; c ; c=c->next)
		if (c->ct_rve==0) default_no++;
	return (default_no<=1)?0:-1;
}



/** fixes the parameters and the type of a module function call.
 * It is done here instead of fix action, to have quicker feedback
 * on error cases (e.g. passing a non constant to a function with a
 * declared fixup)
 * The rest of the fixup is done inside do_action().
 * @param a - filled module function call (MODULE*_T) action structure
 *            complete with parameters, starting at val[2] and parameter
 *            number at val[1].
 * @return 0 on success, -1 on error (it will also print the error msg.).
 *
 */
static int mod_f_params_pre_fixup(struct action* a)
{
	sr31_cmd_export_t* cmd_exp;
	action_u_t* params;
	int param_no;
	struct rval_expr* rve;
	struct rvalue* rv;
	int r;
	str s;

	cmd_exp = a->val[0].u.data;
	param_no = a->val[1].u.number;
	params = &a->val[2];

	switch(cmd_exp->param_no) {
		case 0:
			a->type = MODULE0_T;
			break;
		case 1:
			a->type = MODULE1_T;
			break;
		case 2:
			a->type = MODULE2_T;
			break;
		case 3:
			a->type = MODULE3_T;
			break;
		case 4:
			a->type = MODULE4_T;
			break;
		case 5:
			a->type = MODULE5_T;
			break;
		case 6:
			a->type = MODULE6_T;
			break;
		case VAR_PARAM_NO:
			a->type = MODULEX_T;
			break;
		default:
			yyerror("function %s: bad definition"
					" (invalid number of parameters)", cmd_exp->name);
			return -1;
	}

	if ( cmd_exp->fixup) {
		if (is_fparam_rve_fixup(cmd_exp->fixup))
			/* mark known fparam rve safe fixups */
			cmd_exp->fixup_flags  |= FIXUP_F_FPARAM_RVE;
		else if (!(cmd_exp->fixup_flags & FIXUP_F_FPARAM_RVE) &&
				 cmd_exp->free_fixup == 0) {
			/* v0 or v1 functions that have fixups and no coresp. fixup_free
			   functions, need constant, string params.*/
			for (r=0; r < param_no; r++) {
				rve=params[r].u.data;
				if (!rve_is_constant(rve)) {
					yyerror_at(&rve->fpos, "function %s: parameter %d is not"
								" constant\n", cmd_exp->name, r+1);
					return -1;
				}
				if ((rv = rval_expr_eval(0, 0, rve)) == 0 ||
						rval_get_str(0, 0, &s, rv, 0) < 0 ) {
					/* out of mem or bug ? */
					rval_destroy(rv);
					yyerror_at(&rve->fpos, "function %s: bad parameter %d"
									" expression\n", cmd_exp->name, r+1);
					return -1;
				}
				rval_destroy(rv);
				rve_destroy(rve);
				params[r].type = STRING_ST; /* asciiz */
				params[r].u.string = s.s;
				params[r].u.str.len = s.len; /* not used right now */
			}
		}
	}/* else
		if no fixups are present, the RVEs can be transformed
		into strings at runtime, allowing seamless var. use
		even with old functions.
		Further optimizations -> in fix_actions()
		*/
	return 0;
}



/** frees a filled module function call action structure.
 * @param a - filled module function call action structure
 *            complete with parameters, starting at val[2] and parameter
 *            number at val[1].
 */
static void free_mod_func_action(struct action* a)
{
	action_u_t* params;
	int param_no;
	int r;

	param_no = a->val[1].u.number;
	params = &a->val[2];

	for (r=0; r < param_no; r++)
		if (params[r].u.data)
			rve_destroy(params[r].u.data);
	pkg_free(a);
}



/*
int main(int argc, char ** argv)
{
	if (yyparse()!=0)
		fprintf(stderr, "parsing error\n");
}
*/
