/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:33:55 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/08 14:33:55 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** DESCRIPTION
**    Outputs the character c to the given file descriptor.
** PARAMETERS
**    @c: The character to output.
**    @fd: The file descriptor on which to write the character.
** RETURN VALUES
**    None.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
