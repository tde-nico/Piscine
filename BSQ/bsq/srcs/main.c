/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:44:11 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/14 15:57:08 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	get_file_content(int fd, char **file_content, int *total)
{
	char	buffer;
	int		bytes;
	char	prev;

	if (read(fd, 0, 0) == -1)
		return (0);
	*total = 0;
	*file_content = NULL;
	bytes = 1;
	prev = '\0';
	while (bytes > 0)
	{
		bytes = read(fd, &buffer, 1);
		*file_content = allocate(*file_content, buffer, *total, *total + bytes);
		if (prev == '\n' && buffer == '\n')
			return (1);
		if (!(*file_content))
			return (0);
		(*total) += bytes;
		prev = buffer;
	}
	if (bytes == 0)
		return (1);
	return (0);
}

void	process_args(t_map *map, t_sol *sol, int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (load_map(argv[i], map))
			process_map(map, sol);
		else
			write(2, "map error\n", 10);
		i++;
		if (i != argc)
			write(1, "\n", 1);
		free_map(map);
	}
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_sol	sol;

	if (argc < 2)
	{
		if (parse_map(0, &map))
			process_map(&map, &sol);
		else
			write(2, "map error\n", 10);
		free_map(&map);
	}
	else
		process_args(&map, &sol, argc, argv);
}
