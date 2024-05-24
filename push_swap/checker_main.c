/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:01:59 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/05/23 12:50:36 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplication(size_t i, long *num)
{
	size_t	k;

	k = 0;
	if (i == 0)
		return (0);
	while (k < i)
	{
		if (num[k] == num[i])
			return (1);
		k++;
	}
	return (0);
}

static int	validate_input(int argc, char **argv)
{
	long	*num;
	int		i;
	int		j;

	num = (long *)malloc(argc * sizeof(long));
	if (num == NULL)
		return (1);
	i = -1;
	while (++i < argc)
	{
		j = 0;
		num[i] = 0;
		if (!validate_num(argv[i]))
			return (free(num), 1);
		while (argv[i][j])
		{
			num[i] = 10 * num[i] + argv[i][j++] - '0';
			if (num[i] > INT_MAX)
				return (free(num), 1);
		}
		if (check_duplication(i, num))
			return (free(num), 1);
	}
	free(num);
	return (0);
}

static int	count_split_len(char **r)
{
	int	count;

	count = 0;
	while (r[count] != NULL)
		count++;
	return (count);
}
// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q checker");
// }

int	main(int argc, char **argv)
{
	char	**r;
	int		i;

	i = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		r = ft_split(argv[1], ' ');
		argc = count_split_len(r);
		if (validate_input(argc, r) || check_result(argc, r))
			write(1, "Error\n", 6);
		while (i < argc)
			free(r[i++]);
		free(r);
		return (0);
	}
	argc--;
	argv++;
	if (validate_input(argc, argv) || check_result(argc, argv))
		return (write(1, "Error\n", 6), 0);
	return (0);
}
