#include "cub3d.h"
#include "mlx/mlx.h"

static t_rayc	*put_sprite(char *root_sprite, t_rayc *rayc, int i, t_vars *vars)
{
	if (!(rayc->sprite[i].img_ptr = mlx_xpm_file_to_image(vars->mlx, root_sprite,
    &rayc->sprite[i].width, &rayc->sprite[i].height)))
		printf("Something wrong in sprite\n");
	if (!(rayc->sprite[i].get_data = (int *)mlx_get_data_addr(rayc->sprite[i].img_ptr, &rayc->sprite[i].bits_per_pixel,
     &rayc->sprite[i].size_line, &rayc->sprite[i].endian)))
		printf("Something wrong in sprite\n");
	return (rayc);
}
static t_texture	put_texture(char *root_texture, t_vars *vars)
{
    t_texture	texture;

	if (!(texture.img_ptr = mlx_xpm_file_to_image(vars->mlx, root_texture, &texture.width, &texture.height)))
		printf("Something wrong in texture\n");
	if (!(texture.get_data = (int *)mlx_get_data_addr(texture.img_ptr, &texture.bits_per_pixel, &texture.size_line, &texture.endian)))
		printf("Something wrong in texture\n");
	return (texture);
}

static t_texture	texture_wall(t_rayc *rayc)
{
	if (rayc->side == 0 && rayc->raydirx > 0)
		return (rayc->east);
	else if (rayc->side == 0 && rayc->raydirx < 0)
		return (rayc->west);
	else if (rayc->side == 1 && rayc->raydiry > 0)
		return (rayc->south);
	else
		return (rayc->north);
}

t_rayc *init_textures(t_rayc *rayc, t_data *data, t_vars *vars)
{
    int i;

    rayc->north = put_texture(data->texture_no, vars);
    rayc->south = put_texture(data->texture_so, vars);
    rayc->east = put_texture(data->texture_ea, vars);
    rayc->west = put_texture(data->texture_we, vars);
    i = -1;
    while (++i < rayc->sprites)
        rayc = put_sprite(data->texture_sprite, rayc, i, vars);
    return (rayc);
}

void	set_texture(t_rayc *rayc, int x, int height, t_vars *vars)
{
	double		wall_x;
	int			tex_x;
	int			tex_y;
	int			y;
	t_texture	tex_wall;

	tex_wall = texture_wall(env);
	if (rayc->side == 0)
		wall_x = rayc->posy + rayc->perpwalldist * rayc->raydiry;
	else
		wall_x = rayc->posx + rayc->perpwalldist * rayc->raydiry;
	wall_x -= floor(wall_x);
	tex_x = wall_x * (double)tex_wall.width;
	y = rayc->drawstart;
	while (y++ < rayc->drawend)
	{
		tex_y = (y - height / 2 + rayc->lineheight / 2) * tex_wall.height / rayc->lineheight;
		if (tex_y < 0)
			return ;
		vars->get_data[x + y * (vars->line_length / 4)] = tex_wall.get_data[tex_x + tex_y * tex_wall.width];
	}
}