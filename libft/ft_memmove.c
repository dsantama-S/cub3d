/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:37:41 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/08 11:09:39 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t				count;
	unsigned char		*dest;
	const unsigned char	*src;

	if (!s1 && !s2)
		return (NULL);
	dest = (unsigned char*)s1;
	src = (unsigned char*)s2;
	count = 0;
	if (dest > src)
		while (++count <= n)
			dest[n - count] = src[n - count];
	else
		while (n-- > 0)
			*(dest++) = *(src++);
	return (s1);
}
