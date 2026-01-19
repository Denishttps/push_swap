/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:47:10 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/08 15:47:10 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** DESCRIPTION
**    Trims characters from the beginning and end of
**    a string based on a set of characters.
** PARAMETERS
**    @s1: The string to be trimmed.
**    @set: The set of characters to trim from the string.
** RETURN VALUES
**    Returns a new string with the characters from set removed
**    from the beginning and end of s1. Returns NULL if allocation fails.
*/

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	len = end - start;
	trimmed_str = ft_substr(s1, start, len);
	return (trimmed_str);
}
