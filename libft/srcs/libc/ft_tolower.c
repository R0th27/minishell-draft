/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:10:20 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:42:34 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_tolower
**
** Purpose:
**     Converts an uppercase letter to lowercase.
**
** Returns:
**     Converted character if applicable, otherwise unchanged.
*/
int	ft_tolower(int c)
{
	return (c + (32 * (c >= 'A' && c <= 'Z')));
}
