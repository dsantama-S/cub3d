/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:16:29 by dsantama          #+#    #+#             */
/*   Updated: 2020/12/21 10:42:31 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		define_map(int fd, t_data *data, int lines)
{
	char	*map;
	char	c;
	int		n;

	n = 0;
	map = malloc(lines);
	if (!map)
		return (0);
	while (read(fd, &c, sizeof(c) != 0))
	{
		map[n] = c;
		n++;
	}
	close(fd);
	data->map = map;
	return (0);
}

static void		elements_path(t_data *data, char *str, int condition)
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
		data->elements++;
}

static int		define_path(int fd, char *str, t_data *data, int lines)
{
	char	c;
	int		count;
	int		condition;
	int		n;

	n = 0;
	count = 0;
	data->elements = 0;
	condition = 1;
	while (read(fd, &c, sizeof(c) != 0) && c != '\n')
	{
		str[n] = c;
		n++;
	}
	while (count < lines)
	{
		condition = 1;
		elements_path(data, str, condition);
		get_next_line(fd, &str);
		count++;
		if (data->elements == 8)
			break ;
	}
	define_map(fd, data, lines);
	return (0);
}

static int		read_map(int fd, char *path, t_data *data)
{
	char	*str;
	char	c;
	int		lines;

	lines = 1;
	str = malloc(sizeof(path));
	if (!str)
		return (0);
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
		free(str);
	}
	return (0);
}

int				read_map_cub(char *path)
{
	int		fd;
	t_data	*data;

	data = ((t_data *)malloc(sizeof(t_data)));
	if (!data)
		return (0);
	fd = open(path, O_RDONLY);
	read_map(fd, path, data);
	analyze_map(data);
	printf("%s\n", data->map);
	return (0);
}
