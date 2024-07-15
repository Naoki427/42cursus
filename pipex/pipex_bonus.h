/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:36:52 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/06/17 15:53:16 by nyoshimi         ###   ########.fr       */
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
	char	*read;
}			t_tool;

# define INFILE 0
# define OUTFILE 1

char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_strcmp(char *str1, char *str2);
int			ft_strcmp2(char *str1, char *str2);
int			find_path_line(char *str);
char		**make_path_arr(void);
char		***make_cmd_arr(int argc, char **argv);
void		initialize_tool(t_tool *tool, int argc, char **argv, int *i);
void		put_error_message(char *argv, int flg);
void		wait_for_all_process(int count);
void		free_str(char **r);
void		free_str2(char ***r);
void		free_all(t_tool *tool);
void		finish_process(t_tool *tool);
void		handle_malloc_error(void);
void		handle_pipe_error(t_tool *tool);
int			find_ber(char *str);
void		put_error_message(char *argv, int flg);
void		dup2_and_close(int oldfd, int newfd, int flg, t_tool *tool);
char		*get_next_line(int fd);
char		*ft_strjoin2(char const *s1, char const *s2);
void		*ft_memset(void *buf, int c, size_t n);
int			check_newline(char *s);
char		*get_next_line(int fd);
char		*read_file(int fd, char *str);
size_t		line_len(char *str);
char		*get_oneline(char *str);
void		ft_save(char *str, char *save);
void		read_heredoc(t_tool *tool, char *limitter, int *i);
void		write_heredoc(t_tool *tool);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#endif