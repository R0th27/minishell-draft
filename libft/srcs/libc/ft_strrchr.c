/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:27:57 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:42:27 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strrchr
**
** Purpose:
**     Locates the last occurrence of a character in a string.
**
** Returns:
**     Pointer to the character found, or NULL if not found.
**
** Notes:
**     - The null terminator is considered part of the string.
*/
char	*ft_strrchr(const char *s, int c)
{
	const char	*x;

	x = s;
	while (*x)
		x++;
	while (x >= s)
	{
		if (*x == (unsigned char)c)
			return ((char *)x);
		x--;
	}
	return (NULL);
}
