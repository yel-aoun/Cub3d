/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:15:09 by araysse           #+#    #+#             */
/*   Updated: 2023/01/30 14:27:44 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*s;
	char	*str;
	char	*v;
	t_let	*let;

	let = malloc(sizeof(t_let));
	if (ac != 2)
		exit(0);
	s = av[1];
	v = NULL;
	fd = open(s, O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		v = ft_strjoin(v, str);
		free (str);
		str = get_next_line(fd);
	}
	ft_check_map(v, &let);
	ft_check_path(v, &let);
}
