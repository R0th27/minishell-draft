/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:47:23 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:42:14 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strncmp
**
** Purpose:
**     Compares two strings up to n characters.
**
** Returns:
**     < 0, 0, or > 0 depending on comparison result.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
