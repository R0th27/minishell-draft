/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:19:24 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:39:05 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_atoi
**
** Purpose:
**     Converts a string to an integer.
**
** Returns:
**     The converted integer value.
**
** Notes:
**     - Skips leading whitespace (space and ASCII 9–13).
**     - Handles optional '+' or '-' sign.
**     - Stops conversion at first non-digit character.
**     - Does not detect integer overflow.
*/
int	ft_atoi(const char *nptr)
{
	int	sign;
	int	num;
	int	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		sign = 44 - nptr[i++];
	num = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		num = (num * 10) + (nptr[i++] - '0');
	return (sign * num);
}
