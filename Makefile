CC      =	gcc
CFLAGS  =	#-Wall -Wextra -Werror
NAME    =	lem-in
SRCS    =	main.c helpers.c process.c
INCLUDE =	include libft/include

# -------------------------------

_SRCS   =	$(addprefix srcs/,$(SRCS))
_OBJS   =	libft/libft.a
_IPROJ  =	include
_ILIBFT =	libft/include

all: $(_OBJS) $(NAME)

libft/libft.a:
	@make -C libft re;

$(NAME):
	$(CC) $(CFLAGS) -o$@ -I$(_ILIBFT) -I$(_IPROJ) $(_SRCS) $(_OBJS);

clean:
	@make -C libft clean

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME);

re: fclean all

renolibft: clean
	@rm -f $(NAME)
	@make all

.PHONY: all clean fclean re
