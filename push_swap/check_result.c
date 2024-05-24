/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:41:30 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/23 12:46:35 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>

int	compare_input(char *input, char *command, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (input[i] != command[i])
			return (0);
		i++;
	}
	if (input[i] == '\n')
		return (1);
	else
		return (0);
}

int	read_command(t_stack **a, t_stack **b, char *line)
{
	if (compare_input(line, "pb", 2))
		return (push_node((*a)->next, (*b)->next, NULL), 1);
	if (compare_input(line, "pa", 2))
		return (push_node((*b)->next, (*a)->next, NULL), 1);
	if (compare_input(line, "sa", 2))
		return (swap_node((*a)->next, ""), 1);
	if (compare_input(line, "sb", 2))
		return (swap_node((*b)->next, ""), 1);
	if (compare_input(line, "ra", 2))
		return (rotate_node(a, "", 1), 1);
	if (compare_input(line, "rb", 2))
		return (rotate_node(b, "", 1), 1);
	if (compare_input(line, "rr", 2))
		return (rotate_node(a, "", 1), rotate_node(b, "", 1), 1);
	if (compare_input(line, "rra", 3))
		return (reverce_rotate_node(a, "", 1), 1);
	if (compare_input(line, "rrb", 3))
		return (reverce_rotate_node(b, "", 1), 1);
	if (compare_input(line, "rrr", 3))
		return (reverce_rotate_node(a, "", 1), reverce_rotate_node(b, "", 1),
			1);
	return (0);
}

void	check_sort_ok(t_stack **a)
{
	t_stack	*l;

	l = (*a)->next;
	while (l->next != *a)
	{
		if (l->nb > (l->next)->nb)
		{
			write(1, "KO\n", 3);
			return ;
		}
		l = l->next;
	}
	write(1, "OK\n", 3);
}

int	check_result(int argc, char **argv)
{
	t_stack	**stack[2];
	t_stack	*tmp[2];
	char	*line;

	tmp[0] = ft_lstnew_bid(-1);
	tmp[1] = ft_lstnew_bid(-1);
	stack[A] = &tmp[0];
	stack[B] = &tmp[1];
	fill_stack(stack[A], argc, argv);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (!read_command(stack[A], stack[B], line))
			return (1);
		free(line);
		line = get_next_line(0);
	}
	check_sort_ok(stack[A]);
	free_lst(stack[A]);
	free_lst(stack[B]);
	return (0);
}
