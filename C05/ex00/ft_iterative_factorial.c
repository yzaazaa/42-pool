/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:09:52 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/07/18 11:14:43 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	ret;
	int	i;

	ret = 1;
	i = 2;
	if (nb == 0 || nb == 1)
		return (ret);
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		ret *= i;
		i++;
	}
	return (ret);
}
