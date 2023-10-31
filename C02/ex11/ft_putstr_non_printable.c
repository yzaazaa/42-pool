/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:14:05 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/08/03 17:52:03 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_chr_is_not_printable(char c)
{
	if (c < 32 || c == 127)
		return (1);
	else
		return (0);
}

void	ft_puthex(char c)
{
	char			*base;
	unsigned char	chr;

	chr = (unsigned char)c;
	base = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(base[chr / 16]);
	ft_putchar(base[chr % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (!ft_chr_is_not_printable(*str))
			ft_putchar(*str);
		else
			ft_puthex(*str);
		str++;
	}
}
