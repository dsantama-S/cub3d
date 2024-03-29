/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:15:41 by dsantama          #+#    #+#             */
/*   Updated: 2021/05/06 09:57:34 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		resolution(t_data *data)
{
	char	*str2;
	char	aux[5];
	char	aux2[12];
	int		i;
	int		n;

	i = 0;
	n = 0;
	aux[4] = 0;
	aux2[11] = 0;
	while (i < 11)
	{
		aux2[i] = data->r[i];
		i++;
	}
	i = 2;
	while (aux2[i] != ' ' && aux2[i] != '\0')
		aux[n++] = aux2[i++];
	data->x = aux;
	str2 = ft_strnchr(aux2, ' ', 2);
	str2++;
	data->y = str2;
	error_num_r(data);
	data->swapx = ft_atoi(data->x);
	data->swapy = ft_atoi(data->y);
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
	char	aux[4];
	char	aux2[4];

	ft_bzero(aux, 4);
	ft_bzero(aux2, 4);
	str = ft_strnchr(data->f, ',', 2);
	str++;
	colors->b_f = str;
	str2 = ft_strnchr(data->f, ',', 1);
	str2++;
	while (str2[n] != ',' && str2[n] != '\0')
		aux[n2++] = str2[n++];
	n = 0;
	n2 = 0;
	colors->g_f = aux;
	str3 = ft_strnchr(data->f, ' ', 1);
	str3++;
	while (str3[n] != ',' && str3[n] != '\0')
		aux2[n2++] = str3[n++];
	colors->r_f = aux2;
}

static void		colors_c(int n, int n2, t_data *data, t_colors *colors)
{
	char	*str;
	char	*str2;
	char	*str3;
	char	*aux;
	char	*aux2;

	aux = ft_strdup("");
	ft_bzero(aux, 4);
	aux2 = ft_strdup("");
	str = ft_strnchr(data->c, ',', 2);
	str++;
	colors->b_c = str;
	str2 = ft_strnchr(data->c, ',', 1);
	str2++;
	while (str2[n] != ',' && n < 4 && str2[n] != '\0')
		aux[n2++] = str2[n++];
	n = 0;
	n2 = 0;
	colors->g_c = aux;
	str3 = ft_strnchr(data->c, ' ', 1);
	str3++;
	while (str3[n] != ',' && str3[n] != '\0')
		aux2[n2++] = str3[n++];
	colors->r_c = aux2;
}

int				analyze_map(t_data *data, t_parse *parse)
{
	int			n;
	int			n2;
	t_colors	*colors;

	n = 0;
	n2 = 0;
	colors = ((t_colors *)malloc(sizeof(t_colors)));
	if (!colors)
		return (0);
	resolution(data);
	textures(data);
	colors_f(n, n2, data, colors);
	colors_c(n, n2, data, colors);
	error_colors(colors, data);
	error_map(parse, data);
	error_num_c(colors, data);
	error_text(data);
	if (data->error == -1)
	{
		write(1, "Ha ocurrido un error en la configuración del mapa.\n", 52);
		return (-1);
	}
	initialize(colors, parse, data);
	return (0);
}
