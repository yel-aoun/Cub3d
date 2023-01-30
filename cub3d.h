/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 08:11:58 by yel-aoun          #+#    #+#             */
/*   Updated: 2023/01/29 17:23:21 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define PI 3.142857
# define ARROW_UP 126
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define TURN_RIGHT 5
# define TURN_LEFT -5
# define LINE_LENGHT 2000

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1
# define PIXELS 64
# define WIN_W 1080
# define WIN_H 1080

// int angle = 90;

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>

typedef struct s_let
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		f_n;
	int		c_n;
	char	**map;
	int		x;
	int		y;
	char	vue;
}	t_let;

typedef struct s_img
{
	void	*xpm;
	char	*addr;
	int		img_w;
	int		img_h;
	int		endian;
	int		l_length;
	int		b_p_p;
}	t_img;

typedef struct s_add
{
	t_img	n;
	t_img	s;
	t_img	w;
	t_img	e;
}	t_add;

typedef struct s_data {
	void	*mlx;
	void	*win;
	double	angle;
	double	moves;
	double	marge;
	int		x;
	int		y;
	int		sky;
	int		wall;
	int		state;
	double	ray_dist;
	double	x_inc;
	double	y_inc;
	double	p_x;
	double	p_y;
	double	d_x;
	double	d_y;
	double	steps;
	int		size_x;
	int		size_y;
	char	**map;
	double	player_mv_x;
	double	player_mv_y;
	double	mini_map_size;
	void	*_img;
	char	*addr;
	int		endian;
	int		len;
	int		pxl;
	double	px_px;
	double	py_px;
	int		*keystat;
	int		floor_c;
	int		sky_c;
	t_let	*let;
	t_add	*add;
}		t_data;

void	ft_cub_3d(t_let *let);
void	ft_input_and_window(t_data *data, int argc, char **argv);
void	ft_creat_map(t_data *data, t_let *let);
void	ft_dda(t_data *data, int i);
void	ft_init_dda(t_data *data);
void	ft_increment(t_data *data);
void	ft_move(t_data *data, int m_v);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_draw_img(t_data	*data);
void	ft_push_to_window(t_data *data, int i);
void	calculat_wall_dist(t_data *data);
void	ft_textures_data_addr(t_data *data, t_let *let);

//parcing...
char	*get_next_line(int fd);
int		ft_strlen(char const *str);
int		ft_strlens(char **str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, int start, int len);
char	**ft_split(char *s, char c);
char	*ft_strchr(char *s, int c);
char	*ft_strtrim(char *s1, char const *set, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_eror(int i);
void	ft_check_map(char *s, t_let **let);
char	*ft_strdup(char *src);
int		ft_atoi(const char *str);
void	ft_f_check(t_let **let);
void	ft_c_check(t_let **let);
void	ft_free_split(char **str);
void	add_to_struct(char **split, t_let **let, char **copy);
void	ft_check_space(char **split);
void	ft_last_check(char *v);
char	*find_map(char *v);
int		ft_calcul_fc(int first, int second, int third);
void	ft_check_path(char *v, t_let **let);
void	ft_check_eror(char **str);

#endif