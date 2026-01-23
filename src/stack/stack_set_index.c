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

int	*stack_to_array(t_stack *stack, int size)
{
	int	*arr;
	int	i = 0;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
	return (arr);
}

void	assign_index(t_stack *a, int *arr, int size)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == a->value)
			{
				a->index = i;
				break;
			}
			i++;
		}
		a = a->next;
	}
}

void stack_set_index(t_stack **stack)
{
	int	size;
	int	*arr;

	size = stack_size(*stack);
	arr = stack_to_array(*stack, size);
	bubble_sort(arr, size);
	assign_index(*stack, arr, size);
	free(arr);
}
