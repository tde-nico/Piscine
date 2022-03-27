/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 08:26:18 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/01 08:26:21 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	j;

	argc--;
	while (argc > 0)
	{
		j = 0;
		while (argv[argc][j] != '\0')
		{
			ft_putchar(argv[argc][j]);
			j++;
		}
		ft_putchar('\n');
		argc--;
	}
	return (0);
}
