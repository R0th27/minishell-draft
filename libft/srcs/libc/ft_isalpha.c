/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 23:51:28 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:40:13 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isalpha
**
** Purpose:
**     Checks whether a character is alphabetic.
**
** Returns:
**     Non-zero if true, 0 otherwise.
*/
int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
