/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:04:06 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/15 17:26:16 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** DESCRIPTION
**    Converts an uppercase letter to its lowercase equivalent.
** PARAMETERS
**    @c: The character (as an int) to convert.
** RETURN VALUES
**    Returns the lowercase equivalent if c is
**    an uppercase letter; otherwise, returns c unchanged.
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
