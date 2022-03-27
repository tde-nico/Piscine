/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:42:44 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/14 15:47:24 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strncpy(char *dest, char *src, int n)
{
	int		i;

	i = -1;
	while (++i < n && src[i])
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

char	*allocate(char *origin, char new_char, int old_len, int len)
{
	char	*dest;

	dest = malloc((len + 1) * sizeof(*dest));
	if (!dest)
		return (NULL);
	if (origin != NULL)
		ft_strncpy(dest, origin, old_len);
	ft_strncpy(dest + old_len, &new_char, len - old_len);
	if (origin != NULL)
		free(origin);
	return (dest);
}

int	ft_atoi(char *str, int n, int *res)
{
	int	i;

	i = 0;
	*res = 0;
	while (i < n)
	{
		if ('0' <= str[i] && str[i] <= '9')
			*res = *res * 10 + str[i] - '0';
		else
			return (0);
		i++;
	}
	return (1);
}

int	count_lines(t_map *map)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = map->source;
	while (*ptr)
	{
		if (*ptr == '\n')
			count++;
		ptr++;
	}
	return (count);
}
