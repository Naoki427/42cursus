/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:49:31 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/07 20:25:48 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define HASH 0
# define SPACE 1
# define PLUS 2
# define MINUS 3
# define NUMBER 4
# define ZERO 5
# define DOT 6
# define TOTAL 0
# define ARG 1
# define SYMBOL 2

typedef struct s_list
{
	int	flg;
	int	len;
}		t_list;

int		ft_printf(const char *format, ...);
int		validateinput(const char *format);
void	validateinput_sub(const char **format);
void	validateinput_sub2(const char **format);
void	initialize_flg_len(t_list flglist[7], int len[3]);
void	check_sign_flg(const char **format, t_list flglist[7]);
void	check_field_flg(const char **format, t_list flglist[7]);
void	count_fieldwidth(const char **format, t_list *flglist);
void	fill_field(const char **format, t_list flglist[7], int len[2]);
void	check_arg_len(const char **format, va_list ap_copy, int *len,
			t_list flglist[7]);
void	write_arg(const char *format, va_list ap, int len[3],
			t_list flglist[7]);
void	ft_printf_sub(const char **format, t_list flglist[7], va_list ap[2],
			int len[3]);
void	ft_putchar_count_len(int c, int *len);
size_t	ft_strlen(const char *str);
int		ft_putstr_count_len_sub(char *str, int i);
void	ft_putstr_count_len(char *s, t_list flglist[7], int *len);
void	ft_putnbr_count_len(long nb, t_list flglist[7], int *len);
void	ft_putaddress(unsigned long ptr, int p_flg, int *len);
void	ft_puthex(unsigned int n, int x_flg, int *len, t_list flglist[7]);
void	ft_putblank(const char *format, t_list flglist[7], int len[3]);
void	ft_putzero(const char *format, t_list *flglist, int len[3]);
void	ft_putzero_dot(const char *format, t_list *flglist, int len[3]);
void	count_len_c(int *len);
void	count_len_s(char *s, int *len, t_list flglist[7]);
void	count_len_p(unsigned long ptr, int *len);
void	count_len_diu(long nb, int len[3], t_list flglist[7]);
void	count_len_x(unsigned int n, int *len, t_list flglist[7]);
#endif