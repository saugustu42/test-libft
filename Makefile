NAME = test

LIB = ../eval-libft/libft.a

all : $(NAME)

$(NAME) : $(LIB) main.o
	gcc main.o -L../eval-libft -lft -o $(NAME)

main.o : main.c
	gcc -c main.c

$(LIB) :
	$(MAKE) -C ../eval-libft
