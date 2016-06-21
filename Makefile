GCC      =	gcc
GCCFLAGS =	-Wall -Wextra -Werror
NAME     =	lem-in
OBJS     =	main.o                       parsing/build_data.o         \
          	parsing/parse_flags.o        parsing/parse_input.o        \
          	parsing/read_input.o         processing/process_command.o \
          	processing/process_comment.o processing/process_node.o    \
          	processing/process_room.o    simulation/reset_simulation.o\
          	simulation/run_simulation.o  miscellaneous/key_to_hash.o
INCLUDE  =	include libft/include
# -------------------------------------------------

.PHONY: all clean fclean re

all: libft/libft.a $(NAME)
	@printf "Nothing more to be done!\n"

libft/libft.a:
	@make -C libft all

$(NAME): $(addprefix objs/,$(OBJS))
	@printf "Linking $@ ... "
	@$(GCC) $(GCCFLAGS) -o $@ $^ libft/libft.a
	@printf "OK!\n"

objs/%.o: srcs/%.c
	@printf "Compiling $@ ... "
	@mkdir -p objs
	@mkdir -p objs/miscellaneous
	@mkdir -p objs/parsing
	@mkdir -p objs/processing
	@mkdir -p objs/simulation
	@$(GCC) $(GCCFLAGS) -c -o $@ $(addprefix -I,$(INCLUDE)) $<
	@printf "OK!\n"

clean:
	@printf "Removing object files ... "
	@rm -rf objs
	@printf "OK!\n"

fclean: clean
	@printf "Removing target ... "
	@rm -f $(NAME)
	@printf "OK!\n"

re: fclean all
