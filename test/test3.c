/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:40:27 by dsantama          #+#    #+#             */
/*   Updated: 2021/01/21 10:48:16 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#define MLX_SYNC_IMAGE_WRITABLE    1 
#define MLX_SYNC_WIN_FLUSH_CMD     2
#define MLX_SYNC_WIN_CMD_COMPLETED 3

int	mlx_sync(int cmd, void *ptr);
void    *mlx_png_file_to_image(void *mlx_ptr, char *file, int *width, int *height);

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

typedef struct  s_link {
    void        *mlx;
    void        *win;
}               t_link;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
	int			x;
	char		p;
	int			y;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void			rdata(t_data *data)
{
	if	(data->p != 's')
	{
		data->x = 960;
		data->y = 540;
	}
}

int             key_hook(int keycode, t_vars *vars)
{
	t_data *data;
	
	if (vars){}
	data = ((t_data *)malloc(sizeof(t_data)));
	if (!data)
		return (0);
	rdata(data);
	if (keycode == 13)
	{
		data->y = data->y - 40;
		data->p = 's';
		printf("%i\n", data->y);
	}
	else
		printf("%i\n", keycode);
	return 0;
}

int     main(void)
{
	t_vars	vars;
   	t_data  img;
	t_data	img2;
	t_data	*data;
    char    *relative_path = "../textures/wood.xpm";
	char    *relative_path2 = "../textures/link2.xpm";
    int     img_width;
    int     img_height;
	int		n;
	int 	x;
	
	n = 0;
	x = 0;
	data = ((t_data *)malloc(sizeof(t_data)));
	if (!data)
		return (0);
	data->x = 960;
	data->y = 540;
    vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Barril");
	img.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
	while (n < 1080)
	{
		while (x < 1920)
        {
            mlx_put_image_to_window(vars.mlx, vars.win, img.img, x, n);
			x += 63;
        }
		x = 0;
		n += 63;
	}
	img2.img = mlx_xpm_file_to_image(vars.mlx, relative_path2, &img_width, &img_height);
   	img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.line_length, 
	   	&img2.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, img2.img, data->x, data->y);
	mlx_key_hook(vars.win, key_hook, vars.mlx);
	mlx_loop(vars.mlx);
}

static void		printmap(t_rayc *rayc, int worldmap[rayc->mapwidth][rayc->mapheight])
{
	int x;
	int y;

	x = 0;
	y = 0;
	 while (y < rayc->mapheight)
    {
        while (x < rayc->mapwidth)
        {
			printf("%c", worldmap[x][y]);
            x++;
        }
        x = 0;
        y++;
    }
}

