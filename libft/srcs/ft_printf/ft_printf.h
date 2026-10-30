/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:47:08 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 20:09:42 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *str, ...);
void	pf_putchar(char c, int *byte);
void	pf_putstr(char *str, int *byte);
void	pf_putpointer(void *ptr, int *byte);
void	pf_putnbr(long long num, int *byte);
void	pf_puthex(unsigned int num, int flag, int *byte);

#endif