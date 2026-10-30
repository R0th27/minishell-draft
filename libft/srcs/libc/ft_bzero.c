/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 01:59:29 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:39:23 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_bzero
**
** Purpose:
**     Sets the first n bytes of memory to zero.
**
** Notes:
**     - Equivalent to ft_memset(s, 0, n).
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
