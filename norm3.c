/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araysse <araysse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:59:05 by araysse           #+#    #+#             */
/*   Updated: 2023/02/05 15:22:23 by araysse          ###   ########.fr       */
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
	i = 0;
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
	char	**cpy2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i++])
		if (s[i] == '\t')
			ft_eror(1);
	split = ft_split(s, '\n');
	ft_check_eror(split);
	copy = ft_cpy(split);
	cpy2 = ft_cpy(split);
	_check_map(copy, cpy2, let);
	ft_free_split(split);
}
