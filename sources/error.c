/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:23:58 by dsantama          #+#    #+#             */
/*   Updated: 2020/12/21 10:43:53 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		error_colors(t_colors *colors)
{
	if ((ft_atoi(colors->r_f) > 255) || (ft_strlen(colors->r_f) > 3) ||
	(ft_atoi(colors->g_f) > 255) || (ft_strlen(colors->g_f) > 3) ||
	(ft_atoi(colors->b_f) > 255) || (ft_strlen(colors->b_f) > 3))
		write(1, "Ha ocurrido un error en la configuración del mapa", 61);
	printf("%s\n", colors->r_f);
	printf("%s\n", colors->b_f);
}
