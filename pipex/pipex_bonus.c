/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:36:40 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/06/17 17:50:51 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	find_and_execute_cmd(char **path, char **cmd, char *argv)
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

static void	do_child_process(t_tool tool, int argc, int i, char **argv)
{
	dup2_and_close(tool.record, 0, 0, &tool);
	if (i == argc - 4)
		dup2_and_close(tool.filefd[OUTFILE], 1, 0, &tool);
	else
		dup2_and_close(tool.pipefd[1], 1, 0, &tool);
	if (find_ber(tool.cmd[i][0]))
	{
		if (access(tool.cmd[i][0], X_OK) == -1)
		{
			put_error_message(argv[i + 2], 0);
		}
		else
		{
			execve(tool.cmd[i][0], tool.cmd[i], environ);
		}
	}
	else
	{
		if (!tool.cmd[i][0] || !tool.cmd[i][0][0])
			put_error_message(argv[i + 2], 1);
		find_and_execute_cmd(tool.path, tool.cmd[i], argv[i + 2]);
	}
	exit(1);
}

static void	set_up(t_tool *tool, int *i, int argc, char **argv)
{
	*i = 0;
	if (argc < 5)
	{
		write(2, "Too few args\n", 13);
		exit(1);
	}
	if (argc > 1003)
	{
		write(2, "Too many args\n", 14);
		exit(1);
	}
	initialize_tool(tool, argc, argv, i);
	if (tool->read == NULL && open(argv[1], O_RDONLY) == -1)
		(*i)++;
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q pipex");
// }

int	main(int argc, char **argv)
{
	t_tool	tool;
	int		i;

	set_up(&tool, &i, argc, argv);
	if (tool.read != NULL)
		write_heredoc(&tool);
	while (i < argc - 3)
	{
		if (pipe(tool.pipefd) == -1)
			handle_pipe_error(&tool);
		tool.pid = fork();
		if (tool.pid == -1)
			return (perror("fork failed"), 1);
		else if (tool.pid == 0)
			do_child_process(tool, argc, i, argv);
		else
		{
			if (close(tool.pipefd[1]) == -1)
				return (perror("close failed"), 1);
			dup2_and_close(tool.pipefd[0], tool.record, 1, &tool);
		}
		i++;
		(tool.count)++;
	}
	return (finish_process(&tool), 0);
}
