/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 02:47:33 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/29 16:19:20 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	evolve_enemy(t_enemy *enemy, t_enemy **lst)
{
	t_enemy	*tmp;

	tmp = *lst;
	if (enemy->type == 1)
	{
		while (tmp != NULL)
		{
			if (enemy->x == tmp->x && enemy->y == tmp->y && tmp->type == 0)
			{
				enemy->type = 2;
				delete_typezero(tmp, lst);
				break ;
			}
			tmp = tmp->next;
		}
	}
}

void	delete_typezero(t_enemy *zero, t_enemy **lst)
{
	t_enemy	*tmp;

	if (*lst == zero)
	{
		*lst = zero->next;
		free(zero);
		return ;
	}
	tmp = *lst;
	while (tmp->next != zero)
		tmp = tmp->next;
	tmp->next = zero->next;
	free(zero);
}
