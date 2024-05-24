/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:50:41 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/23 12:08:56 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_threenode_a(t_stack **s)
{
	if (((*s)->next)->nb > (((*s)->next)->next)->nb)
	{
		if (((*s)->next)->nb < ((((*s)->next)->next)->next)->nb)
			swap_node((*s)->next, "sa");
		else if (((*s)->next)->nb > ((((*s)->next)->next)->next)->nb
			&& (((*s)->next)->next)->nb < ((((*s)->next)->next)->next)->nb)
			rotate_node(s, "ra", 1);
		else
		{
			swap_node((*s)->next, "sa");
			reverce_rotate_node(s, "rra", 1);
		}
	}
	else if ((((*s)->next)->next)->nb > ((((*s)->next)->next)->next)->nb)
	{
		if (((*s)->next)->nb > ((((*s)->next)->next)->next)->nb)
			reverce_rotate_node(s, "rra", 1);
		else
		{
			swap_node((*s)->next, "sa");
			rotate_node(s, "ra", 1);
		}
	}
}

int	find_mid(int argc, t_stack **a)
{
	t_stack	*l;
	int		mid;
	int		tmp;
	int		i;

	l = (*a)->next;
	mid = l->nb;
	tmp = INT_MIN;
	i = 0;
	while (i <= argc / 2)
	{
		l = (*a)->next;
		mid = l->nb;
		while (l != (*a))
		{
			if ((mid > l->nb && l->nb > tmp) || mid <= tmp)
				mid = l->nb;
			l = l->next;
		}
		tmp = mid;
		i++;
	}
	return (mid);
}

void	push_to_b(t_stack **a, t_stack **b, int argc, int mid)
{
	int	i;

	i = 0;
	push_node((*a)->next, (*b)->next, "pb");
	argc--;
	while (i < argc - 3)
	{
		if (((*a)->next)->nb < mid || argc <= 50)
			push_node((*a)->next, (*b)->next, "pb");
		else
		{
			push_node((*a)->next, (*b)->next, "pb");
			rotate_node(b, "rb", 1);
		}
		i++;
	}
	sort_threenode_a(a);
}

int	blanch_by_argc(t_stack **a, t_stack **b, int argc, int mid)
{
	if (argc <= 1)
		return (1);
	if (argc == 2)
	{
		if (((*a)->next)->nb > (((*a)->next)->next)->nb)
			swap_node((*a)->next, "sa");
		return (1);
	}
	if (argc == 3)
	{
		sort_threenode_a(a);
		return (1);
	}
	else
	{
		if (!check_sort(a))
			return (1);
		push_to_b(a, b, argc, mid);
	}
	return (0);
}
