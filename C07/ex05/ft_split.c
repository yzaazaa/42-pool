/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:19:36 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/07/26 22:06:06 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	while (*charset)
		if (c == *(charset++))
			return (1);
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	size;
	int	i;

	size = 0;
	i = 1;
	while (str[i])
	{
		while (str[i] && !is_separator(str[i], charset))
			i++;
		if ((is_separator(str[i], charset) || !str[i])
			&& !is_separator(str[i - 1], charset))
			size++;
		if (!str[i])
			break ;
		i++;
	}
	return (size + 1);
}

int	strlen_sep(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_separator(str[i], charset))
		i++;
	return (i + 1);
}

char	*ft_strldup(char *src, int size)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * size);
	if (!ret)
		return (NULL);
	if (size)
	{
		i = 0;
		while (src[i] && i < size - 1)
		{
			ret[i] = src[i];
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		i;
	int		nb_words;
	int		j;

	nb_words = word_count(str, charset);
	ret = malloc(sizeof(char *) * nb_words);
	if (!ret)
		return (NULL);
	if (!*str)
	{
		ret[0] = 0;
		return (ret);
	}
	i = 0;
	j = 0;
	while (i < nb_words)
	{
		while (str[j] && is_separator(str[j], charset))
			j++;
		ret[i++] = ft_strldup(str + j, strlen_sep(str + j, charset));
		j += strlen_sep(str + j, charset);
	}
	ret[nb_words - 1] = 0;
	return (ret);
}
