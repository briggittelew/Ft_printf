/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:20:10 by karlewis          #+#    #+#             */
/*   Updated: 2023/07/13 17:09:57 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_id_types(va_list args, char x)
{
	int	i;

	i = 0;
	if (x == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (x == '%')
		i += ft_putchar('%');
	else if (x == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (x == 'd')
		i += ft_putnbr(va_arg(args, int));
	else if (x == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (x == 'u')
		i += ft_print_u(va_arg(args, unsigned int));
	else if (x == 'x')
		i += ft_print_hexadecimal(va_arg(args, unsigned int), x);
	else if (x == 'X')
		i += ft_print_hexadecimal(va_arg(args, unsigned int), x);
	else if (x == 'p')
		i += ft_putstr("0x")
			+ ft_print_hexadecimal(va_arg(args, unsigned long int), x);
	return (i);
}

int	ft_printf(char const *str, ...)
{
	int		count;
	va_list	args;

	va_start(args, str);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
			count += ft_id_types(args, *++str);
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (count);
}
