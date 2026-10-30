/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:31:59 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:40:54 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memcmp
**
** Purpose:
**     Compares the first n bytes of two memory areas.
**
** Returns:
**     < 0, 0, or > 0 depending on comparison result.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	if (!n)
		return (0);
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (--n && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
