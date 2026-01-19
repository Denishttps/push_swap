/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:12:28 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/04 22:12:28 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** 
** DESCRIPTION
**    Checks whether the given character is alphanumeric (A-Z, a-z, 0-9).
**
** PARAMETERS
**    @c: The character (as an int) to check.
**
** RETURN VALUES
**    Returns 1 if the character is alphanumeric, 0 otherwise.
*/

int	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a'
			&& c <= 'z'));
}
