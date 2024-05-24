/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:43:18 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/04/26 12:46:40 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countdigit(long n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*createarr(int count, long n)
{
	char	*arr;

	arr = (char *)malloc(count + 1);
	if (arr == NULL)
		return (NULL);
	arr[count] = '\0';
	count--;
	while (count >= 0)
	{
		arr[count] = '0' + (n % 10);
		n /= 10;
		count--;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		count;
	long	nb;

	nb = n;
	if (nb == 0)
		count = 1;
	else if (nb < 0)
		count = countdigit(-nb) + 1;
	else
		count = countdigit(nb);
	if (nb < 0)
		arr = createarr(count, -nb);
	else
		arr = createarr(count, nb);
	if (arr == NULL)
		return (NULL);
	if (nb < 0)
		arr[0] = '-';
	return (arr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(-2147483648));
// 	return (0);
// }