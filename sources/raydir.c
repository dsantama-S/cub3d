/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raydir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:30:17 by dsantama          #+#    #+#             */
/*   Updated: 2021/01/28 13:16:05 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

static void		cal_step(t_rayc *rayc, t_vars *vars)
{
	rayc->hit = 0;
	if (rayc->raydirx < vars->endian)
	{
		rayc->stepx = -1;
		rayc->sidedistx = (rayc->posx - rayc->mapx) * rayc->deltadistx;
	}
	else
	{
		rayc->stepx = 1;
		rayc->sidedistx = (rayc->mapx + 1.0 - rayc->posx);
	}
	if (rayc->raydiry < vars->endian)
	{
		rayc->stepy = -1;
		rayc->sidedisty = (rayc->posy - rayc->mapy) * rayc->deltadisty;
	}
	else
	{
		rayc->stepy = 1;
		rayc->sidedisty = (rayc->mapy + 1.0 - rayc->posy);
	}
}

static void		dda(t_rayc *rayc,
int worldmap[rayc->mapwidth][rayc->mapheight], t_vars *vars)
{
	while (rayc->hit == 0)
	{
		if (rayc->sidedistx < rayc->sidedisty)
		{
			rayc->sidedistx += rayc->deltadistx;
			rayc->mapx += rayc->stepx;
			rayc->side = 0;
		}
		else
		{
			rayc->sidedisty += rayc->deltadisty;
			rayc->mapy += rayc->stepy;
			rayc->side = 1;
		}
		if (worldmap[rayc->mapx][rayc->mapy] == '1')
			rayc->hit = 1;
	}
	if (rayc->side == vars->endian)
		rayc->perpwalldist = (rayc->mapx - rayc->posx + (1 - rayc->stepx) / 2) / rayc->raydirx;
	else
		rayc->perpwalldist = (rayc->mapy - rayc->posy + (1 - rayc->stepy) / 2) / rayc->raydiry;		
}

static void			raycast(t_rayc *rayc, int worldmap[rayc->mapwidth][rayc->mapheight],
int x, int width)
{
	rayc->camerax = 2 * x / (double)width - 1;
	rayc->raydirx = rayc->dirx + rayc->planex * rayc->camerax;
	rayc->raydiry = rayc->diry + rayc->planey * rayc->camerax;
	rayc->mapx = (int)rayc->posx;
	rayc->mapy = (int)rayc->posy;
	rayc->deltadistx = ft_absolute(1 / rayc->raydirx);
	rayc->deltadisty = ft_absolute(1 / rayc->raydiry);
}

void			rayprint(t_rayc *rayc, int height, t_vars *vars,
int x)
{
	int y;

	rayc->lineheight = (height / rayc->perpwalldist);
	rayc->drawstart = -rayc->lineheight / 2 + height / 2;
	rayc->drawend = rayc->lineheight / 2 + height / 2
	if (rayc->drawstart < 0)
		rayc->drawstart = 0;
	if (rayc->drawend >= height)
		rayc->drawend = height - 1;
	set_texture(rayc, x, height);
	y = 0;
	if (rayc->drawend < 0)
		rayc->drawend = height;
	y = rayc->drawend;
	while (y < height)
	{
		vars->get_data[x + y * (vars->line_length / 4)] = rayc->color_floor;
		vars->get_data[x + (height - y - 1) * (vars->line_length / 4)] = rayc->color_roof;
		y++;
	}
}

void			ray_starts(t_vars *vars, t_rayc *rayc, t_data *data,
int worldmap[rayc->mapwidth][rayc->mapheight])
{
	int x;
	int y;
	int width;
	int height;

	x = 0;
	y = 0;
	width = ft_atoi(data->x);
	height = ft_atoi(data->y);
	while (x < width)
	{
		raycast(rayc, worldmap, x, width);
		cal_step(rayc, vars);
		dda(rayc, worldmap, vars);
		rayprint(rayc, height, vars, x);
		rayc->dist_wall[x] = rayc->perpwalldist;
		x++;
	}
}
