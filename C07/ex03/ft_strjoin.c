/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:14:01 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/08/03 02:49:07 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

int	ft_strslen(char **strs, int size, char *sep)
{
	int	len;
	int	i;
	int	len_sep;

	len = 0;
	i = 0;
	len_sep = ft_strlen(sep);
	while (i < size)
	{
		len += ft_strlen(strs[i++]);
		if (i != size - 1)
			len += len_sep;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * ft_strslen(strs, size, sep));
	if (!ret)
		return (NULL);
	ret[0] = 0;
	if (size < 1)
		return (ret);
	i = 0;
	while (i < size)
	{
		ret = ft_strcat(ret, strs[i]);
		if (i != size - 1)
			ret = ft_strcat(ret, sep);
		i++;
	}
	return (ret);
}
