/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:16:59 by dsantama          #+#    #+#             */
/*   Updated: 2021/02/17 11:24:27 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

void		move_rot_left(t_vars *vars)
{
	if (vars->mv.rot_left == 1)
	{
		vars->mv.old_dir_x = vars->rc.dirx;
		vars->rc.dirx = vars->rc.dirx * cos(-vars->mv.speed_rot) \
		- vars->rc.diry * sin(-vars->mv.speed_rot);
		vars->rc.diry = vars->mv.old_dir_x * sin(-vars->mv.speed_rot) \
		+ vars->rc.diry * cos(-vars->mv.speed_rot);
		vars->mv.old_plan_x = vars->rc.planex;
		vars->rc.planex = vars->rc.planex * cos(-vars->mv.speed_rot) \
		- vars->rc.planey * sin(-vars->mv.speed_rot);
		vars->rc.planey = vars->mv.old_plan_x * sin(-vars->mv.speed_rot) \
		+ vars->rc.planey * cos(-vars->mv.speed_rot);
	}
}

void		move_rot_right(t_vars *vars)
{
	if (vars->mv.rot_right == 1)
	{
		vars->mv.old_dir_x = vars->rc.dirx;
		vars->rc.dirx = vars->rc.dirx * cos(vars->mv.speed_rot) \
		- vars->rc.diry * sin(vars->mv.speed_rot);
		vars->rc.diry = vars->mv.old_dir_x * sin(vars->mv.speed_rot) \
		+ vars->rc.diry * cos(vars->mv.speed_rot);
		vars->mv.old_plan_x = vars->rc.planex;
		vars->rc.planex = vars->rc.planex * cos(vars->mv.speed_rot) \
		- vars->rc.planey * sin(vars->mv.speed_rot);
		vars->rc.planey = vars->mv.old_plan_x * sin(vars->mv.speed_rot) \
		+ vars->rc.planey * cos(vars->mv.speed_rot);
	}
}
