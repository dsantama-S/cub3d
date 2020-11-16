/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 12:44:00 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/09 09:26:57 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	length_src;
	int		i;

	if (!dest || !src)
		return (0);
	length_src = ft_strlen(src);
	if (n != 0)
	{
		i = -1;
		if (length_src + 1 < n)
		{
			while (++i < (int)length_src)
				dest[i] = src[i];
		}
		else
		{
			while (++i < (int)n - 1)
				dest[i] = src[i];
		}
		dest[i] = '\0';
	}
	return (length_src);
}
