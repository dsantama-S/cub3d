/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:01:52 by dsantama          #+#    #+#             */
/*   Updated: 2020/11/24 09:40:02 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;


typedef struct  s_spain {
    void        *mlx;
    void        *win;
}               t_spain;

typedef struct  s_france {
    void        *mlx;
    void        *win;
}               t_france;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             close(int keycode, t_vars    *vars)
{
    if (keycode == 53)
        mlx_destroy_window(vars->mlx, vars->win);
    return 0;
}

int             close2(int keycode, t_spain    *spain)
{
    if (keycode == 53)
        mlx_destroy_window(spain->mlx, spain->win);
    return 0;
}

int             close3(int keycode, t_spain    *france)
{
    if (keycode == 53)
        mlx_destroy_window(france->mlx, france->win);
    return 0;
}

void            my_spain(t_data img)
{   
    int n;
    int x;
    
    n = 0;
    x = 0;
    while (n < 300)
    {
        while (x < 1920)
        {
            my_mlx_pixel_put(&img, x, n, 0x00FF0000);
            x++;
        }
        x = 0;
        n++;
    }
    while (n < 780)
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

void            my_france(t_data img)
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
            my_mlx_pixel_put(&img, x, n, 0xFFFFFF);
            x++;
        }
        x = 0;
        n++;
    }
    while (n < 1080)
    {
        while (x < 1920)
        {
            my_mlx_pixel_put(&img, x, n, 0x2F52B9);
            x++;
        }
        x = 0;
        n++;
    }
}

int             key_hook(int keycode, t_vars *vars)
{
    t_spain  spain;
    t_france france;
    t_data  img;
    
    if (vars){}
    if (keycode == 14)
    {
        spain.mlx = mlx_init();
        spain.win = mlx_new_window(spain.mlx, 1920, 1080, "ESPAÑA!");
        img.img = mlx_new_image(spain.mlx, 1920, 1080);
        img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
        &img.endian);
        my_spain(img);
        mlx_put_image_to_window(spain.mlx, spain.win, img.img, 0, 0);
        printf("Si!\n");
        mlx_hook(spain.win, 2, 1L<<0, close2, &spain);
        mlx_loop(spain.mlx);
    }
    if (keycode == 3)
    {
        france.mlx = mlx_init();
        france.win = mlx_new_window(france.mlx, 1920, 1080, "HOLANDA!");
        img.img = mlx_new_image(france.mlx, 1920, 1080);
        img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
        &img.endian);
        my_france(img);
        mlx_put_image_to_window(france.mlx, france.win, img.img, 0, 0);
        printf("Si!\n");
        mlx_hook(france.win, 2, 1L<<0, close3, &france);
        mlx_loop(france.mlx);
    }
    printf("%i\n", keycode);
    return 0;
}

int             main(void)
{
    t_vars      vars;
    
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Banderas");
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_hook(vars.win, 2, 1L<<0, close, &vars);
    mlx_loop(vars.mlx);
}
