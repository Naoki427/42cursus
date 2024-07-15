/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:10:07 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/06/17 10:10:59 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	read_heredoc(t_tool *tool, char *limitter, int *i)
{
	char	*line;
	char	*tmp;

	tool->read = NULL;
	write(1, "> ", 2);
	line = get_next_line(0);
	while (ft_strcmp2(line, limitter))
	{
		tmp = tool->read;
		tool->read = ft_strjoin2(tmp, line);
		free(tmp);
		free(line);
		write(1, "> ", 2);
		line = get_next_line(0);
	}
	(*i)++;
}

void	write_heredoc(t_tool *tool)
{
	pipe(tool->pipefd);
	tool->pid = fork();
	if (tool->pid == 0)
	{
		close(tool->pipefd[0]);
		write(tool->pipefd[1], tool->read, ft_strlen(tool->read));
		close(tool->pipefd[1]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(tool->pipefd[1]);
		tool->record = tool->pipefd[0];
		free(tool->read);
		waitpid(-1, NULL, 0);
	}
}
