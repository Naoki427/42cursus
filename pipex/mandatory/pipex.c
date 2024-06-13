/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:14:09 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/06/13 19:23:22 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_and_execute_cmd(char **path, char **cmd, char *argv)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!path)
	{
		if (execve(cmd[0], cmd, environ) == -1)
			put_error_message(cmd[0], 0);
		return ;
	}
	while (path[i])
	{
		str = ft_strjoin(path[i], cmd[0]);
		if (!str)
			handle_malloc_error();
		if (access(str, F_OK) == 0)
		{
			execve(str, cmd, environ);
			free(str);
			return ;
		}
		free(str);
		i++;
	}
	put_error_message(argv, 1);
}

void	do_child_process(t_tool *tool, int i, char **argv)
{
	if (find_ber(tool->cmd[i][0]))
	{
		if (access(tool->cmd[i][0], X_OK) == -1)
			put_error_message(argv[i + 2], 0);
		else
			execve(tool->cmd[i][0], tool->cmd[i], environ);
	}
	else
	{
		if (!tool->cmd[i][0] || !tool->cmd[i][0][0])
			put_error_message(argv[i + 2], 1);
		find_and_execute_cmd(tool->path, tool->cmd[i], argv[i + 2]);
	}
	exit(1);
}

void	pipex(t_tool *tool, char **argv, int i)
{
	pipe(tool->pipefd);
	(tool->count)++;
	tool->pid[i] = fork();
	if (tool->pid[i] == -1)
		return (perror("fork failed"));
	else if (tool->pid[i] == 0)
	{
		dup2_and_close(tool->record, 0);
		if (i == 1)
			dup2_and_close(tool->filefd[OUTFILE], 1);
		else
			dup2_and_close(tool->pipefd[1], 1);
		do_child_process(tool, i, argv);
	}
	else
	{
		if (close(tool->pipefd[1]) == -1)
			return (perror("close failed"));
		dup2_and_close(tool->pipefd[0], tool->record);
	}
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q pipex");
// }

int	main(int argc, char **argv)
{
	t_tool	tool;

	if (argc != 5)
		return (1);
	initialize_tool(&tool, argv);
	if (open(argv[1], O_RDONLY) != -1)
		pipex(&tool, argv, 0);
	pipex(&tool, argv, 1);
	wait_for_all_process(tool);
	free_str(tool.path);
	free_str2(tool.cmd);
	return (0);
}
