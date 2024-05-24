/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonusfunc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:32:10 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/07 19:34:05 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_flg_len(t_list flglist[7], int len[3])
{
	flglist[HASH].flg = 0;
	flglist[HASH].len = 0;
	flglist[SPACE].flg = 0;
	flglist[SPACE].len = 0;
	flglist[PLUS].flg = 0;
	flglist[PLUS].len = 0;
	flglist[MINUS].flg = 0;
	flglist[MINUS].len = 0;
	flglist[NUMBER].flg = 0;
	flglist[NUMBER].len = 0;
	flglist[ZERO].flg = 0;
	flglist[ZERO].len = 0;
	flglist[DOT].flg = 0;
	flglist[DOT].len = 0;
	len[ARG] = 0;
	len[SYMBOL] = 0;
}

void	check_sign_flg(const char **format, t_list flglist[7])
{
	(*format)++;
	while (**format == '#' || **format == ' ' || **format == '+'
		|| **format == '-' || **format == '0')
	{
		if (**format == '#')
			flglist[HASH].flg = 1;
		if (**format == ' ')
			flglist[SPACE].flg = 1;
		if (**format == '+')
			flglist[PLUS].flg = 1;
		if (**format == '-')
			flglist[MINUS].flg = 1;
		if (**format == '0')
			flglist[ZERO].flg = 1;
		(*format)++;
	}
	if (flglist[ZERO].flg == 1)
		count_fieldwidth(format, &flglist[ZERO]);
	if (flglist[MINUS].flg == 1)
		count_fieldwidth(format, &flglist[MINUS]);
}

void	check_field_flg(const char **format, t_list flglist[7])
{
	if (**format >= '1' && **format <= '9')
	{
		flglist[NUMBER].flg = 1;
		count_fieldwidth(format, &flglist[NUMBER]);
	}
	if (**format == '.')
	{
		(*format)++;
		flglist[DOT].flg = 1;
		count_fieldwidth(format, &flglist[DOT]);
	}
}

void	count_fieldwidth(const char **format, t_list *flglist)
{
	while (**format >= '0' && **format <= '9')
	{
		flglist->len = (flglist->len) * 10 + (**format - '0');
		(*format)++;
	}
}

void	fill_field(const char **format, t_list flglist[7], int len[3])
{
	if (flglist[HASH].flg && (**format == 'x' || **format == 'X'))
		len[SYMBOL] += 2;
	if (flglist[NUMBER].flg)
		ft_putblank(*format, flglist, len);
	if (flglist[ZERO].flg && flglist[DOT].flg)
		ft_putblank(*format, flglist, len);
	if (flglist[HASH].flg && (**format == 'x' || **format == 'X'))
	{
		write(1, "0", 1);
		write(1, *format, 1);
		len[TOTAL] += 2;
	}
	if (flglist[SPACE].flg == 1)
	{
		write(1, " ", 1);
		len[TOTAL]++;
	}
	if (flglist[PLUS].flg == 1)
	{
		write(1, "+", 1);
		len[TOTAL]++;
	}
	if (flglist[ZERO].flg && !flglist[DOT].flg)
		ft_putzero(*format, &flglist[ZERO], len);
}
