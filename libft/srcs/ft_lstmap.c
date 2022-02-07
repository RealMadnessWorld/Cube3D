/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:39:25 by jarsenio          #+#    #+#             */
/*   Updated: 2021/03/09 16:56:21 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nani;
	t_list	*head;

	head = NULL;
	nani = ft_lstnew(f(lst->content));
	while (lst)
	{
		if (!nani)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, nani);
		lst = lst->next;
	}
	return (head);
}
