/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:22:15 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/04/26 12:50:52 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize < 1)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int main()
// {
//     char *src1 = "abcd";
//     char *dst1 = 0;
//     char *src2 = "abcd";
//     char *dst2 = 0;
//     size_t n = INT_MIN;

//     dst1 = (char *)malloc(10);
//     dst2 = (char *)malloc(10);

//     ft_strlcpy(dst1,src1,n);
//     strlcpy(dst2,src2,n);

//     printf("result : dst = %s, 戻り値 %zu\n",dst1,ft_strlcpy(dst1,src1,n));
//     printf("result : dst = %s, 戻り値 %zu\n",dst2,strlcpy(dst2,src2,n));
//     free(dst1);
//     free(dst2);

//     return (0);
// }