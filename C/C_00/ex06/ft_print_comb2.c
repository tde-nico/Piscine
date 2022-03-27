/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:34:09 by tde-nico          #+#    #+#             */
/*   Updated: 2021/11/25 12:45:57 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display(int num)
{
	int	first;
	int	second;

	if (num > 9)
	{
		first = num / 10;
		second = num % 10;
		ft_putchar(first + 48);
		ft_putchar(second + 48);
	}
	else
	{
		ft_putchar('0');
		ft_putchar(num + 48);
	}
}

void	ft_print_comb2(void)
{
	int	number_1;
	int	number_2;

	number_1 = 0;
	while (number_1 <= 99)
	{
		number_2 = number_1 + 1;
		while (number_2 <= 99)
		{
			display(number_1);
			ft_putchar(' ');
			display(number_2);
			if (number_1 < 98 || number_2 < 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			number_2++;
		}
		number_1++;
	}
}
