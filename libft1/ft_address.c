/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaleh <msaleh@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:19:48 by msaleh            #+#    #+#             */
/*   Updated: 2022/06/17 19:18:08 by msaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_address(unsigned long long nb)
{
	int	len;
	int	nbr;
	int	result;

	len = 0;
	if (nb >= 16)
		len += ft_address(nb / 16);
	nbr = nb % 16;
	if (nbr < 10)
		result = nbr + 48;
	if (nbr >= 10)
		result = nbr + 87;
	len += ft_putchar(result);
	return (len);
}
