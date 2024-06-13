/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 08:10:01 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/29 01:16:27 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_goal(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (map->map[map->y][map->x] == 'E')
	{
		while (map->map[i])
		{
			j = 0;
			while (map->map[i][j] != '\n' && map->map[i][j] != '\0')
			{
				if (map->map[i][j] == 'C')
					return (0);
				j++;
			}
			i++;
		}
		return (1);
	}
	return (0);
}

void	move_left(t_map *map, int *count)
{
	delete_player(map);
	map->x -= 1;
	map->dir = LEFT;
	if (check_goal(map))
	{
		map->goal_flg = 1;
		mlx_put_image_to_window(map->mlx, map->win, map->pic.object[8], TROUT
			* (map->x - 1), TROUT * (map->y - 1));
	}
	(*count)++;
	write(1, "count:", 7);
	ft_putnbr_fd(*count, 1);
	write(1, "\n", 1);
	put_count(map, *count);
}

void	move_down(t_map *map, int *count)
{
	delete_player(map);
	map->y += 1;
	if (check_goal(map))
	{
		map->goal_flg = 1;
		mlx_put_image_to_window(map->mlx, map->win, map->pic.object[8], TROUT
			* (map->x - 1), TROUT * (map->y - 1));
	}
	(*count)++;
	write(1, "count:", 7);
	ft_putnbr_fd(*count, 1);
	write(1, "\n", 1);
	put_count(map, *count);
}

void	move_right(t_map *map, int *count)
{
	delete_player(map);
	map->x += 1;
	map->dir = RIGHT;
	if (check_goal(map))
	{
		map->goal_flg = 1;
		mlx_put_image_to_window(map->mlx, map->win, map->pic.object[8], TROUT
			* (map->x - 1), TROUT * (map->y - 1));
	}
	(*count)++;
	write(1, "count:", 7);
	ft_putnbr_fd(*count, 1);
	write(1, "\n", 1);
	put_count(map, *count);
}

void	move_up(t_map *map, int *count)
{
	delete_player(map);
	map->y -= 1;
	if (check_goal(map))
	{
		map->goal_flg = 1;
		mlx_put_image_to_window(map->mlx, map->win, map->pic.object[8], TROUT
			* (map->x - 1), TROUT * (map->y - 1));
	}
	(*count)++;
	write(1, "count:", 7);
	ft_putnbr_fd(*count, 1);
	write(1, "\n", 1);
	put_count(map, *count);
}
