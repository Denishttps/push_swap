/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 23:19:38 by dbobrov           #+#    #+#             */
/*   Updated: 2026/01/21 23:19:38 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_front(t_stack **stack, t_stack *elem)
{
	if (!stack || !elem)
		return ;
	if (!*stack)
	{
		*stack = elem;
		return ;
	}
	elem->next = *stack;
	(*stack)->prev = elem;
	*stack = elem;
}
