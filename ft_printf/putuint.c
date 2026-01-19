/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putuint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 21:47:38 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/26 21:47:38 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	putuint(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n >= 10)
		len += putuint(n / 10);
	len += printchar((n % 10) + '0');
	return (len);
}
