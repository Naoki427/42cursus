/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:36:52 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/06/13 19:44:46 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

extern char	**environ;
typedef struct s_tool
{
	pid_t	pid;
	int		pipefd[2];
	int		filefd[2];
	char	***cmd;
	char	**path;
	int		record;
	int		count;
}			t_tool;

# define INFILE 0
# define OUTFILE 1

char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			find_path_line(char *str);
char		**make_path_arr(void);
void		make_cmd_arr(char **argv, char ***cmd);
void		initialize_tool(t_tool *tool, char **argv);
void		put_error_message(char *argv, int flg);
void		wait_for_all_process(t_tool tool);
void		free_str(char **r);
void		free_str2(char ***r);
void		handle_malloc_error(void);
int			find_ber(char *str);
void		put_error_message(char *argv, int flg);
void		dup2_and_close(int oldfd, int newfd);
#endif