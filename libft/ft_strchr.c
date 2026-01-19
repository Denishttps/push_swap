/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:48:22 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/15 17:19:04 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** DESCRIPTION
**    Locates the first occurrence of c (converted to a char) in the string s.
** PARAMETERS
**    @s: Pointer to the string to be searched.
**    @c: The character to locate (as an int).
** RETURN VALUES
**    Returns a pointer to the first occurrence of
**	  the character c in the string s.
**    Returns NULL if the character is not found.
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
