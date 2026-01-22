/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 01:03:28 by dbobrov           #+#    #+#             */
/*   Updated: 2026/01/22 01:03:28 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 3)
		sort_three(a);
	else
		sort_large_stack(a, b);
}

void sort_large_stack(t_stack **a, t_stack **b)
{
	int size;
	size = stack_size(*a);
	while (size > 3)
	{
		pb(a, b);
	}
	
}