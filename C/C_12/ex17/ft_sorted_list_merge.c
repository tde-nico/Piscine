/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:35:19 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/16 15:14:37 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_list_swap(t_list *list)
{
	void	*data;

	data = list->data;
	list->data = list->next->data;
	list->next->data = data;
}

void	ft_list_sor(t_list **begin_list, int (*cmp)())
{
	t_list	*a;
	t_list	*b;

	a = *begin_list;
	while (a != NULL)
	{
		b = *begin_list;
		while (b->next != NULL)
		{
			if ((*cmp)(b->data, b->next->data) > 0)
				ft_list_swap(b);
			b = b->next;
		}
		a = a->next;
	}
}

void	ft_list_merge(t_list **begin_list, t_list *begin_list2)
{
	t_list	*list;

	if (begin_list == 0 || *begin_list == 0)
		*begin_list = begin_list2;
	else
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		list->next = begin_list2;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sor(begin_list1, cmp);
}
