/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:46:27 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/05 18:06:32 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	col_is_valid(int **tab, int *clues, int x, int size)
{
	int	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = -1;
	while (++i[2] < size)
	{
		i[1] += tab[i[2]][x] > i[0];
		if (tab[i[2]][x] > i[0])
			i[0] = tab[i[2]][x];
	}
	if (i[1] != clues[x])
		return (0);
	i[0] = 0;
	i[1] = 0;
	while (--i[2] >= 0)
	{
		i[1] += tab[i[2]][x] > i[0];
		if (tab[i[2]][x] > i[0])
			i[0] = tab[i[2]][x];
	}
	if (i[1] != clues[x + size])
		return (0);
	return (1);
}

int	row_is_valid(int **tab, int *clues, int y, int size)
{
	int	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = -1;
	while (++i[2] < size)
	{
		i[1] += tab[y][i[2]] > i[0];
		if (tab[y][i[2]] > i[0])
			i[0] = tab[y][i[2]];
	}
	if (i[1] != clues[y + size * 2])
		return (0);
	i[0] = 0;
	i[1] = 0;
	while (--i[2] >= 0)
	{
		i[1] += tab[y][i[2]] > i[0];
		if (tab[y][i[2]] > i[0])
			i[0] = tab[y][i[2]];
	}
	if (i[1] != clues[y + size * 3])
		return (0);
	return (1);
}

int	can_put_value(int **tab, int *pos, int value, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (tab[pos[1]][i] == value || tab[i][pos[0]] == value)
			return (0);
	return (1);
}

int	search_empty_case(int **tab, int *pos, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (tab[i][j] == 0)
			{
				pos[0] = j;
				pos[1] = i;
				return (1);
			}
		}
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
