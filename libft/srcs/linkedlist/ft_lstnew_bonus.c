/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 03:04:19 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:51:44 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstnew
**
** Purpose:
**   Creates a new linked list node.
**
** Parameters:
**   content - Pointer to the data to store in the node
**
** Return:
**   Pointer to the newly allocated node.
**   NULL if memory allocation fails.
**
** Notes:
**   - The content pointer is stored without duplication.
**   - The next pointer is initialized to NULL.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}
