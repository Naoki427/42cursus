/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishing_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:52:03 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/06/17 15:23:15 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	wait_for_all_process(int count)
{
	int	i;

	i = 0;
	while (i < count)
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
	free(r);
}

void	free_all(t_tool *tool)
{
	if (tool->path)
		free_str(tool->path);
	free_str2(tool->cmd);
}

void	finish_process(t_tool *tool)
{
	wait_for_all_process(tool->count);
	free_all(tool);
}
