/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsrayc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:23:05 by dsantama          #+#    #+#             */
/*   Updated: 2021/02/08 12:37:54 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

t_vars *orientation(t_vars *vars)
{
	if (vars->rc.direction == 'N')
	{
		vars->rc.dirx = 0;
		vars->rc.diry = -1;
	}
	if (vars->rc.direction == 'S')
	{
		vars->rc.dirx = 0;
		vars->rc.diry = 1;
	}
	if (vars->rc.direction == 'W')
	{
		vars->rc.dirx = -1;
		vars->rc.diry = 0;
	}
	if (vars->rc.direction == 'E')
	{
		vars->rc.dirx = 1;
		vars->rc.diry = 0;
	}
	vars->rc.planex = -0.66 * vars->rc.diry;
	vars->rc.planey = 0.66 * vars->rc.dirx;
	return (vars);
}
t_vars *tresolution(t_vars *vars, t_data *data)
{
	vars->screen_height = data->swapy;
	vars->screen_width = data->swapx;
	return (vars);
}

void	init_values(t_vars *vars, t_data *data)
{
	vars->rc.texture_no = data->texture_no;
	vars->rc.texture_so = data->texture_so;
	vars->rc.texture_we = data->texture_we;
	vars->rc.texture_ea = data->texture_ea;
	vars->rc.texture_sprite = data->texture_sprite;
	vars->mlx = NULL;
	vars->win = NULL;
	if (!(vars->rc.sprite = malloc(sizeof(int) * vars->rc.sprites)))
	{
		exit(0);
	};
}