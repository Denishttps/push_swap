/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:00:04 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/15 17:11:52 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** DESCRIPTION
**    Scans the initial n bytes of the memory area pointed to by s for the
**    first instance of c.
** PARAMETERS
**    @s: Pointer to the memory area to scan.
**    @c: The character (as an int) to search for.
**    @n: Number of bytes to scan.
** RETURN VALUES
**    Returns a pointer to the matching byte or NULL if the character does not
**    occur in the given memory area.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = (const unsigned char *)s;
	while (n > 0)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
		n--;
	}
	return (NULL);
}
