/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araysse <araysse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:03:39 by araysse           #+#    #+#             */
/*   Updated: 2023/02/05 13:06:40 by araysse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	_f_check(t_let **let)
{
	char	**str;
	int		first;
	int		second;
	int		third;

	str = ft_split((*let)->f, ',');
	str[0] = ft_strtrim(str[0], " ", 0);
	str[1] = ft_strtrim(str[1], " ", 0);
	str[2] = ft_strtrim(str[2], " ", 0);
	first = ft_atoi(str[0]);
	second = ft_atoi(str[1]);
	third = ft_atoi(str[2]);
	(*let)->f_n = ft_calcul_fc(first, second, third);
	ft_free_split(str);
}

void	ft_f_check(t_let **let)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((*let)->f[0] == ',')
		ft_eror(1);
	while ((*let)->f[i] != '\0')
	{
		if ((*let)->f[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		ft_eror(1);
	_f_check(let);
}

void	_c_check(t_let **let)
{
	char	**str;
	int		first;
	int		second;
	int		third;

	str = ft_split((*let)->c, ',');
	str[0] = ft_strtrim(str[0], " ", 0);
	str[1] = ft_strtrim(str[1], " ", 0);
	str[2] = ft_strtrim(str[2], " ", 0);
	first = ft_atoi(str[0]);
	second = ft_atoi(str[1]);
	third = ft_atoi(str[2]);
	(*let)->c_n = ft_calcul_fc(first, second, third);
	ft_free_split(str);
}

void	ft_c_check(t_let **let)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((*let)->c[0] == ',')
		ft_eror(1);
	while ((*let)->c[i] != '\0')
	{	
		if ((*let)->c[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		ft_eror(1);
	_c_check(let);
}

void	add_to_struct(char **split, t_let **let, char **copy)
{
	int		i;

	i = 0;
	while (split[i] && i < 6)
	{	
		if (ft_strncmp(split[i], "NO ", 3) == 0)
			(*let)->no = ft_strdup(copy[i]);
		else if (ft_strncmp(split[i], "SO ", 3) == 0)
			(*let)->so = ft_strdup(copy[i]);
		else if (ft_strncmp(split[i], "WE ", 3) == 0)
			(*let)->we = ft_strdup(copy[i]);
		else if (ft_strncmp(split[i], "EA ", 3) == 0)
			(*let)->ea = ft_strdup(copy[i]);
		else if (ft_strncmp(split[i], "F ", 2) == 0)
			(*let)->f = ft_strdup(copy[i]);
		else if (ft_strncmp(split[i], "C ", 2) == 0)
			(*let)->c = ft_strdup(copy[i]);
		i++;
	}
}
