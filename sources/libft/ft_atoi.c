/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 11:40:57 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/08 11:49:12 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int		signo;
	int		c;
	int		numero;

	signo = 1;
	c = 0;
	while (s[c] == ' ' || s[c] == '\n' || s[c] == '\t' \
	|| s[c] == '\v' || s[c] == '\f' || s[c] == '\r')
		c++;
	if (s[c] == '-' || s[c] == '+')
	{
		if (s[c] == '-')
			signo *= -1;
		c++;
	}
	numero = 0;
	while (s[c] >= '0' && s[c] <= '9')
	{
		numero = (numero * 10) + (s[c] - 48);
		c++;
	}
	return (numero * signo);
}
