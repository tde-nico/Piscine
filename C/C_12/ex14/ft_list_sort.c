/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:32:05 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/16 08:32:53 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		swapped;
	t_list	*ptr;
	void	*temp;

	if (!*begin_list)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr = *begin_list;
		while (ptr->next)
		{
			if (cmp(ptr->data, ptr->next->data) > 0)
			{
				swapped = 1;
				temp = ptr->data;
				ptr->data = ptr->next->data;
				ptr->next->data = temp;
			}
			ptr = ptr->next;
		}
	}
}
