/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:16:29 by dsantama          #+#    #+#             */
/*   Updated: 2020/11/26 11:30:31 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int read_map_cub(int fd)
{
	char c;
	char *path;
	
	path = "../maps/map_test.cub";
	fd = open(path ,O_RDONLY);
	if(fd != -1)
	{
		while(read(fd, &c, sizeof(c)!= 0))
		{	
			printf("%c",c);
		}
	}
	return 0;
}