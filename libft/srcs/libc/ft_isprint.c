/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 01:16:52 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:40:38 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isprint
**
** Purpose:
**     Checks whether a character is printable (ASCII 32–126).
**
** Returns:
**     Non-zero if true, 0 otherwise.
*/
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
