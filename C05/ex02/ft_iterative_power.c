/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:17:36 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/07/18 11:20:51 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	if (power == 0 || nb == 1)
		return (1);
	if (power < 0)
		return (0);
	while (i < power)
	{
		ret *= nb;
		i++;
	}
	return (ret);
}
