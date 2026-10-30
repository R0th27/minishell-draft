/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 02:06:12 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:23:53 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putstr_fd
**
** Purpose:
**     Writes a null-terminated string to the given file descriptor.
**
** Parameters:
**     s  - string to write
**     fd - target file descriptor
**
** Notes:
**     - If s is NULL, nothing is written.
*/
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
