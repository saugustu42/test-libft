NAME = test

LIB_PATH = ./eval-libft
LIB = $(LIB_PATH)/libft.a

Libftest = ./Libftest/grademe.sh

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

$(Libftest) :
	git clone https://github.com/jtoty/Libftest.git
	cp ./test-configs/my_config.sh ./Libftest
	
run-libftest : $(Libftest)
	$(Libftest) -n

# run-unit : $(unit)

.PHONY : NONE norm
