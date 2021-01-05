/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:34:05 by dsantama          #+#    #+#             */
/*   Updated: 2021/01/05 11:47:33 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

static void		worldMap(t_rayc *rayc, t_parse *parse)
{
	int 	worldMap[rayc->mapWidth][rayc->mapHeight];
	int		x;
	int		y;
	int		n;

	x = 0;
	y = 0;
	n = 0;
	while (y < rayc->mapHeight)
	{
		while (x < rayc->mapWidth) //arreglar rayc->mapWidth para cuando el tamaño de x en la linea sea menor que mapwidht (ej 30 de x y estamos haciendo hasta 34)
		{
			worldMap[x][y] = parse->map[n];
			n++;
			x++;
		}
		x = 0;
		y++;
	}
	printf("%c\n", worldMap[1][4]);
}

int				start(t_data *data, t_rayc *rayc)
{
	t_vars		vars;
	
	rayc = ((t_rayc *)malloc(sizeof(t_rayc)));
	if (!rayc)
		return (0);
	rayc->dirx = -1;
	rayc->diry = 0;
	rayc->planex = 0;
	rayc->planey = 0.66;
	rayc->time = 0;
	rayc->oldtime = 0;
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, ft_atoi(data->x), ft_atoi(data->y), "Cub3d");
	mlx_loop(vars.mlx);
	return (0);
}

int					initialize(t_colors *colors, t_parse *parse, t_data *data)
{
	t_rayc	*rayc;
	int		n;
	int		y;
	int		x;

	y = 0;
	n = 0;
	x = 0;
	if (colors){}
	if (data){}
	rayc = ((t_rayc *)malloc(sizeof(t_rayc)));
	if (!rayc)
		return (0);
	rayc->mapWidth = 0;
	while (parse->map[n] != '\0')
	{
		if (parse->map[n] == '\n')
		{
			if (x > rayc->mapWidth)
				rayc->mapWidth = x;
			y++;
			x = 0;
		}
		if (parse->map[n] == 'N' || parse->map[n] == 'S' ||
		parse->map[n] == 'E' || parse->map[n] == 'W')
		{
			rayc->posy = y + 1;
			rayc->posx = x;
		}
		n++;
		x++;
	}
	rayc->mapHeight = y + 1;
	worldMap(rayc, parse);
	return (0);
}
