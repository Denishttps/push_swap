/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 23:19:23 by dbobrov           #+#    #+#             */
/*   Updated: 2026/01/21 23:19:23 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_back(t_stack **stack, t_stack *elem)
{
	t_stack	*last;

	if (!stack || !elem)
		return ;
	if (!*stack)
	{
		*stack = elem;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = elem;
	elem->prev = last;
}
