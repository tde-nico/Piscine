/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 08:45:07 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/09 10:16:23 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	if (min >= max)
		return (NULL);
	i = 0;
	range = malloc((max - min) * sizeof(*range));
	if (range != NULL)
	{
		while (min < max)
		{
			range[i] = min;
			min++;
			i++;
		}
	}
	return (range);
}
