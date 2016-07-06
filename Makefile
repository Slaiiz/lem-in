GCC      =	gcc
GCCFLAGS =	-Wall -Wextra -Werror
NAME     =	lem-in
INCLUDE  =	include libft/include
OBJS     =	main.o                       parsing/build_data.o         \
          	parsing/parse_flags.o        parsing/parse_input.o        \
          	parsing/read_input.o         processing/process_command.o \
          	processing/process_comment.o processing/process_node.o    \
          	processing/process_room.o    simulation/reset_simulation.o\
          	simulation/run_simulation.o  miscellaneous/key_to_hash.o  \
			simulation/compute_route.o   simulation/advance.o         \
			simulation/step_back.o       simulation/mark_visit.o      \
			simulation/optimize_route.o
OBJPATH  =	objs
_DEPS    =	$(addprefix $(OBJPATH)/,$(OBJS))
# -------------------------------------------------

.PHONY: all clean fclean re

all: objs/libft/libft.a $(NAME)
	@printf "$(NAME): Nothing more to be done!\n"

objs/libft/libft.a:
	@make -C libft all

$(NAME): $(_DEPS)
	@printf "Linking $@ ... "
	@$(GCC) $(GCCFLAGS) -o $@ $^ objs/libft/libft.a
	@printf "OK!\n"

objs/%.o: srcs/%.c
	@printf "Compiling $@ ... "
	@mkdir -p $(OBJPATH)
	@mkdir -p $(OBJPATH)/miscellaneous
	@mkdir -p $(OBJPATH)/parsing
	@mkdir -p $(OBJPATH)/processing
	@mkdir -p $(OBJPATH)/simulation
	@$(GCC) $(GCCFLAGS) -c -o $@ $(addprefix -I,$(INCLUDE)) $<
	@printf "OK!\n"

clean:
	@printf "Removing object files ... "
	@rm -rf $(OBJPATH)
	@printf "OK!\n"

fclean: clean
	@printf "Removing target ... "
	@rm -f $(NAME)
	@printf "OK!\n"

re: fclean all
