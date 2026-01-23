/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set_target_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:50:22 by dbobrov           #+#    #+#             */
/*   Updated: 2026/01/22 20:50:22 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_stack *a)
{
	int	min;

	min = a->index;
	while (a)
	{
		if (a->index < min)
			min = a->index;
		a = a->next;
	}
	return (min);
}

int	find_target_index(t_stack *a, int b_index)
{
	t_stack	*tmp;
	int		target;
	int		min_index;

	tmp = a;
	target = INT_MAX;
	min_index = a->index;
	while (tmp)
	{
		if (tmp->index < min_index)
			min_index = tmp->index;
		if (tmp->index > b_index && tmp->index < target)
			target = tmp->index;
		tmp = tmp->next;
	}
	if (target == INT_MAX)
		return (min_index);
	return (target);
}

void	set_target_node(t_stack *a, t_stack *b)
{
	while (b)
	{
		b->target_index = find_target_index(a, b->index);
		b = b->next;
	}
}
