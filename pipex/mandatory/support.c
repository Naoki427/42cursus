/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:56:39 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/06/13 19:19:43 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_malloc_error(void)
{
	perror("malloc failed");
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

void	dup2_and_close(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
	{
		perror("dup2 failed");
		exit(1);
	}
	if (close(oldfd) == -1)
	{
		perror("close failed");
		exit(1);
	}
}
