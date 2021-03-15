/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:34:05 by dsantama          #+#    #+#             */
/*   Updated: 2021/03/15 10:53:24 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			numbersprites(t_parse *parse, t_vars *vars, int n)
{
	if (parse->map[n] == '2')
		vars->rc.sprites++;
}

static t_vars		*posmap(int x, int y, t_parse *parse, t_vars *vars)
{
	int n;

	n = 0;
	while (parse->map[n] != '\0')
	{
		if (parse->map[n] == '\n')
		{
			if (x > vars->rc.mapwidth)
				vars->rc.mapwidth = x;
			y++;
			x = 0;
		}
		numbersprites(parse, vars, n);
		if (parse->map[n] == 'N' || parse->map[n] == 'S' ||
		parse->map[n] == 'E' || parse->map[n] == 'W')
		{
			vars->rc.direction = parse->map[n];
			vars->rc.posy = y + 0.5;
			vars->rc.posx = (x + 0.5) - 1;
		}
		n++;
		x++;
	}
	vars->rc.mapheight = y + 1;
	return (vars);
}

static t_vars		*mapsquare(int x, t_parse *parse, t_vars *vars)
{
	int n;
	int y;

	y = 0;
	n = 0;
	while (y < vars->rc.mapheight)
	{
		while (x < vars->rc.mapwidth)
		{
			if (parse->map[n] == '\n' || parse->map[n] == '\0')
			{
				x = mapzeros(vars, x, y);
				parse->map[n + 1] = '1';
			}
			error_wall_x(parse, n, x, vars);
			error_wall_y(parse, y, n, vars);
			vars->worldmap[x + y * vars->rc.mapwidth] = parse->map[n];
			n++;
			x++;
		}
		x = 0;
		y++;
	}
	invalid(parse);
	return (vars);
}

t_vars				*worldmap(t_colors *colors, t_vars *vars, t_parse *parse,
t_data *data)
{
	int		x;
	int		i;

	x = 0;
	i = 0;
	vars->worldmap = malloc(sizeof(int) \
	* vars->rc.mapwidth * vars->rc.mapheight);
	vars->rc.color_floor = ((ft_atoi(colors->r_f) << 16) + \
	(ft_atoi(colors->g_f) << 8) + (ft_atoi(colors->b_f)));
	vars->rc.color_roof = ((ft_atoi(colors->r_c) << 16) + \
	(ft_atoi(colors->g_c) << 8) + (ft_atoi(colors->b_c)));
	vars = mapsquare(x, parse, vars);
	vars = orientation(vars);
	vars = tresolution(vars, data);
	init_values(vars, data);
	inwindow(vars);
	return (vars);
}

int					initialize(t_colors *colors, t_parse *parse, t_data *data)
{
	t_vars		*vars;
	int			y;
	int			x;

	y = 0;
	x = 0;
	vars = ((t_vars *)malloc(sizeof(t_vars)));
	if (!vars)
		return (0);
	parse->error = '0';
	vars->rc.mapwidth = 0;
	vars->rc.sprites = 0;
	vars = posmap(x, y, parse, vars);
	vars = worldmap(colors, vars, parse, data);
	free(vars);
	return (0);
}
