/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 01:26:47 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/06/03 16:18:46 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(char **map)
{
	size_t	i;
	size_t	j;
	size_t	flg;

	i = 0;
	flg = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				flg |= 0b1;
			if (map[i][j] == 'C')
				flg |= 0b10;
			j++;
		}
		i++;
	}
	if ((flg & 0b11) != 0)
		return (0);
	return (1);
}

int	find_valid_path(char **map, int x, int y)
{
	if (check_path(map))
		return (1);
	if (map[y][x] != '1' && map[y][x] != 'R')
	{
		map[y][x] = 'R';
		if (find_valid_path(map, x + 1, y))
			return (1);
		if (find_valid_path(map, x - 1, y))
			return (1);
		if (find_valid_path(map, x, y + 1))
			return (1);
		if (find_valid_path(map, x, y - 1))
			return (1);
	}
	return (0);
}

int	check_charcter_sub(char c, int *flg)
{
	if (c == 'P')
	{
		if (*flg & 0b1)
			return (write(1, "Error\n'P' is duplicated\n", 25), 1);
		else
			*flg |= 0b1;
	}
	if (c == 'E')
	{
		if (*flg & 0b10)
			return (write(1, "Error\n'E' is duplicated\n", 25), 1);
		else
			*flg |= 0b10;
	}
	if (c == 'C')
		*flg |= 0b100;
	if (c != '0' && c != '1' && c != '2' && c != '3' && c != 'C' && c != 'P'
		&& c != 'E')
		return (write(1, "There are invalid characters in the map\n", 41), 1);
	return (0);
}

int	check_charcter(char **map)
{
	size_t	i;
	size_t	j;
	int		flg;

	i = 1;
	flg = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (check_charcter_sub(map[i][j], &flg))
				return (1);
			j++;
		}
		i++;
	}
	if ((flg ^ 0b111) != 0)
		return (write(1, "Error\nRequired characters are missing!\n", 40), 1);
	return (0);
}

int	validate_map(t_map *map)
{
	t_map	cpy;

	if (check_rectangular(map) || check_wall(map->map)
		|| check_charcter(map->map))
		return (1);
	if (fill_cpy(&cpy, map))
		return (free_arr(cpy.map), 1);
	if (!find_valid_path(cpy.map, cpy.x, cpy.y))
		return (free_arr(cpy.map), write(1,
				"Error\nThis map has no valid paths!\n", 36), 1);
	free_arr(cpy.map);
	return (0);
}
