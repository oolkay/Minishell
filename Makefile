NAME	:= minishell

CC		:= gcc 
INCLUDE	:= ./libraries
CFLAGS	:= -ggdb -I $(INCLUDE) -I ./libft
LIBFT	= libft
FLAGS	= -Wall -Wextra -Werror

SRCDIR	:= src
SRC		:= src/utils/ft_fill_env.c \
			src/utils/input_checker.c \
			src/parser/ft_trim_quotes.c \
			src/parser/parser_utils.c \
			src/parser/parser.c \
			src/parser/subsplit.c \
			src/init_and_termiante/free_functs.c \
			src/init_and_termiante/ft_banner.c \
			src/init_and_termiante/ft_error.c \
			src/init_and_termiante/ft_exit.c \
			src/init_and_termiante/ft_signal.c \
			src/fill_block/fill_block.c \
			src/fill_block/fill_blocks_utils.c \
			src/fill_block/fill_blocks_utils2.c \
			src/fill_block/heredocfile.c \
			src/expander/expander.c \
			src/expander/expander_utils.c \
			src/executer/ft_execute.c \
			src/executer/get_path.c \
			src/built_in/ft_cd.c \
			src/built_in/ft_echo.c \
			src/built_in/ft_env.c \
			src/built_in/ft_export.c \
			src/built_in/ft_pwd.c \
			src/built_in/ft_unset.c \
			src/built_in/ft_exit_b.c \
			src/built_in/built_in_utils.c \
			src/main.c

OBJDIR	:= ./objectives
OBJ		:= $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cp libft/libft.a .
	@$(CC) -L /goinfre/homebrew/Cellar/readline/8.2.1/lib -I /goinfre/homebrew/Cellar/readline/8.2.1/include $(FLAGS) $(CFLAGS) $(OBJ) libft.a -lreadline -o $@

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -I ~/.brew/opt/readline/include -I /goinfre/homebrew/Cellar/readline/8.2.1/include $(FLAGS) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	rm -rf libft.a
	@rm -rf $(OBJDIR)

fclean:
	make fclean -C $(LIBFT)
	rm -rf libft.a
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=definite ./$(NAME)

norm:
	norminette libft

re:	fclean all
