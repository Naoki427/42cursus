/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:11:51 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/07 20:28:27 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_count_len(int c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (str == NULL)
		return (0);
	while (str[count])
		count++;
	return (count);
}

int	ft_putstr_count_len_sub(char *str, int i)
{
	int	count;

	count = 0;
	while (i > 0 && count < 6)
	{
		write(1, str, 1);
		i--;
		str++;
		count++;
	}
	return (count);
}

void	ft_putstr_count_len(char *s, t_list flglist[7], int *len)
{
	if (flglist[DOT].flg == 1)
	{
		if (s == NULL && flglist[DOT].len > 0)
		{
			*len += ft_putstr_count_len_sub("(null)", flglist[DOT].len);
			return ;
		}
		while (flglist[DOT].len > 0 && *s)
		{
			ft_putchar_count_len(*s, len);
			s++;
			flglist[DOT].len--;
		}
	}
	else
	{
		if (s == NULL)
		{
			write(1, "(null)", 6);
			*len += 6;
			return ;
		}
		write(1, s, ft_strlen(s));
		*len += ft_strlen(s);
	}
}

void	ft_putnbr_count_len(long nb, t_list flglist[7], int *len)
{
	char	num;

	if (flglist[6].flg == 1 && flglist[6].len == 0 && nb == 0)
		return ;
	if (nb < 0)
	{
		if (flglist[ZERO].flg == 0 && flglist[DOT].flg == 0)
			write(1, "-", 1);
		(*len)++;
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_count_len(nb / 10, flglist, len);
	num = nb % 10 + '0';
	write(1, &num, 1);
	(*len)++;
}
