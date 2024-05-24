/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:27:28 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/23 12:10:58 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define A 0
# define B 1

typedef struct s_stack
{
	int				nb;
	int				flg;
	struct s_stack	*pre;
	struct s_stack	*next;
}					t_stack;

typedef struct s_param
{
	int				n[2];
	int				mid;
}					t_param;
char				**ft_split(char const *s, char c);
t_stack				*ft_lstnew_bid(int nb);
void				ft_lstadd_back_bid(t_stack **lst, t_stack *new);
int					validate_num(char *s);
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *str);
void				swap_node(t_stack *node, char *content);
void				rotate_node(t_stack **stack, char *content, int i);
void				reverce_rotate_node(t_stack **stack, char *content, int i);
void				rotate_double(t_stack **a, t_stack **b, int i);
void				reverce_rotate_double(t_stack **a, t_stack **b, int i);
void				push_node(t_stack *st1, t_stack *st2, char *content);
int					ft_min_rot(int n, int m);
int					count_lower_mid(t_stack **a, int mid);
void				free_lst(t_stack **a);
int					check_sort(t_stack **a);
void				sort_threenode_a(t_stack **s);
int					find_mid(int argc, t_stack **a);
void				push_to_b(t_stack **a, t_stack **b, int argc, int mid);
int					blanch_by_argc(t_stack **a, t_stack **b, int argc, int mid);
int					count_ra(int bn, t_stack *a);
int					count_rra(int bn, t_stack *a);
int					**allocate_count_arr(int size);
void				fill_count_arr(t_stack **a, t_stack **b, int **count,
						t_param params);
int					*find_optimal_node(t_stack **a, t_stack **b, int n[2],
						int mid);
int					ft_maximum(int n, int m);
int					ft_minimum(int n, int m);
int					apply_rot_rule(int n, int m);
int					*find_opt_sub(int n, int **count);
void				fill_stack(t_stack **a, int argc, char **argv);
void				push_stack_a_sub(t_stack **a, t_stack **b, int count[2]);
void				push_stack_a(t_stack **a, t_stack **b, int argc, int mid);
int					count_to_head(t_stack **a);
void				push_swap(int argc, char **argv);
char				*ft_strjoin(char const *s1, char const *s2);
void				*ft_memset(void *buf, int c, size_t n);
int					check_newline(char *s);
char				*get_next_line(int fd);
char				*read_file(int fd, char *str);
size_t				line_len(char *str);
char				*get_oneline(char *str);
void				ft_save(char *str, char *save);
int					compare_input(char *input, char *command, int n);
int					read_command(t_stack **a, t_stack **b, char *line);
void				check_sort_ok(t_stack **a);
int					check_result(int argc, char **argv);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#endif