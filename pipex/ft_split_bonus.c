/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:52:46 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/06/16 10:27:33 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	lowsize(char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			size++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (size);
}

static void	free_arr(char **r, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(r[j]);
		j++;
	}
	free(r);
}

static char	*fill_arr(char const *s, char c, int *j)
{
	int	len;

	len = 0;
	while (s[*j] == c && s[*j])
		(*j)++;
	while (s[*j] != c && s[*j])
	{
		(*j)++;
		len++;
	}
	return (ft_substr(s, *j - len, len));
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (0);
	len = lowsize(s, c);
	r = (char **)malloc(sizeof(char *) * (len + 1));
	if (!r)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		r[i] = fill_arr(s, c, &j);
		if (r[i] == NULL)
		{
			free_arr(r, i);
			return (0);
		}
		i++;
	}
	r[i] = NULL;
	return (r);
}
