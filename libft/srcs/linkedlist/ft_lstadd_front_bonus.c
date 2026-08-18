/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 03:17:10 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:51:52 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstadd_front
**
** Purpose:
**   Adds a node to the beginning of the list.
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
**   - The new node becomes the first element of the list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}
