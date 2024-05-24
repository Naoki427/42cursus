/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:38:08 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/04/28 13:35:00 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	size_t	offset;
	size_t	bytes_to_write;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	offset = 0;
	while (len > offset)
	{
		if ((len - offset > INT_MAX))
			bytes_to_write = INT_MAX;
		else
			bytes_to_write = len - offset;
		write(fd, s + offset, bytes_to_write);
		offset += bytes_to_write;
	}
}
