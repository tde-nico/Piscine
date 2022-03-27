/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:40:53 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/14 16:01:04 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	parse_first_line(t_map *map, char *line, int len)
{
	int	res;

	if (len < 4)
		return (0);
	map->tr[2] = line[len - 1];
	map->tr[1] = line[len - 2];
	map->tr[0] = line[len - 3];
	if (line[len - 1] == line[len - 2] || line[len - 1] == line[len - 3]
		|| line[len - 2] == line[len - 3])
		return (0);
	res = ft_atoi(line, len - 3, &(map->h));
	return (res);
}

int	parse_normal_line(t_map *map, char *line, int len)
{
	int		i;
	char	c;

	if (len < 1)
		return (0);
	map->w = len;
	i = 0;
	while (i < len)
	{
		c = line[i];
		if (c == map->tr[2])
			return (0);
		if (c != map->tr[0] && c != map->tr[1] && c != map->tr[2])
			return (0);
		i++;
	}
	return (1);
}

int	check(t_map *map, int *w)
{
	if (*w == ((int) -1))
		*w = map->w;
	return (*w != map->w);
}

int	process_lines(t_map *map, int i, char *file_content, int total)
{
	int	j;
	int	y;
	int	w;

	y = 0;
	w = -1;
	while (i < total && y < map->h)
	{
		j = i;
		while (file_content[j] != '\n')
			if (j++ + 1 >= total)
				return (0);
		if (parse_normal_line(map, file_content + i, j - i))
		{
			map->grid[y++] = (char *)(file_content + i);
			if (check(map, &w))
				return (0);
		}
		else
			return (0);
		i = j + 1;
	}
	return (y == map->h);
}

int	parse_map(int fd, t_map *map)
{
	char	*file_content;
	int		total;
	int		i;

	map->grid = 0;
	if (!get_file_content(fd, &file_content, &total))
		return (0);
	map->source = file_content;
	i = 0;
	while (i < total)
	{
		if (file_content[i] == '\n')
		{
			if (!parse_first_line(map, file_content, i)
				|| (fd && map->h < count_lines(map) - 1)
				|| (!fd && map->h < count_lines(map) - 2))
				return (0);
			map->grid = malloc(sizeof(char *) * map->h);
			if (!map->grid)
				return (0);
			return (process_lines(map, i + 1, file_content, total));
		}
		i++;
	}
	return (0);
}
