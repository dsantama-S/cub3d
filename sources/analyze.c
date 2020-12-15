/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:15:41 by dsantama          #+#    #+#             */
/*   Updated: 2020/12/15 13:31:03 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int resolution(t_data *data)
{
	char	str[sizeof(data->r)];
	char	str2[sizeof(data->r) - 1];
	int		n;
	int		n2;
	int		x;

	n = 0;
	n2 = 0;
	x = 0;
	data->x = NULL;
	while (data->r[n] != '\0')
	{
		if ((data->r[n] >= '0' && data->r[n] <= '9') && x == 0)
		{
			while (data->r[n] != (data->r[n] >= '0' && data->r[n] <= '9') && n <= 5)
			{
				str[n2] = data->r[n];
				n++;
				n2++;
			}
			data->x = str;
			n2 = 0;
			x = 1;
		}
		if ((data->r[n] >= '0' && data->r[n] <= '9') && x != 0)
		{
			while (data->r[n] != (data->r[n] >= '0' && data->r[n] <= '9'))
			{
				str2[n2] = data->r[n];
				n++;
				n2++;
			}
			data->y = str2;
		}
		n++;
	}
	return (0);
}

static void texture_so(t_data *data)
{
	char	str[30];
	int 	n;
	int		n2;

	n = 0;
	n2 = 0;
	while (data->so[n] != '\0')
	{
		if (data->so[n] == 't')
		{
			while (data->so[n] != (data->r[n] >= 65 && data->r[n] <= 122))
			{
				str[n2] = data->so[n];
				printf("%c\n", str[n2]);
				n++;
				n2++;
			}
		}
		n++;
	}
	data->texture_so = str;
	printf("%s\n", data->texture_so);
	printf("%s\n", data->x);
	printf("%s\n", data->y);
}

void	analyze_map(t_data *data)
{
	resolution(data);
	texture_so(data);
}
