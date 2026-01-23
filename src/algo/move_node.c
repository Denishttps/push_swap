/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:47:31 by dbobrov           #+#    #+#             */
/*   Updated: 2026/01/23 00:47:31 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rr_or_rrr(t_stack **a, t_stack **b, t_stack *n)
{
	while (n->cost_a > 0 && n->cost_b > 0)
	{
		rr(a, b);
		n->cost_a--;
		n->cost_b--;
	}
	while (n->cost_a < 0 && n->cost_b < 0)
	{
		rrr(a, b);
		n->cost_a++;
		n->cost_b++;
	}
}

void	do_ra_or_rra(t_stack **a, t_stack *n)
{
	while (n->cost_a > 0)
	{
		ra(a);
		n->cost_a--;
	}
	while (n->cost_a < 0)
	{
		rra(a);
		n->cost_a++;
	}
}

void	do_rb_or_rrb(t_stack **b, t_stack *n)
{
	while (n->cost_b > 0)
	{
		rb(b);
		n->cost_b--;
	}
	while (n->cost_b < 0)
	{
		rrb(b);
		n->cost_b++;
	}
}

void	move_node(t_stack **a, t_stack **b, t_stack *n)
{
	do_rr_or_rrr(a, b, n);
	do_ra_or_rra(a, n);
	do_rb_or_rrb(b, n);
	pa(a, b);
}
