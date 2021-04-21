/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:08:20 by dsantama          #+#    #+#             */
/*   Updated: 2021/04/21 09:02:24 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

void	move_left(t_vars *vars)
{
	if (vars->mv.left == 1)
	{
		if (vars->worldmap[(int)(vars->rc.posx) + \
		(int)(vars->rc.posy - vars->rc.planey * 0.09) \
		* vars->rc.mapwidth] != '1' && vars->worldmap[(int)(vars->rc.posx) + \
		(int)(vars->rc.posy - vars->rc.planey * 0.09) \
		* vars->rc.mapwidth] != '2')
			vars->rc.posy -= vars->rc.planey * 0.09;
		if (vars->worldmap[(int)(vars->rc.posx - vars->rc.planex * 0.09) + \
		(int)(vars->rc.posy) * vars->rc.mapwidth] != '1' \
		&& vars->worldmap[(int)(vars->rc.posx - vars->rc.planex * 0.09) + \
		(int)(vars->rc.posy) * vars->rc.mapwidth] != '2')
			vars->rc.posx -= vars->rc.planex * 0.09;
	}
}

void	move_right(t_vars *vars)
{
	if (vars->mv.right == 1)
	{
		if (vars->worldmap[(int)(vars->rc.planex * 0.09 + vars->rc.posx) + \
		(int)(vars->rc.posy) * vars->rc.mapwidth] != '1' \
		&& vars->worldmap[(int)(vars->rc.planex * 0.09 + vars->rc.posx) + \
		(int)(vars->rc.posy) * vars->rc.mapwidth] != '2')
			vars->rc.posx += vars->rc.planex * 0.09;
		if (vars->worldmap[(int)(vars->rc.posx) + \
		(int)(vars->rc.posy + vars->rc.planey * 0.09) \
		* vars->rc.mapwidth] != '1' && vars->worldmap[(int)(vars->rc.posx) + \
		(int)(vars->rc.posy + vars->rc.planey * 0.09) \
		* vars->rc.mapwidth] != '2')
			vars->rc.posy += vars->rc.planey * 0.09;
	}
}

void	move_down(t_vars *vars)
{
	if (vars->mv.down == 1)
	{
		if (vars->worldmap[(int)(vars->rc.posx - vars->rc.dirx * 0.09) + \
		(int)(vars->rc.posy) * vars->rc.mapwidth] != '1' \
		&& vars->worldmap[(int)(vars->rc.posx - vars->rc.dirx * 0.09) + \
		(int)(vars->rc.posy) * vars->rc.mapwidth] != '2')
			vars->rc.posx -= vars->rc.dirx * 0.09;
		if (vars->worldmap[(int)(vars->rc.posx) + \
		(int)(vars->rc.posy - vars->rc.diry * 0.09) * vars->rc.mapwidth] != '1'\
		&& vars->worldmap[(int)(vars->rc.posx) + \
		(int)(vars->rc.posy - vars->rc.diry * 0.09) * vars->rc.mapwidth] != '2')
			vars->rc.posy -= vars->rc.diry * 0.09;
	}
}

void	move_up(t_vars *vars)
{
	if (vars->mv.up == 1)
	{
		if (vars->worldmap[(int)(vars->rc.posx + vars->rc.dirx * 0.09) + \
		(int)(vars->rc.posy) * vars->rc.mapwidth] != '1' \
		&& vars->worldmap[(int)(vars->rc.posx + vars->rc.dirx * 0.09) + \
		(int)(vars->rc.posy) * vars->rc.mapwidth] != '2')
			vars->rc.posx += vars->rc.dirx * 0.09;
		if (vars->worldmap[(int)(vars->rc.posx) + \
		(int)(vars->rc.posy + vars->rc.diry * 0.09) * vars->rc.mapwidth] != '1'\
		&& vars->worldmap[(int)(vars->rc.posx) + \
		(int)(vars->rc.posy + vars->rc.diry * 0.09) * vars->rc.mapwidth] != '2')
			vars->rc.posy += vars->rc.diry * 0.09;
	}
	if (vars->mv.up_speed == 1)
	{
		if (vars->worldmap[(int)(vars->rc.posx + vars->rc.dirx * 0.09) + \
		(int)(vars->rc.posy) * vars->rc.mapwidth] != '1' \
		&& vars->worldmap[(int)(vars->rc.posx + vars->rc.dirx * 0.09) + \
		(int)(vars->rc.posy) * vars->rc.mapwidth] != '2')
			vars->rc.posx += vars->rc.dirx * 0.09;
		if (vars->worldmap[(int)(vars->rc.posx) + \
		(int)(vars->rc.posy + vars->rc.diry * 0.09) * vars->rc.mapwidth] != '1'\
		&& vars->worldmap[(int)(vars->rc.posx) + \
		(int)(vars->rc.posy + vars->rc.diry * 0.09) * vars->rc.mapwidth] != '2')
			vars->rc.posy += vars->rc.diry * 0.09;
	}
}
