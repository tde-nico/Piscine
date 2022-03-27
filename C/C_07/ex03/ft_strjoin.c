/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 08:45:42 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/09 16:51:28 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	len_str_join(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	if (size <= 0)
		return (0);
	i = 0;
	len = 0;
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		i++;
	}
	return (len + (size - 1) * ft_strlen(sep));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str_join;
	int		len;

	i = 0;
	len = len_str_join(size, strs, sep);
	str_join = malloc(sizeof(char) * (len + 100));
	if (!str_join)
		return (NULL);
	while (i < len)
		str_join[i++] = 0;
	str_join[len] = '\0';
	if (!size)
		return (str_join);
	i = 0;
	while (i < size)
	{
		ft_strcat(str_join, strs[i]);
		if (i < size - 1)
			ft_strcat(str_join, sep);
		i++;
	}
	return (str_join);
}
