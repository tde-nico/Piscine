/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:23:06 by tde-nico          #+#    #+#             */
/*   Updated: 2021/11/29 08:45:40 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp_int;
	int	i;
	int	j;
	int	control;

	i = 0;
	control = size - 1;
	while (i < control)
	{
		j = 0;
		while (j < control)
		{
			if (tab[j] > tab[j + 1])
			{
				temp_int = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = temp_int;
			}
			j++;
		}
		i++;
	}
}
