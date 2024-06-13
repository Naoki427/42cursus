/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_picture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:16:00 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/28 22:17:01 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_pic_object(t_map *map, int tmp[2])
{
	map->pic.object[0] = mlx_xpm_file_to_image(map->mlx,
			"pictures/chest_close.xpm", &tmp[0], &tmp[1]);
	map->pic.object[1] = mlx_xpm_file_to_image(map->mlx,
			"pictures/chest_open.xpm", &tmp[0], &tmp[1]);
	map->pic.object[2] = mlx_xpm_file_to_image(map->mlx, "pictures/anker.xpm",
			&tmp[0], &tmp[1]);
	map->pic.object[3] = mlx_xpm_file_to_image(map->mlx, "pictures/block.xpm",
			&tmp[0], &tmp[1]);
	map->pic.object[4] = mlx_xpm_file_to_image(map->mlx,
			"pictures/block_left.xpm", &tmp[0], &tmp[1]);
	map->pic.object[5] = mlx_xpm_file_to_image(map->mlx,
			"pictures/block_right.xpm", &tmp[0], &tmp[1]);
	map->pic.object[6] = mlx_xpm_file_to_image(map->mlx, "pictures/sea_64.xpm",
			&tmp[0], &tmp[1]);
	map->pic.object[7] = mlx_xpm_file_to_image(map->mlx, "pictures/sea_32.xpm",
			&tmp[0], &tmp[1]);
	map->pic.object[8] = mlx_xpm_file_to_image(map->mlx, "pictures/clear.xpm",
			&tmp[0], &tmp[1]);
	map->pic.object[9] = mlx_xpm_file_to_image(map->mlx,
			"pictures/gameover.xpm", &tmp[0], &tmp[1]);
}

void	set_pic_player(t_map *map, int tmp[2])
{
	map->pic.player[0] = mlx_xpm_file_to_image(map->mlx,
			"pictures/diver_right1.xpm", &tmp[0], &tmp[1]);
	map->pic.player[1] = mlx_xpm_file_to_image(map->mlx,
			"pictures/diver_right2.xpm", &tmp[0], &tmp[1]);
	map->pic.player[2] = mlx_xpm_file_to_image(map->mlx,
			"pictures/diver_right3.xpm", &tmp[0], &tmp[1]);
	map->pic.player[3] = mlx_xpm_file_to_image(map->mlx,
			"pictures/diver_right4.xpm", &tmp[0], &tmp[1]);
	map->pic.player[4] = mlx_xpm_file_to_image(map->mlx,
			"pictures/diver_left1.xpm", &tmp[0], &tmp[1]);
	map->pic.player[5] = mlx_xpm_file_to_image(map->mlx,
			"pictures/diver_left2.xpm", &tmp[0], &tmp[1]);
	map->pic.player[6] = mlx_xpm_file_to_image(map->mlx,
			"pictures/diver_left3.xpm", &tmp[0], &tmp[1]);
	map->pic.player[7] = mlx_xpm_file_to_image(map->mlx,
			"pictures/diver_left4.xpm", &tmp[0], &tmp[1]);
}

void	set_pic_enemy(t_map *map, int tmp[2])
{
	map->pic.enemy[0] = mlx_xpm_file_to_image(map->mlx, "pictures/enemyw1.xpm",
			&tmp[0], &tmp[1]);
	map->pic.enemy[1] = mlx_xpm_file_to_image(map->mlx, "pictures/enemyw2.xpm",
			&tmp[0], &tmp[1]);
	map->pic.enemy[2] = mlx_xpm_file_to_image(map->mlx, "pictures/enemyw3.xpm",
			&tmp[0], &tmp[1]);
	map->pic.enemy[3] = mlx_xpm_file_to_image(map->mlx, "pictures/enemyw4.xpm",
			&tmp[0], &tmp[1]);
	map->pic.enemy[4] = mlx_xpm_file_to_image(map->mlx, "pictures/enemy1.xpm",
			&tmp[0], &tmp[1]);
	map->pic.enemy[5] = mlx_xpm_file_to_image(map->mlx, "pictures/enemy2.xpm",
			&tmp[0], &tmp[1]);
	map->pic.enemy[6] = mlx_xpm_file_to_image(map->mlx, "pictures/enemy3.xpm",
			&tmp[0], &tmp[1]);
	map->pic.enemy[7] = mlx_xpm_file_to_image(map->mlx, "pictures/enemy4.xpm",
			&tmp[0], &tmp[1]);
	map->pic.enemy[8] = mlx_xpm_file_to_image(map->mlx, "pictures/enemyb1.xpm",
			&tmp[0], &tmp[1]);
	map->pic.enemy[9] = mlx_xpm_file_to_image(map->mlx, "pictures/enemyb2.xpm",
			&tmp[0], &tmp[1]);
	map->pic.enemy[10] = mlx_xpm_file_to_image(map->mlx, "pictures/enemyb3.xpm",
			&tmp[0], &tmp[1]);
	map->pic.enemy[11] = mlx_xpm_file_to_image(map->mlx, "pictures/enemyb4.xpm",
			&tmp[0], &tmp[1]);
}

void	set_pic_nb(t_map *map, int tmp[2])
{
	map->pic.nb[0] = mlx_xpm_file_to_image(map->mlx, "pictures/zero.xpm",
			&tmp[0], &tmp[1]);
	map->pic.nb[1] = mlx_xpm_file_to_image(map->mlx, "pictures/one.xpm",
			&tmp[0], &tmp[1]);
	map->pic.nb[2] = mlx_xpm_file_to_image(map->mlx, "pictures/two.xpm",
			&tmp[0], &tmp[1]);
	map->pic.nb[3] = mlx_xpm_file_to_image(map->mlx, "pictures/three.xpm",
			&tmp[0], &tmp[1]);
	map->pic.nb[4] = mlx_xpm_file_to_image(map->mlx, "pictures/four.xpm",
			&tmp[0], &tmp[1]);
	map->pic.nb[5] = mlx_xpm_file_to_image(map->mlx, "pictures/five.xpm",
			&tmp[0], &tmp[1]);
	map->pic.nb[6] = mlx_xpm_file_to_image(map->mlx, "pictures/six.xpm",
			&tmp[0], &tmp[1]);
	map->pic.nb[7] = mlx_xpm_file_to_image(map->mlx, "pictures/seven.xpm",
			&tmp[0], &tmp[1]);
	map->pic.nb[8] = mlx_xpm_file_to_image(map->mlx, "pictures/eight.xpm",
			&tmp[0], &tmp[1]);
	map->pic.nb[9] = mlx_xpm_file_to_image(map->mlx, "pictures/nine.xpm",
			&tmp[0], &tmp[1]);
}

void	set_picture(t_map *map, t_vars *vars)
{
	int	tmp[2];

	map->mlx = vars->mlx;
	map->win = vars->win;
	map->dir = RIGHT;
	map->flame = 0;
	map->goal_flg = 0;
	set_pic_object(map, tmp);
	set_pic_player(map, tmp);
	set_pic_enemy(map, tmp);
	set_pic_nb(map, tmp);
}
