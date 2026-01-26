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

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	bool	is_error;

	if (argc == 1)
		ft_error();
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		parse_single_argument(argv[1], &stack_a);
	else
	{
		is_error = add_in_stack(argc, argv, &stack_a, 1);
		if (is_error)
			ft_error();
	}
	stack_set_index(&stack_a);
	if (is_sorted(stack_a))
	{
		free_stacks(&stack_a, &stack_b);
		return (0);
	}
	sort_stack(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
