/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:16:38 by dbobrov           #+#    #+#             */
/*   Updated: 2025/11/15 17:11:30 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** DESCRIPTION
**    Creates a new node with the given content.
** PARAMETERS
**    @content: The content to store in the new node.
** RETURN VALUES
**    Returns a pointer to the newly created node. Returns NULL if memory
**    allocation fails.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*s1;

	s1 = (t_list *)malloc(sizeof(t_list));
	if (!s1)
		return (NULL);
	s1->content = content;
	s1->next = NULL;
	return (s1);
}
