/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:50:51 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/15 17:13:31 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** DESCRIPTION
**    Fills the first len bytes of the memory area pointed to by b with the
**    constant byte c.
** PARAMETERS
**    @b: Pointer to the memory area to be filled.
**    @c: The byte value to set (as an int).
**    @len: Number of bytes to be set to the value.
** RETURN VALUES
**    Returns a pointer to the memory area b.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len > 0)
	{
		*p = (unsigned char)c;
		p++;
		len--;
	}
	return (b);
}
