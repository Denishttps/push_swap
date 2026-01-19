/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:05:41 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/04 22:05:41 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** 
** DESCRIPTION
**    Converts the initial portion of the string pointed to by str to int.
** PARAMETERS
**    @str: The string to convert.
**
** RETURN VALUES
**    Returns the converted integer value.
*/

int	ft_atoi(const char *str)
{
	int		sig;
	long	num;

	sig = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*(str + 1) == '-' || *(str + 1) == '+')
			return (0);
		if (*str == '-')
			sig = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return ((int)(num * sig));
}
