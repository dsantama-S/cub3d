/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 10:55:05 by dsantama          #+#    #+#             */
/*   Updated: 2021/03/09 09:50:31 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//error de la resolución cuando no escribo numero
//error de los colores cuando no escribo numero
//error de las texturas

void				error_colors(t_colors *colors, t_data *data)
{
	if (ft_atoi(colors->r_f) > 255 || ft_atoi(colors->r_f) < 0 ||
	ft_atoi(colors->g_f) > 255 || ft_atoi(colors->g_f) < 0 ||
	ft_atoi(colors->b_f) > 255 || ft_atoi(colors->b_f) < 0 ||
	ft_atoi(colors->r_c) > 255 || ft_atoi(colors->r_c) < 0 ||
	ft_atoi(colors->g_c) > 255 || ft_atoi(colors->g_c) < 0 ||
	ft_atoi(colors->b_c) > 255 || ft_atoi(colors->b_c) < 0)
	{
		write(1, "Error: : Revise que los colores se encuentren dentro ", 53);
		write(1, "del rango RGB completo(0 - 255).\n", 33);
		data->error = -1;
	}
}

void				error_map(t_parse *parse, t_data *data)
{
	int		n;
	int		c;
	int		bytes;

	n = 0;
	c = 0;
	bytes = ft_strlen(parse->map);
	while (n < bytes)
	{
		if (parse->map[n] == 'N' || parse->map[n] == 'S' ||
		parse->map[n] == 'E' || parse->map[n] == 'W')
			c++;
		if (parse->map[n] != 'N' && parse->map[n] != 'S' &&
		parse->map[n] != 'E' && parse->map[n] != 'W' &&
		parse->map[n] != '1' && parse->map[n] != ' ' &&
		parse->map[n] != '0' && parse->map[n] != '2' &&
		parse->map[n] != '\n')
			data->error = -1;
		n++;
	}
	if (c > 1 || c == 0)
		data->error = -1;
}

char				*res_width(char *aux, char *aux2)
{
	char	*str;
	int		n;

	n = 0;
	str = ft_strchr(aux2, ' ');
	str++;
	while (str[n] != ' ' && str[n] != '\0')
	{
		aux[n] = str[n];
		n++;
	}
	return (aux);
}

int					mapzeros(t_vars *vars, int x, int y)
{
	while (x < vars->rc.mapwidth)
	{
		if (y == (vars->rc.mapheight - 1))
			vars->worldmap[x + y * vars->rc.mapwidth] = '1';
		else
		{
			if (x == (vars->rc.mapwidth - 2))
				vars->worldmap[x + y * vars->rc.mapwidth] = '1';
			else
				vars->worldmap[x + y * vars->rc.mapwidth] = '0';
		}
		x++;
	}
	x--;
	return (x);
}

void				error_wall_y(t_parse *parse, int y, int n, t_vars *vars)
{
	if (parse->map[n] == ' ')
		parse->map[n] = '0';
	if (y == 0)
	{
		if (parse->map[n] == '0')
		{
			parse->error = '1';
			parse->map[n] = '1';
		}
	}
	if (y == (vars->rc.mapheight - 1))
	{
		if (parse->map[n] == '0')
		{
			parse->error = '1';
			parse->map[n] = '1';
		}
	}
}
