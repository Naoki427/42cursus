/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:57:06 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/04/18 09:46:33 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		while (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char *s = "abcdefghijdklmn";
//     int c = 100;

//     printf("result = %s\n",ft_strrchr(s,c));
//     printf("answer = %s\n",strrchr(s,c));

//     return (0);
// }