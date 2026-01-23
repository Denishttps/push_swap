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

void stack_set_pos(t_stack *stack)
{
	int		pos;

	if (!stack)
		return;
	pos = 0;
	while (stack)
	{
		stack->pos = pos;
		pos++;
		stack = stack->next;
	}
}