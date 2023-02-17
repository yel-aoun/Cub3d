/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:06:30 by yel-aoun          #+#    #+#             */
/*   Updated: 2023/02/03 14:35:34 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move(t_data *data, int m_v)
{
	if (data->map[(int)(data->p_y + sin(((data->angle + m_v) * PI) / 180) / 4)] \
		[(int)(data->p_x + cos(((data->angle + m_v) * PI) / 180) / 4)] == '0')
	{
		if (data->map[(int)(data->p_y + sin(((data->angle + m_v) * \
			PI) / 180) / 4)][(int)(data->p_x)] == '0' && data->map[(int) \
			(data->p_y)][(int)(data->p_x + cos(((data->angle + m_v) * \
			PI) / 180) / 4)] == '0')
		{
			data->p_x += cos(((data->angle + m_v) * PI) / 180) / 6;
			data->p_y += sin(((data->angle + m_v) * PI) / 180) / 6;
		}
	}
}
