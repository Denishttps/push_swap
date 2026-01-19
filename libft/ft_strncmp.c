/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:35:19 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/08 13:35:19 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** DESCRIPTION
**    Compares up to n characters of the strings s1 and s2.
** PARAMETERS
**    @s1: The first string to compare.
**    @s2: The second string to compare.
**    @n: The maximum number of characters to compare.
** RETURN VALUES
**    Returns an integer less than, equal to, or greater than zero if s1 is
**    found, respectively, to be less than, to match, or be greater than s2.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
