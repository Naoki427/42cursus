/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:50:59 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/06/13 19:19:14 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_for_all_process(t_tool tool)
{
	int	i;

	i = 0;
	while (i < tool.count)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
}

void	free_str(char **r)
{
	int	i;

	i = 0;
	while (r[i])
	{
		free(r[i]);
		i++;
	}
	free(r);
}

void	free_str2(char ***r)
{
	int	j;

	j = 0;
	while (r[j])
	{
		free_str(r[j]);
		j++;
	}
}
