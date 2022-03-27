/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:34:09 by tde-nico          #+#    #+#             */
/*   Updated: 2021/11/25 16:50:48 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	evaluate_comb(int *table, int size)
{
	int	index;
	int	grow;

	index = 1;
	grow = 1;
	while (index < size)
	{
		if (table[index - 1] >= table[index])
			grow = 0;
		index++;
	}
	if (grow)
	{
		index = 0;
		while (index < size)
			ft_putchar(table[index++] + 48);
		if (table[0] < (10 - size))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_print_combn(int n)
{
	int	index;
	int	table[10];

	index = 0;
	while (index < n)
		table[index++] = 0;
	while (table[0] <= (10 - n))
	{
		evaluate_comb(table, n);
		table[n - 1]++;
		index = n;
		while (index && n > 1)
		{
			index--;
			if (table[index] > 9)
			{
				table[index - 1]++;
				table[index] = 0;
			}
		}
	}
}
