/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:43:00 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:39:53 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_calloc
**
** Purpose:
**     Allocates zero-initialized memory for an array.
**
** Parameters:
**     nmemb - number of elements
**     size  - size of each element
**
** Returns:
**     Pointer to allocated memory, or NULL on failure.
**
** Notes:
**     - Protects against integer overflow.
**     - Memory is initialized to zero.
**
** Memory:
**     - Caller must free the returned pointer.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (size_t)-1 / size)
		return (NULL);
	size *= nmemb;
	ptr = (unsigned char *)malloc(size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}
