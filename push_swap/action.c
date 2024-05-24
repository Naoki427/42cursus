/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:34:42 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/23 12:50:08 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_node(t_stack *node, char *content)
{
	t_stack	*nextnode;

	nextnode = node->next;
	(nextnode->next)->pre = node;
	(node->pre)->next = nextnode;
	node->next = nextnode->next;
	nextnode->pre = node->pre;
	node->pre = nextnode;
	nextnode->next = node;
	write(1, content, ft_strlen(content));
	if (ft_strlen(content))
		write(1, "\n", 1);
}

void	rotate_node(t_stack **stack, char *content, int i)
{
	while (i > 0 && (*stack)->next != *stack
		&& ((*stack)->next)->next != *stack)
	{
		swap_node((*stack), content);
		i--;
	}
}

void	reverce_rotate_node(t_stack **stack, char *content, int i)
{
	while (i > 0 && (*stack)->next != *stack
		&& ((*stack)->next)->next != *stack)
	{
		swap_node((*stack)->pre, content);
		i--;
	}
}

void	rotate_double(t_stack **a, t_stack **b, int i)
{
	while (i > 0)
	{
		swap_node(*a, "");
		swap_node(*b, "");
		write(1, "rr", 2);
		write(1, "\n", 1);
		i--;
	}
}

void	reverce_rotate_double(t_stack **a, t_stack **b, int i)
{
	while (i > 0)
	{
		swap_node((*a)->pre, "");
		swap_node((*b)->pre, "");
		write(1, "rrr", 3);
		write(1, "\n", 1);
		i--;
	}
}
