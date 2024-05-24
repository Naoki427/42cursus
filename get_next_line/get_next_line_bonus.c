/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:35:54 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/04/29 18:54:53 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

char	*get_next_line(int fd)
{
	static char	save[10241][BUFFER_SIZE] = {};
	char		*result;
	char		*str;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	str = NULL;
	str = ft_strjoin(str, save[fd]);
	if (str == NULL)
		return (NULL);
	str = read_file(fd, str);
	if (str == NULL)
	{
		ft_memset(save[fd], 0, ft_strlen(save[fd]));
		free(str);
		return (NULL);
	}
	result = get_oneline(str);
	ft_save(str, save[fd]);
	free(str);
	return (result);
}

char	*read_file(int fd, char *str)
{
	int		byte;
	char	*buf;
	char	*temp;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	byte = 1;
	while (byte > 0 && check_newline(str))
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1)
			return (free(buf), free(str), NULL);
		buf[byte] = '\0';
		temp = str;
		str = ft_strjoin(str, buf);
		free(temp);
		if (!str)
			break ;
	}
	free(buf);
	return (str);
}

size_t	line_len(char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\n' && str[count])
		count++;
	if (str[count] == '\n')
		count++;
	return (count);
}

char	*get_oneline(char *str)
{
	char	*r;
	size_t	i;

	i = 0;
	if (str[0] == '\0')
		return (NULL);
	r = (char *)malloc(line_len(str) + 1);
	if (!r)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		r[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		r[i] = '\n';
		r[i + 1] = '\0';
	}
	else
		r[i] = '\0';
	return (r);
}

void	ft_save(char *str, char *save)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
		i++;
		while (str[i + j] != '\0')
		{
			save[j] = str[i + j];
			j++;
		}
		save[j] = '\0';
	}
	else
		save[0] = '\0';
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int fd1 = open("test1.txt", O_RDONLY);
// 	int fd2 = open("test2.txt", O_RDONLY);
// 	char *line1 = "";
// 	char *line2 = "";
// 	while (line1 || line2)
// 	{
// 		line1 = get_next_line(fd1);
// 		line2 = get_next_line(fd2);
// 		printf("fd1line:%s\n", line1);
// 		printf("fd2line:%s\n", line2);
// 		free(line1);
// 		free(line2);
// 	}
// 	return (0);
// }