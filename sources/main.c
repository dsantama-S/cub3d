/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:44:08 by dsantama          #+#    #+#             */
/*   Updated: 2021/04/26 11:21:32 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	char *path;

	if (argc == 2)
	{
		path = argv[1];
		read_map_cub(path);
	}
	else
	{
		printf("*** Introduce correctamente el mapa ***\n");
		return (-1);
	}
}
