/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaleh <msaleh@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:30:27 by msaleh            #+#    #+#             */
/*   Updated: 2022/06/17 21:27:21 by msaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	len = 0;
	i = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			len += ft_putchar (str[i]);
			i++;
		}
		else
		{
			len += ft_parser(arg, str[i + 1]);
			i += 2;
		}
	}
	va_end(arg);
	return (len);
}
