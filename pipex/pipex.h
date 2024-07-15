/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:26:47 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/06/17 15:36:21 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

extern char	**environ;
typedef struct s_tool
{
	pid_t	pid[2];
	int		pipefd[2];
	int		filefd[2];
	char	**cmd[3];
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
void		wait_for_all_process(int count);
void		free_str(char **r);
void		free_str2(char ***r);
void		free_all(t_tool *tool);
void		handle_malloc_error(void);
void		handle_pipe_error(t_tool *tool);
int			find_ber(char *str);
void		put_error_message(char *argv, int flg);
void		dup2_and_close(int oldfd, int newfd, int flg, t_tool *tool);
#endif