/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:59:05 by araysse           #+#    #+#             */
/*   Updated: 2023/01/30 14:37:07 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlens(char **str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

void	ft_free_split(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
}

void	_check_map(char **copy, char **split, t_let **let)
{
	char	*t;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (copy[i] && i < 6)
	{
		j = 0;
		while (copy[i][j] && copy[i][j] != ' ')
			j++;
		t = copy[i];
		copy[i] = ft_strtrim((copy[i] + j), " ", 1);
		free (t);
		i++;
	}
	add_to_struct(split, let, copy);
	ft_f_check(let);
	ft_c_check(let);
	ft_free_split(copy);
	ft_free_split(split);
}

void	ft_check_map(char *s, t_let **let)
{
	char	**split;
	char	**copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	(void)let;
	while (s[i++])
		if (s[i] == '\t')
			ft_eror(1);
	split = ft_split(s, '\n');
	ft_check_eror(split);
	copy = malloc(sizeof(char *) * (ft_strlens(split) + 1));
	i = 0;
	while (i < ft_strlens(split))
	{
		copy[i] = ft_strdup(split[i]);
		i++;
	}
	copy[i] = NULL;
	_check_map(copy, split, let);
}
