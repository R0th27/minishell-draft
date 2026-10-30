/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 02:03:17 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:23:33 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putchar_fd
**
** Purpose:
**     Writes a single character to the given file descriptor.
**
** Parameters:
**     c  - character to write
**     fd - target file descriptor
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
