/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 08:56:04 by yel-aoun          #+#    #+#             */
/*   Updated: 2023/01/29 17:24:58 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_add(t_add *add)
{
	add->n.addr = mlx_get_data_addr(add->n.xpm, \
		&add->n.b_p_p, &add->n.l_length, &add->n.endian);
	add->s.addr = mlx_get_data_addr(add->s.xpm, \
		&add->s.b_p_p, &add->s.l_length, &add->s.endian);
	add->w.addr = mlx_get_data_addr(add->w.xpm, \
		&add->w.b_p_p, &add->w.l_length, &add->w.endian);
	add->e.addr = mlx_get_data_addr(add->e.xpm, \
		&add->e.b_p_p, &add->e.l_length, &add->e.endian);
}

void	ft_textures_data_addr(t_data *data, t_let *let)
{
	t_add	*add;

	add = malloc(sizeof(t_add));
	add->n.xpm = mlx_xpm_file_to_image(data->mlx, \
		let->no, &add->n.img_w, &add->n.img_h);
	add->s.xpm = mlx_xpm_file_to_image(data->mlx, \
		let->so, &add->s.img_w, &add->s.img_h);
	add->w.xpm = mlx_xpm_file_to_image(data->mlx, \
		let->we, &add->w.img_w, &add->w.img_h);
	add->e.xpm = mlx_xpm_file_to_image(data->mlx, \
		let->ea, &add->e.img_w, &add->e.img_h);
	if (!add->n.xpm || !add->s.xpm || !add->w.xpm || !add->e.xpm)
	{
		printf("Error : textures files doesn't exist");
		exit(0);
	}
	ft_add(add);
	data->add = add;
}

void	ft_creat_map(t_data *data, t_let *let)
{
	int	i;

	i = 0;
	while (let->map[i])
		i++;
	data->map = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (let->map[i])
	{
		data->map[i] = ft_strdup(let->map[i]);
		i++;
	}
	data->p_y = let->x + 0.5;
	data->p_x = let->y + 0.5;
	if (data->map[let->x][let->y] == 'N')
		data->angle = 270;
	else if (data->map[let->x][let->y] == 'S')
		data->angle = 90;
	else if (data->map[let->x][let->y] == 'W')
		data->angle = 180;
	else if (data->map[let->x][let->y] == 'E')
		data->angle = 0;
	data->map[let->x][let->y] = '0';
	data->floor_c = let->f_n;
	data->sky_c = let->c_n;
}
