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

int	total_cost(int cost_a, int cost_b);

int	total_cost(int cost_a, int cost_b)
{
	int	a;
	int	b;

	a = cost_a;
	b = cost_b;
	if (a >= 0 && b >= 0)
	{
		if (a > b)
			return (a);
		return (b);
	}
	if (a < 0 && b < 0)
	{
		if (-a > -b)
			return (-a);
		return (-b);
	}
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	return (a + b);
}

t_stack	*get_cheapest(t_stack *b)
{
	t_stack	*best;
	int		min_cost;
	int		current_cost;

	best = b;
	min_cost = total_cost(b->cost_a, b->cost_b);
	while (b)
	{
		current_cost = total_cost(b->cost_a, b->cost_b);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			best = b;
		}
		b = b->next;
	}
	return (best);
}
