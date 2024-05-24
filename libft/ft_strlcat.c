/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:44:32 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/04/26 12:51:07 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	int		i;

	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	dest_len = ft_strlen(dst);
	i = 0;
	if (size <= dest_len)
		return (size + src_len);
	while (dest_len + i < size - 1 && src[i])
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}

// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>

// int main()
// {
//     char *s0;
//     char *s1;
//     char *s2 = "World!!!";
//     int n =7;

//     s0 = malloc(100);
//     strcpy(s0, "Hello");
//     s1 = malloc(100);
//     strcpy(s1, "Hello");
//     printf("result = %zu\n",ft_strlcat(s0,s2,n));
//     printf("answer = %lu\n",strlcat(s1,s2,n));
//     printf("result_s = %s\n",s0);
//     printf("answer_s = %s\n",s1);
//     free(s0);
//     free(s1);
//     return (0);
// }