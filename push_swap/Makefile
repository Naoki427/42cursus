NAME = push_swap

BONUS_NAME = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra

BASIC_SOURCES = action.c \
                find_opt_sub.c \
                find_optimal_node.c \
                ft_split.c \
                push_to_b.c \
                support.c \
                support_2.c \
                push_swap.c \
				get_next_line.c \
				get_next_line_utils.c \
				check_result.c

MANDATORY_MAIN = main.c

BONUS_MAIN = checker_main.c

ifeq ($(BONUS_FLAG),yes)
    SOURCES = $(BASIC_SOURCES) $(BONUS_MAIN)
else
    SOURCES = $(BASIC_SOURCES) $(MANDATORY_MAIN)
endif

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	$(MAKE) BONUS_FLAG=yes $(BONUS_NAME)

$(BONUS_NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS) checker_main.o

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
