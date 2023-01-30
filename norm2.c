/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:58:48 by araysse           #+#    #+#             */
/*   Updated: 2023/01/27 13:53:02 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*_find(char *v, int i, int j)
{
	j = i + 1;
	while (v[j] == ' ')
	{
		if (v[j + 1] == '1')
		{
			j = i;
			return (v + j);
		}
		j++;
	}
	return (NULL);
}

char	*find_map(char *v)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (v[i])
	{
		if (v[i] == '\n' && v[i + 1] == '1')
		{
			j = i;
			return (v + j);
		}
		else if (v[i] == '\n' && v[i + 1] == ' ')
		{
			if (_find(v, i, j) != NULL)
				return (_find(v, i, j));
		}
		i++;
	}
	return (NULL);
}

void	_space(char **split)
{
	int		i;

	i = 0;
	while (split[ft_strlens(split) - 1][i])
	{
		if (split[ft_strlens(split) - 1][i] != '1'
			&& split[ft_strlens(split) - 1][i] != ' ')
			ft_eror(1);
		i++;
	}
	i = 1;
	while (i < (ft_strlen(split[i]) - 1))
	{
		split[i] = ft_strtrim(split[i], " ", 0);
		if (split[i][0] != '1' || split[i][ft_strlen(split[i]) - 1] != '1')
			ft_eror(1);
		i++;
	}
}

void	ft_check_space(char **split)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (split[0][i])
	{
		if (split[0][i] != '1' && split[0][i] != ' ')
			ft_eror(1);
		i++;
	}
	i = 0;
	while (split[ft_strlens(split) - 1][i])
	{
		if (split[ft_strlens(split) - 1][i] != '1'
		&& split[ft_strlens(split) - 1][i] != ' ')
			ft_eror(1);
		i++;
	}
}
