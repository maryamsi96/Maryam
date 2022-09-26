/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaleh <msaleh@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:20:47 by msaleh            #+#    #+#             */
/*   Updated: 2022/06/17 19:22:22 by msaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	len;
	int	c;

	len = 0;
	if (nb == -2147483648)
	{
		return (len += ft_putstr("-2147483648"));
	}
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
		len += ft_putnbr(nb / 10);
		c = (nb % 10) + 48;
		len += ft_putchar(c);
	return (len);
}
