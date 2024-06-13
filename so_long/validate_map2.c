/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:32:40 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/06/03 16:19:59 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 1;
	if (map->map[0] == NULL)
		return (write(1, "Error\nMap is empty or does not exist\n", 38), 1);
	while (map->map[0][i] != '\n' && map->map[0][i] != '\0')
		i++;
	if (i > 40)
		return (write(1, "Error\nMap width is too wide!\n", 30), 1);
	map->x = i;
	while (map->map[j] != NULL)
	{
		k = 0;
		while (map->map[j][k] != '\n' && map->map[j][k] != '\0')
			k++;
		if (k != i)
			return (write(1, "Error\nThis map is not rectangular!\n", 36), 1);
		j++;
	}
	map->y = j;
	return (0);
}

int	check_wall_sub(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_wall(char **map)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1')
			return (write(1, "Error\nThis map is not surrounded by walls!\n",
					44), 1);
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
			j++;
		if (map[i][j - 1] != '1')
			return (write(1, "Error\nThis map is not surrounded by walls!\n",
					44), 1);
		i++;
	}
	if (check_wall_sub(map[0]) || check_wall_sub(map[i - 1]))
		return (write(1, "Error\nThis map is not surrounded by walls!\n", 44),
			1);
	return (0);
}

int	fill_cpy(t_map *cpy, t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		cpy->map[i] = ft_strdup(map->map[i]);
		if (!cpy->map[i])
			return (1);
		while (cpy->map[i][j] != '\n' && cpy->map[i][j] != '\0')
		{
			if (cpy->map[i][j] == 'P')
			{
				cpy->x = j;
				cpy->y = i;
			}
			j++;
		}
		i++;
	}
	cpy->map[i] = NULL;
	return (0);
}
