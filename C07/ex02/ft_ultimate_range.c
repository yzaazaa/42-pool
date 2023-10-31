/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 02:57:34 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/07/26 22:04:47 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;
	int	*ints;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	len = max - min;
	ints = (int *)malloc(sizeof(int) * len);
	if (ints == 0)
	{
		*range = 0;
		return (-1);
	}
	i = 0;
	*range = ints;
	while (i < len)
		ints[i++] = min++;
	return (len);
}
