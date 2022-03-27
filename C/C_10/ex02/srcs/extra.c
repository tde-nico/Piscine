/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 08:51:17 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/09 09:14:38 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int		i;
	unsigned int		j;

	j = 0;
	while (dest[j] != '\0')
		j++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int		i;
	int					state;

	i = 0;
	state = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && state == 0)
	{
		state = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (state == 0)
		state = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (state);
}

int	add_to_buffer(char *buffer, char cbuf, int len, int limit)
{
	int	i;

	if (limit == 0)
		return (0);
	if (len == limit)
	{
		i = 0;
		while (i < len - 1)
		{
			buffer[i] = buffer[i + 1];
			i++;
		}
		buffer[len - 1] = cbuf;
		return (len);
	}
	buffer[len] = cbuf;
	return (len + 1);
}

int	ft_atoi(char *str)
{
	long				result;
	int					i;

	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += (str[i] - '0');
		}
		else
			return (-1);
		i++;
	}
	return (result);
}
