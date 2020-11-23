/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 09:09:37 by dsantama          #+#    #+#             */
/*   Updated: 2020/11/23 09:52:34 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void            my_square(t_data img)
{   
    int n;
    int x;
    
    n = 0;
    x = 0;
    while (x < 1920)
    {
        while (n < 960)
        {
            my_mlx_pixel_put(&img, x, n, 0x00FF0000);
            n++;
        }
        n = 0;
        x++;
    }
}

void            my_spain(t_data img)
{   
    int n;
    int x;
    
    n = 0;
    x = 0;
    while (n < 360)
    {
        while (x < 1920)
        {
            my_mlx_pixel_put(&img, x, n, 0x00FF0000);
            x++;
        }
        x = 0;
        n++;
    }
    while (n < 720)
    {
        while (x < 1920)
        {
            my_mlx_pixel_put(&img, x, n, 0xF5E625);
            x++;
        }
        x = 0;
        n++;
    }
    while (n < 1080)
    {
        while (x < 1920)
        {
            my_mlx_pixel_put(&img, x, n, 0x00FF0000);
            x++;
        }
        x = 0;
        n++;
    }
}

int     main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    my_spain(img);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
