/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:34:05 by dsantama          #+#    #+#             */
/*   Updated: 2021/01/27 13:13:10 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

static void		posmap(int x, int y, t_parse *parse, t_rayc *rayc)
{
	int n;

	n = 0;
	rayc->sprites = 0;
	while (parse->map[n] != '\0')
	{
		if (parse->map[n] == '\n')
		{
			if (x > rayc->mapwidth)
				rayc->mapwidth = x;
			y++;
			x = 0;
		}
		if (parse->map[n] == '2')
		{
			rayc->sprites++;
		}
		if (parse->map[n] == 'N' || parse->map[n] == 'S' ||
		parse->map[n] == 'E' || parse->map[n] == 'W')
		{
			rayc->direction = parse->map[n];
			rayc->posy = (y + 1) + 0.5;
			rayc->posx = x + 0.5;
		}
		n++;
		x++;
	}
	rayc->mapheight = y + 1;
}

static void		mapsquare(int x, t_parse *parse,
t_rayc *rayc, int worldmap[rayc->mapwidth][rayc->mapheight])
{
	int n;
	int y;

	y = 0;
	n = 0;
	while (y < rayc->mapheight)
	{
		while (x < rayc->mapwidth)
		{
			if (parse->map[n] == '\n' || parse->map[n] == '\0')
			{
				while (x < rayc->mapwidth)
				{
					worldmap[x][y] = ' ';
					x++;
				}
				x--;
			}
			worldmap[x][y] = parse->map[n];
			n++;
			x++;
		}
		x = 0;
		y++;
	}
}

int				worldmap(t_colors *colors, t_rayc *rayc, t_parse *parse, t_data *data)
{
	int			worldmap[rayc->mapwidth][rayc->mapheight];
	t_vars		*vars;
	int			x;
	
	x = 0;
	rayc->color_floor = (ft_atoi(colors->r_f) << 16) + (ft_atoi(colors->g_f) << 8) + \
	(ft_atoi(colors->b_f);
	rayc->color_roof = (ft_atoi(colors->r_c) << 16) + (ft_atoi(colors->g_c) << 8) + \
	(ft_atoi(colors->b_c);
	mapsquare(x, parse, rayc, worldmap);
	orientation(rayc);
	inwindow(rayc, vars, data, worldmap);
	return (0);
}

int				initialize(t_colors *colors, t_parse *parse, t_data *data)
{
	t_rayc	*rayc;
	int		y;
	int		x;

	y = 0;
	x = 0;
	rayc = ((t_rayc *)malloc(sizeof(t_rayc)));
	if (!rayc)
		return (0);
	rayc->mapwidth = 0;
	posmap(x, y, parse, rayc);
	worldmap(colors, rayc, parse, data);
	return (0);
}
