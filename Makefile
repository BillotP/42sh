##
## Makefile for PSU_2016_42sh in /home/bender/LASTP/psu_2016_42sh
## 
## Made by Bender_Jr
## Login   <@epitech.eu>
## 
## Started on  Mon Apr 10 09:27:20 2017 Bender_Jr
## Last update Mon Apr 10 09:38:35 2017 Bender_Jr
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
DFLAGS		+= -O0 -g3 -I./include/

LDFLAGS		+= -z relro -z now -pie

NAME		= 42sh

SRCS		= lib/core/base.c		\
		lib/core/base2.c		\
		lib/core/flag_match.c		\
		lib/core/flgs.c			\
		lib/core/get_next_line.c	\
		lib/core/printf.c		\
		lib/core/putnbr.c		\
		lib/core/string.c		\
		lib/core/stringbis.c		\
		lib/core/strtowordtab.c		\
		src/main.c


OBJS		= $(SRCS:.c=.o)


$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

all:		$(NAME)


dbg:
		$(CC)  $(DFLAGS) -g3 -D DEBUG $(SRCS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
