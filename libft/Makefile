GCC       =	gcc
GCCFLAGS  =	-Wall -Wextra -Werror
AR        =	ar
NAME      =	libft.a
INCLUDE   =	include include/printf
PRINTFOBJ =	main.o           extras.o        display.o         utilities.o
OBJS      =	ft_atoi.o        ft_bzero.o      ft_isalnum.o      ft_isalpha.o    \
           	ft_isdigit.o     ft_isprint.o    ft_itoa.o         ft_lstadd.o     \
           	ft_lstdelone.o   ft_lstiter.o    ft_lstmap.o       ft_lstnew.o     \
           	ft_memccpy.o     ft_memchr.o     ft_memcmp.o       ft_memcpy.o     \
           	ft_memmove.o     ft_memset.o     ft_putchar.o      ft_putchar_fd.o \
           	ft_putendl_fd.o  ft_putnbr.o     ft_putnbr_fd.o    ft_putstr.o     \
           	ft_strcat.o      ft_strchr.o     ft_strclr.o       ft_strcmp.o     \
           	ft_strdel.o      ft_strdup.o     ft_strequ.o       ft_striter.o    \
           	ft_strjoin.o     ft_strlcat.o    ft_strlen.o       ft_strmap.o     \
           	ft_strncat.o     ft_strncmp.o    ft_strncpy.o      ft_strnequ.o    \
           	ft_strnstr.o     ft_strrchr.o    ft_strsplit.o     ft_strstr.o     \
           	ft_strtrim.o     ft_tolower.o    ft_toupper.o      ft_min.o        \
           	ft_itoa_base.o   ft_isblank.o    ft_chrrep.o       ft_strrev.o     \
           	ft_putnbr_base.o ft_printmem.o   ft_nbrlen.o       ft_realloc.o    \
           	ft_abs.o         ft_strndup.o    ft_itoa_base64.o  ft_strlowcase.o \
           	ft_strcmpcase.o  ft_seekstr.o    ft_expect.o       ft_wstrlen.o    \
           	ft_uitoa64.o     ft_uitoa_base.o ft_uitoa_base64.o ft_itoa64.o     \
           	ft_arraycount.o  ft_memdup.o     ft_parseint.o     ft_lstlen.o     \
           	ft_isascii.o     ft_lstdel.o     ft_memalloc.o     ft_memdel.o     \
           	ft_putendl.o     ft_putstr_fd.o  ft_strcpy.o       ft_striteri.o   \
           	ft_strmapi.o     ft_strnew.o     ft_strsub.o       ft_max.o        \
           	ft_rot13.o       ft_arraydel.o   ft_strupcase.o    ft_uitoa.o      \
           	ft_arrayfind.o   ft_lstdup.o
OBJPATH   =	../objs/libft
DEPS      =	$(addprefix $(OBJPATH)/printf/,$(PRINTFOBJ))\
           	$(addprefix $(OBJPATH)/,$(OBJS))
# ------------------------------------------------------------------------------

.PHONY: all clean fclean re

all: $(OBJPATH)/$(NAME)
	@printf "$(NAME): Nothing more to be done!\n"

$(OBJPATH)/$(NAME): $(DEPS)
	@printf "Linking $@ ... "
	@$(AR) -cr $@ $^
	@printf "OK!\n"

$(OBJPATH)/printf/%.o: srcs/printf/%.c
	@printf "Compiling $@ ... "
	@mkdir -p $(OBJPATH)/printf
	@$(GCC) $(GCCFLAGS) -c -o $@ $(addprefix -I,$(INCLUDE)) $<
	@printf "OK!\n"

$(OBJPATH)/%.o: srcs/%.c
	@printf "Compiling $@ ... "
	@mkdir -p $(OBJPATH)
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
