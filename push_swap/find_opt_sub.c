/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_opt_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:54:59 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/23 12:10:37 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_maximum(int n, int m)
{
	if (n >= m)
		return (n);
	else
		return (m);
}

int	ft_minimum(int n, int m)
{
	if (n <= m)
		return (n);
	else
		return (m);
}

int	apply_rot_rule(int n, int m)
{
	if (n >= 0 && m >= 0)
		return (ft_maximum(n, m));
	if (n < 0 && m < 0)
		return (-(ft_minimum(n, m)));
	if (n >= 0 && m < 0)
		return (n - m);
	if (n < 0 && m >= 0)
		return (-n + m);
	return (0);
}

int	*find_opt_sub(int n, int **count)
{
	int			i;
	static int	min[2];

	min[0] = count[0][0];
	min[1] = count[0][1];
	i = 0;
	while (i < 2 * n)
	{
		if (apply_rot_rule(min[0], min[1]) > apply_rot_rule(count[i][0],
			count[i][1]))
		{
			min[0] = count[i][0];
			min[1] = count[i][1];
		}
		i++;
	}
	return (min);
}
