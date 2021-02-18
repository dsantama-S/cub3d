/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:52:19 by dsantama          #+#    #+#             */
/*   Updated: 2021/02/18 09:19:06 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

void	set_sprites(t_vars *vars)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < vars->rc.mapheight)
	{
		x = 0;
		while (x < vars->rc.mapwidth)
		{
			if (vars->worldmap[x + y * vars->rc.mapwidth] == '2')
			{
				vars->rc.sprite[i].coord_x = (x + 0.5);
				vars->rc.sprite[i].coord_y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	init_frame(t_vars *vars)
{
	vars->new_image = mlx_new_image(vars->mlx, \
	vars->screen_width, vars->screen_height);
	vars->get_data = (int *)mlx_get_data_addr(vars->new_image, \
	&vars->bits_per_pixel, &vars->size_line, &vars->endian);
	if (!(vars->rc.render.dist_wall = \
	ft_calloc(sizeof(double), vars->screen_width)))
	{
		exit(0);
	}
	ray_starts(vars);
	ray_sprite(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->new_image, 0, 0);
	mlx_do_sync(vars->mlx);
	mlx_destroy_image(vars->mlx, vars->new_image);
}

int		inwindow(t_vars *vars)
{
	if (!(vars->mlx = mlx_init()))
	{
		free(vars);
		exit(0);
		return (0);
	}
	if (!(vars->win = mlx_new_window(vars->mlx, \
	vars->screen_width, vars->screen_height, "Cub3d")))
	{
		free(vars->mlx);
		free(vars);
		exit(0);
		return (0);
	}
	init_textures(vars);
	init_frame(vars);
	mlx_hook(vars->win, 2, 1, &key_press, vars);
	mlx_hook(vars->win, 3, 2, &key_release, vars);
	mlx_hook(vars->win, 33, 0, &key_exit, vars);
	mlx_loop_hook(vars->mlx, &movement, vars);
	mlx_loop(vars->mlx);
	return (0);
}
