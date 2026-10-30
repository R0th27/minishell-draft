/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:17:12 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:42:46 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_toupper
**
** Purpose:
**     Converts a lowercase letter to uppercase.
**
** Returns:
**     Converted character if applicable, otherwise unchanged.
*/
int	ft_toupper(int c)
{
	return (c - (32 * (c >= 'a' && c <= 'z')));
}
