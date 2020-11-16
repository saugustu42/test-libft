NAME = test

LIB_PATH = ./eval-libft
LIB = $(LIB_PATH)/libft.a

Libftest = ./Libftest/grademe.sh

unit = ./libft-unit-test

cfg = ./cfg/.vimrc

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

$(unit) :
	git clone https://github.com/alelievr/libft-unit-test.git
	cp ./test-configs/Makefile $(unit)
	
run-libftest : $(Libftest)
	$(Libftest) -n

run-unit : $(unit)
	cd $(unit) && make f

$(cfg) : 
	git clone https://github.com/alexoleshk/cfg.git

myvim : $(cfg)
	vim -u $(cfg)

.PHONY : NONE norm run-my-test run-libftest run-unit
