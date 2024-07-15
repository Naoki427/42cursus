/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:52:27 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/06/17 18:07:09 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

char	***make_cmd_arr(int argc, char **argv)
{
	char	***arr;
	int		i;

	arr = (char ***)malloc(sizeof(char **) * (argc - 3 + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < argc - 3)
	{
		arr[i] = ft_split(argv[i + 2], ' ');
		if (!arr)
			return (NULL);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

static void	initialize_tool_sub(t_tool *tool, int argc, char **argv)
{
	tool->filefd[INFILE] = open(argv[1], O_RDONLY);
	if (tool->filefd[INFILE] == -1)
	{
		put_error_message(argv[1], 0);
		tool->filefd[INFILE] = open("/dev/null", O_RDONLY);
	}
	tool->record = tool->filefd[INFILE];
	tool->filefd[OUTFILE] = open(argv[argc - 1], O_WRONLY | O_TRUNC);
	if (tool->filefd[OUTFILE] == -1)
	{
		if (errno == ENOENT)
			tool->filefd[OUTFILE] = open(argv[argc - 1], O_WRONLY | O_CREAT,
					S_IRUSR | S_IWUSR);
		else
		{
			put_error_message(argv[argc - 1], 0);
			exit(1);
		}
	}
}

void	initialize_tool(t_tool *tool, int argc, char **argv, int *i)
{
	tool->read = NULL;
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		read_heredoc(tool, argv[2], i);
		tool->filefd[OUTFILE] = open(argv[argc - 1], O_WRONLY | O_APPEND);
		if (tool->filefd[OUTFILE] == -1)
		{
			if (errno == ENOENT)
				tool->filefd[OUTFILE] = open(argv[argc - 1], O_WRONLY | O_CREAT,
						S_IRUSR | S_IWUSR);
			else
			{
				put_error_message(argv[argc - 1], 0);
				exit(1);
			}
		}
	}
	else
		initialize_tool_sub(tool, argc, argv);
	tool->path = make_path_arr();
	tool->cmd = make_cmd_arr(argc, argv);
}
