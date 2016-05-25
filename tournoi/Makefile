##
## Makefile for tetris in /home/cheval_8/rendu/PSU_2015_tetris
##
## Made by Chevalier Nicolas
## Login   <cheval_8@epitech.net>
##
## Started on  Wed Feb 24 16:02:04 2016 Chevalier Nicolas
## Last update Sun May 22 23:16:42 2016 Nicolas Chevalier
##


NAME		=	solver

SRC		= 	src/main.c \
			src/list.c \
			src/parser.c \
			src/algorithm.c \
			src/neighbours.c

MOD		=	 $(SRC:.c=.o)

LIB		=	-L../lib/
LIB		+=	-I../lib/include -L../lib/ -lmyutils

LIBMYUTILS_MAKE	=	make -C ../lib/
LIBMYUTILS	=	lib/libmyutils.a

CFLAGS		=	-W -Wall -Werror -Wextra
CFLAGS		+=	-O2
CFLAGS		+=	-Iinclude/
CFLAGS		+=	$(LIB)

LDFLAGS		=	$(LIB)

all:		$(LIBMYUTILS) $(NAME)

$(NAME):	$(MOD)
		@cc $(MOD) -o $(NAME) $(LDFLAGS)

$(LIBMYUTILS):
	 	$(LIBMYUTILS_MAKE)

clean		:
		 rm -rf $(MOD)
		 $(LIBMYUTILS_MAKE) clean

fclean		: clean
		  rm -rf $(NAME)
		  $(LIBMYUTILS_MAKE) fclean

re:		fclean all

.PHONY:		all clean fclean re
