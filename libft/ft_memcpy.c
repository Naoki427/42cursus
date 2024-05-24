/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:19:16 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/04/17 19:12:46 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *)buf1;
	src = (unsigned char *)buf2;
	if (!dest && !src)
		return (0);
	while (n > 0)
	{
		*dest++ = *src++;
		n--;
	}
	return (buf1);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(void)
// {
// 	char buf[] = "ABCDDEFG";
// 	char buf2[] = "123456789";
// 	char abuf[] = "ABCDDEFG";
// 	char abuf2[] = "123456789";

// 	ft_memcpy(buf,buf2,5);
// 	memcpy(abuf,abuf2,5);

// 	printf("resrlt: buf文字列→%s\n",buf);
// 	printf("answer: buf文字列→%s\n",abuf);

// 	return (0);
// }