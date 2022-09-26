/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaleh <msaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:29:18 by msaleh            #+#    #+#             */
/*   Updated: 2022/09/22 20:19:12 by msaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parser(va_list arg, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg (arg, int));
	else if (c == 's')
		len += ft_putstr (va_arg (arg, char *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr (va_arg(arg, int));
	else if (c == 'x' || c == 'X')
		len += ft_hex (va_arg(arg, unsigned int), c);
	else if (c == 'p')
	{
		len += ft_putstr ("0x");
		len += ft_address (va_arg (arg, unsigned long long));
	}
	else if (c == 'u')
		len += ft_putnbr_u(va_arg (arg, unsigned int));
	else
		len += ft_putchar (c);
	return (len);
}
