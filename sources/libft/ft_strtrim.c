/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:47:20 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/08 11:52:48 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_set(char c, const char *set)
{
	size_t i;
	size_t size_set;

	i = 0;
	size_set = ft_strlen(set);
	while (i <= size_set)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	start = 0;
	end = 0;
	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	while (check_set(s1[start], set))
		start++;
	while (check_set(s1[end], set) && end >= 0)
		end--;
	if (end < start)
	{
		return (ft_strdup(""));
	}
	str = (char *)malloc(end - start + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 2);
	return (str);
}
