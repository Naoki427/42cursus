/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:33:21 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/22 21:39:37 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew_bid(int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->flg = 0;
	new->pre = new;
	new->next = new;
	return (new);
}

void	ft_lstadd_back_bid(t_stack **lst, t_stack *new)
{
	t_stack	*l;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		l = (*lst)->pre;
		l->next = new;
		(*lst)->pre = new;
		new->next = (*lst);
		new->pre = l;
	}
}

int	validate_num(char *s)
{
	if (*s == '-')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		flg;
	long	num;

	flg = 1;
	num = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			flg *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = 10 * num + (*str - '0');
		str++;
	}
	return (flg * (int)num);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (str == NULL)
		return (0);
	while (str[count])
		count++;
	return (count);
}
