/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 08:30:00 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/09 09:12:23 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *head;

	while (*lst != '\0')
	{
		head = *lst;
		del((*lst)->content);
		*lst = ((*lst)->next);
		free(head);
	}
}
