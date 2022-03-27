/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:33:26 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/16 08:33:45 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*begin;
	t_list	*end;
	void	*temp;

	end = 0;
	while (begin_list != end)
	{
		begin = begin_list;
		while (begin->next != end)
		{
			temp = begin->data;
			begin->data = begin->next->data;
			begin->next->data = temp;
			begin = begin->next;
		}
		end = begin;
	}
}
