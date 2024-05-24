/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:27:31 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/04/26 12:49:50 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == s)
		return (dest);
	if (d > s && d < s + n)
	{
		d += n - 1;
		s += n - 1;
		while (n--)
			*d-- = *s--;
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(void)
// {
// 	char *dst = malloc(1);
// 	dst[0] = '\0';
// 	char *dst2 = malloc(1);
// 	dst2[0] = '\0';
// 	ft_memmove(dst, dst - 1, 0);
// 	memmove(dst2, dst2 - 1, 0);

// 	printf("resrlt: buf文字列→%s\n",dst);
// 	printf("answer: buf文字列→%s\n",dst2);

// 	return (0);
// }