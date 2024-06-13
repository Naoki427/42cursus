/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_enemy2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 02:29:05 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/29 01:32:18 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_animation(t_enemy *enemy, size_t frame, t_map *map)
{
	if (frame % 60 < 15)
		mlx_put_image_to_window(enemy->mlx, enemy->win, map->pic.enemy[0 + 4
			* (enemy->type)], TROUT * enemy->x, TROUT * enemy->y);
	else if (frame % 60 < 30 && frame >= 15)
		mlx_put_image_to_window(enemy->mlx, enemy->win, map->pic.enemy[1 + 4
			* (enemy->type)], TROUT * enemy->x, TROUT * enemy->y);
	else if (frame % 60 < 45 && frame >= 30)
		mlx_put_image_to_window(enemy->mlx, enemy->win, map->pic.enemy[2 + 4
			* (enemy->type)], TROUT * enemy->x, TROUT * enemy->y);
	else
		mlx_put_image_to_window(enemy->mlx, enemy->win, map->pic.enemy[3 + 4
			* (enemy->type)], TROUT * enemy->x, TROUT * enemy->y);
}

int	cmp_absolute_value(int n, int m)
{
	if (n < 0)
		n = -n;
	if (m < 0)
		m = -m;
	if (n <= m)
		return (1);
	return (0);
}

int	add_absolute(int n, int m)
{
	if (n < 0)
		n = -n;
	if (m < 0)
		m = -m;
	return (n + m);
}

void	game_over(t_map *map, t_enemy *enemy)
{
	void	*p_image;
	int		width;
	int		height;

	if (map->x == enemy->x && map->y == enemy->y)
	{
		map->goal_flg = 1;
		p_image = mlx_xpm_file_to_image(map->mlx, "pictures/gameover.xpm",
				&width, &height);
		mlx_put_image_to_window(map->mlx, map->win, p_image, TROUT * (map->x
				- 1), TROUT * (map->y - 1));
	}
}

void	free_lst(t_enemy **a)
{
	t_enemy	*l;
	t_enemy	*tmp;

	l = (*a)->next;
	while (l != *a)
	{
		tmp = l->next;
		free(l);
		l = tmp;
	}
	free(*a);
}
