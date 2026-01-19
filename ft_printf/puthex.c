/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 21:28:19 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/26 21:28:19 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	puthex(uintptr_t n, int letter_case)
{
	size_t		len;
	const char	*hex;

	if (letter_case == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	len = 0;
	if (n >= 16)
		len += puthex(n / 16, letter_case);
	len += printchar(hex[n % 16]);
	return (len);
}
