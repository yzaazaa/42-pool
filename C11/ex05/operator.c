/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:45:08 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/08/03 17:45:12 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"
#include <stdio.h>

void	plus(int a, int b)
{
	ft_putnbr(a + b);
	write(1, "\n", 1);
}

void	minus(int a, int b)
{
	ft_putnbr(a - b);
	write(1, "\n", 1);
}

void	mult(int a, int b)
{
	ft_putnbr(a * b);
	write(1, "\n", 1);
}

void	div(int a, int b)
{
	if (b == 0)
		write(1, "Stop : division by zero", 23);
	else
		ft_putnbr(a / b);
	write(1, "\n", 1);
}

void	mod(int a, int b)
{
	if (b == 0)
		write(1, "Stop : modulo by zero", 21);
	else
		ft_putnbr(a % b);
	write(1, "\n", 1);
}
