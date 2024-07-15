NAME = pipex
CC = cc -Wall -Wextra -Werror #-g -fsanitize=address
MANDATORY_SRC = pipex.c \
				ft_split.c \
				libfunc.c \
				prepare.c \
				support.c \
				finishing.c

BONUS_SRC = 	pipex_bonus.c \
				ft_split_bonus.c \
				libfunc_bonus.c \
				prepare_bonus.c \
				support_bonus.c \
				finishing_bonus.c \
				get_next_line_bonus.c \
				get_next_line_utils_bonus.c \
				heredoc_bonus.c
				
OBJ = $(SRC:.c=.o)

RM = rm -rf

ifeq ($(BONUS_FLAG),yes)
    SRC = $(BONUS_SRC)
else
    SRC = $(MANDATORY_SRC)
endif

%.o:%.c
	$(CC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(MANDATORY_SRC:.c=.o) $(BONUS_SRC:.c=.o)

fclean: clean
	$(RM) $(NAME)

bonus: 
	$(MAKE) BONUS_FLAG=yes $(NAME)

re: fclean all