/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 08:45:22 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/01 09:01:50 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		size;

	size = 0;
	while (src[size] != '\0')
		size++;
	ptr = malloc(size * sizeof(*ptr) + 1);
	if (ptr != NULL)
		ft_strcpy(ptr, src);
	return (ptr);
}
