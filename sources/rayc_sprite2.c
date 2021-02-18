/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayc_sprite2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:52:11 by dsantama          #+#    #+#             */
/*   Updated: 2021/02/18 10:08:33 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

void		free_sprite(t_vars *vars)
{
	if (vars->rc.render.dist_wall)
	{
		free(vars->rc.render.dist_wall);
		vars->rc.render.dist_wall = NULL;
	}
}

static void	get_color(t_vars *vars, int i)
{
	if (vars->rc.render.tex_y > 0)
	{
		if (vars->rc.sprite[i].get_data[vars->rc.render.tex_x + \
		vars->rc.render.tex_y * vars->rc.sprite[i].width] != 0)
			vars->rc.sprite[i].color = \
			vars->rc.sprite[i].get_data[vars->rc.render.tex_x\
			+ vars->rc.render.tex_y * vars->rc.sprite[i].width];
		else
			vars->rc.sprite[i].color = 0xBFD195;
	}
}

void		last_render_sprite(int x, int i, t_vars *vars)
{
	int	y;
	int	d;

	y = vars->rc.render.start_y;
	while (y < vars->rc.render.end_y)
	{
		d = (y * 256 - vars->screen_height * \
		128 + vars->rc.render.height * 128);
		vars->rc.render.tex_y = ((d * vars->rc.sprite[i].height / \
		vars->rc.render.height) / 256);
		get_color(vars, i);
		if (vars->rc.sprite[i].color != 0xBFD195 &&\
		vars->rc.render.transform_y < \
		vars->rc.render.dist_wall[x])
		{
			if (x >= 0 && x < vars->screen_width && \
			y >= 0 && y < vars->screen_height)
			{
				vars->get_data[x + y * (vars->size_line / 4)] = \
				vars->rc.sprite[i].color;
			}
		}
		y++;
	}
}

void		aux_render_sprite2(t_vars *vars)
{
	if (vars->rc.render.start_y < 0)
		vars->rc.render.start_y = 0;
	vars->rc.render.end_y = vars->rc.render.height / \
	2 + vars->screen_height / 2;
	if (vars->rc.render.end_y >= vars->screen_height)
		vars->rc.render.end_y = vars->screen_height - 1;
	vars->rc.render.width = abs((int)(vars->screen_height / \
	vars->rc.render.transform_y));
	vars->rc.render.start_x = -vars->rc.render.width / \
	2 + vars->rc.render.screen_x;
	if (vars->rc.render.start_x < 0)
		vars->rc.render.start_x = 0;
	vars->rc.render.end_x = vars->rc.render.width / \
	2 + vars->rc.render.screen_x;
	if (vars->rc.render.end_x >= vars->screen_width)
		vars->rc.render.end_x = vars->screen_width - 1;
}
