#include "cub3d.h"
#include "mlx/mlx.h"

void	move_left(t_vars *vars, int worldmap[vars->rc.mapwidth][vars->rc.mapheight])
{
	if (vars->mv.rot_left == 1)
	{
		vars->mv.old_dir_x = vars->rc.dirx;
		vars->rc.dirx = vars->rc.dirx * cos(-vars->mv.speed_rot) - vars->rc.diry * sin(-vars->mv.speed_rot);
		vars->rc.diry = vars->mv.old_dir_x * sin(-vars->mv.speed_rot) + vars->rc.diry * cos(-vars->mv.speed_rot);
		vars->mv.old_plan_x = vars->rc.planex;
		vars->rc.planex = vars->rc.planex * cos(-vars->mv.speed_rot) - vars->rc.planey * sin(-vars->mv.speed_rot);
		vars->rc.planey = vars->mv.old_plan_x * sin(-vars->mv.speed_rot) + vars->rc.planey * cos(-vars->mv.speed_rot);
	}
	if (vars->mv.left == 1)
	{
		if (vars->worldmap[(int)(vars->rc.posy - vars->rc.planey * 0.06)][(int)(vars->rc.posx)] != '1' && vars->worldmap[(int)(vars->rc.posy - vars->rc.planey * 0.06)][(int)(vars->rc.posx)] != '2')
			vars->rc.posy -= vars->rc.planey * 0.06;
		if (vars->worldmap[(int)(vars->rc.posy)][(int)(vars->rc.posx - vars->rc.planex * 0.06)] != '1' && vars->worldmap[(int)(vars->rc.posy)][(int)(vars->rc.posx - vars->rc.planex * 0.06)] != '2')
			vars->rc.posx -= vars->rc.planex * 0.06;
	}
}

void	move_right(t_vars *vars, int worldmap[vars->rc.mapwidth][vars->rc.mapheight])
{
	if (vars->mv.rot_right == 1)
	{
		vars->mv.old_dir_x = vars->rc.dirx;
		vars->rc.dirx = vars->rc.dirx * cos(vars->mv.speed_rot) - vars->rc.diry * sin(vars->mv.speed_rot);
		vars->rc.diry = vars->mv.old_dir_x * sin(vars->mv.speed_rot) + vars->rc.diry * cos(vars->mv.speed_rot);
		vars->mv.old_plan_x = vars->rc.planex;
		vars->rc.planex = vars->rc.planex * cos(vars->mv.speed_rot) - vars->rc.planey * sin(vars->mv.speed_rot);
		vars->rc.planey = vars->mv.old_plan_x * sin(vars->mv.speed_rot) + vars->rc.planey * cos(vars->mv.speed_rot);
	}
	if (vars->mv.right == 1)
	{
		if (vars->worldmap[(int)(vars->rc.posy)][(int)(vars->rc.planex * 0.06 + vars->rc.posx)] != '1' && vars->worldmap[(int)(vars->rc.posy)][(int)(vars->rc.planex * 0.06 + vars->rc.posx)] != '2')
			vars->rc.posx += vars->rc.planex * 0.06;
		if (vars->worldmap[(int)(vars->rc.posy + vars->rc.planey * 0.06)][(int)(vars->rc.posx)] != '1' && vars->worldmap[(int)(vars->rc.posy + vars->rc.planey * 0.06)][(int)(vars->rc.posx)] != '2')
			vars->rc.posy += vars->rc.planey * 0.06;
	}
}

void	move_down(t_vars *vars, int worldmap[vars->rc.mapwidth][vars->rc.mapheight])
{
	if (vars->mv.down == 1)
	{
		if (vars->worldmap[(int)(vars->rc.posy)][(int)(vars->rc.posx - vars->rc.dirx * 0.06)] != '1' && vars->worldmap[(int)(vars->rc.posy)][(int)(vars->rc.posx - vars->rc.dirx * 0.06)] != '2')
			vars->rc.posx -= vars->rc.dirx * 0.06;
		if (vars->worldmap[(int)(vars->rc.posy - vars->rc.diry * 0.06)][(int)(vars->rc.posx)] != '1' && vars->worldmap[(int)(vars->rc.posy - vars->rc.diry * 0.06)][(int)(vars->rc.posx)] != '2')
			vars->rc.posy -= vars->rc.diry * 0.06;
	}
}

void	move_up(t_vars *vars, int worldmap[vars->rc.mapwidth][vars->rc.mapheight])
{
	if (vars->mv.up == 1)
	{
		if (vars->worldmap[(int)(vars->rc.posy)][(int)(vars->rc.posx + vars->rc.dirx * 0.06)] != '1' && vars->worldmap[(int)(vars->rc.posy)][(int)(vars->rc.posx + vars->rc.dirx * 0.06)] != '2')
			vars->rc.posx += vars->rc.dirx * 0.06;
		if (vars->worldmap[(int)(vars->rc.posy + vars->rc.diry * 0.06)][(int)(vars->rc.posx)] != '1' && vars->worldmap[(int)(vars->rc.posy + vars->rc.diry * 0.06)][(int)(vars->rc.posx)] != '2')
			vars->rc.posy += vars->rc.diry * 0.06;
	}
}