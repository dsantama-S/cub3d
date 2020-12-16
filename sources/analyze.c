/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:15:41 by dsantama          #+#    #+#             */
/*   Updated: 2020/12/16 11:11:19 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		resolution_p(int n, int n2, int x, t_data *data)
{
	char	str[sizeof(data->r)];
	char	str2[sizeof(data->r) - 1];

	while (data->r[n] != '\0')
	{
		if ((data->r[n] >= '0' && data->r[n] <= '9') && x == 0)
		{
			while (data->r[n] != (data->r[n] >= '0' && data->r[n] <= '9')
			&& n <= 5)
				str[n2++] = data->r[n++];
			data->x = str;
			n2 = 0;
			x = 1;
		}
		if ((data->r[n] >= '0' && data->r[n] <= '9') && x != 0)
		{
			while (data->r[n] != (data->r[n] >= '0' && data->r[n] <= '9'))
				str2[n2++] = data->r[n++];
			data->y = str2;
		}
		n++;
	}
}

static int		resolution(t_data *data)
{
	int		n;
	int		n2;
	int		x;

	n = 0;
	n2 = 0;
	x = 0;
	resolution_p(n, n2, x, data);
	return (0);
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

static void		colors_fc(t_data *data, t_colors *colors)
{
	char *str;
	char *str2;
	
	str = ft_strnchr(data->f, ',', 2);
	str++;
	colors->b_f = str;
	str2 = ft_strnchr(data->f, ',', 1);
	str2++;
	
	printf("%s\n", colors->b_f);
	printf("%s\n", str2);
	printf("%s\n", colors->g_f);
}

int				analyze_map(t_data *data)
{
	t_colors *colors;

	colors = ((t_colors *)malloc(sizeof(t_colors)));
	if (!colors)
		return (0);
	resolution(data);
	textures(data);
	colors_fc(data, colors);
	return (0);
}
