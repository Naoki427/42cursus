/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:30:01 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/29 03:06:04 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define TROUT 64
# define RIGHT 0
# define LEFT 1

typedef struct s_enemy
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			type;
	void		*next;
	size_t		frame;
}				t_enemy;

typedef struct s_picture
{
	void		*object[10];
	void		*player[8];
	void		*enemy[12];
	void		*nb[10];
}				t_picture;

typedef struct s_map
{
	void		*mlx;
	void		*win;
	char		*map[23];
	int			x;
	int			y;
	int			dir;
	t_picture	pic;
	size_t		flame;
	int			goal_flg;
	t_enemy		**lst;
}				t_map;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;

	t_data		img;
}				t_vars;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

size_t			ft_strlen(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_memset(void *buf, int c, size_t n);
int				check_newline(char *s);
char			*get_next_line(int fd);
char			*read_file(int fd, char *str);
size_t			line_len(char *str);
char			*get_oneline(char *str);
void			ft_save(char *str, char *save);
int				check_rectangular(t_map *map);
int				check_wall(char **map);
int				check_wall_sub(char *line);
int				check_path(char **map);
int				fill_cpy(t_map *cpy, t_map *map);
int				find_valid_path(char **map, int x, int y);
void			find_valid_path_sub(char **map, int x, int y);
int				check_charcter(char **map);
int				check_charcter_sub(char c, int *flg);
int				validate_map(t_map *map);
char			*ft_strdup(const char *str);
void			free_arr(char **arr);
void			move_left(t_map *map, int *count);
void			move_down(t_map *map, int *count);
void			move_right(t_map *map, int *count);
void			move_up(t_map *map, int *count);
void			delete_player(t_map *map);
t_enemy			*ft_lstnew(int x, int y, int type);
void			ft_lstadd_back(t_enemy **lst, t_enemy *new);
t_enemy			*ft_lstlast(t_enemy *lst);
void			set_mlx(t_vars *vars, t_map *map);
int				check_file_name(char *file);
int				fill_arr(char **arr, char *ber);
void			add_image(t_map *map, int i, int j, t_vars *vars);
void			screen_map(t_map *map, t_vars *vars);
void			set_map(t_map *map);
void			set_enemy(t_enemy **lst, char **map);
void			set_enemy_mlx(t_enemy **lst, t_map map);
void			delete_player(t_map *map);
void			*choose_image(t_map *map);
void			delete_enemy(t_map *map, t_enemy *enemy);
void			delete_enemy_sub(t_map *map, t_enemy *enemy);
void			move_enemy(t_map *map, t_enemy *enemy, int frame);
void			move_enemy_sub(t_map *map, t_enemy *enemy, int x_ab, int y_ab);
int				set_enemy_speed(int type, int frame);
void			enemy_animation(t_enemy *enemy, size_t frame, t_map *map);
int				cmp_absolute_value(int n, int m);
int				add_absolute(int n, int m);
void			game_over(t_map *map, t_enemy *enemy);
void			set_picture(t_map *map, t_vars *vars);
void			set_picture_object(t_map *map, int tmp[2]);
void			set_picture_player(t_map *map, int tmp[2]);
void			set_picture_enemy(t_map *map, int tmp[2]);
void			set_picture_nb(t_map *map, int tmp[2]);
void			ft_putnbr_fd(int n, int fd);
void			put_count(t_map *map, int count);
void			free_lst(t_enemy **a);
int				set_enemy_sensor(int type, int range);
void			evolve_enemy(t_enemy *enemy, t_enemy **lst);
void			delete_typezero(t_enemy *zero, t_enemy **lst);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#endif