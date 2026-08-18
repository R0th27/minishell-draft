/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:59:54 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:41:37 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strdup
**
** Purpose:
**     Duplicates a string into newly allocated memory.
**
** Returns:
**     Newly allocated copy of the string,
**     or NULL if allocation fails.
**
** Memory:
**     - Caller must free the returned string.
*/
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr = ft_memcpy(ptr, s, len + 1);
	return (ptr);
}
