/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raykeys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:23:05 by dsantama          #+#    #+#             */
/*   Updated: 2021/01/27 13:16:02 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

static void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void skyline(t_vars vars, t_data *data, int x, t_rayc *rayc)
{
	t_data 	img;
	int		c;
	int		y;

	c = rayc->drawend;
	y = rayc->drawstart;
    while (c < rayc->drawstart)
    {
		my_mlx_pixel_put(&img, x, c, 0x000000FF);
        c++;
    }
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
}
