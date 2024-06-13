/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 00:39:17 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/28 23:36:56 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_player(t_map *map)
{
	if (map->map[map->y][map->x] == '0' || map->map[map->y][map->x] == 'P')
		mlx_put_image_to_window(map->mlx, map->win, map->pic.object[6], TROUT
			* map->x, TROUT * map->y);
	if (map->map[map->y][map->x] == 'C' || map->map[map->y][map->x] == 'R')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->pic.object[1], TROUT
			* map->x, TROUT * map->y);
		map->map[map->y][map->x] = 'R';
	}
	if (map->map[map->y][map->x] == 'E')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->pic.object[6], TROUT
			* map->x, TROUT * map->y);
		mlx_put_image_to_window(map->mlx, map->win, map->pic.object[2], TROUT
			* map->x, TROUT * map->y);
	}
}

void	*choose_image(t_map *map)
{
	if (map->dir == RIGHT)
	{
		if (map->flame % 60 < 15)
			return (map->pic.player[0]);
		else if (map->flame % 60 < 30 && map->flame % 60 >= 15)
			return (map->pic.player[1]);
		else if (map->flame % 60 < 45 && map->flame % 60 >= 30)
			return (map->pic.player[2]);
		else
			return (map->pic.player[3]);
	}
	else
	{
		if (map->flame % 60 < 15)
			return (map->pic.player[4]);
		else if (map->flame % 60 < 30 && map->flame % 60 >= 15)
			return (map->pic.player[5]);
		else if (map->flame % 60 < 45 && map->flame % 60 >= 30)
			return (map->pic.player[6]);
		else
			return (map->pic.player[7]);
	}
}
