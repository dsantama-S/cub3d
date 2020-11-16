/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:50:08 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/08 11:42:40 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			n;

	n = 0;
	while (s[n])
	{
		n++;
	}
	while (n >= 0)
	{
		if (s[n] == c)
			return ((char*)s + n);
		n--;
	}
	return (NULL);
}
