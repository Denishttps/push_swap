/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:12:43 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/15 17:09:12 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** DESCRIPTION
**    Checks whether the given character is printable, including space.
** PARAMETERS
**    @c: The character (as an int) to check.
** RETURN VALUES
**    Returns 1 if the character is printable, 0 otherwise.
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
