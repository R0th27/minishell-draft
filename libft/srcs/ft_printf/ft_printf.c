/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:57:27 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 20:28:06 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putchar(char c, int *byte)
{
	write(1, &c, 1);
	(*byte)++;
}

void	pf_putstr(char *str, int *byte)
{
	if (!str)
		return (pf_putstr("(null)", byte));
	while (*str)
		pf_putchar(*str++, byte);
}

static void	pf_formatparser(va_list args, char c, int *byte)
{
	if (c == '%')
		pf_putchar('%', byte);
	else if (c == 'c')
		pf_putchar(va_arg(args, int), byte);
	else if (c == 's')
		pf_putstr(va_arg(args, char *), byte);
	else if (c == 'p')
		pf_putpointer(va_arg(args, void *), byte);
	else if (c == 'd' || c == 'i')
		pf_putnbr(va_arg(args, int), byte);
	else if (c == 'u')
		pf_putnbr(va_arg(args, unsigned int), byte);
	else if (c == 'x' || c == 'X')
		pf_puthex(va_arg(args, unsigned int), c == 'X', byte);
	else
	{
		pf_putchar('%', byte);
		if (c)
			pf_putchar(c, byte);
	}
}

/*
** ft_printf
**
** Purpose:
**   Writes formatted output to the standard output.
**
** Parameters:
**   str - Format string containing text and conversion specifiers
**   ... - Variable arguments corresponding to format specifiers
**
** Return:
**   Total number of bytes written.
**
** Notes:
**   - Supported specifiers: %c %s %p %d %i %u %x %X %%
**   - If an unknown specifier is encountered, prints '%' followed by it.
**   - If str is NULL, returns 0.
**   - Does not support flags, width, or precision.
*/
int	ft_printf(const char *str, ...)
{
	int		byte;
	va_list	args;

	va_start(args, str);
	if (!str)
		return (0);
	byte = 0;
	while (*str)
	{
		if (*str == '%')
			pf_formatparser(args, *(++str), &byte);
		else
			pf_putchar(*str, &byte);
		if (*str)
			str++;
	}
	va_end(args);
	return (byte);
}
