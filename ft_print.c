/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:22:27 by karlewis          #+#    #+#             */
/*   Updated: 2023/07/13 17:04:29 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		i += ft_putchar('-');
		i += ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb = nb * (-1);
		i += write(1, "-", 1);
	}
	if (nb >= 10)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	if (nb < 10)
	{
		i += ft_putchar (nb + '0');
	}
	return (i);
}

int	ft_print_u(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 10)
		i = ft_print_u(nb / 10);
	nb = nb % 10;
	if (nb < 10)
		i += ft_putchar(nb + '0');
	return (i);
}

int	ft_print_hexadecimal(unsigned long int nb, char c)
{
	int	i;

	i = 0;
	if (c == 'x' || c == 'p')
	{
		if (nb >= 16)
			i = ft_print_hexadecimal(nb / 16, c);
		i += ft_putchar("0123456789abcdef"[nb % 16]);
	}
	if (c == 'X')
	{
		if (nb >= 16)
			i = ft_print_hexadecimal(nb / 16, c);
		i += ft_putchar("0123456789ABCDEF"[nb % 16]);
	}
	return (i);
}
