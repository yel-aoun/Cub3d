/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:58:35 by araysse           #+#    #+#             */
/*   Updated: 2023/02/09 12:10:52 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	_last(char **split, int i, int j)
{
	if (split[i][j] == '0')
	{
		if ((j + 1) > ft_strlen(split[i + 1])
			|| (j + 1) > ft_strlen(split[i - 1]))
		{
			ft_eror(1);
		}
		else if (split[i - 1][j] == ' ' || split[i + 1][j] == ' '
			|| split[i][j + 1] == ' ' || split[i][j - 1] == ' ')
			ft_eror(1);
	}
	if (split[i][j] == 'N' || split[i][j] == 'S'
	|| split[i][j] == 'W' || split[i][j] == 'E')
	{
		if ((j + 1) > ft_strlen(split[i - 1])
			|| (j + 1) > ft_strlen(split[i + 1]))
			ft_eror(1);
		else if (split[i - 1][j] == ' ' || split[i + 1][j] == ' '
		|| split[i][j + 1] == ' ' || split[i][j - 1] == ' ')
			ft_eror(1);
	}
}

void	ft_last_check(char *v)
{
	char	**split;
	int		i;
	int		j;
	int		len;

	i = 1;
	j = 0;
	split = ft_split(v, '\n');
	len = ft_strlens(split);
	while (i < len - 1)
	{
		j = 0;
		while (split[i][j])
		{
			_last(split, i, j);
			j++;
		}
		i++;
	}
	ft_free_split(split);
}

void	_path(char *v, int i)
{
	int		j;

	j = 0;
	while (v[i])
	{
		if (v[i] == '\n' && v[i + 1] == '\n')
			ft_eror(1);
		i++;
	}
	i = 0;
	while (v[i])
	{
		if (v[i] != '0' && v[i] != '1' && v[i] != ' ' && v[i] != 'N'
			&& v[i] != 'S' && v[i] != 'W' && v[i] != 'E' && v[i] != '\n')
			ft_eror(1);
		if (v[i] == 'N' || v[i] == 'S' || v[i] == 'W' || v[i] == 'E')
			j++;
		i++;
	}
	if (j != 1)
		ft_eror(1);
}

void	ft_position(char **s, t_let **let)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'N' || s[i][j] == 'S'
			|| s[i][j] == 'W' || s[i][j] == 'E')
			{
				(*let)->x = i;
				(*let)->y = j;
				(*let)->vue = s[i][j];
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_check_path(char *v, t_let **let)
{
	int		i;
	char	**split;
	int		j;

	i = 0;
	j = 0;
	v = find_map(v);
	if (v == NULL)
		ft_eror(1);
	_path(v, i);
	split = ft_split(v, '\n');
	ft_check_space(split);
	ft_position(split, let);
	ft_last_check(v);
	(*let)->map = malloc(sizeof (char *) * (ft_strlens(split) + 1));
	while (split[i])
	{
		(*let)->map[i] = ft_strdup(split[i]);
		i++;
	}
	(*let)->map[i] = NULL;
	ft_free_split(split);
}
