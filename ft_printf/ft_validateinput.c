/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validateinput.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:29:08 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/07 20:28:20 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	validateinput_sub(const char **format)
{
	char	c;

	c = **format;
	while (**format == c)
		(*format)++;
	if (**format == '-')
	{
		while (**format == c || **format == '-')
			(*format)++;
	}
	else if (**format == '0')
	{
		while (**format == c || **format == '0')
			(*format)++;
	}
}

void	validateinput_sub2(const char **format)
{
	char	c;

	c = **format;
	while (**format == c)
		(*format)++;
	if (**format == '#')
	{
		while (**format == c || **format == '#')
			(*format)++;
	}
	else if (**format == ' ')
	{
		while (**format == c || **format == ' ')
			(*format)++;
	}
	else if (**format == '+')
	{
		while (**format == c || **format == '+')
			(*format)++;
	}
}

int	validateinput(const char *format)
{
	while (*format)
	{
		if (*format == '%' && *format)
		{
			format++;
			if (*format == '#' || *format == ' ' || *format == '+')
				validateinput_sub(&format);
			if (*format == '-' || *format == '0')
				validateinput_sub2(&format);
			while (*format >= '0' && *format <= '9')
				format++;
			if (*format == '.')
				format++;
			while (*format >= '0' && *format <= '9')
				format++;
			if (*format != 'c' && *format != 's' && *format != 'p'
				&& *format != 'd' && *format != 'i' && *format != 'u'
				&& *format != 'x' && *format != 'X' && *format != '%')
				return (0);
		}
			format++;
	}
	return (1);
}
