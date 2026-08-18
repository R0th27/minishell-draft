/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 03:54:18 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:52:18 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstsize
**
** Purpose:
**   Counts the number of nodes in the list.
**
** Parameters:
**   lst - Pointer to the first node
**
** Return:
**   The number of nodes in the list.
**
** Notes:
**   - Returns 0 if the list is empty.
*/
int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst -> next;
	}
	return (size);
}
