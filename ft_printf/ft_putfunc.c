/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:49:52 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/17 02:25:29 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddress(unsigned long ptr, int p_flg, int *len)
{
	if (p_flg == 0)
	{
		write(1, "0x", 2);
		*len += 2;
		p_flg = 1;
	}
	if (ptr >= 16)
		ft_putaddress(ptr / 16, 1, len);
	write(1, &HEX_LOWER[ptr % 16], 1);
	(*len)++;
}

void	ft_puthex(unsigned int n, int x_flg, int *len, t_list flglist[7])
{
	if (flglist[DOT].flg && flglist[DOT].len == 0 && n == 0)
		return ;
	if (n >= 16)
		ft_puthex(n / 16, x_flg, len, flglist);
	if (x_flg == 0)
	{
		write(1, &HEX_LOWER[n % 16], 1);
		(*len)++;
	}
	else
	{
		write(1, &HEX_UPPER[n % 16], 1);
		(*len)++;
	}
}

void	ft_putblank(const char *format, t_list flglist[7], int len[3])
{
	int	tmp;
	int	total_len;

	if (flglist[MINUS].flg)
		tmp = flglist[MINUS].len;
	if (flglist[NUMBER].flg)
		tmp = flglist[NUMBER].len;
	if (flglist[ZERO].flg)
		tmp = flglist[ZERO].len;
	if (flglist[6].flg && flglist[6].len > len[ARG] && *format != 's')
		total_len = flglist[6].len + len[SYMBOL];
	else
		total_len = len[ARG] + len[SYMBOL];
	while (tmp > total_len)
	{
		write(1, " ", 1);
		tmp--;
		len[TOTAL]++;
	}
}

void	ft_putzero(const char *format, t_list *flglist, int len[3])
{
	int	total_len;

	if (*format == 'd' || *format == 'i' || *format == 'u' || *format == 'x'
		|| *format == 'X' || *format == '%')
	{
		if (flglist->flg == 2)
			write(1, "-", 1);
		total_len = len[ARG] + len[SYMBOL];
		while (flglist->len > total_len)
		{
			write(1, "0", 1);
			(flglist->len)--;
			len[TOTAL]++;
		}
	}
}

void	ft_putzero_dot(const char *format, t_list *flglist, int len[3])
{
	int	tmp;

	tmp = flglist->len;
	if (*format == 'd' || *format == 'i' || *format == 'u' || *format == 'x'
		|| *format == 'X')
	{
		if (flglist->flg == 2 && *format != 's')
			write(1, "-", 1);
		while (tmp > len[ARG])
		{
			write(1, "0", 1);
			tmp--;
			len[TOTAL]++;
		}
	}
}
