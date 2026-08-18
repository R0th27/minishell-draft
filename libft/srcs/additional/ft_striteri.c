/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 01:59:08 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:25:36 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_striteri
**
** Purpose:
**     Applies a function to each character of a string (in-place).
**
** Parameters:
**     s - string to modify
**     f - function applied to each character (index, char *)
**
** Notes:
**     - Modifies the original string.
**     - Does nothing if s or f is NULL.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	index = 0;
	if (!s || !f)
		return ;
	while (s[index])
	{
		f(index, &s[index]);
		index++;
	}
}
