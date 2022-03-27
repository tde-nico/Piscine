/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:55:29 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/16 10:17:09 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*node;

	if (!root)
		return (0);
	node = btree_search_item(root->left, data_ref, cmpf);
	if (node)
		return (node);
	if (!cmpf(root->item, data_ref))
		return (root->item);
	node = btree_search_item(root->right, data_ref, cmpf);
	if (node)
		return (node);
	return (0);
}
