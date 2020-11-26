/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 12:39:39 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/08 11:08:23 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*s1;
	const unsigned char	*s2;

	if (!dest && !src)
		return (NULL);
	s1 = (unsigned char*)dest;
	s2 = (unsigned char*)src;
	while (n-- > 0)
		*(s1++) = *(s2++);
	return (dest);
}
