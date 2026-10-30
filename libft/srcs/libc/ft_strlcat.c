/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 08:30:07 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:41:45 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strlcat
**
** Purpose:
**     Appends src to dest with size limitation.
**
** Returns:
**     Total length the string tried to create
**     (initial length of dest + length of src).
**
** Notes:
**     - Ensures null-termination if dsize > 0.
*/
size_t	ft_strlcat(char *dest, const char *src, size_t dsize)
{
	size_t	dlen;

	dlen = ft_strlen(dest);
	if (dlen >= dsize)
		return (dsize + ft_strlen(src));
	return (dlen + ft_strlcpy(dest + dlen, src, dsize - dlen));
}
