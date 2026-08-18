/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 05:18:55 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:52:43 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstmap
**
** Purpose:
**   Creates a new list by applying a function to each node's content.
**
** Parameters:
**   lst - Pointer to the first node
**   f   - Function applied to each node's content
**   del - Function used to delete content if allocation fails
**
** Return:
**   Pointer to the newly created list.
**   NULL if allocation fails.
**
** Notes:
**   - If lst, f, or del is NULL, returns NULL.
**   - On allocation failure, previously created nodes are freed.
**   - The original list remains unchanged.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst -> content));
		if (!node)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		lst = lst -> next;
	}
	return (head);
}
