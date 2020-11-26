/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 10:44:33 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/09 09:27:32 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;
	size_t	n;

	n = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	while (*s1)
	{
		str[n] = *s1;
		n++;
		s1++;
	}
	while (*s2)
	{
		str[n] = *s2;
		n++;
		s2++;
	}
	str[n] = '\0';
	return (str);
}
