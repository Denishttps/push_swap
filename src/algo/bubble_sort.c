/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 23:07:22 by dbobrov           #+#    #+#             */
/*   Updated: 2026/01/21 23:07:22 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	bool swapped;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			swapped = false;
			if (arr[j] > arr[j + 1])
			{
				swap_int(&arr[j], &arr[j + 1]);
				swapped = true;
			}
			if (!swapped)
				break;
			j++;
		}
		i++;
	}
}
