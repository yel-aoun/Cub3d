/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_drawing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:26:33 by yel-aoun          #+#    #+#             */
/*   Updated: 2023/01/30 14:27:09 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_textures_no(t_data *data, double py, double px, t_add *add)
{
	int		x;
	int		y;
	char	*clr;

	x = (int)(px * add->n.img_w) % add->n.img_w;
	y = (int)(py * add->n.img_h) % add->n.img_h;
	clr = add->n.addr + (y * add->n.l_length + x * (add->n.b_p_p / 8));
	return (clr);
}

int	ft_textures(t_data *data, double py, double px, t_add *add)
{
	int		x;
	int		y;
	char	*clr;

	if (data->state == 0)
	{
		x = (int)(px * add->w.img_w) % add->w.img_w;
		y = (int)(py * add->w.img_h) % add->w.img_h;
		clr = add->w.addr + (y * add->w.l_length + x * (add->w.b_p_p / 8));
	}
	else if (data->state == 1)
	{
		x = (int)(px * add->e.img_w) % add->e.img_w;
		y = (int)(py * add->e.img_h) % add->e.img_h;
		clr = add->e.addr + (y * add->e.l_length + x * (add->e.b_p_p / 8));
	}
	else if (data->state == 2)
		clr = ft_textures_no(data, py, px, add);
	else if (data->state == 3)
	{
		x = (int)(px * add->s.img_w) % add->s.img_w;
		y = (int)(py * add->s.img_h) % add->s.img_h;
		clr = add->s.addr + (y * add->s.l_length + x * (add->s.b_p_p / 8));
	}
	return (*(unsigned int *) clr);
}

void	calculat_wall_dist(t_data *data)
{
	double	new_angle;
	double	p_screen_dist;

	new_angle = (((data->angle + data->marge) * PI) / 180) \
		- (((data->angle) * PI) / 180);
	data->ray_dist = data->ray_dist * cos(new_angle);
	p_screen_dist = (WIN_H / 2) / tan((30 * PI) / 180);
	data->wall = ((PIXELS) * p_screen_dist / data->ray_dist);
	data->sky = (WIN_W - data->wall) / 2 ;
}

void	ft_push_to_window(t_data *data, int i)
{
	int		j;
	double	y;

	calculat_wall_dist(data);
	j = 0;
	while (j <= data->sky && j < WIN_W)
	{
		my_mlx_pixel_put(data, i, j, data->sky_c);
		j++;
	}
	while (j <= data->sky + data->wall && j < WIN_W)
	{
		y = (double)(j - data->sky) / (double)data->wall;
		my_mlx_pixel_put(data, i, j, ft_textures(data, y, \
			data->px_px, data->add));
		j++;
	}
	while (j < WIN_W)
	{
		my_mlx_pixel_put(data, i, j, data->floor_c);
		j++;
	}
}
