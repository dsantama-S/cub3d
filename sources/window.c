#include "cub3d.h"
#include "mlx/mlx.h"

static t_vars	*set_sprites(t_vars *vars, int worldmap[vars->rc.mapwidth][vars->rc.mapheight])
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
			if (worldmap[x][y] == '2')
			{
				vars->rc.sprite[i].coord_x = x + 0.5;
				vars->rc.sprite[i].coord_y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
	return (vars);
}

t_vars	*init_frame(t_vars *vars, int worldmap[vars->rc.mapwidth][vars->rc.mapheight])
{
	vars->new_image = mlx_new_image(vars->mlx, vars->screen_width, vars->screen_height);
	vars->get_data = (int *)mlx_get_data_addr(vars->new_image, &vars->bits_per_pixel,
    &vars->size_line, &vars->endian);
	if (!(vars->rc.dist_wall = ft_calloc(sizeof(double), vars->screen_width)))
	{
		printf("Error malloc\n");
		exit(0);
	}
	ray_starts(vars, worldmap);
	ray_sprite(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->new_image, 0, 0);
	mlx_do_sync(vars->mlx);
	mlx_destroy_image(vars->mlx, vars->new_image);
	return (vars);
}

int     inwindow(t_vars *vars, t_data *data,
int worldmap[vars->rc.mapwidth][vars->rc.mapheight])
{
	if (data){}
	if (worldmap){}
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->screen_width, vars->screen_height, "Cub3d");
    //vars = init_textures(data, vars);
    vars = set_sprites(vars, worldmap);
    //vars = init_frame(vars, worldmap);
    mlx_loop(vars->mlx);
	return (0);
}