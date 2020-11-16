/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 08:24:01 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/08 10:41:30 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	char *ptr;

	ptr = (char *)malloc(size * number);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, number * size);
	return (ptr);
}
