/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:31:00 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/04/26 12:52:02 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 'a' && c <= 'z'))
		return (c - 32);
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>

// int main()
// {
//     int n = 'z';
//     printf("result : %d\n",ft_toupper(n));
//     printf("answer : %d\n",toupper(n));
//     return (0);
// }