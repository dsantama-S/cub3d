/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:14:24 by dsantama          #+#    #+#             */
/*   Updated: 2021/01/05 09:04:25 by dsantama         ###   ########.fr       */
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

typedef struct		s_rayc
{
	int				mapHeight;
	int				mapWidth;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			oldtime;
}					t_rayc;

typedef struct		s_vars
{
	void			*mlx;
	void			*win;
}					t_vars;

typedef struct		s_parse
{
	char			*map;
}					t_parse;

int					get_next_line(int fd, char **line);
int					analyze_map(t_data *data, t_parse *parse);
void				error_colors(t_colors *colors, t_data *data);
void				error_map(t_parse *parse, t_data *data);
int					read_map_cub(char *path);
int					initialize(t_colors *colors, t_parse *parse, t_data *data);
int					start(t_data *data, t_rayc *rayc);
#endif
