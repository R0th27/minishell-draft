/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 01:23:53 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:42:06 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strlen
**
** Purpose:
**     Calculates the length of a null-terminated string.
**
** Returns:
**     Number of characters before the null terminator.
*/
size_t	ft_strlen(const char *s)
{
	const char	*x;

	x = s;
	while (*x)
		x++;
	return ((size_t)(x - s));
}
