/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 08:34:20 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/08 11:55:21 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t						count;
	unsigned const char			*s1;
	unsigned char				*s2;

	s1 = src;
	s2 = dest;
	count = 0;
	while (n-- > 0)
	{
		s2[count] = s1[count];
		if (s1[count] == (unsigned char)c)
			return (dest + count + 1);
		count++;
	}
	return (NULL);
}
