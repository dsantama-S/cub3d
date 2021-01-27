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
	while (parse->map[n] != '\0')
	{
		if (parse->map[n] == '\n')
		{
			if (x > rayc->mapwidth)
				rayc->mapwidth = x;
			y++;
			x = 0;
		}
		if (parse->map[n] == 'N' || parse->map[n] == 'S' ||
		parse->map[n] == 'E' || parse->map[n] == 'W')
		{
			rayc->posy = y + 1;
			rayc->posx = x;
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
	t_vars		vars;
	int			x;
	
	x = 0;
	mapsquare(x, parse, rayc, worldmap);
	rayc->dirx = -1;
	rayc->diry = 0;
	rayc->planex = 0;
	rayc->planey = 0.66;
	rayc->time = 0;
	rayc->oldtime = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, ft_atoi(data->x),
	ft_atoi(data->y), "Cub3d");
	ray_starts(vars, rayc, data, worldmap);
	mlx_loop(vars.mlx);
	if (colors){}
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
