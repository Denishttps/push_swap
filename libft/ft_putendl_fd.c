/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:32:38 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/08 14:32:38 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** DESCRIPTION
**    Outputs the string s to the given file descriptor, followed by a newline.
** PARAMETERS
**    @s: The string to output.
**    @fd: The file descriptor on which to write the string.
** RETURN VALUES
**    None.
*/

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}
