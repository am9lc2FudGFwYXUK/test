/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

union YYSTYPE
{
#line 199 "core/cfg.y" /* yacc.c:1909  */

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

#line 408 "core/cfg.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CORE_CFG_TAB_H_INCLUDED  */
