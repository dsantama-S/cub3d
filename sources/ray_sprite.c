/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:51:46 by dsantama          #+#    #+#             */
/*   Updated: 2021/04/14 12:07:26 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

static void		aux_render_sprite(t_vars *vars, int i)
{
	vars->rc.render.x = vars->rc.sprite[vars->rc.sprite[i].order].coord_x \
	- vars->rc.posx;
	vars->rc.render.y = vars->rc.sprite[vars->rc.sprite[i].order].coord_y \
	- vars->rc.posy;
	vars->rc.render.inv_det = 1 / (vars->rc.planex * vars->rc.diry \
	- vars->rc.dirx * vars->rc.planey);
	vars->rc.render.transform_x = vars->rc.render.inv_det * \
	(vars->rc.diry * vars->rc.render.x - vars->rc.dirx * vars->rc.render.y);
	vars->rc.render.transform_y = vars->rc.render.inv_det * (-vars->rc.planey \
	* vars->rc.render.x + vars->rc.planex * vars->rc.render.y);
	vars->rc.render.screen_x = (int)((vars->screen_width / 2) * \
	(1 + vars->rc.render.transform_x / vars->rc.render.transform_y));
	vars->rc.render.height = abs((int)(vars->screen_height / \
	vars->rc.render.transform_y));
	vars->rc.render.start_y = -vars->rc.render.height / \
	2 + vars->screen_height / 2;
	aux_render_sprite2(vars);
}

static void		render_sprite(t_vars *vars)
{
	int	i;
	int	x;

	i = 0;
	while (i < vars->rc.sprites)
	{
		aux_render_sprite(vars, i);
		x = vars->rc.render.start_x;
		while (x < vars->rc.render.end_x && x < vars->screen_width)
		{
			vars->rc.render.tex_x = (int)(256 * (x - (-vars->rc.render.width / \
			2 + vars->rc.render.screen_x)) * vars->rc.sprite[i].width / \
			vars->rc.render.width) / 256;
			if (vars->rc.render.transform_y > 0)
				last_render_sprite(x, i, vars);
			x++;
		}
		i++;
	}
}

static void		sort_sprite(t_vars *vars)
{
	int	i;
	int	swap;

	i = 0;
	while (i + 1 < vars->rc.sprites)
	{
		if (vars->rc.sprite[vars->rc.sprite[i].order].distance < \
		vars->rc.sprite[vars->rc.sprite[i + 1].order].distance)
		{
			swap = vars->rc.sprite[i].order;
			vars->rc.sprite[i].order = vars->rc.sprite[i + 1].order;
			vars->rc.sprite[i + 1].order = swap;
			sort_sprite(vars);
		}
		i++;
	}
}

static void		sprite_distance(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->rc.sprites)
	{
		vars->rc.sprite[i].order = i;
		vars->rc.sprite[i].distance = \
		pow(vars->rc.posx - \
		vars->rc.sprite[i].coord_x, 2) + \
		pow(vars->rc.posy - \
		vars->rc.sprite[i].coord_y, 2);
		i++;
	}
}

void			ray_sprite(t_vars *vars)
{
	sprite_distance(vars);
	sort_sprite(vars);
	render_sprite(vars);
	free_sprite(vars);
}
