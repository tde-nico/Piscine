/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:29:35 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/16 09:23:32 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*list;
	t_list	*temp;

	list = *begin_list;
	while (list && list->next)
	{
		if (!((*cmp)(list->next->data, data_ref)))
		{
			temp = list->next;
			list->next = list->next->next;
			(*free_fct)(temp->data);
			free(temp);
		}
		list = list->next;
	}
	list = *begin_list;
	if (list && !((*cmp)(list->data, data_ref)))
	{
		*begin_list = list->next;
		(*free_fct)(list->data);
		free(list);
	}
}
