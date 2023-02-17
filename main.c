/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:15:09 by araysse           #+#    #+#             */
/*   Updated: 2023/02/09 12:07:44 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*_ft_str(char *str, int fd)
{
	char	*v;

	v = NULL;
	while (str != NULL)
	{
		v = ft_strjoin(v, str);
		free (str);
		str = get_next_line(fd);
	}
	v = ft_strtrim(v, " \n", 0);
	if (v == NULL)
		ft_eror(1);
	return (v);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*s;
	char	*str;
	t_let	*let;
	char	*v;

	let = malloc(sizeof(t_let));
	v = NULL;
	if (ac != 2)
		exit(0);
	if (ft_strrchr(av[1], '.') == NULL)
		ft_eror(2);
	if (ft_strcmp(ft_strrchr(av[1], '.'), ".cub") != 0)
		ft_eror(2);
	s = av[1];
	fd = open(s, O_RDONLY);
	if (fd == -1)
		ft_eror(1);
	str = get_next_line(fd);
	v = _ft_str(str, fd);
	ft_check_map(v, &let);
	ft_check_path(v, &let);
	ft_cub_3d(let);
}
