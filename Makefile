CC = gcc
NAME = push_swap
SRC = src/push_swap.c
OBJ=$(SRC:.c=.o)

CFLAGS = -Werror -Wall -Wextra

all : $(NAME)

%.c : %.o
	@$(CC) $(CFLAGS) -I/src/ -c $< -o $@

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	@rm -rf src/*.o
	@echo Done

fclean : clean
	@rm -rf $(NAME)
