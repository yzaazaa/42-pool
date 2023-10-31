/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:39:42 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/08/01 03:08:16 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	len_base;
	int	i;
	int	j;

	len_base = ft_strlen(base);
	i = 0;
	if (!base || !*base || len_base == 0 || len_base == 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] == 127)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_nb(int nbr)
{
	unsigned int	nb;

	if (nbr < 0)
	{
		ft_putchar('-');
		nb = -nbr;
	}
	else
		nb = nbr;
	return (nb);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				len_base;
	unsigned int	nb;
	char			arr[256];
	int				i;

	len_base = ft_strlen(base);
	if (!check_base(base))
		return ;
	if (nbr == 0)
	{
		ft_putchar(base[0]);
		return ;
	}
	nb = check_nb(nbr);
	i = 0;
	while (nb)
	{
		arr[i] = base[nb % len_base];
		nb = nb / len_base;
		i++;
	}
	while (i--)
		ft_putchar(arr[i]);
}

int main()
{
	ft_putnbr_base(42, "\v0123456789abcdef");
}
