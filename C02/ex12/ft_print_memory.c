/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:48:00 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/08/03 17:54:22 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_diff_abs(int a, int b)
{
	if (a - b >= 0)
		return (a - b);
	return (b - a);
}

void	ft_putstr(char *str, int index)
{
	int	i;
	int	j;

	if (index >= 16)
		i = 16;
	else
		i = index;
	j = 0;
	while (j < i)
	{
		if (str[j] >= ' ' && str[j] < 127)
			write(1, &str[j], 1);
		else
			write(1, ".", 1);
		j++;
	}
	write(1, "\n", 1);
}

void	ft_print_hex(char *add, int index, char *s)
{
	int				i;
	int				calc;

	i = 0;
	if (index >= 16)
		calc = 16;
	else
		calc = index;
	while (i < calc)
	{
		write(1, &s[(unsigned char)add[i] / 16], 1);
		write(1, &s[(unsigned char)add[i] % 16], 1);
		if ((i + 1) % 2 == 0 && i != 15)
			write(1, " ", 1);
		i++;
	}
	while (calc < 16)
	{
		write(1, " ", 1);
		write(1, " ", 1);
		if ((calc + 1) % 2 == 0 && calc != 15)
			write(1, " ", 1);
		calc++;
	}
	write(1, " ", 1);
}

void	ft_print_addr(unsigned long addr)
{
	int		i;
	char	arr[16];
	char	*hex;

	i = 15;
	hex = "0123456789abcdef";
	while (addr)
	{
		arr[i--] = hex[addr % 16];
		addr /= 16;
	}
	while (i >= 0)
		arr[i--] = '0';
	write(1, arr, 16);
	write(1, ": ", 2);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		ft_print_addr((unsigned long)(&addr[i]));
		ft_print_hex(&addr[i], ft_diff_abs(i, size), "0123456789abcdef");
		ft_putstr(&addr[i], ft_diff_abs(i, size));
		i += 16;
	}
	return (addr);
}
