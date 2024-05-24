/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimal_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:52:57 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/22 02:12:09 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_ra(int bn, t_stack *a)
{
	t_stack	*n;
	t_stack	*p;
	int		r_count;

	n = a->next;
	p = a->pre;
	r_count = 0;
	while ((bn > n->nb || bn < p->nb) && (bn > n->nb || bn > p->nb
			|| n->nb >= p->nb) && (bn < n->nb || bn < p->nb || n->nb >= p->nb))
	{
		r_count++;
		p = n;
		n = n->next;
	}
	return (r_count);
}

int	count_rra(int bn, t_stack *a)
{
	t_stack	*n;
	t_stack	*p;
	int		r_count;

	n = a->next;
	p = a->pre;
	r_count = 0;
	while ((bn > n->nb || bn < p->nb) && (bn > n->nb || bn > p->nb
			|| n->nb >= p->nb) && (bn < n->nb || bn < p->nb || n->nb >= p->nb))
	{
		r_count++;
		n = p;
		p = p->pre;
	}
	return (r_count);
}

int	**allocate_count_arr(int size)
{
	int	**count;
	int	i;

	i = 0;
	count = (int **)malloc(size * sizeof(int *));
	if (!count)
		return (0);
	while (i < size)
	{
		count[i] = (int *)malloc(2 * sizeof(int));
		if (!count[i])
			return (0);
		i++;
	}
	return (count);
}

void	fill_count_arr(t_stack **a, t_stack **b, int **count, t_param params)
{
	int		i;
	t_stack	*c;

	i = 0;
	c = (*b)->next;
	while (i < 2 * params.n[0])
	{
		if (i == params.n[0])
			c = (*b)->pre;
		if (params.n[0] >= params.n[1] && c->nb >= params.mid)
			count[i][0] = INT_MAX / 2;
		else
			count[i][0] = ft_min_rot(count_ra(c->nb, *a), count_rra(c->nb, *a));
		if (i < params.n[0])
		{
			count[i][1] = i;
			c = c->next;
		}
		else
		{
			count[i][1] = -i + params.n[0] - 1;
			c = c->pre;
		}
		i++;
	}
}

int	*find_optimal_node(t_stack **a, t_stack **b, int n[2], int mid)
{
	int		**count;
	int		i;
	t_param	params;
	int		*opt;

	i = 0;
	count = allocate_count_arr(2 * n[0]);
	if (!count)
		return (0);
	params.n[0] = n[0];
	params.n[1] = n[1];
	params.mid = mid;
	fill_count_arr(a, b, count, params);
	opt = find_opt_sub(n[0], count);
	while (i < 2 * n[0])
	{
		free(count[i]);
		i++;
	}
	free(count);
	return (opt);
}
