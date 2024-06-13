/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 03:18:49 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/29 16:19:51 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	int		i;

	if (!str)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dest)
		return (0);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}

t_enemy	*ft_lstnew(int x, int y, int type)
{
	t_enemy	*new;

	new = (t_enemy *)malloc(sizeof(t_enemy));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->type = type;
	new->next = NULL;
	return (new);
}

t_enemy	*ft_lstlast(t_enemy *lst)
{
	t_enemy	*last;

	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}

void	ft_lstadd_back(t_enemy **lst, t_enemy *new)
{
	t_enemy	*l;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		l = ft_lstlast(*lst);
		l->next = new;
	}
}
