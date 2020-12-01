/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:16:29 by dsantama          #+#    #+#             */
/*   Updated: 2020/12/01 11:43:23 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		define_map(int fd, char *str, t_data *data)
{
	char	c;
	int		n;

	n = 0;
	get_next_line(fd, &str);
	while (read(fd, &c, sizeof(c) != 0))
	{
		str[n] = c;
		n++;
	}
	data->map = str;
	printf("%s", data->map);
	return (0);
}

static int		define_path(int fd, char *str, t_data *data)
{
	data->r = str;
	get_next_line(fd, &str);
	data->no = str;
	get_next_line(fd, &str);
	data->so = str;
	get_next_line(fd, &str);
	data->we = str;
	get_next_line(fd, &str);
	data->ea = str;
	get_next_line(fd, &str);
	get_next_line(fd, &str);
	data->s = str;
	get_next_line(fd, &str);
	data->f = str;
	get_next_line(fd, &str);
	data->c = str;
	define_map(fd, str, data);
	return (0);
}

int				read_map_cub(char *path)
{
	char	c;
	int		n;
	int		fd;
	char	*str;
	t_data	*data;

	data = ((t_data *)malloc(sizeof(t_data)));
	if (!data)
		return (0);
	str = malloc(sizeof(path));
	if (!str)
		return (0);
	fd = open(path, O_RDONLY);
	n = 0;
	if (fd != -1)
	{
		while (read(fd, &c, sizeof(c) != 0) && c != '\n')
		{
			str[n] = c;
			n++;
		}
		define_path(fd, str, data);
	}
	return (0);
}
