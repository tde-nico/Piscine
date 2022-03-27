/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:49:37 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/15 08:19:28 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>

void	putstr(char *str, int out)
{
	while (*str)
	{
		write(out, str, 1);
		str++;
	}
}

void	display_error(char *exec, char *path)
{
	if (!errno)
		return ;
	putstr(basename(exec), 2);
	putstr(": ", 2);
	putstr(path, 2);
	putstr(": ", 2);
	putstr(strerror(errno), 2);
	putstr("\n", 2);
	errno = 0;
}

void	display_file_content(char *exec, char *path, int file_descriptor)
{
	int		bytes;
	char	buffer[1024];

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(file_descriptor, buffer, 1024);
		if (errno)
		{
			display_error(exec, path);
		}
		write(1, buffer, bytes);
	}
	if (file_descriptor > 2)
		close(file_descriptor);
}

int	cat(char **paths, int count, int offset)
{
	int		error;
	int		file_descriptor;
	int		i;
	char	*path;

	error = 1;
	i = offset;
	while (i < count + offset)
	{
		path = paths[i];
		file_descriptor = open(path, O_RDONLY);
		if (file_descriptor < 0)
		{
			display_error(paths[0], path);
			error = 0;
		}
		else
			display_file_content(paths[0], path, file_descriptor);
		i++;
	}
	return (error);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		display_file_content(NULL, NULL, 0);
	else if (!cat(argv, argc - 1, 1))
		return (1);
	return (0);
}
