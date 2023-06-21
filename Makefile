CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
NAME_BONUS = checker

SOURCES = ./src/push_swap.c ./src/utils.c ./src/input_checks.c ./src/stack_funcs.c ./src/rotate_both_and_push.c \
	./src/swap_rules.c ./src/rotate_one_rules.c ./algorithm/ft_sort.c ./algorithm/mid_point.c ./algorithm/utils_sort.c \
	./algorithm/optimizations.c ./algorithm/ft_next_move.c

BONUS_SOURCES = ./bonus/ft_checker.c ./bonus/err_handling.c ./bonus/rules/rotate_bo_a_push_bonus.c \
	./bonus/rules/rotate_one_rules_bonus.c ./bonus/rules/swap_rules_bonus.c ./src/utils.c \
	./algorithm/utils_sort.c ./src/stack_funcs.c ./bonus/utils.c


OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	@cd libs && make
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) ./libs/libs.a

clean:
	@cd libs && make fclean
	@rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re:	fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(BONUS_OBJECTS)
	@cd libs && make
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(BONUS_OBJECTS) ./libs/libs.a
