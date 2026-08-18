/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:44:32 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:42:22 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strnstr
**
** Purpose:
**     Locates the first occurrence of little in big,
**     searching at most len characters.
**
** Returns:
**     Pointer to the first match, or NULL if not found.
**
** Notes:
**     - If little is empty, returns big.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!*little)
		return ((char *)big);
	while (*big && len)
	{
		i = 0;
		while ((len - i) && *(big + i) && *(little + i) == *(big + i))
		{
			i++;
			if (!*(little + i))
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
