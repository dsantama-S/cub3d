/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:15:46 by dsantama          #+#    #+#             */
/*   Updated: 2020/11/26 11:27:57 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			return_vl(int fd, char **ln, char **line)
{
	char	*str;
	int		n;

	n = 0;
	str = ft_strchr(ln[fd], '\n');
	while (ln[fd][n] != '\0' && ln[fd][n] != '\n')
		n++;
	*line = (char *)malloc(n + 1);
	if (!line)
		return (-1);
	ft_strlcpy(*line, ln[fd], n + 1);
	if (str)
	{
		str = ft_strdup(str + 1);
		free(ln[fd]);
		ln[fd] = str;
		return (1);
	}
	free(ln[fd]);
	ln[fd] = NULL;
	return (0);
}

static int			error_reading(int reading, char **line)
{
	if (reading < 0)
		return (-1);
	*line = ft_strdup("");
	return (0);
}

static int			read_line(int fd, char **line, char *buffer, char **ln)
{
	char			*aux;
	int				reading;

	reading = 0;
	while ((reading = read(fd, buffer, BUFFER_SIZE)) && reading > 0)
	{
		*(buffer + reading) = '\0';
		if (!ln[fd])
			ln[fd] = ft_strdup(buffer);
		else
		{
			aux = ft_strjoin(ln[fd], buffer);
			free(ln[fd]);
			ln[fd] = aux;
		}
		if (ft_strchr(ln[fd], '\n'))
			break ;
	}
	free(buffer);
	if (reading < 0 || (reading == 0 && !ln[fd]))
		return (error_reading(reading, line));
	return (return_vl(fd, ln, line));
}

int					get_next_line(int fd, char **line)
{
	static char		*ln[42];
	char			*buffer;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	return (read_line(fd, line, buffer, ln));
}