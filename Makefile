##
## Makefile for PSU_2016_42sh in /home/bender/LASTP/psu_2016_42sh
## 
## Made by Bender_Jr
## Login   <@epitech.eu>
## 
## Started on  Mon Apr 10 09:27:20 2017 Bender_Jr
## Last update Fri Apr 14 18:43:37 2017 Bender_Jr
##

CC		= gcc

RM		= rm -f

##
## Release build Flags
##
CFLAGS		+= -Wextra -Wall -Werror -ansi
CFLAGS		+= -O2 -fstack-protector -fPIC
CFLAGS		+= -D_FORTIFY_SOURCE=2
CFLAGS		+= -I./include/

##
## d-bug flags
##
DFLAGS		+= -O0 -g3 -D DEBUG -I./include/

LDFLAGS		+= -z relro -z now -pie

42SH		= 42sh
PARSER		= parser

SRCS		= lib/core/base.c		\
		lib/core/base2.c		\
		lib/core/flag_match.c		\
		lib/core/flgs.c			\
		lib/core/get_next_line.c	\
		lib/core/printf.c		\
		lib/core/putnbr.c		\
		lib/core/string.c		\
		lib/core/stringbis.c		\
		lib/core/strtowordtab.c

SRC_SHELL	= $(SRCS)			\
		src/main.c

SRC_PARSER	= $(SRCS)			\
		src/check.c			\
		src/fill_tree.c			\
		src/get_keywrd.c		\
		src/node_ops.c			\
		src/tree.c			\
		src/tree_utils.c		\
		src/parser.c

OBJ_S		= $(SRC_SHELL:.c=.o)

OBJ_P		= $(SRC_PARSER:.c=.o)

$(PARSER):	$(OBJ_P)
		$(CC) $(OBJ_P) -o $(PARSER)

$(SHELL):	$(OBJ_S)
		$(CC) $(OBJ_S) -o $(42SH) $(LDFLAGS)

all:		$(42SH)

parser:		$(PARSER)

dbgsh:
		$(CC)  $(DFLAGS) -g3 -D DEBUG $(SRC_SHELL) -o dbg42

dbgpars:
		$(CC)  $(DFLAGS) -g3 -D DEBUG $(SRC_PARSER) -o dbgpars

clean:
		$(RM) $(OBJ_S) $(OBJ_P)

fclean:		clean
		$(RM) $(42SH) $(PARSER)

re:		fclean all

.PHONY:		all clean fclean re
