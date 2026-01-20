/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:10:35 by dbobrov           #+#    #+#             */
/*   Updated: 2026/01/20 17:59:15 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	swap(t_list **stack)
{
	t_list *first;
	t_list *second;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (1);
}

int	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;
	
	if (!stack_from || !*stack_from || !(*stack_from)->next || !stack_to || !*stack_to || !(*stack_to)->next)
		return (0);
	tmp = *stack_from;
	*stack_from = tmp->next;
	tmp->next = *stack_to;
	*stack_to = tmp;
	return (1);
}

int	rotate(t_list **stack)
{
	t_list	*tmp;
	
	if (!stack || !*stack || !(*stack)->next)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, tmp);
	return (1);
}

int reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	
	tmp = *stack;
}
