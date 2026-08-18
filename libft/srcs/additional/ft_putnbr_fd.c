/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 02:13:21 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:24:11 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putnbr_fd
**
** Purpose:
**     Writes an integer to the given file descriptor.
**
** Parameters:
**     n  - integer to write
**     fd - target file descriptor
**
** Notes:
**     - Handles negative numbers.
**     - Handles INT_MIN safely using long conversion.
**     - Does not allocate memory.
*/
void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		index;
	char	arr[10];

	num = n;
	if (num == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	index = 0;
	while (num > 0)
	{
		arr[index++] = (num % 10) + '0';
		num /= 10;
	}
	while (--index >= 0)
		write(fd, &arr[index], 1);
}
