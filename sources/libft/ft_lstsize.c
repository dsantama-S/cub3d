/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 08:24:50 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/09 09:43:13 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*aux;

	aux = lst;
	count = 0;
	while (aux)
	{
		aux = aux->next;
		count++;
	}
	return (count);
}
