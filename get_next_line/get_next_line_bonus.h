/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:05:25 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/04/29 18:52:48 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *buf, int c, size_t n);
int		check_newline(char *s);
char	*get_next_line(int fd);
char	*read_file(int fd, char *str);
size_t	line_len(char *str);
char	*get_oneline(char *str);
void	ft_save(char *str, char *save);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define BUFFER_SIZE_MAX 99999999
# if BUFFER_SIZE > BUFFER_SIZE_MAX
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#else
# define BUFFER_SIZE 42
#endif