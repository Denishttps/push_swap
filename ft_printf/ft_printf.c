/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:49:53 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/25 21:14:00 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	write_format(char format, va_list *args)
{
	if (format == 'c')
		return (printchar(va_arg(*args, int)));
	else if (format == '%')
		return (printchar('%'));
	else if (format == 's')
		return (putstr(va_arg(*args, char *)));
	else if (format == 'p')
		return (putptr(va_arg(*args, void *)));
	else if (format == 'd' || format == 'i')
		return (putnbr(va_arg(*args, int)));
	else if (format == 'u')
		return (putuint(va_arg(*args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (puthex(va_arg(*args, unsigned int), format));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	count;
	size_t	i;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count += write_format(str[++i], &args);
		else
			count += printchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
