/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:39:27 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/04/26 12:40:33 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		flg;
	long	num;

	flg = 1;
	num = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			flg *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = 10 * num + (*str - '0');
		str++;
		if ((LONG_MAX - (*str - '0')) / 10 < num && ft_isdigit(*str)
			&& flg == 1)
			return ((int)LONG_MAX);
		else if ((LONG_MIN + (*str - '0')) / 10 > -num && ft_isdigit(*str)
			&& flg == -1)
			return ((int)LONG_MIN);
	}
	return (flg * (int)num);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	*s;

// 	s = "9223372036854775808";
// 	s = "922337203685477581";
// 	printf("result : %d\n", ft_atoi(s));
// 	printf("answer : %d\n", atoi(s));
// 	return (0);
// }