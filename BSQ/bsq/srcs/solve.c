/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:42:03 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/14 14:45:32 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	find_sol(t_sol *sol, t_map *map)
{
	int		i;
	int		j;
	t_sol	try;

	i = 0;
	sol->size = 0;
	try.size = 1;
	while (i < map->h - sol->size)
	{
		j = 0;
		while (j < map->w - sol->size)
		{
			try.x = j;
			try.y = i;
			test_sol(sol, &try, map);
			j++;
		}
		i++;
	}
	return (sol->size);
}

void	test_sol(t_sol *sol, t_sol *try, t_map *map)
{
	if (!test(try, map))
		return ;
	sol->x = try->x;
	sol->y = try->y;
	sol->size++;
	try->size++;
	while (test_success(try, map))
	{
		sol->size++;
		try->size++;
	}
}

int	test(t_sol *try, t_map *map)
{
	int	i;
	int	i_max;
	int	j;
	int	j_max;

	if (fail(try, map))
		return (0);
	i = try->y;
	i_max = try->y + try->size;
	j_max = try->x + try->size;
	while (i < i_max)
	{
		j = try->x;
		while (j < j_max)
		{
			if (map->grid[i][j] == map->tr[1])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	test_success(t_sol *try, t_map *map)
{
	int	i;
	int	j;
	int	i_max;

	if (fail(try, map))
		return (0);
	i = try->x;
	i_max = try->x + try->size;
	j = try->y + try->size - 1;
	while (i < i_max)
	{
		if (map->grid[j][i] == map->tr[1])
			return (0);
		i++;
	}
	i = try->y;
	i_max = try->y + try->size - 1;
	j = try->x + try->size - 1;
	while (i < i_max)
	{
		if (map->grid[i][j] == map->tr[1])
			return (0);
		i++;
	}
	return (1);
}

int	fail(t_sol *try, t_map *map)
{
	return (try->x + try->size > map->w || try->y + try->size > map->h);
}
