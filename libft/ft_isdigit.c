/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:26:45 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/15 17:09:19 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** DESCRIPTION
**    Checks whether the given character is a digit (0-9).
** PARAMETERS
**    @c: The character (as an int) to check.
** RETURN VALUES
**    Returns 1 if the character is a digit, 0 otherwise.
*/

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
