/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:34:17 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/16 14:57:51 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*prev;
	t_list	*cur;

	if (!*begin_list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	if (cmp((*begin_list)->data, data) > 0)
	{
		cur = *begin_list;
		*begin_list = ft_create_elem(data);
		(*begin_list)->next = cur;
		return ;
	}
	prev = *begin_list;
	cur = prev->next;
	while (cur && (cmp(cur->data, data) < 0))
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = ft_create_elem(data);
	prev->next->next = cur;
}
