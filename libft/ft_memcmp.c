/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:30:40 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/04/26 21:03:51 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;
	int				num;

	num = 0;
	s1 = (unsigned char *)b1;
	s2 = (unsigned char *)b2;
	i = 0;
	while (i < len)
	{
		num = s1[i] - s2[i];
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (num);
}

// #include<stdio.h>
// #include<string.h>

// int main()
// {
// 	char s2[] = {0, 0, 127, 0};
// 	char s3[] = {0, 0, 42, 0};

//     printf("result = %d\n",ft_memcmp(s2, s3, 4));
//     printf("answer = %d\n",memcmp(s2, s3, 4));
//     return (0);
// }