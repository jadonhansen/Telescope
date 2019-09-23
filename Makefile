HM = Telescope
LIB = libft
FLAGS = -Wall -Werror -Wextra
SRCS = ./srcs/Telescope.c ./srcs/struct_handling.c
OPTIONS = -I./srcs/libft -lft -L./srcs/libft

all: $(LIB) $(HM)

$(LIB): relib cleanlib

$(HM):
	@gcc -o $(HM) $(FLAGS) $(OPTIONS) $(SRCS)
	@echo "Compiled!"

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(HM)
	@/bin/rm -f ./srcs/libft/libft.a
	@echo "Cleaned All Objects"

re: fclean all
	@echo "Cleaned All"

relib:
	@make -C ./srcs/libft re
	@echo "Compiled Libft"

cleanlib:
	@make -C ./srcs/libft clean
	@echo "Cleaned Libft Objects"
