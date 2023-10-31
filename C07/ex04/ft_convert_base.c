/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:42:38 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/07/31 17:33:17 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		ft_strlen(char *str);
int		check(char *base);

char	*ft_rev_arr(char *arr, int size)
{
	int		i;
	char	*ret;
	int		tmp;

	tmp = size - 1;
	i = 0;
	ret = (char *)malloc(sizeof(char) * size + 1);
	if (ret == 0)
		return (0);
	if (arr[0] == '-')
	{
		ret[0] = '-';
		i++;
	}
	ret[size] = '\0';
	while (i < size)
		ret[i++] = arr[tmp--];
	return (ret);
}

char	*ft_zero(char *base)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * 2);
	if (ret == 0)
		return (0);
	ret[0] = base[0];
	ret[1] = '\0';
	return (ret);
}

char	*ft_itoa_base(int nbr, char *base)
{
	unsigned int	n;
	char			arr[30];
	int				i;
	int				len_base;

	i = 0;
	n = nbr;
	if (nbr == 0)
		return (ft_zero(base));
	if (nbr < 0)
	{
		arr[i++] = '-';
		n = -nbr;
	}
	len_base = ft_strlen(base);
	while (n > 0)
	{
		arr[i++] = base[n % len_base];
		n = n / len_base;
	}
	return (ft_rev_arr(arr, i));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*ret;

	if (!check(base_from) || !check(base_to))
		return (0);
	num = ft_atoi_base(nbr, base_from);
	ret = ft_itoa_base(num, base_to);
	return (ret);
}
