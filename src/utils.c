/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 00:24:11 by dbobrov           #+#    #+#             */
/*   Updated: 2026/01/20 00:24:11 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

#include <limits.h>

int ft_is_int(char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (!str || !*str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		num = num * 10 + (*str - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (0);
		str++;
	}
	return (1);
}

int ft_error()
{
	write(2, "Error\n", 6);
	exit(1);
}

int ft_in_stack(int *stack, int size, int num)
{
	int	i;

	if (size <= 0)
		return (0);
	i = 0;
	while (i < size)
	{
		if (stack[i] == num)
			return (1);
		i++;
	}
	return (0);
}