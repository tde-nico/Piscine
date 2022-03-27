/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:24:35 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/16 14:56:51 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*temp;
	t_list	*prev;
	t_list	*cur;

	if (!*begin_list || !(*begin_list)->next)
		return ;
	prev = *begin_list;
	cur = prev->next;
	prev->next = 0;
	while (cur->next)
	{
		temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}
	cur->next = prev;
	*begin_list = cur;
}
