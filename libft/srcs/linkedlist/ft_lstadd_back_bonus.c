/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 04:19:30 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:51:58 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstadd_back
**
** Purpose:
**   Adds a node to the end of the list.
**
** Parameters:
**   lst - Address of the pointer to the first node
**   new - Node to add
**
** Return:
**   None
**
** Notes:
**   - If lst or new is NULL, the function does nothing.
**   - If the list is empty, new becomes the first node.
**   - Uses ft_lstlast to locate the final node.
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last -> next = new;
}
