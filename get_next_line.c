/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:04:03 by araysse           #+#    #+#             */
/*   Updated: 2023/01/27 13:53:02 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define BUFFER_SIZE 1

int	sheck_newline(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*after_new_line( char *buf)
{
	char	*remind;
	int		j;

	j = 0;
	while (buf[j])
	{
		if (buf[j] == '\n')
		{
			remind = ft_substr(buf, j + 1, ft_strlen(buf) - (j + 1));
			free(buf);
			return (remind);
		}
		j++;
	}
	free(buf);
	return (NULL);
}

char	*befor_new_line(char *buf)
{
	int		j;

	j = 0;
	if (!buf[0])
		return (NULL);
	while (buf[j] && buf[j] != '\n')
		j++;
	return (ft_substr(buf, 0, j + 1));
}

char	*get_line(int fd, char *buf)
{
	char	*save;
	int		i;

	save = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	i = 1;
	while (!sheck_newline(buf) && i)
	{
		i = read(fd, save, BUFFER_SIZE);
		if (i == -1)
		{
			free(save);
			return (NULL);
		}
		save[i] = '\0';
		buf = ft_strjoin(buf, save);
	}
	free (save);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = get_line(fd, buf);
	if (!buf)
		return (NULL);
	line = befor_new_line(buf);
	buf = after_new_line(buf);
	return (line);
}
