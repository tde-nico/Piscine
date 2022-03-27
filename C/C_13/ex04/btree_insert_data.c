/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:54:27 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/16 15:01:31 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item);

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, (*root)->item) < 0)
	{
		if (!(*root)->left)
		{
			(*root)->left = btree_create_node(item);
			return ;
		}
		btree_insert_data(&(*root)->left, item, cmpf);
	}
	else
	{
		if (!(*root)->right)
		{
			(*root)->right = btree_create_node(item);
			return ;
		}
		btree_insert_data(&(*root)->right, item, cmpf);
	}
}
