NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

BASIC_SOURCES = 	ft_printf.c \
					ft_count_len.c \
					ft_libfunc.c \
					ft_putfunc.c \
					ft_bonusfunc.c \
					ft_validateinput.c
													
ifeq ($(BONUS_FLAG),yes)
	SOURCES = $(BASIC_SOURCES) $(BONUSES)
else
	SOURCES = $(BASIC_SOURCES)
endif

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BASIC_SOURCES:.c=.o) $(BONUSES:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	$(MAKE) all BONUS_FLAG=yes

.PHONY: all clean fclean re bonus