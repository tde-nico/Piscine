/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:39:50 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/14 15:24:18 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	load_map(char *path, t_map *map)
{
	int	fd;
	int	res;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	res = parse_map(fd, map);
	close(fd);
	return (res);
}

void	free_map(t_map *map)
{
	free(map->grid);
	free(map->source);
}

void	process_map(t_map *map, t_sol *sol)
{
	int	x;
	int	y;

	if (find_sol(sol, map))
	{
		x = sol->x;
		while (x < sol->x + sol->size)
		{
			y = sol->y;
			while (y < sol->y + sol->size)
			{
				map->grid[y][x] = map->tr[2];
				y++;
			}
			x++;
		}
		y = 0;
		while (y < map->h)
		{
			write(1, map->grid[y], map->w);
			write(1, "\n", 1);
			y++;
		}
	}
}
