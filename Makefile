CC = gcc
NAME = push_swap
SRC = src/lst_managing.c src/main_parsing.c src/instructions.c src/sorting.c src/errors.c src/more_instructions.c
OBJ=$(SRC:.c=.o)
LFT = libft
CFLAGS = -Werror -Wall -Wextra
LFLAGS = L $(LFT)-lft

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -g3 -I/src/ -c $< -o $@

$(NAME) : $(OBJ)
	make -C $(LFT)
	$(CC) $(CFLAGS) $(OBJ) -L $(LFT) -lft -o $(NAME)

re : fclean all

clean :
	rm -rf src/*.o
	make fclean -C $(LFT)

fclean : clean
	rm -rf $(NAME)