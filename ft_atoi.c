/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:05:40 by araysse           #+#    #+#             */
/*   Updated: 2023/01/27 13:53:02 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long int	total;

	i = 0;
	total = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_eror(1);
		i++;
	}
	i = 0;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		total = total * 10 + (str[i] - '0');
		i++;
	}
	return (total);
}
