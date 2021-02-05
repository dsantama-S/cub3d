#include "cub3d.h"
#include "mlx/mlx.h"

void        free_sprite(t_rayc *rayc)
{
	if (rayc->render.dist_wall)
	{
		free(rayc->render.dist_wall);
		rayc->render.dist_wall = NULL;
	}
}

static void get_color(t_rayc *rayc, int i)
{
	if (rayc->render.tex_y > 0)
	{
		if (rayc->sprite[i].get_data[rayc->render.tex_x + rayc->render.tex_y * rayc->sprite[i].width] != 0)
			rayc->sprite[i].color = rayc->sprite[i].get_data[rayc->render.tex_x + rayc->render.tex_y * rayc->sprite[i].width];
		else
			rayc->sprite[i].color = 0xBFD195;
	}
}

void        last_render_sprite(t_rayc *rayc, int x, int i, t_vars *vars)
{
	int	y;
	int	d;

	y = rayc->render.start_y;
	while (y < rayc->render.end_y)
	{
		d = (y * 256 - rayc->height_screen * 128 + rayc->render.height * 128);
		rayc->render.tex_y = (d * rayc->sprite[i].height / rayc->render.height) / 256;
		get_color(rayc, i);
		if (rayc->sprite[i].color != 0xBFD195 && rayc->render.transform_y < rayc->render.dist_wall[x])
		{
			if (x >= 0 && x < rayc->width_screen && y >= 0 && y < rayc->height_screen)
			{
				vars->get_data[x + y * (vars->line_length / 4)] = rayc->sprite[i].color;
			}
		}
		y++;
	}
}