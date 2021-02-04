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

t_rayc *orientation(t_rayc *rayc)
{
	if (rayc->direction == 'N')
	{
		rayc->dirx = 0;
		rayc->diry = -1;
	}
	if (rayc->direction == 'S')
	{
		rayc->dirx = 0;
		rayc->diry = 1;
	}
	if (rayc->direction == 'W')
	{
		rayc->dirx = -1;
		rayc->diry = 0;
	}
	if (rayc->direction == 'E')
	{
		rayc->dirx = 1;
		rayc->diry = 0;
	}
	rayc->planex = -0.66 * rayc->diry;
	rayc->planey = 0.66 * rayc->dirx;
	return (rayc);
}