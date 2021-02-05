/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:14:24 by dsantama          #+#    #+#             */
/*   Updated: 2021/02/05 13:14:50 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <math.h>

typedef struct		s_data
{
	char				*r;
	char				*no;
	char				*texture_no;
	char				*so;
	char				*texture_so;
	char				*we;
	char				*texture_we;
	char				*ea;
	char				*texture_ea;
	char				*s;
	char				*texture_sprite;
	char				*f;
	char				*c;
	char				*x;
	char				*y;
	int					swapx;
	int					swapy;
	int					elements;
	int					error;
}					t_data;

typedef struct		s_colors
{
	char			*r_f;
	char			*g_f;
	char			*b_f;
	char			*r_c;
	char			*g_c;
	char			*b_c;
}					t_colors;

typedef struct	s_rendering
{
	double	x;
	double	y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int		screen_x;
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	int		tex_x;
	int		tex_y;
	int		height;
	int		width;
	double	*dist_wall;
}				t_rendering;

typedef struct	s_sprite
{
	int		order;
	double	distance;
	double	coord_x;
	double	coord_y;
	void	*img_ptr;
	int		*get_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	int		color;
}				t_sprite;

typedef struct	s_texture
{
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		*get_data;
	int		width;
	int		height;
}				t_texture;

typedef struct		s_rayc
{
	t_texture		north;
	t_texture		south;
	t_texture		east;
	t_texture		west;
	t_sprite		*sprite;
	t_rendering		render;
	char			direction;
	int				sprites;
	unsigned int	color_roof;
	unsigned int	color_floor;
	int				width_screen;
	int				height_screen;
	int				mapheight;
	int				mapwidth;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			*dist_wall;
	double			perpwalldist;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			camerax;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			raydirx;
	double			raydiry;
	double			planex;
	double			planey;
	double			time;
	double			oldtime;
	unsigned int	color;
}					t_rayc;

typedef struct		s_vars
{
	t_rayc			rc;
	void			*mlx;
	void			*win;
	int				screen_width;
	int				screen_height;
	void			*img;
    char			*addr;
	void			*img_ptr;
	int				*get_data;
	void			*new_image;
    int				bits_per_pixel;
    int				size_line;
	int				endian;
	int				width;
	int				height;
}					t_vars;

typedef struct		s_parse
{
	char			*map;
}					t_parse;

void				free_sprite(t_vars *vars);
void				last_render_sprite(int x, int i, t_vars *vars);
void				ray_sprite(t_vars *vars);
t_vars 				*tresolution(t_vars *vars, t_data *data);
void				set_texture(int x, int height, t_vars *vars);
void				rayprint(int height, t_vars *vars, int x);
t_vars				*init_frame(t_vars *vars, int worldmap[vars->rc.mapwidth][vars->rc.mapheight]);
t_vars				*init_textures(t_data *data, t_vars *vars);
t_vars				*orientation(t_vars *vars);
int					inwindow(t_vars *vars, t_data *data,
int worldmap[vars->rc.mapwidth][vars->rc.mapheight]);
int					get_next_line(int fd, char **line);
int					analyze_map(t_data *data, t_parse *parse);
void				error_colors(t_colors *colors, t_data *data);
void				error_map(t_parse *parse, t_data *data);
t_vars				*worldmap(t_colors *colors, t_vars *vars, t_parse *parse,
t_data *data);
int					read_map_cub(char *path);
void 				ray_starts(t_vars *vars, int worldmap[vars->rc.mapwidth][vars->rc.mapheight]);
int					initialize(t_colors *colors, t_parse *parse, t_data *data);
int					start(t_data *data, t_rayc *rayc);
#endif
