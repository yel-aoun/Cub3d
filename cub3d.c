/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 08:12:01 by yel-aoun          #+#    #+#             */
/*   Updated: 2023/02/05 15:19:32 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	printf("You gave up :(\n Is the map to hard for you?\n");
	exit(EXIT_SUCCESS);
}

int	ft_key_hook(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->addr = mlx_get_data_addr(data->_img, &data->pxl, \
		&data->len, &data->endian);
	if (data->keystat[0])
		ft_move(data, 0);
	if (data->keystat[1])
		ft_move(data, 180);
	if (data->keystat[2])
		ft_move(data, -90);
	if (data->keystat[3])
		ft_move(data, 90);
	if (data->keystat[4])
		data->angle += 4;
	if (data->keystat[5])
		data->angle -= 4;
	ft_draw_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->_img, 0, 0);
	return (0);
}

int	ft_key_hook1(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_exit(data);
	if (keycode == W || keycode == ARROW_UP)
		data->keystat[0] = 1;
	if (keycode == S || keycode == ARROW_DOWN)
		data->keystat[1] = 1;
	if (keycode == A)
		data->keystat[2] = 1;
	if (keycode == D)
		data->keystat[3] = 1;
	if (keycode == ARROW_RIGHT)
		data->keystat[4] = 1;
	if (keycode == ARROW_LEFT)
		data->keystat[5] = 1;
	return (0);
}

int	ft_key_hook2(int keycode, t_data *data)
{
	if (keycode == W || keycode == ARROW_UP)
		data->keystat[0] = 0;
	if (keycode == S || keycode == ARROW_DOWN)
		data->keystat[1] = 0;
	if (keycode == A)
		data->keystat[2] = 0;
	if (keycode == D)
		data->keystat[3] = 0;
	if (keycode == ARROW_RIGHT)
		data->keystat[4] = 0;
	if (keycode == ARROW_LEFT)
		data->keystat[5] = 0;
	return (0);
}

void	ft_cub_3d(t_let *let)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->moves = 6;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_W, WIN_H, "Cub3d");
	data->_img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->addr = mlx_get_data_addr(data->_img, &data->pxl, \
		&data->len, &data->endian);
	ft_creat_map(data, let);
	ft_textures_data_addr(data, let);
	data->keystat = calloc(6, 4);
	ft_draw_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->_img, 0, 0);
	mlx_hook(data->win, 17, 0, ft_exit, data);
	mlx_hook(data->win, 2, 0, ft_key_hook1, data);
	mlx_hook(data->win, 3, 0, ft_key_hook2, data);
	mlx_loop_hook(data->mlx, ft_key_hook, data);
	mlx_loop(data->mlx);
}
