/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:59:31 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/07/23 19:03:43 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_arr(int arr[10], int n)
{
	int	i;

	i = 0;
	while (i < n)
		ft_putchar(arr[i++] + '0');
}

void	ft_print_combn(int n)
{
	int	arr[10];
	int	index;
	int	current;

	index = 0;
	current = 0;
	while (42)
	{
		if (index == n)
		{
			print_arr(arr, n);
			if (arr[0] < (10 - n))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			index--;
			while (arr[index] == 9 - (n - 1 - index))
				index--;
			if (index == -1)
				break ;
			current = arr[index] + 1;
		}
		arr[index++] = current++;
	}
}
