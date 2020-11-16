/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 09:26:08 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/08 11:35:01 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		size;

	size = ft_strlen(src);
	dest = (char *)malloc(size + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, src, size + 1);
	return (dest);
}
