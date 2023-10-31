/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:45:04 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/08/03 17:57:26 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int	main(int argc, char **argv)
{
	void	(*op)(int, int);
	int		a;
	int		b;

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	op = do_op(argv[2]);
	if (op == NULL)
	{
		write(1, "0\n", 2);
		return (0);
	}
	op(a, b);
	return (0);
}

void	*do_op(char *op)
{
	char	*arr[5];
	void	(*calc[5])(int, int);
	int		i;

	i = 0;
	arr[0] = "-";
	arr[1] = "+";
	arr[2] = "*";
	arr[3] = "/";
	arr[4] = "%";
	calc[0] = &minus;
	calc[1] = &plus;
	calc[2] = &mult;
	calc[3] = &div;
	calc[4] = &mod;
	while (i < 5)
	{
		if (ft_strcmp(op, arr[i]) == 0)
			return (calc[i]);
		i++;
	}
	return (NULL);
}
