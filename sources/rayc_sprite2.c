#include "cub3d.h"
#include "mlx/mlx.h"

void        free_sprite(t_vars *vars)
{
	if (vars->rc.render.dist_wall)
	{
		free(vars->rc.render.dist_wall);
		vars->rc.render.dist_wall = NULL;
	}
}

static void get_color(t_vars *vars, int i)
{
	if (vars->rc.render.tex_y > 0)
	{
		if (vars->rc.sprite[i].get_data[vars->rc.render.tex_x + vars->rc.render.tex_y * vars->rc.sprite[i].width] != 0)
			vars->rc.sprite[i].color = vars->rc.sprite[i].get_data[vars->rc.render.tex_x + vars->rc.render.tex_y * vars->rc.sprite[i].width];
		else
			vars->rc.sprite[i].color = 0xBFD195;
	}
}

void        last_render_sprite(int x, int i, t_vars *vars)
{
	int	y;
	int	d;

	y = vars->rc.render.start_y;
	while (y < vars->rc.render.end_y)
	{
		d = (y * 256 - vars->screen_height * 128 + vars->rc.render.height * 128);
		vars->rc.render.tex_y = (d * vars->rc.sprite[i].height / vars->rc.render.height) / 256;
		get_color(vars, i);
		if (vars->rc.sprite[i].color != 0xBFD195 && vars->rc.render.transform_y < vars->rc.render.dist_wall[x])
		{
			if (x >= 0 && x < vars->screen_width && y >= 0 && y < vars->screen_height)
			{
				vars->get_data[x + y * (vars->size_line / 4)] = vars->rc.sprite[i].color;
			}
		}
		y++;
	}
}