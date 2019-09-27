NAME = libft.a
OBJECTS = *.o
SRC = ft_array_free.c ft_atoi.c ft_atol.c ft_bzero.c ft_getlen.c ft_intlen.c
SRC += ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c
SRC += ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstmap.c
SRC += ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c
SRC += ft_memdel.c ft_memmove.c ft_memset.c ft_negcase.c ft_populatearray.c ft_poscase.c
SRC += ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c
SRC += ft_putnbr.c ft_putstr_colour.c ft_putstr_fd.c ft_putstr.c ft_str_is_numeric.c
SRC += ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c
SRC += ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c
SRC += ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c
SRC += ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c
SRC += ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_word_count.c
SRC += ft_word_len.c ft_putchar_colour.c get_next_line.c
FLAGS = -Wall -Werror -Wextra
OPTIONS = -c -I.

all: $(NAME)

$(NAME): 
	@gcc $(FLAGS) $(SRC) $(OPTIONS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean: 
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
