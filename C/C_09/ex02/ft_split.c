/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 08:24:38 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/09 15:07:52 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (c != charset[i] && charset[i] != '\0')
		i++;
	if (charset[i] != '\0')
		return (0);
	return (1);
}

int	len(char *str, int i, char *charset)
{
	int	j;

	j = 0;
	while (ft_charset(str[i], charset) && str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

int	wc(char *str, char *charset)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] && charset[0])
	{
		while (ft_charset(str[i], charset) == 0)
			i++;
		if (str[i])
			nbr++;
		while (ft_charset(str[i], charset) == 1 && str[i] != '\0')
			i++;
	}
	if (!(charset[0]))
		return (1);
	return (nbr);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	k = 0;
	i = 0;
	tab = malloc(sizeof(*tab) * (wc(str, charset) + 1));
	if (!tab)
		return (0);
	while (i < wc(str, charset) && str[0] != '\0')
	{
		j = 0;
		while (ft_charset(str[k], charset) == 0 && str[k])
			k++;
		tab[i] = malloc(sizeof(char) * len(str, k, charset) + 1);
		if (!tab[i])
			return (0);
		while (ft_charset(str[k], charset) == 1 && str[k])
			tab[i][j++] = str[k++];
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
