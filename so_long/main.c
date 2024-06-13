/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:57:09 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/06/03 16:30:50 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

int	window_close(t_vars *vars)
{
	write(1, "window close\n", 14);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_map *map)
{
	static int	count = 0;

	if (keycode == 53)
	{
		write(1, "window close\n", 14);
		mlx_destroy_window(map->mlx, map->win);
		exit(0);
	}
	if (map->goal_flg)
		return (0);
	if ((keycode == 0 || keycode == 123) && map->map[map->y][map->x - 1] != '1')
		move_left(map, &count);
	if ((keycode == 1 || keycode == 125) && map->map[(map->y)
			+ 1][map->x] != '1')
		move_down(map, &count);
	if ((keycode == 2 || keycode == 124) && map->map[map->y][(map->x)
		+ 1] != '1')
		move_right(map, &count);
	if ((keycode == 13 || keycode == 126) && map->map[(map->y)
			- 1][map->x] != '1')
		move_up(map, &count);
	return (0);
}

int	loop_hook(t_map *map)
{
	t_enemy	*tmp;

	if (!map->goal_flg)
	{
		delete_player(map);
		mlx_put_image_to_window(map->mlx, map->win, choose_image(map), TROUT
			* map->x, TROUT * map->y);
		tmp = *(map->lst);
		while (tmp != NULL)
		{
			delete_enemy(map, tmp);
			move_enemy(map, tmp, map->flame);
			enemy_animation(tmp, (map->flame), map);
			evolve_enemy(tmp, map->lst);
			game_over(map, tmp);
			tmp = tmp->next;
		}
		(map->flame)++;
		if (map->flame >= 60)
			map->flame = 0;
	}
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q so_long");
// }

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_map	map;
	t_enemy	**lst;
	t_enemy	*tmp;

	tmp = NULL;
	lst = &tmp;
	if (argc != 2)
		return (write(1, "Error\nPlease input only one map!\n", 34), 0);
	if (fill_arr(map.map, argv[1]))
		return (free_arr(map.map), 0);
	if (validate_map(&map))
		return (free_arr(map.map), 0);
	screen_map(&map, &vars);
	set_map(&map);
	set_enemy(lst, map.map);
	set_enemy_mlx(lst, map);
	map.lst = lst;
	mlx_loop_hook(vars.mlx, loop_hook, &map);
	mlx_key_hook(vars.win, key_hook, &map);
	mlx_hook(vars.win, ON_DESTROY, 0, window_close, &vars);
	mlx_loop(vars.mlx);
	free_arr(map.map);
	free_lst(lst);
	return (0);
}
