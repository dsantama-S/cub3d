/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:14:24 by dsantama          #+#    #+#             */
/*   Updated: 2020/12/15 13:14:08 by dsantama         ###   ########.fr       */
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
	char				*so;
	char				*texture_so;
	char				*we;
	char				*ea;
	char				*s;
	char				*f;
	char				*c;
	char				*map;
	char				*x;
	char				*y;
	int					elements;
}					t_data;

int					get_next_line(int fd, char **line);
void				analyze_map(t_data *data);
int					read_map_cub(char *path);
#endif
