/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 00:54:38 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:25:12 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_substr
**
** Purpose:
**     Extracts a substring from a string.
**
** Parameters:
**     s     - source string
**     start - starting index
**     len   - maximum length of substring
**
** Returns:
**     Newly allocated substring.
**     Returns NULL if allocation fails or if s is NULL.
**
** Notes:
**     - If start is beyond string length, returns empty string.
**
** Memory:
**     - Allocates a new string.
**     - Caller must free it.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	clen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		clen = 0;
	else if (slen - start > len)
		clen = len;
	else
		clen = slen - start;
	sub = (char *)malloc(sizeof(char) * (clen + 1));
	if (!sub)
		return (NULL);
	if (clen)
		sub = ft_memcpy(sub, s + start, clen);
	sub[clen] = '\0';
	return (sub);
}
