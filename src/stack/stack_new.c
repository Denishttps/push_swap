/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 23:19:48 by dbobrov           #+#    #+#             */
/*   Updated: 2026/01/21 23:19:48 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *stack_new(int value)
{
	t_stack *new_elem;

	new_elem = (t_stack *)malloc(sizeof(t_stack));
	if (!new_elem)
		return (NULL);
	new_elem->value = value;
	new_elem->index = -1;
	new_elem->target_pos = -1;
	new_elem->cost_a = -1;
	new_elem->cost_b = -1;
	new_elem->prev = NULL;
	new_elem->next = NULL;
	return (new_elem);
}