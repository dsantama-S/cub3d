/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:50:08 by dsantama          #+#    #+#             */
/*   Updated: 2020/12/16 10:35:36 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnchr(const char *s, int c, int n)
{
	int			i;
	int			num;

	i = 0;
	num = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (num == n)
				return ((char*)s + i);
			if (n < 1)
			{
				printf("******Error******");
				return (0);
			}
			num++;
		}
		i++;
	}
	return (0);
}
