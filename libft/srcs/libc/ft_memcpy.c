/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:02:19 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:41:10 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memcpy
**
** Purpose:
**     Copies n bytes from src to dest.
**
** Returns:
**     dest.
**
** Notes:
**     - Undefined behavior if memory regions overlap.
**     - Use ft_memmove for overlapping regions.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*str;

	dst = (unsigned char *)dest;
	str = (const unsigned char *)src;
	while (n--)
		*dst++ = *str++;
	return (dest);
}
