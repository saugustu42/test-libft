NAME = test

LIB_PATH = ./eval-libft
LIB = $(LIB_PATH)/libft.a

LIST = main.c print_output.c

OBJ = $(patsubst %.c,%.o,$(LIST))

Libftest = ./Libftest/grademe.sh

unit = ./libft-unit-test

cfg = ./cfg/.vimrc

all : $(NAME)

$(NAME) : $(LIB) $(OBJ)
	gcc $(OBJ) -L$(LIB_PATH) -lft -o $(NAME)

%.o : %.c
	gcc -c $< -o $@

$(LIB) : NONE
	$(MAKE) -C $(LIB_PATH)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

norm :
	cd $(LIB_PATH) && make clean && norminette .

run-my-test : $(NAME)
	@echo "\n\n\n"
	./$(NAME)

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

grep-printf :
	cd $(LIB_PATH) && make clean && grep -RIn printf .

grep-malloc :
	cd $(LIB_PATH) && make clean && grep -RIn malloc .

myvim : $(cfg)
	vim -u $(cfg)

.PHONY : NONE norm run-my-test run-libftest run-unit grep-printf grep-malloc myvim
