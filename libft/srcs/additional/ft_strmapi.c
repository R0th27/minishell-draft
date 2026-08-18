/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 01:36:59 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:25:30 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strmapi
**
** Purpose:
**     Creates a new string by applying a function to each character.
**
** Parameters:
**     s - input string
**     f - function applied to each character (index, char)
**
** Returns:
**     Newly allocated transformed string.
**     Returns NULL if allocation fails or if inputs are NULL.
**
** Memory:
**     - Allocates a new string.
**     - Caller must free it.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*nstr;

	if (!s || !f)
		return (NULL);
	nstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!nstr)
		return (NULL);
	index = 0;
	while (s[index])
	{
		nstr[index] = f(index, s[index]);
		index++;
	}
	nstr[index] = '\0';
	return (nstr);
}
