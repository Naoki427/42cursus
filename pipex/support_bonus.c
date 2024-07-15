/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:51:30 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/06/17 15:47:30 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_malloc_error(void)
{
	perror("malloc failed");
	exit(1);
}

void	handle_pipe_error(t_tool *tool)
{
	perror("pipe failed");
	free_all(tool);
	exit(1);
}

int	find_ber(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

void	put_error_message(char *argv, int flg)
{
	write(2, "bash: ", 6);
	write(2, argv, ft_strlen(argv));
	write(2, ": ", 2);
	if (flg == 1)
		write(2, "command not found\n", 18);
	else
		perror("");
}

void	dup2_and_close(int oldfd, int newfd, int flg, t_tool *tool)
{
	if (dup2(oldfd, newfd) == -1)
	{
		perror("dup2 failed");
		if (flg == 1)
			free_all(tool);
		exit(1);
	}
	if (close(oldfd) == -1)
	{
		perror("close failed");
		if (flg == 1)
			free_all(tool);
		exit(1);
	}
}
