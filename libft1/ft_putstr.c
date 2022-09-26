/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaleh <msaleh@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:21:03 by msaleh            #+#    #+#             */
/*   Updated: 2022/06/17 19:23:37 by msaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;
	int	i;

	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	else
		len = 0;
	i = -1;
	while (str[++i] != '\0')
		len += ft_putchar(str[i]);
	return (len);
}
