NAME = so_long
CC = cc -Wall -Wextra -Werror #-g -fsanitize=address
SRC = 	main.c \
		get_next_line.c \
		get_next_line_utils.c \
		validate_map.c \
		validate_map2.c \
		support.c \
		move.c \
		prepare.c \
		prepare2.c \
		loop_hook_player.c \
		loop_hook_enemy.c \
		loop_hook_enemy2.c \
		set_picture.c \
		key_hook.c \
		extra.c

OBJ = $(SRC:.c=.o)

RM = rm -rf

%.o:%.c
	$(CC) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o so_long

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

bonus: all

re: fclean all
