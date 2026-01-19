/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:05:55 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/04 22:05:55 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/** 
** DESCRIPTION
**    Sets the first n bytes of the memory area pointed to by s to zero.
** PARAMETERS
**    @s: Pointer to the memory area to be set to zero.
**    @n: Number of bytes to set to zero.
*/

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
