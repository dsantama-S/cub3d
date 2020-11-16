/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 09:37:39 by dsantama          #+#    #+#             */
/*   Updated: 2020/08/27 09:38:05 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *start;

	start = (char *)malloc((size + 1) * sizeof(*start));
	if (!start)
		return (NULL);
	ft_bzero(start, size + 1);
	return (start);
}
