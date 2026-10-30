/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:21:56 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:41:32 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strchr
**
** Purpose:
**     Locates the first occurrence of a character in a string.
**
** Returns:
**     Pointer to the character found, or NULL if not found.
**
** Notes:
**     - The null terminator is considered part of the string.
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
