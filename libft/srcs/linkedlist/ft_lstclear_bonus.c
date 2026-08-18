/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 04:30:20 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:52:31 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstclear
**
** Purpose:
**   Deletes and frees all nodes of the list.
**
** Parameters:
**   lst - Address of the pointer to the first node
**   del - Function used to free each node's content
**
** Return:
**   None
**
** Notes:
**   - If lst, *lst, or del is NULL, the function does nothing.
**   - Frees every node and sets *lst to NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	if (!lst || !*lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		temp = current -> next;
		del(current -> content);
		free(current);
		current = temp;
	}
	*lst = NULL;
}
