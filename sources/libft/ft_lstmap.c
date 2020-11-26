/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 09:39:42 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/12 10:30:12 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*aux;

	if (!lst)
		return (NULL);
	lst2 = (t_list *)malloc(sizeof(t_list));
	if (!lst2)
		return (NULL);
	lst2 = ft_lstnew(f(lst->content));
	aux = lst2;
	while (lst->next)
	{
		lst = lst->next;
		if (!(aux->next = ft_lstnew(f(lst->content))))
		{
			del(aux->content);
			return (NULL);
		}
		aux = aux->next;
	}
	return (lst2);
}
