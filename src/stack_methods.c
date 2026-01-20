/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:10:35 by dbobrov           #+#    #+#             */
/*   Updated: 2026/01/20 18:32:33 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	swap(t_list **stack)
{
	t_list *first;
	t_list *second;

	if (!stack || !*stack || !(*stack)->next)
		return;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (1);
}

void	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;
	
	if (!stack_from || !*stack_from || !(*stack_from)->next || !stack_to || !*stack_to || !(*stack_to)->next)
		return;
	tmp = *stack_from;
	*stack_from = tmp->next;
	tmp->next = *stack_to;
	*stack_to = tmp;
}

void	rotate(t_list **stack)
{
	t_list	*tmp;
	
	if (!stack || !*stack || !(*stack)->next)
		return;
	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, tmp);
}

void reverse_rotate(t_list **stack)
{
    t_list *last = *stack;
    t_list *before_last = NULL;

	if (!*stack || !(*stack)->next)
        return;
    while (last->next)
    {
        before_last = last;
        last = last->next;
    }
    before_last->next = NULL;
    last->next = *stack;      
    *stack = last;            
}
