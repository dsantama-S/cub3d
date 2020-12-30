/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 10:55:05 by dsantama          #+#    #+#             */
/*   Updated: 2020/12/30 10:31:58 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				error_colors(t_colors *colors, t_data *data)
{
	if (ft_atoi(colors->r_f) > 255 || ft_atoi(colors->r_f) < 0 ||
	ft_atoi(colors->g_f) > 255 || ft_atoi(colors->g_f) < 0 ||
	ft_atoi(colors->b_f) > 255 || ft_atoi(colors->b_f) < 0 ||
	ft_atoi(colors->r_c) > 255 || ft_atoi(colors->r_c) < 0 ||
	ft_atoi(colors->g_c) > 255 || ft_atoi(colors->g_c) < 0 ||
	ft_atoi(colors->b_c) > 255 || ft_atoi(colors->b_c) < 0)
	{
		write(1, "Error: : Revise que los colores se encuentren dentro ", 53);
		write(1, "del rango RGB completo(0 - 255).\n", 33);
		data->error = -1;
	}
	if (data->texture_so[1] != 'e' || data->texture_no[1] != 'e' ||
	data->texture_we[1] != 'e' || data->texture_ea[1] != 'e' ||
	data->texture_sprite[1] != 'e')
	{
		write(1, "Error: : Revise que las texturas se encuentren ", 48);
		write(1, "en la carpeta “textures”.\n", 30);
		data->error = -1;
	}
}

void				error_map(t_parse *parse)
{
	if (parse){}
}
