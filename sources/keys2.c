#include "cub3d.h"
#include "mlx/mlx.h"

void	move_left(t_vars *vars)
{
	if (vars->mv.left == 1)
	{
		if (vars->worldmap[(int)(vars->rc.posx) * (int)(vars->rc.posy - vars->rc.planey * 0.06)] != '1' \
		&& vars->worldmap[(int)(vars->rc.posx) * (int)(vars->rc.posy - vars->rc.planey * 0.06)] != '2')
			vars->rc.posy -= vars->rc.planey * 0.06;
		if (vars->worldmap[(int)(vars->rc.posx - vars->rc.planex * 0.06) * (int)(vars->rc.posy)] != '1' \
		&& vars->worldmap[(int)(vars->rc.posx - vars->rc.planex * 0.06) * (int)(vars->rc.posy)] != '2')
			vars->rc.posx -= vars->rc.planex * 0.06;
	}
}

void	move_right(t_vars *vars)
{
	if (vars->mv.right == 1)
	{
		if (vars->worldmap[(int)(vars->rc.planex * 0.06 + vars->rc.posx) * (int)(vars->rc.posy)] != '1' \
		&& vars->worldmap[(int)(vars->rc.planex * 0.06 + vars->rc.posx) * (int)(vars->rc.posy)] != '2')
			vars->rc.posx += vars->rc.planex * 0.06;
		if (vars->worldmap[(int)(vars->rc.posx) * (int)(vars->rc.posy + vars->rc.planey * 0.06)] != '1' \
		&& vars->worldmap[(int)(vars->rc.posx) * (int)(vars->rc.posy + vars->rc.planey * 0.06)] != '2')
			vars->rc.posy += vars->rc.planey * 0.06;
	}
}

void	move_down(t_vars *vars)
{
	if (vars->mv.down == 1)
	{
		if (vars->worldmap[(int)(vars->rc.posx - vars->rc.dirx * 0.06) * (int)(vars->rc.posy)] != '1' \
		&& vars->worldmap[(int)(vars->rc.posx - vars->rc.dirx * 0.06) * (int)(vars->rc.posy)] != '2')
			vars->rc.posx -= vars->rc.dirx * 0.06;
		if (vars->worldmap[(int)(vars->rc.posx) * (int)(vars->rc.posy - vars->rc.diry * 0.06)] != '1' \
		&& vars->worldmap[(int)(vars->rc.posx) * (int)(vars->rc.posy - vars->rc.diry * 0.06)] != '2')
			vars->rc.posy -= vars->rc.diry * 0.06;
	}
}

void	move_up(t_vars *vars)
{
	if (vars->mv.up == 1)
	{
		if (vars->worldmap[(int)(vars->rc.posx + vars->rc.dirx * 0.06) * (int)(vars->rc.posy)] != '1' \
		&& vars->worldmap[(int)(vars->rc.posx + vars->rc.dirx * 0.06) * (int)(vars->rc.posy)] != '2')
			vars->rc.posx += vars->rc.dirx * 0.06;
		if (vars->worldmap[(int)(vars->rc.posx) * (int)(vars->rc.posy + vars->rc.diry * 0.06)] != '1' \
		&& vars->worldmap[(int)(vars->rc.posx) * (int)(vars->rc.posy + vars->rc.diry * 0.06)] != '2')
			vars->rc.posy += vars->rc.diry * 0.06;
	}
}
