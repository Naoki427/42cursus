/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 02:11:24 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/23 12:09:04 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node(t_stack *st1, t_stack *st2, char *content)
{
	t_stack	*prest1;
	t_stack	*nextst1;

	prest1 = st1->pre;
	nextst1 = st1->next;
	prest1->next = nextst1;
	nextst1->pre = prest1;
	(st2->pre)->next = st1;
	st1->pre = st2->pre;
	st1->next = st2;
	st2->pre = st1;
	if (st2->next == st2)
		st2->next = st1;
	if (content != NULL)
	{
		write(1, content, 2);
		write(1, "\n", 1);
	}
}

int	ft_min_rot(int n, int m)
{
	if (n <= m)
		return (n);
	else
		return (-m);
}

int	count_lower_mid(t_stack **a, int mid)
{
	t_stack	*l;
	int		count;

	l = (*a)->next;
	count = 0;
	while (l != *a)
	{
		if (l->nb <= mid)
			count++;
		l = l->next;
	}
	return (count);
}

void	free_lst(t_stack **a)
{
	t_stack	*l;
	t_stack	*tmp;

	l = (*a)->next;
	while (l != *a)
	{
		tmp = l->next;
		free(l);
		l = tmp;
	}
	free(*a);
}

int	check_sort(t_stack **a)
{
	t_stack	*l;

	l = (*a)->next;
	while (l->next != *a)
	{
		if (l->nb > (l->next)->nb)
			return (1);
		l = l->next;
	}
	return (0);
}
