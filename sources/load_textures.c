#include "cub3d.h"
#include "mlx/mlx.h"

static t_vars	*put_sprite(char *root_sprite, int i, t_vars *vars)
{
	vars->rc.sprite[i].img_ptr = mlx_xpm_file_to_image(vars->mlx, root_sprite,
    &vars->rc.sprite[i].width, &vars->rc.sprite[i].height);
	vars->rc.sprite[i].get_data = (int *)mlx_get_data_addr(vars->rc.sprite[i].img_ptr, &vars->rc.sprite[i].bits_per_pixel,
    &vars->rc.sprite[i].size_line, &vars->rc.sprite[i].endian);
	return (vars);
}
static t_texture	put_texture(char *root_texture, t_vars *vars)
{
    t_texture	texture;
	
	texture.img_ptr = mlx_xpm_file_to_image(vars->mlx, root_texture, &texture.width, &texture.height);
	texture.get_data = (int *)mlx_get_data_addr(texture.img_ptr, &texture.bits_per_pixel, &texture.size_line, &texture.endian);
	return (texture);
}

static t_texture	texture_wall(t_vars *vars)
{
	if (vars->rc.side == 0 && vars->rc.raydirx > 0)
		return (vars->rc.east);
	else if (vars->rc.side == 0 && vars->rc.raydirx < 0)
		return (vars->rc.west);
	else if (vars->rc.side == 1 && vars->rc.raydiry > 0)
		return (vars->rc.south);
	else
		return (vars->rc.north);
}

void	init_textures(t_vars *vars, int worldmap[vars->rc.mapwidth][vars->rc.mapheight])
{
    int i;

    vars->rc.north = put_texture(vars->rc.texture_no, vars);
    vars->rc.south = put_texture(vars->rc.texture_so, vars);
    vars->rc.east = put_texture(vars->rc.texture_ea, vars);
    vars->rc.west = put_texture(vars->rc.texture_we, vars);
    i = -1;
    while (++i < vars->rc.sprites)
        vars = put_sprite(vars->rc.texture_sprite, i, vars);
    set_sprites(vars, worldmap);
}

void	set_texture(int x, int height, t_vars *vars)
{
	double		wall_x;
	int			tex_x;
	int			tex_y;
	int			y;
	t_texture	tex_wall;

	tex_wall = texture_wall(vars);
	if (vars->rc.side == 0)
		wall_x = vars->rc.posy + vars->rc.perpwalldist * vars->rc.raydiry;
	else
		wall_x = vars->rc.posx + vars->rc.perpwalldist * vars->rc.raydiry;
	wall_x -= floor(wall_x);
	tex_x = wall_x * (double)tex_wall.width;
	y = vars->rc.drawstart;
	while (y++ < vars->rc.drawend)
	{
		tex_y = (y - height / 2 + vars->rc.lineheight / 2) * tex_wall.height / vars->rc.lineheight;
		if (tex_y < 0)
			return ;
		vars->get_data[x + y * (vars->size_line / 4)] = tex_wall.get_data[tex_x + tex_y * tex_wall.width];
	}
}