/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:16:29 by dsantama          #+#    #+#             */
/*   Updated: 2020/12/03 11:42:48 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		define_map(int fd, char *str, t_data *data)
{
	char	c;
	int		n;

	n = 0;
	while (read(fd, &c, sizeof(c) != 0))
	{
		str[n] = c;
		n++;
	}
	data->map = str;
	printf("%s\n", data->map);
	return (0);
}

static int		define_path(int fd, char *str, t_data *data, int lines)
{
	char	c;
	int		count;
	int		n;
	int		condition;

	n = 0;
	count = 1;
	condition = 1;
	while (read(fd, &c, sizeof(c) != 0) && c != '\n')
	{
		str[n] = c;
		n++;
	}
	while (count < lines)
	{
		if (ft_strncmp(str, "R", 1) == 0)
			data->r = str;
		else if (ft_strncmp(str, "NO", 2) == 0)
			data->no = str;
		else if (ft_strncmp(str, "SO", 2) == 0)
			data->so = str;
		else if (ft_strncmp(str, "WE", 2) == 0)
			data->we = str;
		else if (ft_strncmp(str, "EA", 2) == 0)
			data->ea = str;
		else if (ft_strncmp(str, "S ", 2) == 0)
			data->s = str;
		else if (ft_strncmp(str, "F", 1) == 0)
			data->f = str;
		else if (ft_strncmp(str, "C", 1) == 0)
			data->c = str;
		else
			condition = 0;
		if (condition == 1)
			lines--;
		get_next_line(fd, &str);
		count++;
	}
	define_map(fd, str, data);
	return (0);
}

int				read_map_cub(char *path)
{
	char	c;
	int		fd;
	int		lines;
	char	*str;
	t_data	*data;

	lines = 0;
	data = ((t_data *)malloc(sizeof(t_data)));
	if (!data)
		return (0);
	str = malloc(sizeof(path));
	if (!str)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		while (read(fd, &c, sizeof(c) != 0))
		{
			if (c == '\n')
				lines++;
		}
		close(fd);
		fd = open(path, O_RDONLY);
		define_path(fd, str, data, lines);
	}
	return (0);
}
