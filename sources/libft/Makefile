NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I. -c

SRC = 	ft_atoi.c \
		ft_memset.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_putstr_fd.c \
		ft_putstr.c \
		ft_putchar.c \
		ft_putnbr_fd.c \
		ft_strncpy.c	\
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_split.c \
		ft_strdup.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strtrim.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_strnew.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_substr.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_toupper.c \
		ft_tolower.c \

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(OBJ) $(BONUS_OBJ)
	ar rc $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
