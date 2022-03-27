/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:21:32 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/16 14:55:16 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*res;
	t_list	*temp;
	int		i;

	res = 0;
	i = -1;
	while (++i < size)
	{
		temp = res;
		res = ft_create_elem(strs[i]);
		res->next = temp;
	}
	return (res);
}
