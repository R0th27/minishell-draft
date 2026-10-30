/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 05:10:17 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:52:37 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstiter
**
** Purpose:
**   Applies a function to the content of each node.
**
** Parameters:
**   lst - Pointer to the first node
**   f   - Function applied to each node's content
**
** Return:
**   None
**
** Notes:
**   - If lst or f is NULL, the function does nothing.
**   - Does not modify the list structure.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}
