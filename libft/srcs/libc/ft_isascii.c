/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 01:15:25 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:40:21 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isascii
**
** Purpose:
**     Checks whether a character is within ASCII range (0–127).
**
** Returns:
**     Non-zero if true, 0 otherwise.
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
