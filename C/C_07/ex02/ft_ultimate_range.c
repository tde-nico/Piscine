/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 08:45:24 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/09 10:17:54 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*ptr;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	ptr = malloc((max - min) * sizeof(*ptr));
	if (ptr != NULL)
	{
		while (min < max)
		{
			ptr[i] = min;
			min++;
			i++;
		}
	}
	else
		return (-1);
	*range = ptr;
	return (i);
}
