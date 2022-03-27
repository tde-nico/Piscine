/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 08:40:15 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/06 08:38:46 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	if ((base[0] == '\0') || (base[1] == '\0'))
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if ((base[i] == '-') || (base[i] == '+'))
			return (0);
		if ((base[i] < 32) || (base[i] > 126))
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	print_nums(long int nbr, char *base)
{
	int			base_size;
	int			size;
	long int	temp;

	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	size = 1;
	temp = nbr;
	while (temp > base_size)
	{
		size *= base_size;
		temp /= base_size;
	}
	while (size)
	{
		ft_putchar(base[nbr / size]);
		nbr %= size;
		size /= base_size;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	long_nbr;

	long_nbr = nbr;
	if (base_check(base))
	{
		if (long_nbr < 0)
		{
			ft_putchar('-');
			long_nbr = -long_nbr;
		}
		print_nums(long_nbr, base);
	}
}
