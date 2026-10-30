/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 04:26:43 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:52:25 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstdelone
**
** Purpose:
**   Deletes a single node from the list.
**
** Parameters:
**   lst - Node to delete
**   del - Function used to free the node's content
**
** Return:
**   None
**
** Notes:
**   - If lst or del is NULL, the function does nothing.
**   - Only deletes the given node.
**   - Does not relink surrounding nodes.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free(lst);
}
