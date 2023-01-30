/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:35:31 by araysse           #+#    #+#             */
/*   Updated: 2023/01/27 13:53:02 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_word(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s[i] == c)
		i++;
	if (s[i] != c && s[i])
	{
		i++;
		j++;
	}
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
		{
			j++;
		}
		i++;
	}
	return (j);
}

int	word_size(char const *s, char c, int start)
{
	int	len;

	len = 0;
	while (s[start] && s[start] != c)
	{
		start++;
		len++;
	}
	return (len);
}

int	ft_sep(const char *s, char c, int k)
{
	while (s[k] == c)
		k++;
	return (k);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	i = -1;
	if (!(s) || s[0] == '\0')
		return (calloc(1, sizeof(char *)));
	str = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!str)
		return (NULL);
	k = ft_sep(s, c, 0);
	while (++i < count_word(s, c))
	{
		str[i] = malloc(sizeof(char) * (word_size(s, c, k) + 1));
		if (!str[i])
			return (NULL);
		j = 0;
		while (s[k] && s[k] != c)
			str[i][j++] = s[k++];
		str[i][j] = '\0';
		k = ft_sep(s, c, k);
	}
	str[i] = NULL;
	return (str);
}
