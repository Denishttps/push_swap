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

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
	{
		if (!is_sorted(*a))
			sa(a);
	}
	else if (size == 3)
		sort_three(a);
	else
		sort_large_stack(a, b);
}

t_stack	*find_min_node(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (min->value > stack->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	final_sort(t_stack **a)
{
	t_stack	*min;
	int		size;

	min = find_min_node(*a);
	if (!min)
		return ;
	stack_set_pos(*a);
	size = stack_size(*a);
	if (min->pos <= size / 2)
	{
		while ((*a)->index != min->index)
			ra(a);
	}
	else
	{
		while ((*a)->index != min->index)
			rra(a);
	}
}

void	sort_large_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	while (size > 3)
	{
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
	{
		stack_set_pos(*a);
		stack_set_pos(*b);
		set_target_node(*a, *b);
		stack_set_costs(*a, *b);
		move_node(a, b, get_cheapest(*b));
	}
	final_sort(a);
}
