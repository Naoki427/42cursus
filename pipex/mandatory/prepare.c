/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:36:49 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/06/13 19:19:37 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_path_line(char *str)
{
	if (str[0] != 'P')
		return (0);
	if (str[1] != 'A')
		return (0);
	if (str[2] != 'T')
		return (0);
	if (str[3] != 'H')
		return (0);
	return (1);
}

char	**make_path_arr(void)
{
	int		i;
	int		j;
	char	**arr;
	char	*tmp;

	i = 0;
	while (environ[i] && !find_path_line(environ[i]))
		i++;
	if (!environ[i])
		return (NULL);
	environ[i] += 5;
	arr = ft_split(environ[i], ':');
	if (!arr)
		handle_malloc_error();
	j = 0;
	while (arr[j])
	{
		tmp = arr[j];
		arr[j] = ft_strjoin(arr[j], "/");
		if (!arr[j])
			handle_malloc_error();
		free(tmp);
		j++;
	}
	return (arr);
}

void	make_cmd_arr(char **argv, char ***cmd)
{
	cmd[0] = ft_split(argv[2], ' ');
	if (!cmd[0])
		handle_malloc_error();
	cmd[1] = ft_split(argv[3], ' ');
	if (!cmd[1])
		handle_malloc_error();
	cmd[2] = NULL;
}

void	initialize_tool(t_tool *tool, char **argv)
{
	tool->count = 0;
	tool->path = make_path_arr();
	make_cmd_arr(argv, tool->cmd);
	tool->filefd[INFILE] = open(argv[1], O_RDONLY);
	if (tool->filefd[INFILE] == -1)
	{
		put_error_message(argv[1], 0);
		tool->filefd[INFILE] = open("/dev/null", O_RDONLY);
	}
	tool->record = tool->filefd[INFILE];
	tool->filefd[OUTFILE] = open(argv[4], O_WRONLY | O_TRUNC);
	if (tool->filefd[OUTFILE] == -1)
	{
		if (errno == ENOENT)
			tool->filefd[OUTFILE] = open(argv[4], O_WRONLY | O_CREAT,
					S_IRUSR | S_IWUSR);
		else
		{
			put_error_message(argv[4], 0);
			exit(1);
		}
	}
}
