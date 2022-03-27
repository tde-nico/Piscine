/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:18:10 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/16 13:42:31 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	left;
	int	right;

	if (!root)
		return (0);
	left = btree_level_count(root->left);
	right = btree_level_count(root->right);
	if (left < right)
		return (right + 1);
	return (left + 1);
}

void	apply(t_btree *root, int level, int *levels,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		first;

	first = 1;
	if (levels[level] == 1)
		first = 0;
	else
		levels[level] = 1;
	applyf(root->left, level, first);
	if (root->left)
		apply(root->left, level + 1, levels, applyf);
	if (root->right)
		apply(root->right, level + 1, levels, applyf);
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		count;
	int		*levels;
	int		i;

	if (root == 0)
		return ;
	count = ft_btree_level_count(root);
	levels = (int *)malloc(sizeof(int) * count);
	if (!levels)
		return ;
	i = -1;
	while (++i < count)
		levels[i] = 0;
	apply(root, 0, levels, applyf);
}
