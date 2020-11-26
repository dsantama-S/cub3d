/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:28:44 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/01 10:36:57 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	char			*s1;
	unsigned char	c2;

	s1 = (char *)s;
	c2 = c;
	while (*s1 != '\0')
	{
		if (*s1 == c2)
			return (s1);
		s1++;
	}
	if (*s1 == '\0' && c2 == '\0')
		return (s1);
	return (NULL);
}
