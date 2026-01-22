/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steck_set_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:03:46 by dbobrov           #+#    #+#             */
/*   Updated: 2026/01/22 00:03:46 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void stack_set_index(t_stack **stack)
{
	t_stack *current;
	int		index;

	if (!stack || !*stack)
		return;
	index = 0;
	current = *stack;
	while (current)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}