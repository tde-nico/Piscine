/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:12:40 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/05 18:06:24 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	col_is_valid(int **tab, int *clues, int x, int size);
int	row_is_valid(int **tab, int *clues, int y, int size);
int	can_put_value(int **tab, int *pos, int value, int size);
int	search_empty_case(int **tab, int *pos, int size);
int	ft_strlen(char *str);

int	**generate_tab(int size)
{
	int	**tab;
	int	x;
	int	y;

	y = -1;
	tab = malloc(sizeof(*tab) * size);
	while (++y < size)
	{
		x = -1;
		tab[y] = malloc(sizeof(**tab) * size);
		while (++x < size)
			tab[y][x] = 0;
	}
	return (tab);
}

void	display_tab(int **tab, int size)
{
	int		y;
	int		x;
	char	c;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			c = tab[y][x];
			write(1, &c, 1);
			if (x != (size - 1))
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

int	resolve(int **tab, int *clues, int size)
{
	int	value;
	int	p[2];

	if (search_empty_case(tab, p, size))
	{
		value = '0';
		while (++value <= (size + '0'))
		{
			if (can_put_value(tab, p, value, size))
			{
				tab[p[1]][p[0]] = value;
				if (p[0] == (size - 1) && !row_is_valid(tab, clues, p[1], size))
					continue ;
				if (p[1] == (size - 1) && !col_is_valid(tab, clues, p[0], size))
					continue ;
				if (resolve(tab, clues, size))
					return (1);
			}
		}
		tab[p[1]][p[0]] = 0;
		return (0);
	}
	return (1);
}

int	*arg_check(char *av, int *size)
{
	int	i[3];
	int	*clues;

	i[0] = -1;
	i[1] = 0;
	i[2] = (ft_strlen(av) + 1) / 2 ;
	while (*size * 4 < i[2])
		*size += 1;
	clues = malloc(sizeof(*clues) * *size * 4);
	if (*size * 4 != i[2] || clues == NULL)
		return (NULL);
	while (av[++i[0]] != '\0')
	{
		if (i[0] % 2 != 0 && av[i[0]] == ' ')
			continue ;
		if ((i[0] % 2 != 0 && av[i[0]] != ' '))
			return (NULL);
		if (i[0] % 2 == 0 && !(av[i[0]] >= '1' && av[i[0]] <= (*size + '0')))
			return (NULL);
		clues[i[1]] = av[i[0]] - '0';
		i[1]++;
	}
	if (i[0] != (i[2] * 2 - 1))
		return (NULL);
	return (clues);
}

int	main(int argc, char **argv)
{
	int	**tab;
	int	size;
	int	*clues;

	size = 0;
	clues = NULL;
	if (argc == 2)
		clues = arg_check(argv[1], &size);
	if (clues == NULL)
		size = 0;
	tab = generate_tab(size);
	if (!resolve(tab, clues, size))
		size = 0;
	if (!size)
	{
		write(1, "Error\n", 6);
		free(clues);
		free(tab);
		return (1);
	}
	display_tab(tab, size);
	free(clues);
	free(tab);
	return (0);
}
