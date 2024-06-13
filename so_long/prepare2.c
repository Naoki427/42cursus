/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 00:47:59 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/29 02:42:23 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] != '\n' && map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'P')
			{
				map->x = j;
				map->y = i;
			}
			j++;
		}
		i++;
	}
}

void	set_enemy(t_enemy **lst, char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == '2' || map[i][j] == '3')
			{
				if (*lst == NULL)
					*lst = ft_lstnew(j, i, map[i][j] - '2');
				else
					ft_lstadd_back(lst, ft_lstnew(j, i, map[i][j] - '2'));
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void	set_enemy_mlx(t_enemy **lst, t_map map)
{
	t_enemy	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		tmp->mlx = map.mlx;
		tmp->win = map.win;
		tmp = tmp->next;
	}
	if (*lst != NULL)
		(*lst)->frame = 0;
}
