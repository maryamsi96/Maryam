/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaleh <msaleh@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:20:44 by msaleh            #+#    #+#             */
/*   Updated: 2022/06/17 19:24:42 by msaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_hex(unsigned int nb, char c)
{
	int			len;
	int			d;
	long long	nbr;
	char		result;

	len = 0;
	result = 0;
	if (c == 'x')
		d = 87;
	if (c == 'X')
		d = 55;
	if (nb >= 16)
		len += ft_hex(nb / 16, c);
	nbr = nb % 16;
	if (nbr < 10)
		result = nbr + 48;
	if (nbr >= 10)
		result += nbr + d;
	len += ft_putchar(result);
	return (len);
}
