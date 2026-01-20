/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:11:15 by dbobrov           #+#    #+#             */
/*   Updated: 2026/01/19 23:11:15 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	if (argc <= 1)
		ft_error();
	stack_a = NULL;
	stack_b = NULL;
	add_in_stack(argc, argv, &stack_a);

	

	free(stack_a);
	free(stack_b);
	return (0);
}

void add_in_stack(int argc, char **argv, t_list **stack)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_int(argv[i]))
			ft_error();
		num = ft_atoi(argv[i]);
		if (ft_in_stack(*stack, num))
			ft_error();
		ft_lstadd_back(stack, ft_lstnew(num));
		if (!*stack)
			ft_error();
		i++;
	}
	return (0);
}