#include "cub3d.h"
#include "mlx/mlx.h"

static t_rayc	*set_sprites(t_rayc *rayc, int worldmap[rayc->mapwidth][rayc->mapheight])
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < rayc->mapheight)
	{
		x = 0;
		while (x < rayc->mapwidth)
		{
			if (worldmap[x][y] == '2')
			{
				rayc->sprite[i].coord_x = x + 0.5;
				rayc->sprite[i].coord_y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
	return (rayc);
}

t_rayc	*init_frame(t_rayc *rayc, t_vars *vars, t_data *data,
int worldmap[rayc->mapwidth][rayc->mapheight])
{
	vars->new_image = mlx_new_image(vars->mlx, ft_atoi(data->x), ft_atoi(data->y));
	vars->get_data = (int *)mlx_get_data_addr(vars->new_image, &vars->bits_per_pixel,
    &vars->line_length, &vars->endian);
	if (!(rayc->dist_wall = ft_calloc(sizeof(double), ft_atoi(data->x))))
	{
		printf("Error malloc\n");
		exit(0);
	}
	ray_starts(vars, rayc, data, worldmap);
	ray_sprite(rayc, data, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->new_image, 0, 0);
	mlx_do_sync(vars->mlx);
	mlx_destroy_image(vars->mlx, vars->new_image);
	return (rayc);
}

int     inwindow(t_rayc *rayc, t_vars *vars, t_data *data,
int worldmap[rayc->mapwidth][rayc->mapheight])
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, ft_atoi(data->x),
	ft_atoi(data->y), "Cub3d");
    rayc = init_textures(rayc, data, vars);
    rayc = set_sprites(rayc, worldmap);
    rayc = init_frame(rayc, vars, data, worldmap);
    mlx_loop(vars->mlx);
	return 0;
}