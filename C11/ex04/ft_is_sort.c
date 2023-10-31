/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:14:14 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/07/31 22:55:48 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ascend;
	int	descend;

	i = 0;
	ascend = 0;
	descend = 0;
	if (length < 3)
		return (1);
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			descend++;
		if (f(tab[i], tab[i + 1]) <= 0)
			ascend++;
		i++;
	}
	if (ascend == (length - 1) || descend == (length - 1))
		return (1);
	return (0);
}
