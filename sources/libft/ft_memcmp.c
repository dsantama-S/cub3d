/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:57:29 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/01 11:23:28 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*primero;
	unsigned char		*segundo;
	size_t				count;

	primero = (unsigned char *)s1;
	segundo = (unsigned char *)s2;
	count = 0;
	while (count < n && primero[count] == segundo[count])
	{
		count++;
	}
	if (!(count == n))
		return (primero[count] - segundo[count]);
	return (primero[count - 1] - segundo[count - 1]);
}
