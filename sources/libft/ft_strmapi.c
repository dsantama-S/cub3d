/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 09:42:43 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/09 09:41:06 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	int		size_s;

	if (!s)
		return (NULL);
	size_s = ft_strlen(s);
	str = (char *)malloc(size_s + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < size_s)
	{
		str[i] = f(i, s[i]);
	}
	str[i] = '\0';
	return (str);
}
