NAME = test

LIB_PATH = ./eval-libft
LIB = $(LIB_PATH)/libft.a

all : $(NAME)

$(NAME) : $(LIB) main.o
	gcc main.o -L$(LIB_PATH) -lft -o $(NAME)

main.o : main.c
	gcc -c main.c

$(LIB) : NONE
	$(MAKE) -C $(LIB_PATH)

clean :
	rm -f  main.o

fclean : clean
	rm -f $(NAME)

norm :
	norminette ./eval-libft

run-my-test : $(NAME)
	@echo "\n\n\n"
	./$(NAME) | cat -e

.PHONY : NONE norm
