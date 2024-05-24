/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:43:14 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/04/26 12:41:24 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *buf, size_t n)
{
	ft_memset(buf, 0, n);
}

// #include<stdio.h>
// #include<string.h>

// int main()
// {
//     char buf1[] = "ABCDEFGHIJK";
//     char buf2[] = "ABCDEFGHIJK";

// 	ft_bzero(buf1+2,3);
// 	bzero(buf2+2,3);
//     printf("result : %s\n",buf1);
//     printf("answer : %s\n",buf2);
//     return (0);
// }
