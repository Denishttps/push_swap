/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 21:26:44 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/26 21:26:44 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	putnbr(int n)
{
	size_t	len;

	len = 0;
	if (n == -2147483648)
		return (putstr("-2147483648"));
	if (n < 0)
	{
		len += printchar('-');
		n = -n;
	}
	if (n >= 10)
		len += putnbr(n / 10);
	len += printchar((n % 10) + '0');
	return (len);
}
