/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:20:04 by dsantama          #+#    #+#             */
/*   Updated: 2021/03/15 10:51:37 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			error_num_r(t_data *data)
{
	if (ft_istrdigit(data->x) == -1 || ft_istrdigit(data->y) == -1)
		data->error = -1;
}

void			error_num_c(t_colors *colors, t_data *data)
{
	if (ft_istrdigit(colors->r_f) == -1 || ft_istrdigit(colors->r_c) == -1
	|| ft_istrdigit(colors->g_f) == -1 || ft_istrdigit(colors->g_f) == -1 ||
	ft_istrdigit(colors->b_f) == -1 || ft_istrdigit(colors->b_c) == -1)
		data->error = -1;
}

void			error_text(t_data *data)
{
	if (ft_strncmp(data->texture_ea, "textures/", 9) != 0 ||
	ft_strncmp(data->texture_so, "textures/", 9) != 0 ||
	ft_strncmp(data->texture_no, "textures/", 9) != 0 ||
	ft_strncmp(data->texture_we, "textures/", 9) != 0 ||
	ft_strncmp(data->texture_sprite, "textures/", 9) != 0)
		data->error = -1;
}
