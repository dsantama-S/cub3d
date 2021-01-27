/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raydir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:30:17 by dsantama          #+#    #+#             */
/*   Updated: 2021/01/27 13:23:18 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

static void		cal_step(t_rayc *rayc)
{
	rayc->hit = 0;
	if (rayc->raydirx < 0)
	{
		rayc->stepx = -1;
		rayc->sidedistx = (rayc->posx - rayc->mapx) * rayc->deltadistx;
	}
	else
	{
		rayc->stepx = 1;
		rayc->sidedistx = (rayc->mapx + 1.0 - rayc->posx);
	}
	if (rayc->raydiry < 0)
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
int worldmap[rayc->mapwidth][rayc->mapheight])
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
		if (worldmap[rayc->mapx][rayc->mapy] > 0)
			rayc->hit = 1;
	}
	if (rayc->side == 0)
		rayc->perpwalldist = (rayc->mapx - rayc->posx + (1 - rayc->stepx) / 2) / rayc->raydirx;
	else
		rayc->perpwalldist = (rayc->mapy - rayc->posy + (1 - rayc->stepy) / 2) / rayc->raydiry;		
}

static void			raycast(t_rayc *rayc, int worldmap[rayc->mapwidth][rayc->mapheight],
int x, int width)
{
	rayc->camerax = 2 * x / width - 1;
	rayc->raydirx = rayc->dirx + rayc->planex * rayc->camerax;
	rayc->raydiry = rayc->diry + rayc->planey * rayc->camerax;
	rayc->mapx = rayc->posx;
	rayc->mapy = rayc->posy;
	if (rayc->raydirx == 0)
		rayc->deltadistx = 0;
	else
		rayc->deltadistx = ft_absolute(1 / rayc->raydirx);
	if (rayc->raydiry == 0)
		rayc->deltadisty = 0;
	else
		rayc->deltadisty = ft_absolute(1 / rayc->raydiry);
	cal_step(rayc);
	dda(rayc, worldmap);
}

static void			rayprint(t_rayc *rayc, int worldmap[rayc->mapwidth][rayc->mapheight],
int height)
{
	rayc->lineheight = (int)(height / rayc->perpwalldist);
	rayc->drawstart = -rayc->lineheight / 2 + height / 2;
	if (rayc->drawstart < 0)
		rayc->drawstart = 0;
	rayc->drawend = rayc->lineheight / 2 + height / 2;
	if (rayc->drawend >= 0)
		rayc->drawend = height - 1;
	if (worldmap[rayc->mapx][rayc->mapy] == 1)
		rayc->color = 0x000000FF;
	if (rayc->side == 1)
		rayc->color = rayc->color / 2;	
}

void			ray_starts(t_vars vars, t_rayc *rayc, t_data *data,
int worldmap[rayc->mapwidth][rayc->mapheight])
{
	int x;
	int width;
	int height;

	x = 0;
	width = ft_atoi(data->x);
	height = ft_atoi(data->y);
	while (x < width)
	{
		raycast(rayc, worldmap, x, width);
		rayprint(rayc, worldmap, height);
		if (rayc->drawend < 0)
			rayc->drawend = 0;
		if (rayc->drawstart > height)
			rayc->drawstart = height;
		verline(vars, data, x, rayc);
		x++;
	}
}
