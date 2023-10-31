/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 02:50:25 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/07/26 22:04:23 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ret;
	int	i;

	i = 0;
	ret = malloc(sizeof(int) * (max - min + 1));
	if (!ret)
		return (NULL);
	if (min >= max)
		return (NULL);
	while (min < max)
	{
		ret[i++] = min;
		min++;
	}
	return (ret);
}
