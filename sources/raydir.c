/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raydir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:30:17 by dsantama          #+#    #+#             */
/*   Updated: 2021/02/05 13:08:16 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

static void		cal_step(t_vars *vars)
{
	vars->rc.hit = 0;
	if (vars->rc.raydirx < 0)
	{
		vars->rc.stepx = -1;
		vars->rc.sidedistx = (vars->rc.posx - vars->rc.mapx) * vars->rc.deltadistx;
	}
	else
	{
		vars->rc.stepx = 1;
		vars->rc.sidedistx = (vars->rc.mapx + 1.0 - vars->rc.posx);
	}
	if (vars->rc.raydiry < 0)
	{
		vars->rc.stepy = -1;
		vars->rc.sidedisty = (vars->rc.posy - vars->rc.mapy) * vars->rc.deltadisty;
	}
	else
	{
		vars->rc.stepy = 1;
		vars->rc.sidedisty = (vars->rc.mapy + 1.0 - vars->rc.posy);
	}
}

static void		dda(t_vars *vars, int worldmap[vars->rc.mapwidth][vars->rc.mapheight])
{
	while (vars->rc.hit == 0)
	{
		if (vars->rc.sidedistx < vars->rc.sidedisty)
		{
			vars->rc.sidedistx += vars->rc.deltadistx;
			vars->rc.mapx += vars->rc.stepx;
			vars->rc.side = 0;
		}
		else
		{
			vars->rc.sidedisty += vars->rc.deltadisty;
			vars->rc.mapy += vars->rc.stepy;
			vars->rc.side = 1;
		}
		if (worldmap[vars->rc.mapx][vars->rc.mapy] == '1')
			vars->rc.hit = 1;
	}
}

static void			raycast(t_vars *vars, int x, int width)
{
	vars->rc.camerax = 2 * x / (double)width - 1;
	vars->rc.raydirx = vars->rc.dirx + vars->rc.planex * vars->rc.camerax;
	vars->rc.raydiry = vars->rc.diry + vars->rc.planey * vars->rc.camerax;
	vars->rc.mapx = (int)vars->rc.posx;
	vars->rc.mapy = (int)vars->rc.posy;
	vars->rc.deltadistx = fabs(1 / vars->rc.raydirx);
	vars->rc.deltadisty = fabs(1 / vars->rc.raydiry);
}

void			rayprint(int height, t_vars *vars, int x)
{
	int y;
	
	y = 0;
	vars->rc.lineheight = (height / vars->rc.perpwalldist);
	vars->rc.drawstart = -vars->rc.lineheight / 2 + height / 2;
	vars->rc.drawend = vars->rc.lineheight / 2 + height / 2;
	if (vars->rc.drawstart < 0)
		vars->rc.drawstart = 0;
	if (vars->rc.drawend >= height)
		vars->rc.drawend = height - 1;
	set_texture(x, height, vars);
	y = vars->rc.drawend;
	while (y < height)
	{
		vars->get_data[x + y * (vars->size_line / 4)] = vars->rc.color_floor;
		vars->get_data[x + (height - y - 1) * (vars->size_line / 4)] = vars->rc.color_roof;
		y++;
	}
}

void			ray_starts(t_vars *vars, int worldmap[vars->rc.mapwidth][vars->rc.mapheight])
{
	int x;
	int y;
	int width;
	int height;

	x = 0;
	y = 0;
	width = vars->screen_width;
	height = vars->screen_height;
	while (x < width)
	{
		raycast(vars, x, width);
		cal_step(vars);
		dda(vars, worldmap);
		if (vars->rc.side == 0)
			vars->rc.perpwalldist = (vars->rc.mapx - vars->rc.posx + (1 - vars->rc.stepx) / 2) / vars->rc.raydirx;
		else
			vars->rc.perpwalldist = (vars->rc.mapy - vars->rc.posy + (1 - vars->rc.stepy) / 2) / vars->rc.raydiry;
		rayprint(height, vars, x);
		vars->rc.dist_wall[x] = vars->rc.perpwalldist;
		x++;
	}
}
