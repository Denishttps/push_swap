/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:39:01 by dbobrov           #+#    #+#             */
/*   Updated: 2026/01/23 00:39:01 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

t_stack	*get_cheapest(t_stack *b)
{
	t_stack	*best;
	int		min_cost;
	int		total_cost;

	best = b;
	min_cost = abs(b->cost_a) + abs(b->cost_b);
	while (b)
	{
		total_cost = abs(b->cost_a) + abs(b->cost_b);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			best = b;
		}
		b = b->next;
	}
	return (best);
}
