/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:17:20 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/21 17:00:04 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		len = 0;
		start = ft_strlen(s);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	r = (char *)malloc(len + 1);
	if (r == NULL)
		return (NULL);
	s += start;
	while (s[i] && len)
	{
		r[i] = s[i];
		i++;
		len--;
	}
	r[i] = '\0';
	return (r);
}

// #include <stdio.h>

// int main()
// {
//     printf("%s\n",ft_substr("tripouille", 50, 42));
//     return (0);
// }