#include "cub3d.h"
#include "mlx/mlx.h"

static void	aux_render_sprite(t_rayc *rayc, int i, t_data *data)
{
	rayc->render.x = rayc->sprite[rayc->sprite[i].order].coord_x - rayc->posx;
	rayc->render.y = rayc->sprite[rayc->sprite[i].order].coord_y - rayc->posy;
	rayc->render.inv_det = 1 / (rayc->planex * rayc->diry - rayc->dirx * rayc->planey);
	rayc->render.transform_x = rayc->render.inv_det * (rayc->diry * rayc->render.x - rayc->dirx * rayc->render.y);
	rayc->render.transform_y = rayc->render.inv_det * (-rayc->planey * rayc->render.x + rayc->planex * rayc->render.y);
	rayc->render.screen_x = (int)((rayc->width_screen / 2) * (1 + rayc->render.transform_x / rayc->render.transform_y));
	rayc->render.height = abs((int)(rayc->height_screen / rayc->render.transform_y));
	rayc->render.start_y = -rayc->render.height / 2 + rayc->height_screen / 2;	
	if (rayc->render.start_y < 0)
		rayc->render.start_y = 0;
	rayc->render.end_y = rayc->render.height / 2 + rayc->height_screen / 2;
	if (rayc->render.end_y >= rayc->height_screen)
		rayc->render.end_y = rayc->height_screen - 1;
	rayc->render.width = abs((int)(rayc->height_screen / rayc->render.transform_y));
	rayc->render.start_x = -rayc->render.width / 2 + rayc->render.screen_x;
	if (rayc->render.start_x < 0)
		rayc->render.start_x = 0;
	rayc->render.end_x = rayc->render.width / 2 + rayc->render.screen_x;
	if (rayc->render.end_x >= rayc->width_screen)
		rayc->render.end_x = rayc->width_screen - 1;
}

static void	render_sprite(t_rayc *rayc, t_data *data, t_vars *vars)
{
	int	i;
	int	x;

	i = 0;
    rayc->width_screen = ft_atoi(data->x);
    rayc->height_screen = ft_atoi(data->y);
	while (i < rayc->sprites)
	{
		aux_render_sprite(rayc, i, data);
		x = rayc->render.start_x;
		while (x < rayc->render.end_x && x < rayc->width_screen)
		{
			rayc->render.tex_x = (int)(256 * (x - (-rayc->render.width / 2 + rayc->render.screen_x)) * rayc->sprite[i].width / rayc->render.width) / 256;
			if (rayc->render.transform_y > 0)
				last_render_sprite(rayc, x, i, vars);
			x++;
		}
		i++;
	}
}

static void	sort_sprite(t_rayc *rayc)
{
	int	i;
	int	swap;

	i = 0;
	while (i + 1 < rayc->sprites)
	{
		if (rayc->sprite[rayc->sprite[i].order].distance < rayc->sprite[rayc->sprite[i + 1].order].distance)
		{
			swap = rayc->sprite[i].order;
			rayc->sprite[i].order = rayc->sprite[i + 1].order;
			rayc->sprite[i + 1].order = swap;
			sort_sprite(rayc);
		}
		i++;
	}
}

static void	sprite_distance(t_rayc *rayc)
{
	int	i;

	i = 0;
	while (i < rayc->sprites)
	{
		rayc->sprite[i].order = i;
		rayc->sprite[rayc->sprite[i].order].distance = \
        pow(rayc->posx - rayc->sprite[rayc->sprite[i].order].coord_x, 2) + \
        pow(rayc->posy - rayc->sprite[rayc->sprite[i].order].coord_y, 2);
		i++;
	}
}

void	ray_sprite(t_rayc *rayc, t_data *data, t_vars *vars)
{
	sprite_distance(rayc);
	sort_sprite(rayc);
	render_sprite(rayc, data, vars);
	free_sprite(rayc);
}