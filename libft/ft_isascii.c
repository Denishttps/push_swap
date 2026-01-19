/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:24:53 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/15 17:09:27 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** 
** DESCRIPTION
**    Checks whether the given character is an ASCII character (0-127).
** PARAMETERS
**    @c: The character (as an int) to check.
** RETURN VALUES
**    Returns 1 if the character is an ASCII character, 0 otherwise.
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
