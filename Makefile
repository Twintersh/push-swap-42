CC = gcc #-fsanitize=leak
NAME = push_swap
SRC = src/push_swap.c src/lst_managing.c src/parsing.c src/instructions.c src/sorting.c src/TESTS.c
OBJ=$(SRC:.c=.o)
LFT = lib-twinters
CFLAGS = -Werror -Wall -Wextra
LFLAGS = L $(LFT)-lft

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -g3 -I/src/ -c $< -o $@

$(NAME) : $(OBJ)
	@make -C $(LFT)
	@$(CC) $(CFLAGS) $(OBJ) -L $(LFT) -lft -o $(NAME)

re : fclean all

debug : fclean $(OBJ)
	@make -C $(LFT)
	@ $(CC) $(CFLAGS) -g3 $(OBJ) -L $(LFT) -lft -o $(NAME)

clean :
	@rm -rf src/*.o
	@make fclean -C $(LFT)
	@echo Done

fclean : clean
	@rm -rf $(NAME)
