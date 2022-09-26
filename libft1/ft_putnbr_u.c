/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaleh <msaleh@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:25:40 by msaleh            #+#    #+#             */
/*   Updated: 2022/06/17 19:27:13 by msaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nb)
{
	int		len;
	char	c;

	len = 0;
	if (nb == 2147483648)
		return (len += ft_putstr("2147483648"));
	if (nb >= 10)
		len += ft_putnbr (nb / 10);
	c = (nb % 10) + 48;
	len += ft_putchar(c);
	return (len);
}
