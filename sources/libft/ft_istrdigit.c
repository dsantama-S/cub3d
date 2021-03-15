/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istrdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:49:07 by dsantama          #+#    #+#             */
/*   Updated: 2021/03/15 09:58:45 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_istrdigit(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (!(ft_isdigit(str[i])))
			{
				return (-1);
				break ;
			}
		i++;
	}
	return (1);
}
