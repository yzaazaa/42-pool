/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:55:56 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/07/18 15:37:55 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_valid_position(char *board, int x, int pos)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (board[i] == pos + '0')
			return (0);
		i++;
	}
	i = 0;
	while (i < x)
	{
		if (board[i] == pos - x + i + '0' || board[i] == pos + x - i + '0')
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_solutions(char *board, int *x, int *max)
{
	*x = 0;
	while (*x < 10)
	{
		ft_putchar(board[*x]);
		(*x)++;
	}
	ft_putchar('\n');
	*max = *max + 1;
}

void	ft_backtrack(char *board, int x, int *max)
{
	if (x == 10)
	{
		ft_print_solutions(board, &x, max);
		return ;
	}
	board[x] = '0';
	while (board[x] - '0' < 10)
	{
		if (ft_is_valid_position(board, x, board[x] - '0'))
			ft_backtrack(board, x + 1, max);
		board[x]++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	board[10];
	int		max;

	max = 0;
	ft_backtrack(board, 0, &max);
	return (max);
}
