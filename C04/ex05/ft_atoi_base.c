/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:34:58 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/07/27 03:14:45 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || !*base)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] == 127)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

char	*skip_spaces(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

int	count_ret_value(char *str, char *base, int len_base)
{
	int	j;
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
				break ;
			j++;
		}
		if (!base[j])
			return (ret);
		ret *= len_base;
		ret += j;
		i++;
	}
	return (ret);
}

int	ft_atoi_base(char *str, char *base)
{
	int	ret;
	int	len_base;
	int	i;
	int	isneg;

	len_base = check_base(base);
	if (!len_base || !str)
		return (0);
	i = 0;
	isneg = 1;
	ret = 0;
	str = skip_spaces(str);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isneg = -isneg;
		i++;
	}
	ret = count_ret_value(str + i, base, len_base);
	return (isneg * ret);
}
