/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:24:06 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/08 13:24:06 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** 
** DESCRIPTION
**    Allocates memory for an array of count elements of size bytes each and
**    initializes all bytes in the allocated storage to zero.
** PARAMETERS
**    @count: Number of elements to allocate.
**    @size: Size of each element.
** RETURN VALUES
**    Returns a pointer to the allocated memory, or NULL if the allocation fails.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
