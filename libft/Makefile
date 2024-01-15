NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_strcpy.c ft_strcat.c ft_atoi.c ft_strcmp.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

B_SRC = ft_lstnew.c ft_strcmp.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar -rcs $(NAME) $(OBJ)

bonus : $(OBJ)
	@$(CC) $(CFLAGS) -c $(B_SRC)
	@ar -rcs $(NAME) $(OBJ) $(B_OBJ)

re : fclean all

clean :
	@rm -rf $(OBJ) $(B_OBJ)

fclean : clean
	@rm -rf $(NAME)

.PHONY : all bonus clean fclean re
