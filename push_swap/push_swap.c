/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:26:50 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/23 12:02:35 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack **a, int argc, char **argv)
{
	while (argc)
	{
		ft_lstadd_back_bid(a, ft_lstnew_bid(ft_atoi(*argv)));
		argv++;
		argc--;
	}
}

void	push_stack_a_sub(t_stack **a, t_stack **b, int count[2])
{
	if (count[0] >= 0 && count[1] >= 0)
	{
		rotate_double(a, b, ft_minimum(count[0], count[1]));
		if (count[0] > count[1])
			rotate_node(a, "ra", count[0] - count[1]);
		else
			rotate_node(b, "rb", count[1] - count[0]);
	}
	if (count[0] < 0 && count[1] < 0)
	{
		reverce_rotate_double(a, b, -(ft_maximum(count[0], count[1])));
		if (count[0] < count[1])
			reverce_rotate_node(a, "rra", -count[0] + count[1]);
		else
			reverce_rotate_node(b, "rrb", -count[1] + count[0]);
	}
	if (count[0] >= 0 && count[1] < 0)
		return (rotate_node(a, "ra", count[0]), reverce_rotate_node(b, "rrb",
				-count[1]));
	if (count[0] < 0 && count[1] >= 0)
		return (reverce_rotate_node(a, "rra", -count[0]), rotate_node(b, "rb",
				count[1]));
}

void	push_stack_a(t_stack **a, t_stack **b, int argc, int mid)
{
	int	n[2];

	n[0] = argc - 3;
	if (argc > 50)
		n[1] = argc - (argc / 2 - count_lower_mid(a, mid));
	else
		n[1] = n[0] + 1;
	while ((n[0] > 0))
	{
		push_stack_a_sub(a, b, find_optimal_node(a, b, n, mid));
		push_node((*b)->next, (*a)->next, "pa");
		n[0]--;
	}
}

int	count_to_head(t_stack **a)
{
	t_stack	*l;
	int		count[2];

	count[0] = 0;
	count[1] = 0;
	l = (*a)->next;
	count[0]++;
	while (l->nb < (l->next)->nb)
	{
		l = l->next;
		count[0]++;
	}
	l = (*a)->pre;
	count[1]++;
	while (l->nb > (l->pre)->nb)
	{
		l = l->pre;
		count[1]++;
	}
	return (ft_min_rot(count[0], count[1]));
}

void	push_swap(int argc, char **argv)
{
	t_stack	**stack[2];
	t_stack	*tmp[2];
	int		mid;
	int		count;

	tmp[0] = ft_lstnew_bid(-1);
	tmp[1] = ft_lstnew_bid(-1);
	stack[A] = &tmp[0];
	stack[B] = &tmp[1];
	fill_stack(stack[A], argc, argv);
	mid = find_mid(argc, stack[A]);
	if (blanch_by_argc(stack[A], stack[B], argc, mid))
		return (free_lst(stack[A]), free(*stack[B]));
	push_stack_a(stack[A], stack[B], argc, mid);
	if (((*stack[A])->next)->nb > ((*stack[A])->pre)->nb)
	{
		count = count_to_head(stack[A]);
		if (count > 0)
			rotate_node(stack[A], "ra", count);
		else
			reverce_rotate_node(stack[A], "rra", -count);
	}
	free_lst(stack[A]);
	free(*stack[B]);
}

// int	main(int argc, char **argv)
// {
// 	argc--;
// 	argv++;
// 	push_swap(argc, argv);
// 	return (0);
// }
