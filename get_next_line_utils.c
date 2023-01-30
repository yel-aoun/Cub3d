/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:05:54 by araysse           #+#    #+#             */
/*   Updated: 2023/01/27 13:53:02 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(char const *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;
	int		lens1;
	int		lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	new = (char *) malloc ((lens1 + lens2 + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (i < lens1)
		new[i++] = s1[j++];
	j = 0;
	while (j < lens2)
		new[i++] = s2[j++];
	new[i] = '\0';
	free (s1);
	return (new);
}

char	*ft_substr(char const *s, int start, int len)
{
	int		j;
	char	*a;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	a = (char *)s;
	j = 0;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (j < len)
		sub[j++] = a[start++];
	sub[j] = '\0';
	return (sub);
}
