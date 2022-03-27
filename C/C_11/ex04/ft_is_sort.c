/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:42:10 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/15 08:42:15 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		sort;

	sort = 1;
	i = 0;
	while (i < length - 1 && sort)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			sort = 0;
		i++;
	}
	if (sort != 1)
	{
		sort = 1;
		i = 0;
		while (i < length - 1)
		{
			if ((*f)(tab[i], tab[i + 1]) > 0)
				return (0);
			i++;
		}
	}
	return (1);
}
