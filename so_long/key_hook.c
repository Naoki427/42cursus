/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 00:54:36 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/29 01:54:44 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	num;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb < 10)
	{
		num = nb + '0';
		write(fd, &num, 1);
	}
	else
	{
		num = nb % 10 + '0';
		ft_putnbr_fd(nb / 10, fd);
		write(fd, &num, 1);
	}
}

void	put_count(t_map *map, int count)
{
	int	i;
	int	digit;
	int	tmp;

	i = 0;
	digit = 0;
	tmp = count;
	while (tmp > 0)
	{
		digit++;
		tmp /= 10;
	}
	while (digit > 0)
	{
		if (digit % 2 == 1)
			mlx_put_image_to_window(map->mlx, map->win, map->pic.object[5], 32
				* digit, 0);
		else
			mlx_put_image_to_window(map->mlx, map->win, map->pic.object[4], 32
				* digit, 0);
		mlx_put_image_to_window(map->mlx, map->win, map->pic.nb[count % 10], 32
			* digit, 0);
		count /= 10;
		digit--;
	}
}
