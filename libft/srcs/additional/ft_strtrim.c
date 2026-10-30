/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:08:50 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:25:22 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strtrim
**
** Purpose:
**     Trims characters from the beginning and end of a string.
**
** Parameters:
**     s1  - source string
**     set - set of characters to remove
**
** Returns:
**     Newly allocated trimmed string.
**     Returns NULL if allocation fails or if inputs are NULL.
**
** Memory:
**     - Allocates a new string.
**     - Caller must free it.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*nstr;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	nstr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!nstr)
		return (NULL);
	ft_memcpy(nstr, s1 + start, end - start);
	nstr[end - start] = '\0';
	return (nstr);
}
