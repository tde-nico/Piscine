/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 09:09:44 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/07 10:08:14 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*str_dup(char *src)
{
	int		i;
	char	*dest;

	i = -1;
	dest = malloc(ft_strlen(src) * sizeof(*src) + 1);
	if (!dest)
		return (0);
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*stock;

	stock = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!stock)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = av[i];
		stock[i].copy = str_dup(av[i]);
	}
	stock[i] = (struct s_stock_str){0, 0, 0};
	return (stock);
}
