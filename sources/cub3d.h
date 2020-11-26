/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:14:24 by dsantama          #+#    #+#             */
/*   Updated: 2020/11/26 11:03:32 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct  s_data {
    int     width;
    int     height;
}               t_data;

int			get_next_line(int fd, char **line);
int			read_map_cub(int fd);