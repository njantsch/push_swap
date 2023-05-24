CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = push_swap

SOURCES = ./src/push_swap.c ./src/utils.c ./src/input_checks.c ./src/stack_funcs.c ./src/rotate_both_and_push.c \
./src/swap_rules.c ./src/rotate_one_rules.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	@cd libs && make
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) ./libs/libs.a

clean:
	@cd libs && make fclean
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re:	fclean all
