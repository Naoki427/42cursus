/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:45:17 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/17 02:26:31 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_arg_len(const char **format, va_list ap_copy, int len[3],
		t_list flglist[7])
{
	if (**format == 'c')
		return ((va_arg(ap_copy, int)), count_len_c(&len[ARG]));
	if (**format == 's')
		return (count_len_s(va_arg(ap_copy, char *), &len[ARG], flglist));
	if (**format == 'p')
		return (count_len_p((unsigned long)(va_arg(ap_copy, void *)),
			&len[ARG]));
	if (**format == 'd' || **format == 'i')
		return (count_len_diu(va_arg(ap_copy, int), len, flglist));
	if (**format == 'u')
		return (count_len_diu((va_arg(ap_copy, unsigned int)), len, flglist));
	if (**format == 'x')
		return (count_len_x((unsigned int)va_arg(ap_copy, unsigned int),
				&len[ARG], flglist));
	if (**format == 'X')
		return (count_len_x((unsigned int)va_arg(ap_copy, unsigned int),
				&len[ARG], flglist));
	if (**format == '%')
		(len[ARG])++;
}

void	write_arg(const char *format, va_list ap, int len[3], t_list flglist[7])
{
	if (*format == 'c')
		return (ft_putchar_count_len(va_arg(ap, int), &len[TOTAL]));
	if (*format == 's')
		return (ft_putstr_count_len(va_arg(ap, char *), flglist, &len[TOTAL]));
	if (*format == 'p')
		return (ft_putaddress((unsigned long)(va_arg(ap, void *)), 0,
			&len[TOTAL]));
	if (*format == 'd' || *format == 'i')
		return (ft_putnbr_count_len(va_arg(ap, int), flglist, &len[TOTAL]));
	if (*format == 'u')
		return (ft_putnbr_count_len(va_arg(ap, unsigned int), flglist,
				&len[TOTAL]));
	if (*format == 'x')
		return (ft_puthex((unsigned int)va_arg(ap, unsigned int), 0,
				&len[TOTAL], flglist));
	if (*format == 'X')
		return (ft_puthex((unsigned int)va_arg(ap, unsigned int), 1,
				&len[TOTAL], flglist));
	if (*format == '%')
	{
		write(1, "%", 1);
		(len[TOTAL])++;
	}
}

void	ft_printf_sub(const char **format, t_list flglist[7], va_list ap[2],
		int len[3])
{
	check_sign_flg(format, flglist);
	check_field_flg(format, flglist);
	check_arg_len(format, ap[0], len, flglist);
	fill_field(format, flglist, len);
	if (flglist[DOT].flg)
		ft_putzero_dot(*format, &flglist[DOT], len);
	write_arg(*format, ap[1], len, flglist);
	if (flglist[MINUS].flg)
		ft_putblank(*format, flglist, len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap[2];
	int		len[3];
	t_list	flglist[7];

	len[TOTAL] = 0;
	va_start(ap[0], format);
	va_copy(ap[1], ap[0]);
	if (!validateinput(format))
		return (-1);
	while (*format)
	{
		initialize_flg_len(flglist, len);
		if (*format == '%' && *format)
			ft_printf_sub(&format, flglist, ap, len);
		else
		{
			write(1, format, 1);
			len[TOTAL]++;
		}
		format++;
	}
	va_end(ap[0]);
	va_end(ap[1]);
	return (len[TOTAL]);
}

// #include <stdio.h>
// int main()
// {
// 	printf("return = %d\n",ft_printf("%-10%"));
// 	// printf("return = %d\n",printf("|%+-++ +7.0d|\n",0));
// 	return (0);
// }