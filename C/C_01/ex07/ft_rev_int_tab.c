/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:22:05 by tde-nico          #+#    #+#             */
/*   Updated: 2021/11/29 08:22:08 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp_int;
	int	i;

	i = 0;
	size -= 1;
	while (i < size)
	{
		temp_int = tab[size];
		tab[size] = tab[i];
		tab[i] = temp_int;
		size--;
		i++;
	}
}
