/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raykeys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:23:05 by dsantama          #+#    #+#             */
/*   Updated: 2021/01/28 13:46:38 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

void skyline(t_vars vars, t_data *data, int x, t_rayc *rayc)
{
	int				horizontal;
	unsigned char	*s;
	
	horizontal =  ft_atoi(data->y) / 2;
    if (horizontal > rayc->drawstart)
		horizontal = rayc->drawstart;
	s = (unsigned char	*)vars.img_ptr;
	s += x * 4;
	while (horizontal-- >= 0)
    {
		s[0] = colors->b_c;
		s[1] = colors->g_c;
		s[2] = colors->r_c;
		s[3] = 0;
		s += vars.line_length;
    }
}
