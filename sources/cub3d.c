/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:16:29 by dsantama          #+#    #+#             */
/*   Updated: 2021/01/05 11:40:58 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		define_map(int fd, t_parse *parse)
{
	char	*map;
	char	*aux;
	char	*aux2;
	char	*aux3;
	char	*line;

	map = ft_strdup("");
	while (get_next_line(fd, &line) != 0)
	{
		aux = ft_strjoin(map, line);
		free(map);
		map = aux;
		aux2 = ft_strjoin(map, "\n");
		free(map);
		map = aux2;
	}
	aux3 = ft_strjoin(map, line);
	free(map);
	map = aux3;
	close(fd);
	parse->map = map;
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
	return (0);
}

static int		read_map(int fd, char *path, t_data *data, t_parse *parse)
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
		define_map(fd, parse);
		free(str);
	}
	return (0);
}

int				read_map_cub(char *path)
{
	int		fd;
	t_data	*data;
	t_parse *parse;

	parse = ((t_parse *)malloc(sizeof(t_parse)));
	if (!parse)
		return (0);
	data = ((t_data *)malloc(sizeof(t_data)));
	if (!data)
		return (0);
	data->error = 0;
	fd = open(path, O_RDONLY);
	read_map(fd, path, data, parse);
	analyze_map(data, parse);
	if (data->error == -1)
	{
		write(1, "Ha ocurrido un error en la configuración del mapa.\n", 52);
		return (-1);
	}
	free(data);
	printf("%s\n", parse->map);
	free(parse);
	return (0);
}
