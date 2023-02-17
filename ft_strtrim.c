/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araysse <araysse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:13:46 by araysse           #+#    #+#             */
/*   Updated: 2023/02/05 14:47:39 by araysse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_char_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char const *set, int c)
{
	size_t		i;
	size_t		debu;
	size_t		fin;
	char		*str;

	debu = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[debu] && ft_char_set(s1[debu], set))
		debu++;
	fin = ft_strlen(s1);
	while (fin > debu && ft_char_set(s1[fin - 1], set))
		fin--;
	str = malloc((fin - debu + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (debu < fin)
	{
		str[i++] = s1[debu++];
	}
	if (c != 1)
		free(s1);
	str[i] = '\0';
	return (str);
}
