/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:22:16 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/08 13:22:16 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** DESCRIPTION
**    Compares the first n bytes of the memory areas s1 and s2.
** PARAMETERS
**    @s1: Pointer to the first memory area.
**    @s2: Pointer to the second memory area.
**    @n: Number of bytes to compare.
** RETURN VALUES
**    Returns an integer less than, equal to,
	or greater than zero if the first n bytes
**    of s1 is found, respectively, to be less than, to match,
	or be greater than the first n bytes of s2.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		n--;
	}
	return (0);
}
