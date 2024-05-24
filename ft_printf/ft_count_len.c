/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:29:09 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/07 20:28:31 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	count_len_c(int *len)
{
	(*len)++;
}

void	count_len_s(char *s, int *len, t_list flglist[7])
{
	flglist[SPACE].flg = 0;
	if (s == NULL)
		*len = 6;
	else
		*len += ft_strlen(s);
	if (flglist[DOT].flg > 0 && flglist[DOT].len < *len)
		*len = flglist[DOT].len;
}

void	count_len_p(unsigned long ptr, int *len)
{
	*len += 2;
	if (ptr == 0)
		(*len)++;
	while (ptr > 0)
	{
		ptr /= 16;
		(*len)++;
	}
}

void	count_len_diu(long nb, int len[3], t_list flglist[7])
{
	if (nb >= 0 && (flglist[SPACE].flg || flglist[PLUS].flg))
		(len[SYMBOL])++;
	if (flglist[DOT].flg && flglist[DOT].len == 0 && nb == 0)
		return ;
	if (nb == 0)
		(len[ARG])++;
	if (nb < 0)
	{
		flglist[SPACE].flg = 0;
		flglist[PLUS].flg = 0;
		if (flglist[ZERO].flg)
			flglist[ZERO].flg = 2;
		if (flglist[DOT].flg)
			flglist[DOT].flg = 2;
		nb = -nb;
		(len[SYMBOL])++;
	}
	while (nb > 0)
	{
		nb /= 10;
		(len[ARG])++;
	}
}

void	count_len_x(unsigned int n, int *len, t_list flglist[7])
{
	if (flglist[DOT].flg && flglist[DOT].len == 0 && n == 0)
	{
		flglist[HASH].flg = 0;
		return ;
	}
	if (n == 0)
	{
		(*len)++;
		flglist[HASH].flg = 0;
	}
	while (n > 0)
	{
		n /= 16;
		(*len)++;
	}
}
