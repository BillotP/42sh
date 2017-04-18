##
## Makefile for PSU_2016_42sh in /home/bender/LASTP/psu_2016_42sh
## 
## Made by Bender_Jr
## Login   <@epitech.eu>
## 
## Started on  Mon Apr 10 09:27:20 2017 Bender_Jr
## Last update Tue Apr 18 10:33:32 2017 Bender_Jr
##

uname_s := $(shell uname -srm)
$(info ' **************************************************************************  ')
$(info '    _  _   .___________. _______  __  ___      _______. __    __     _  _    ')   
$(info '  _| || |_ |           ||   ____||  |/  /     /       ||  |  |  |  _| || |_  ') 
$(info ' |_  __  _|`---|  |----`|  |__   |  '  /     |   |----`|  |__|  | |_  __  _| ')
$(info '  _| || |_     |  |     |   __|  |    <       \   \    |   __   |  _| || |_  ') 
$(info ' |_  __  _|    |  |     |  |____ |  .  \  .----    |   |  |  |  | |_  __  _| ')
$(info '   |_||_|      |__|     |_______||__|\__\ |_______/    |__|  |__|   |_||_|   ')
$(info ' *************************************************************************** ')
$(info   =============  You run at $(uname_s) OS ================= )

CC		= gcc

RM		= @rm -f

##
## Release build Flags
##
CFLAGS		+= -Wextra -Wall -Werror -std=gnu90
CFLAGS		+= -O2 -fstack-protector -fPIC
CFLAGS		+= -D_FORTIFY_SOURCE=2
CFLAGS		+= -I./include/

##
## d-bug flags
##
DFLAGS		+= -O0 -g3 -D DEBUG -std=gnu90 -I./include/

LDFLAGS		+= -z relro -z now -pie

NAME		= 42sh

TEST		= parser

SRCS		= lib/core/base.c		\
		lib/core/base2.c		\
		lib/core/check.c		\
		lib/core/flag_match.c		\
		lib/core/flgs.c			\
		lib/core/get_next_line.c	\
		lib/core/printf.c		\
		lib/core/putnbr.c		\
		lib/core/string.c		\
		lib/core/stringbis.c		\
		lib/core/strtowordtab.c

SRC_S		= $(SRCS)			\
		src/prompt_print/prompt.c	\
		src/prompt_print/pr_printf.c	\
		src/termios/termios.c		\
		src/main.c

SRC_P		= $(SRCS)				\
		src/scripting/fill_tree.c		\
		src/scripting/get_keywrd.c		\
		src/scripting/node_ops.c		\
		src/scripting/tree.c			\
		src/scripting/tree_utils.c		\
		src/scripting/parser.c

OBJ_S		= $(SRC_S:.c=.o)
OBJ_P		= $(SRC_P:.c=.o)

all:		$(NAME)

parser:		$(TEST)

$(TEST):	$(OBJ_P)
		$(CC) $(OBJ_P) -o $(TEST) $(LDFLAGS)

$(NAME):	$(OBJ_S)
		$(CC) $(OBJ_S) -o $(NAME) $(LDFLAGS)

dbgsh:
		$(CC)  $(DFLAGS) -g3 -D DEBUG $(SRC_S) -o $(NAME)

dbgpars:
		$(CC)  $(DFLAGS) -g3 -D DEBUG $(SRC_P) -o $(TEST)

clean:
		$(RM) 	$(OBJ_S)
		$(RM)	$(OBJ_P)

fclean:		clean
		$(RM) 	$(NAME)
		$(RM)	$(TEST)

re:		fclean all

.PHONY:		all clean
