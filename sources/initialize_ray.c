/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:34:05 by dsantama          #+#    #+#             */
/*   Updated: 2021/02/12 13:51:18 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_vars		*posmap(int x, int y, t_parse *parse, t_vars *vars)
{
	int n;

	n = 0;
	vars->rc.sprites = 0;
	while (parse->map[n] != '\0')
	{
		if (parse->map[n] == '\n')
		{
			if (x > vars->rc.mapwidth)
				vars->rc.mapwidth = x;
			y++;
			x = 0;
		}
		if (parse->map[n] == '2')
		{
			vars->rc.sprites++;
		}
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

static t_vars		*mapsquare(int x, t_parse *parse,
t_vars *vars, int worldmap[vars->rc.mapwidth][vars->rc.mapheight])
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
				while (x < vars->rc.mapwidth)
				{
					worldmap[x][y] = '0';
					x++;
				}
				x--;
			}
			if (parse->map[n] == ' ')
			{
				parse->map[n] = '0';
			}
			worldmap[x][y] = parse->map[n];
			n++;
			x++;
		}
		x = 0;
		y++;
	}
	return (vars);
}

static void		printmap(t_vars *vars, int	worldmap[vars->rc.mapwidth][vars->rc.mapheight]);
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < vars->rc.mapheight)
    {
        while (x < vars->rc.mapwidth)
        {
			printf("%c", vars->wmap[x + y * vars->rc.mapwidth]);
            x++;
        }
        x = 0;
        y++;
    }
}

t_vars				*worldmap(t_colors *colors, t_vars *vars, t_parse *parse, t_data *data)
{

	int			worldmap[vars->rc.mapwidth][vars->rc.mapheight];
	int			x;
	int			i;
	
	x = 0;
	i = 0;
	vars->rc.color_floor = ((ft_atoi(colors->r_f) << 16) + (ft_atoi(colors->g_f) << 8) + \
	(ft_atoi(colors->b_f)));
	vars->rc.color_roof = ((ft_atoi(colors->r_c) << 16) + (ft_atoi(colors->g_c) << 8) + \
	(ft_atoi(colors->b_c)));
	vars = mapsquare(x, parse, vars, worldmap);
	vars->wmap = worldmap[vars->rc.mapwidth][vars->rc.mapheight];
	printmap(vars, worldmap);
	vars = orientation(vars);
	vars = tresolution(vars, data);
	init_values(vars, data);
	//inwindow(vars, worldmap);
	return (vars);
}

int				initialize(t_colors *colors, t_parse *parse, t_data *data)
{
	t_vars		*vars;
	int			y;
	int			x;

	y = 0;
	x = 0;
	vars = ((t_vars *)malloc(sizeof(t_vars)));
	if (!vars)
		return (0);
	vars->rc.mapwidth = 0;
	vars = posmap(x, y, parse, vars);
	vars = worldmap(colors, vars, parse, data);
	return (0);
}
