/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:04:26 by araysse           #+#    #+#             */
/*   Updated: 2023/01/27 13:53:02 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_eror(int i)
{
	if (i == 1)
	{
		printf("you have error in your map\n");
		exit(0);
	}
}

void	_ft_eror_check(char **str, int *arr)
{
	int		i;

	i = 0;
	while (str[i] && i < 6)
	{
		if (ft_strncmp(str[i], "NO ", 3) == 0)
			arr[0] += 1;
		else if (ft_strncmp(str[i], "SO ", 3) == 0)
			arr[1] += 1;
		else if (ft_strncmp(str[i], "WE ", 3) == 0)
			arr[2] += 1;
		else if (ft_strncmp(str[i], "EA ", 3) == 0)
			arr[3] += 1;
		else if (ft_strncmp(str[i], "F ", 2) == 0)
			arr[4] += 1;
		else if (ft_strncmp(str[i], "C ", 2) == 0)
			arr[5] += 1;
		else
			ft_eror(1);
		i++;
	}
}

void	ft_check_eror(char **str)
{
	int		i;
	int		arr[6];

	i = 0;
	while (str[i] && i < 6)
	{
		str[i] = ft_strtrim(str[i], " ", 0);
		i++;
	}
	i = 0;
	while (i < 6)
		arr[i++] = 0;
	_ft_eror_check(str, arr);
	i = 0;
	while (i < 6)
	{
		if (arr[i] != 1)
			ft_eror(1);
		i++;
	}
}

int	ft_calcul_fc(int first, int second, int third)
{
	if (first < 0 || first > 255)
		ft_eror(1);
	if (second < 0 || second > 255)
		ft_eror(1);
	if (third < 0 || third > 255)
		ft_eror(1);
	first = first << 16;
	second = second << 8;
	return (first + second + third);
}
