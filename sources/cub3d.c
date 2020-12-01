/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:16:29 by dsantama          #+#    #+#             */
/*   Updated: 2020/12/01 14:01:03 by dsantama         ###   ########.fr       */
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
	return (0);
}

static int		define_path(int fd, char *str, t_data *data)
{
	int n;
	int	lines_read;

	n = 0;
	lines_read = 1;
	while (n < 14(hay q sacar cuantas lineas))
	{
		if (ft_strncmp(str, "R", 1) == 0)
			data->r = str;
		if (ft_strncmp(str, "NO", 2) == 0)
			data->no = str;
		if (ft_strncmp(str, "SO", 2) == 0)
			data->so = str;
		if (ft_strncmp(str, "WE", 2) == 0)
			data->we = str;
		if (ft_strncmp(str, "EA", 2) == 0)
			data->ea = str;
		if (ft_strncmp(str, "S ", 2) == 0)
			data->s = str;
		if (ft_strncmp(str, "F", 1) == 0)
			data->f = str;
		if (ft_strncmp(str, "C", 1) == 0)
			data->c = str;
		get_next_line(fd, &str);
		n++;
	}
	printf("%s\n", data->f);
	define_map(fd, str, data);
	return (0);
}

int				read_map_cub(char *path)
{
	char	c;
	int		fd;
	int		n;
	char	*str;
	t_data	*data;

	n = 0;
	data = ((t_data *)malloc(sizeof(t_data)));
	if (!data)
		return (0);
	str = malloc(sizeof(path));
	if (!str)
		return (0);
	fd = open(path, O_RDONLY);
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
