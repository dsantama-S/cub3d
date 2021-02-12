/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 09:44:53 by dsantama          #+#    #+#             */
/*   Updated: 2021/02/12 02:12:31 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

int	movement(t_vars *vars,  int worldmap[vars->rc.mapwidth][vars->rc.mapheight])
{
	vars->mv.speed_rot = 0.06;
	move_up(vars, worldmap);
	move_down(vars, worldmap);
	move_right(vars, worldmap);
	move_left(vars, worldmap);
	init_frame(vars, worldmap);
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
	if (keycode == 119)
		vars->mv.up = 0;
	if (keycode == 115)
		vars->mv.down = 0;
	if (keycode == 100)
		vars->mv.right = 0;
	if (keycode == 97)
		vars->mv.left = 0;
	if (keycode == 65363)
		vars->mv.rot_right = 0;
	if (keycode == 65361)
		vars->mv.rot_left = 0;
	if (keycode == 65307)
		key_exit(vars);
	return (0);
}

int		key_press(int keycode, t_vars *vars)
{
	if (keycode == 119)
		vars->mv.up = 1;
	if (keycode == 115)
		vars->mv.down = 1;
	if (keycode == 100)
		vars->mv.right = 1;
	if (keycode == 97)
		vars->mv.left = 1;
	if (keycode == 65363)
		vars->mv.rot_right = 1;
	if (keycode == 65361)
		vars->mv.rot_left = 1;
	printf("%i\n", keycode);
	return 0;
}
