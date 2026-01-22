/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:47:08 by dbobrov           #+#    #+#             */
/*   Updated: 2026/01/22 00:47:08 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int len_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void ft_free_split(char **arr)
{
	int	i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void add_in_stack(int size, char **args, t_stack **stack, int start)
{
	int		i;
	long	num;
	t_stack	*new_elem;

	i = start;
	while (i < size)
	{
		if (!ft_is_int(args[i]))
			ft_error();
		num = ft_atoi(args[i]);
		if (ft_in_stack(*stack, (int)num))
			ft_error();
		new_elem = stack_new((int)num);
		if (!new_elem)
			ft_error();
		stack_add_back(stack, new_elem);
		i++;
	}
}

void parse_single_argument(char *arg, t_stack **stack)
{
	char	**numbers;

	numbers = ft_split(arg, ' ');
	if (!numbers)
		ft_error();
	add_in_stack(len_array(numbers), numbers, stack, 0);
	ft_free_split(numbers);
}