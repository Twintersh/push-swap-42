CC = gcc #-fsanitize=leak
NAME = push_swap
SRC = src/push_swap.c src/lst_managing.c src/parsing.c src/instructions.c src/sorting.c src/TESTS.c
OBJ=$(SRC:.c=.o)
LFT = lib-twinters
CFLAGS = -Werror -Wall -Wextra -g3
LFLAGS = L $(LFT)-lft

GREEN = \033[0;32m
RED = \033[0;31m

all : $(NAME)
	echo "${GREEN}Compilation done !"

%.o : %.c
	$(CC) $(CFLAGS) -g3 -I/src/ -c $< -o $@

$(NAME) : $(OBJ)
	make -C $(LFT)
	$(CC) $(CFLAGS) $(OBJ) -L $(LFT) -lft -o $(NAME)

re : fclean all

clean :
	rm -rf src/*.o
	make fclean -C $(LFT)
	echo "${RED}Clean done"

debug : all

fclean : clean
	rm -rf $(NAME)

.SILENT :