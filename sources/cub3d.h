/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:14:24 by dsantama          #+#    #+#             */
/*   Updated: 2021/05/06 09:57:09 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

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

typedef struct		s_rendering
{
	double			x;
	double			y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				screen_x;
	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;
	int				tex_x;
	int				tex_y;
	int				height;
	int				width;
	double			*dist_wall;
}					t_rendering;

typedef struct		s_sprite
{
	int				order;
	double			distance;
	double			coord_x;
	double			coord_y;
	void			*img_ptr;
	int				*get_data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	int				color;
}					t_sprite;

typedef struct		s_texture
{
	void			*img_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				*get_data;
	int				width;
	int				height;
}					t_texture;

typedef struct		s_movement
{
	int				up;
	int				up_speed;
	int				down;
	int				right;
	int				left;
	int				rot_right;
	int				rot_left;
	double			old_dir_x;
	double			old_plan_x;
	double			speed_rot;
}					t_movement;

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
	char			*texture_so;
	char			*texture_no;
	char			*texture_we;
	char			*texture_ea;
	char			*texture_sprite;
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
	unsigned int	color;
	unsigned int	colortex;
}					t_rayc;

typedef struct		s_vars
{
	t_rayc			rc;
	t_movement		mv;
	int				*worldmap;
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
	int				*wmap;
}					t_vars;

typedef struct		s_parse
{
	char			error;
	char			*map;
}					t_parse;

void				free_sprite(t_vars *vars);
void				last_render_sprite(int x, int i, t_vars *vars);
void				ray_sprite(t_vars *vars);
t_vars				*tresolution(t_vars *vars, t_data *data);
void				set_texture(int x, t_vars *vars);
void				rayprint(int y, t_vars *vars, int x);
void				init_frame(t_vars *vars);
void				init_textures(t_vars *vars);
t_vars				*orientation(t_vars *vars);
int					inwindow(t_vars *vars);
int					get_next_line(int fd, char **line);
int					analyze_map(t_data *data, t_parse *parse);
void				error_colors(t_colors *colors, t_data *data);
void				error_wall_y(t_parse *parse, int y, int n, t_vars *vars);
void				error_wall_x(t_parse *parse, int n, int x, t_vars *vars);
void				error_map(t_parse *parse, t_data *data);
t_vars				*worldmap(t_colors *colors, t_vars *vars, t_parse *parse,
t_data *data);
void				error_num_r(t_data *data);
void				error_num_c(t_colors *colors, t_data *data);
void				error_text(t_data *data);
int					movement(t_vars *vars);
void				init_values(t_vars *vars, t_data *data);
int					read_map_cub(char *path);
int					key_press(int keycode, t_vars *vars);
int					key_release(int keycode, t_vars *vars);
int					key_exit(t_vars *vars);
void				move_left(t_vars *vars);
void				move_right(t_vars *vars);
void				move_down(t_vars *vars);
void				move_up(t_vars *vars);
void				move_rot_left(t_vars *vars);
void				move_rot_right(t_vars *vars);
void				ray_starts(t_vars *vars);
void				set_sprites(t_vars *vars);
int					mapzeros(t_vars *vars, int x, int y);
void				aux_render_sprite2(t_vars *vars);
int					initialize(t_colors *colors, t_parse *parse, t_data *data);
int					start(t_data *data, t_rayc *rayc);
void				invalid(t_parse *parse);
#endif
