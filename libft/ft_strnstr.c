/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:39:38 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/08 13:39:38 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** DESCRIPTION
**    Locates the first occurrence of s2 in s1,
**    where not more than n characters are searched.
** PARAMETERS
**    @s1: The string to be searched.
**    @s2: The substring to find.
**    @n: The maximum number of characters to search.
** RETURN VALUES
**    Returns a pointer to the first occurrence of s2 in s1,
**    or NULL if s2 is not found within the first n characters of s1.
*/

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (*s2 == '\0')
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j) < n)
		{
			if (s2[j + 1] == '\0')
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
