/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 02:05:05 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/29 17:32:49 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_enemy(t_map *map, t_enemy *enemy)
{
	if (map->map[enemy->y][enemy->x] == '0'
		|| map->map[enemy->y][enemy->x] == 'P')
		mlx_put_image_to_window(map->mlx, map->win, map->pic.object[6], TROUT
			* enemy->x, TROUT * enemy->y);
	if (map->map[enemy->y][enemy->x] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->pic.object[0], TROUT
			* enemy->x, TROUT * enemy->y);
	if (map->map[enemy->y][enemy->x] == 'R')
		mlx_put_image_to_window(map->mlx, map->win, map->pic.object[1], TROUT
			* enemy->x, TROUT * enemy->y);
	if (map->map[enemy->y][enemy->x] == 'E')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->pic.object[6], TROUT
			* enemy->x, TROUT * enemy->y);
		mlx_put_image_to_window(map->mlx, map->win, map->pic.object[2], TROUT
			* enemy->x, TROUT * enemy->y);
	}
}

void	move_enemy(t_map *map, t_enemy *enemy, int frame)
{
	int	x_ab;
	int	y_ab;
	int	tmp;

	if (set_enemy_speed(enemy->type, frame))
	{
		x_ab = map->x - (enemy->x);
		y_ab = map->y - (enemy->y);
		tmp = enemy->y;
		if ((((cmp_absolute_value(y_ab, x_ab) || x_ab == 0)
					|| (map->map[enemy->y][(enemy->x) - 1] == '1'
					&& map->map[enemy->y][(enemy->x) + 1] == '1'))
				&& y_ab != 0))
		{
			if (y_ab < 0 && map->map[(enemy->y) - 1][enemy->x] != '1'
				&& set_enemy_sensor(enemy->type, add_absolute(x_ab, y_ab)))
				(enemy->y)--;
			else if (y_ab > 0 && map->map[(enemy->y) + 1][enemy->x] != '1'
				&& set_enemy_sensor(enemy->type, add_absolute(x_ab, y_ab)))
				(enemy->y)++;
		}
		if (enemy->y == tmp)
			move_enemy_sub(map, enemy, x_ab, y_ab);
	}
}

void	move_enemy_sub(t_map *map, t_enemy *enemy, int x_ab, int y_ab)
{
	if (x_ab < 0 && map->map[enemy->y][(enemy->x) - 1] != '1'
		&& set_enemy_sensor(enemy->type, add_absolute(x_ab, y_ab)))
		(enemy->x)--;
	else if (x_ab > 0 && map->map[enemy->y][(enemy->x) + 1] != '1'
		&& set_enemy_sensor(enemy->type, add_absolute(x_ab, y_ab)))
		(enemy->x)++;
}

int	set_enemy_speed(int type, int frame)
{
	if (type == 0 && frame % 20 == 0)
		return (1);
	if (type == 1 && (frame == 0 || frame == 5 || frame == 15 || frame == 20))
		return (1);
	if (type == 2 && frame % 3 == 0)
		return (1);
	return (0);
}

int	set_enemy_sensor(int type, int range)
{
	if (type == 0 && range <= 5)
		return (1);
	if (type == 1 && range <= 10)
		return (1);
	if (type == 2)
		return (1);
	return (0);
}
