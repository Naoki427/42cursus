/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 00:22:22 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/06/03 16:17:37 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_name(char *file)
{
	size_t	i;

	i = 0;
	while (file[i])
		i++;
	if (i < 4)
		return (1);
	if (file[i - 4] != '.' || file[i - 3] != 'b' || file[i - 2] != 'e' || file[i
			- 1] != 'r')
		return (write(1, "Error\nInvalid file name\n", 25), 1);
	return (0);
}

int	fill_arr(char **arr, char *ber)
{
	size_t	i;
	int		fd;
	char	*tmp;

	if (check_file_name(ber))
		return (1);
	fd = open(ber, O_RDONLY);
	i = 0;
	while (i < 22)
	{
		arr[i] = get_next_line(fd);
		if (!arr[i])
			break ;
		i++;
	}
	arr[i] = NULL;
	tmp = get_next_line(fd);
	if (tmp)
	{
		free(tmp);
		write(1, "Error\nMap height is too high!\n", 31);
		return (1);
	}
	return (0);
}

void	set_mlx(t_vars *vars, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, TROUT * map->x, TROUT * map->y,
			"so_long");
	vars->img.img = mlx_new_image(vars->mlx, TROUT * map->x, TROUT * map->y);
	set_picture(map, vars);
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, map->pic.object[6],
				TROUT * x, TROUT * y);
			x++;
		}
		y++;
	}
}

void	add_image(t_map *map, int i, int j, t_vars *vars)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, map->pic.object[3], TROUT
			* j, TROUT * i);
	if (map->map[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, map->pic.object[0], TROUT
			* j, TROUT * i);
	if (map->map[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, map->pic.object[2], TROUT
			* j, TROUT * i);
}

void	screen_map(t_map *map, t_vars *vars)
{
	size_t	i;
	size_t	j;

	i = 0;
	set_mlx(vars, map);
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\n' && map->map[i][j] != '\0')
		{
			add_image(map, i, j, vars);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, map->pic.nb[0], 32, 0);
}
