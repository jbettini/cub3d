CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	libft.a
SRC_DIR		=	srcs
OBJ_DIR		=	srcs/objs
I_DIR		=	includes

SRC			=	ft_memset.c		\
				ft_bzero.c		\
				ft_memcpy.c		\
				ft_memmove.c 	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_strlen.c		\
				ft_isalpha.c 	\
				ft_isdigit.c	\
				ft_isalnum.c	\
				ft_isascii.c	\
				ft_isprint.c	\
				ft_toupper.c	\
				ft_tolower.c	\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_strncmp.c	\
				ft_strlcpy.c	\
				ft_strlcat.c	\
				ft_strnstr.c	\
				ft_atoi.c		\
				ft_calloc.c		\
				ft_strdup.c		\
				ft_substr.c		\
				ft_strjoin.c 	\
				ft_strtrim.c	\
				ft_split.c		\
				ft_itoa.c		\
				ft_strmapi.c	\
				ft_putchar_fd.c	\
				ft_putstr_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\
				ft_striteri.c	\
				ft_putstr.c		\
				ft_putchar.c	\
				ft_atoi_long_long.c	\
				is_number.c		\
				get_next_line.c	\
				ft_printf.c \
				is_flag.c	\
				get_opts.c	\
				print_char.c	\
				print_str.c	\
				print_ptr.c	\
				print_int.c	\
				print_percentage.c	\
				print_uint.c	\
				print_hexa.c	\
				ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstclear.c		\
				ft_lstdelone.c		\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_join_and_free.c	\
				ft_base.c \

OBJ				=	$(SRC:%.c=%.o)
OBJ_PFX			=	$(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(OBJ_PFX)
	ar -rcs $(NAME) $(OBJ_PFX)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< -I$(I_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re