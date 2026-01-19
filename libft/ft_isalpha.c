/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:29:06 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/10 13:29:06 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** 
** DESCRIPTION
**    Checks whether the given character is an alphabetic letter (A-Z, a-z).
** PARAMETERS
**    @c: The character (as an int) to check.
**
** RETURN VALUES
**    Returns 1 if the character is an alphabetic letter, 0 otherwise.
*/

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
