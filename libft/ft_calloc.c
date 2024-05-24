/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:44:34 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/04/26 13:29:55 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*ptr;

	if (number != 0 && size != 0 && (SIZE_MAX / number) < size)
		return (NULL);
	if (number == 0 || size == 0)
	{
		number = 1;
		size = 1;
	}
	ptr = malloc(number * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, number * size);
	return (ptr);
}
