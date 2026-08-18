/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 01:03:52 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:40:30 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isdigit
**
** Purpose:
**     Checks whether a character is a digit ('0'–'9').
**
** Returns:
**     Non-zero if true, 0 otherwise.
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
