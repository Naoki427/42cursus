/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:38:58 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/04/17 12:49:42 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)buf;
	while (n > 0)
	{
		*ptr = c;
		++ptr;
		n--;
	}
	return (buf);
}

// #include<stdio.h>
// #include<string.h>

// int main()
// {
//     char buf1[] = "ABCDEFGHIJK";
//     char buf2[] = "ABCDEFGHIJK";

//     ft_memset(buf1,'1',3);
//     memset(buf2,'1',3);
//     printf("result: buf文字列→%s\n",buf1);
//     printf("answer: buf文字列→%s\n",buf2);

//     return (0);
// }
