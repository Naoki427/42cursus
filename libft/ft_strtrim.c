/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:41:54 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/04/26 12:51:34 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	setcmp(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (j == (int)ft_strlen(set))
			break ;
		i++;
	}
	return (i);
}

int	set_rev_cmp(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (j == (int)ft_strlen(set))
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;

	if (!s1)
		return (NULL);
	arr = ft_substr(s1, setcmp(s1, set), (set_rev_cmp(s1, set) - setcmp(s1, set)
				+ 1));
	if (!arr)
		return (NULL);
	return (arr);
}

// #include <stdio.h>

// int main()
// {
//     printf("%s\n",ft_strtrim("hello world", "world"));
//     return (0);
// }