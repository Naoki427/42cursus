/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:54:35 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/04/18 10:20:43 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n != 0)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		n--;
	}
	return (0);
}

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char s[] = {0, 1, 2 ,3 ,4 ,5};
//     // int c = 100;

//     printf("result = %s\n",ft_memchr(s, 2 + 256, 3));
//     printf("answer = %s\n",memchr(s, 2 + 256, 3));

//     return (0);
// }
