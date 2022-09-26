/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaleh <msaleh@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:19:39 by msaleh            #+#    #+#             */
/*   Updated: 2022/06/17 19:28:54 by msaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_address(unsigned long long nb);
int	ft_parser(va_list arg, char c);
int	ft_putnbr(int nb);
int	ft_hex(unsigned int nb, char c);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putnbr_u(unsigned int nb);

#endif
