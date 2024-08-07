/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfunc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:52:59 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/06/17 08:55:20 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	r = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (r == NULL)
		return (NULL);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		r[i + j] = s2[j];
		j++;
	}
	r[i + j] = '\0';
	return (r);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	if (str == NULL)
		return (0);
	while (str[count])
		count++;
	return (count);
}

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

int	ft_strcmp(char *str1, char *str2)
{
	size_t	i;
	int		num;

	i = 0;
	num = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i] && str2[i])
	{
		num = (unsigned char)str1[i] - (unsigned char)str2[i];
		if (str1[i] != str2[i])
			break ;
		i++;
	}
	num = (unsigned char)str1[i] - (unsigned char)str2[i];
	return (num);
}

int	ft_strcmp2(char *str1, char *str2)
{
	size_t	i;
	int		num;

	i = 0;
	num = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i] && str2[i])
	{
		num = (unsigned char)str1[i] - (unsigned char)str2[i];
		if (str1[i] != str2[i])
			break ;
		i++;
	}
	if (str1[i] == '\n' && str2[i] == '\0')
		return (0);
	num = (unsigned char)str1[i] - (unsigned char)str2[i];
	return (num);
}
