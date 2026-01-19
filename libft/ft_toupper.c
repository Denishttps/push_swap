/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:11:12 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/15 17:26:10 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** DESCRIPTION
**    Converts a lowercase letter to its uppercase equivalent.
** PARAMETERS
**    @c: The character (as an int) to convert.
** RETURN VALUES
**    Returns the uppercase equivalent if c is
**    a lowercase letter; otherwise, returns c unchanged.
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
