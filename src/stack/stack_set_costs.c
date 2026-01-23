/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:38:04 by dbobrov           #+#    #+#             */
/*   Updated: 2026/01/23 00:38:04 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_to_top(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

void	stack_set_costs(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		size_a;
	int		size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (b)
	{
		b->cost_b = cost_to_top(b->pos, size_b);
		tmp = a;
		while (tmp)
		{
			if (tmp->index == b->target_index)
			{
				b->cost_a = cost_to_top(tmp->pos, size_a);
				break ;
			}
			tmp = tmp->next;
		}
		b = b->next;
	}
}
