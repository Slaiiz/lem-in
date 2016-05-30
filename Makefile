CC      =	gcc
CFLAGS  =	-Wall -Wextra -Werror
NAME    =	lem-in
SRCS    =	main.c
INCLUDE =	include libft/include

vpath %.a libft
vpath %.o get_next_line

_SRCS   =	$(addprefix srcs/,$(SRCS))
_OBJS   =	libft/libft.a get_next_line/get_next_line.o
_IPROJ  =	include
_IGNL   =	get_next_line
_ILIBFT =	libft/include

# -------------------------------

all: $(_OBJS) $(NAME)

libft.a:
	make -C libft re;

get_next_line.o:
	@cd get_next_line;\
	$(CC) -Wall -Wextra -Werror -c -o$@ -I../$(_ILIBFT) get_next_line.c;

$(NAME):
	$(CC) $(CFLAGS) -o$@ -I$(_ILIBFT) -I$(_IGNL) -I$(_IPROJ) $(_SRCS) $(_OBJS);

clean:
	rm -f $(NAME);

fclean: clean
	rm -f $(_SRCS);

re: fclean all

.PHONY: all clean fclean re
