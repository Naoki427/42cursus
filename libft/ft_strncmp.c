/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:48:17 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/04/19 19:53:53 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	int		num;

	i = 0;
	if (n == 0)
		return (0);
	num = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		num = (unsigned char)str1[i] - (unsigned char)str2[i];
		if (str1[i] != str2[i])
			break ;
		i++;
	}
	return (num);
}

// #include<stdio.h>
// #include<string.h>

// int main()
// {
//     char *s1 = "libft-test-tokyo";
//     char *s2 = calloc(10, 1);
// 	strlcpy(s2, "libft", 10);
// 	s2[5] = -42;
//     int	len = strlen(s1);
//     printf("result = %d\n",ft_strncmp(s1,s2,len));
//     printf("answer = %d\n",strncmp(s1,s2,len));
//     return (0);
// }