/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:24:49 by yel-aoun          #+#    #+#             */
/*   Updated: 2023/01/30 13:34:34 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_increment(t_data *data)
{
	while (1)
	{
		if (data->map[(int)((data->py_px + data->y_inc / 4) / PIXELS)] \
			[(int)(data->px_px / PIXELS)] != '0')
		{
			if (data->y_inc < 0)
				data->state = 2;
			else
				data->state = 3;
			break ;
		}
		if (data->map[(int)(data->py_px / PIXELS)][(int) \
			((data->px_px + data->x_inc / 4) / PIXELS)] != '0')
		{
			if (data->x_inc < 0)
				data->state = 0;
			else
				data->state = 1;
			break ;
		}
		data->px_px += data->x_inc / 4;
		data->py_px += data->y_inc / 4;
	}
}

void	ft_init_dda(t_data *data)
{
	data->d_x = data->player_mv_x - data->px_px;
	data->d_y = data->player_mv_y - data->py_px;
	if (fabs(data->d_x) > fabs(data->d_y))
		data->steps = fabs(data->d_x);
	else
		data->steps = fabs(data->d_y);
	data->x_inc = data->d_x / data->steps;
	data->y_inc = data->d_y / data->steps;
}

void	ft_dda(t_data *data, int i)
{
	ft_init_dda(data);
	ft_increment(data);
	data->ray_dist = sqrt((pow(data->px_px - (data->p_x * PIXELS), 2)) + \
		(pow(data->py_px - (data->p_y * PIXELS), 2)));
	if (data->state == 2 || data->state == 3)
	{
		data->px_px /= PIXELS;
		data->px_px = fmod(data->px_px, 1);
	}
	else
	{
		data->px_px = data->py_px / PIXELS;
		data->px_px = fmod(data->px_px, 1);
	}
	ft_push_to_window(data, i);
}

void	ft_draw_img(t_data	*data)
{
	int		i;
	double	j;

	j = (double)60 / (double)WIN_H;
	data->marge = -30.0;
	i = 0;
	while (i < WIN_W)
	{
		data->px_px = data->p_x * PIXELS;
		data->py_px = data->p_y * PIXELS;
		data->player_mv_y = (data->p_y + 100 * (sin((data->angle + data->marge) \
			* PI / 180))) * PIXELS;
		data->player_mv_x = (data->p_x + 100 * (cos((data->angle + data->marge) \
			* PI / 180))) * PIXELS;
		ft_dda(data, i);
		data->marge += j;
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIN_W || y >= WIN_H)
		return ;
	dst = data->addr + (y * data->len + x * (data->pxl / 8));
	*(unsigned int *)dst = color;
}
