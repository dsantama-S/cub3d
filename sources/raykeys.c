/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raykeys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:23:05 by dsantama          #+#    #+#             */
/*   Updated: 2021/01/25 14:01:40 by dsantama         ###   ########.fr       */
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

void verline(t_data *data, int x, t_rayc *rayc)
{
	t_data img;
	
	img.img = mlx_new_image(vars.mlx, ft_atoi(data->x), ft_atoi(data->y));
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	&img.endian);
    while (rayc->drawstart < rayc->drawend)
    {
		my_mlx_pixel_put(&img, x, rayc->drawstart, rayc->color);
        rayc->drawstart++;
    }
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
}
