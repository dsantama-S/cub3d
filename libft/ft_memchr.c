/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:06:19 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/06 11:46:50 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*s1;
	unsigned char		c2;

	s1 = (unsigned char *)s;
	c2 = c;
	while (n-- > 0)
	{
		if (*s1 == c2)
			return (s1);
		s1++;
	}
	return (NULL);
}
