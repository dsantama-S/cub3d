/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:15:41 by dsantama          #+#    #+#             */
/*   Updated: 2020/12/21 11:14:21 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		resolution(t_data *data)
{
	char	*str;
	char	*str2;
	char	aux[5];
	int		n;

	n = 0;
	str = ft_strnchr(data->r, ' ', 1);
	str++;
	while (str[n] != ' ')
	{
		aux[n] = str[n];
		n++;
	}
	data->x = aux;
	str2 = ft_strnchr(data->r, ' ', 2);
	str2++;
	data->y = str2;
}

static void		textures(t_data *data)
{
	char *str;
	char *str2;
	char *str3;
	char *str4;
	char *str5;

	str = ft_strchr(data->so, 't');
	str2 = ft_strchr(data->no, 't');
	str3 = ft_strchr(data->we, 't');
	str4 = ft_strchr(data->ea, 't');
	str5 = ft_strchr(data->s, 't');
	data->texture_so = str;
	data->texture_no = str2;
	data->texture_we = str3;
	data->texture_ea = str4;
	data->texture_sprite = str5;
}

static void		colors_f(int n, int n2, t_data *data, t_colors *colors)
{
	char	*str;
	char	*str2;
	char	*str3;
	char	*aux;
	char	*aux2;

	aux = ft_strnew(4);
	aux2 = ft_strnew(4);
	str = ft_strnchr(data->f, ',', 2);
	str++;
	colors->b_f = str;
	str2 = ft_strnchr(data->f, ',', 1);
	str2++;
	while (str2[n] != ',')
		aux[n2++] = str2[n++];
	n = 0;
	n2 = 0;
	colors->g_f = aux;
	str3 = ft_strnchr(data->f, ' ', 1);
	str3++;
	while (str3[n] != ',')
		aux2[n2++] = str3[n++];
	colors->r_f = aux2;
}

static void		colors_c(int n, int n2, t_data *data, t_colors *colors)
{
	printf("%i,%i\n", n, n2);
	printf("%s\n", data->x);
	printf("%s\n", colors->r_f);
	printf("%s\n", colors->b_f);
}
int				analyze_map(t_data *data)
{
	int n;
	int n2;

	n = 0;
	n2 = 0;
	t_colors *colors;

	colors = ((t_colors *)malloc(sizeof(t_colors)));
	if (!colors)
		return (0);
	resolution(data);
	textures(data);
	colors_f(n, n2, data, colors);
	colors_c(n, n2, data, colors);
	return (0);
}
