/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 09:44:53 by dsantama          #+#    #+#             */
/*   Updated: 2021/04/26 10:55:31 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

int	movement(t_vars *vars)
{
	vars->mv.speed_rot = 0.06;
	move_up(vars);
	move_down(vars);
	move_right(vars);
	move_left(vars);
	move_rot_right(vars);
	move_rot_left(vars);
	init_frame(vars);
	return (0);
}

int	key_exit(t_vars *vars)
{
	free(vars->mlx);
	free(vars->win);
	free(vars->rc.north.img_ptr);
	free(vars->rc.south.img_ptr);
	free(vars->rc.east.img_ptr);
	free(vars->rc.west.img_ptr);
	if (vars->rc.render.dist_wall)
		free(vars->rc.render.dist_wall);
	exit(0);
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->mv.up = 0;
	if (keycode == 257)
		vars->mv.up_speed = 0;
	if (keycode == 1)
		vars->mv.down = 0;
	if (keycode == 2)
		vars->mv.right = 0;
	if (keycode == 0)
		vars->mv.left = 0;
	if (keycode == 124)
		vars->mv.rot_right = 0;
	if (keycode == 123)
		vars->mv.rot_left = 0;
	if (keycode == 53)
		key_exit(vars);
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->mv.up = 1;
	if (keycode == 257)
		vars->mv.up_speed = 1;
	if (keycode == 1)
		vars->mv.down = 1;
	if (keycode == 2)
		vars->mv.right = 1;
	if (keycode == 0)
		vars->mv.left = 1;
	if (keycode == 124)
		vars->mv.rot_right = 1;
	if (keycode == 123)
		vars->mv.rot_left = 1;
	return (0);
}
